# Overview

Why should C++ people have all the meta-programming fun that comes
from abusing the heck out of their language?

Variadic macros accidentally made the C99 pre-processor [Turing
complete](https://en.wikipedia.org/wiki/Turing_completeness) too.
It's time for C people to get in on the fun too!


# Quick intro

Have a look at [Tests/List.c](Tests/List.c) to get an idea of how it
works.  Compile up this file

```sh
gcc --std=c99 -E Tests/List.c
```

and you will see the C99 pre-processor faithfully replaces each
`eval(...)` line with it's value to match the line below.  Note,
in particular, the use of partial application in statements like

```C
eval(map,(add,P1),L2(P1,P2))
```

(i.e., the equivalent to the Haskell `map (+ 1) [1,2]`).


# More details

Let's take a quick look at the implementation of `zipWith` in
[List.h](List.h).  From the [Tests/List.c](Tests/List.c) file we see

```C
 eval(zipWith,(Tupple2),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x2,0x1),(0x3,0x4),(0x4,0x5)}
```
where the first line will evaluate to the second (minus the `=`)
when passed through the pre-processor.

## Wonky syntax

The fact that the pre-processor has very limited syntax and only
really understands strings puts some limitations on the syntax.  What
emerges is a lisp like thing with `,` being the separator instead of
` `.

The above could thus be thought of as

```
(zipWith (Tupple2) L3(P2 P3 P4) L4(P1 P2 P3 P4))
```

where

`PN`
  ~ the Nth positive integer (i.e., `P2` is `2`)

`LN`
  ~ a macro to construct a N-component list (i.e., `L3(P2,P3,P4)` is `[2,3,4]`

`TuppleN`
  ~ the N-component tuple constructor (i.e., `Tupple2` would be `(,)`)

## Implementation

In Haskell, a `zipWith` implementation would look something like this

```haskell
zipWith f (x:xs) (y:ys) = f x y : zipWith f xs ys
zipWith f _      _      = []
```

Or, in more gruesome detail, if we had to drop the function matching
syntactic sugar and fully spelling out all the pattern match cases

```haskell
zipWith f xs ys = case xs ys of
  (x:xs) (y:ys) -> f x y : zipWith f xs ys
  (x:xs) []     -> []
  []     (y:ys) -> []
  []     []     -> []

```

Looking into the `List.h` file, we hopefully recognize an implementation
that pretty much mirrors this later version

```
#define _list_zipWith(f,xs,ys,...)                         reduce_caseReduce2(list_zipWith,xs,ys,f,__VA_ARGS__)
#define _list_zipWith_list_Cons_list_Cons(x,xs,y,ys,f,...) reduce_construct((list_Cons,reduce_apply(f,x,y),(list_zipWith,f,xs,ys)),__VA_ARGS__)
#define _list_zipWith_list_Cons_list_Nil( x,xs     ,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith_list_Nil_list_Cons(      y,ys,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith_list_Nil_list_Nil(            f,...) reduce_construct((list_Nil),__VA_ARGS__)
```

The first line define `_list_zipWith(f,xs,ys,...)`.  It is a `zipWith`
binding in the `list` namespace that takes three arguments (note that,
this being a lazy system, all definitions are functions).

The body associated with this binding is a call to the
`reduce_caseReduce2` macro (the leading `reduce` is a namespace -- see
[Reduce.h](Reduce.h) for full details and more forms).  This macro takes the
base name of the next macro to call, two arguments to evaluate to weak
head normal form (WHNF) whose types are append to the base name, and
any other arguments/bindings to pass along.

The rest is then just bindings for each of the cases.  Each of them
construct a list type by calling the macro `reduce_construct` (again
the leading `reduce` is just the namesapce -- see [Reduce.h](Reduce.h)
for full details).  This constructs the type an continues with
whatever caused us to be evaluated.

In the first case it is a `list_Cons` constructor (i.e., `:` in
Haskell), where the first argument (the head of the list) is `f`
applied to `x` and `y` and the second argument (the tail of the list)
is a recursive call to zipWith.  In the remainder cases, as with the
Haskell code, it is just the `list_Nil` constructor.


# Debugging

The evaluation should not go astray if the types are correct (i.e.,
functions cover all the cases for the types they support and are only
applied to arguments of those types).  Noticeably absent though is
type annotations and a type checker to ensure this is the case.

What's the nest best thing?  Break the code into small bits and tests
to ensure those small bits do what they are suppose to do.  Another
easy option is to translate the problematic code to Haskell.  Haskell
has a type checker, so it will tell you where things went wrong.

## Decoding bad output

All that aside, there is some basic information to be obtained from
the bad output.  Take, for example, the incorrect expression

```C
eval(zipWith,(Tuple2),L3(P2,P3,P4),P4)
```

which calls `zipWith` with a `Integer` third argument instead of a
`List`.  It evaluates to a long ugly string that begins with

```
_list_zipWith_list_Cons_integer_Integer
```

prefixed with a bunch of `_recurse_NN_` prefixes.  What this means is
pattern matching went astray because in the definition of `zipWith`
above

```C
reduce_caseReduce2(list_zipWith,xs,ys,f,__VA_ARGS__)
```

there was no `list_zipWith_list_Cons_integer_Integer` branch.  The
`ys` argument must be of `List` type because it is only matched
against the `List` constructors.  An invalid call was made to
`zipWith` with an incorrect third argument that was not a `List`.

## Single stepping

Where?  Well that gets messy.  The evaluation can be stopped at an
arbitrary step by defining `RECURSE_DEBUG`.  For example,

```sh
gcc --std=c99 -E -D "RECURSE_DEBUG=(0,0,1,c)" Tests/List.c
```

stops evaluation at recursion step `0x1c` (i.e., `28`).  With a bit of
shell scripting to repeatedly call it for incrementing values of
`RECURSE_DEBUG` it is possible to simulate single stepping the
evaluation.

For example, assume the problematic code is in the file
[Debug.c](Debug.c).

```
#include "List.h"
#include "Integer.h"

tag: eval(zipWith,(Tuple2),L3(P2,P3,P4),P3)
```

where we've added `tag:` as some arbitrary bit of text filter the
output to just the line we are interested in.  Then the following code
will dump a trace of the first 256 evaluation steps

```sh
for i1 in {0..9} a b c d e f; do
  for i0 in in {0..9} a b c d e f; do
    gcc --std=c99 -E -D "RECURSE_DEBUG=(0,0,$i1,$i0)" Example.c | sed -e '/^tag:/!d' >> Example.c-singlestep
  done
done
```

Of course the evaluation is lazy, and single stepping lazy programs
gives notoriously convoluted code path.

What to do?  Did we mention how it is a good idea to break the program
into small bits and verify that these small bits work as advertised
before attempting building bigger components from faulty blocks?


# Implementation

The code is well documented.  See [Recurse.h](Recurse.h) for details
about how Variadic macros accidentally made the the C99 pre-processor
turning complete.  Then see [Reduce.h](Reduce.h) for details on how a
somewhat Haskell-like syntax is achieved on top of this.
