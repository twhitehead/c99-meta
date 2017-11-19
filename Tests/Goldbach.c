#include "../Integer.h"
#include "../Tuple.h"
#include "../List.h"
#include "../Equal.h"
#include "../Order.h"


// The following code computes two lists
//
//   primes :: [Integer]               -- infinite list of prime numbers
//   goldbaches :: [(Integer,Integer)] -- infinite list of primes summing to even numbers
//
// The equivalent Haskell code is show in comments above and units test are included below.
//
//  - whether x is prime or not is determined by test dividing by all 2..x/2.
//  - the goldbach numbers for 2*x are determined by subtracting all primes in x..1 and checking to see if the
//    resulting number if prime in x..2*x
//
// For the later, should a solution not be found in x..1, an exception is generated with the number that disproves
// Goldbach's conjecture (all even numbers are the sum of two primes).
//
// Note that avoiding lazy thunk explossion requires us to be careful about work duplication
//
//  - duplicating a term without first reducing it
//  - using a term after having case reduced it or a strict operation on it without first having reduced it
//    ourselves
//
// This is especially important in recursive code as it can turn O(N) into O(N^2).  Possibly reduceCaseN routines
// should return the reduced version as well to help avoid the second issue (as in ghc core).  This doesn't help
// the case of using strict operations though.
//
// A general rule of thumb is to pre-reduce anything that gets passed on that we are strict in or duplicating.
// Especially if any recursion is involved.


// from x is [x..].
//
// take 7 (from 2): [2,3,4,5,6,7,8]
//
// from :: Integer -> [Integer]
// from !x = x : from (x+1)
//
// It duplicates and recursed with x.
//
#define _from(x,...) reduce1(from0,x,__VA_ARGS__)
#define _from0(x,...) construct((Cons,x,(from,(add,x,P1))),__VA_ARGS__)

 eval(take,P7,(from,P2))
={0x2,0x3,0x4,0x5,0x6,0x7,0x8}

// fromTo x y is [x..y].
//
// fromTo 3 7: [3,4,5,6,7]
//
// fromTo :: Integer -> Integer -> [Integer]
// fromTo !x !y = case x <= y of
//   True  -> x : fromTo (x+1) y
//   False -> []
//
// It is strict in x and y and duplicates x and recurses with x and y.
//
#define _fromTo( x,y,...) reduce2(fromTo0,x,y,__VA_ARGS__)
#define _fromTo0(x,y,...) caseReduce1(fromTo0,(lesserequal,x,y),x,y,__VA_ARGS__)
#define _fromTo0_bool_True( x,y,...) construct((Cons,x,(fromTo,(add,x,P1),y)),__VA_ARGS__)
#define _fromTo0_bool_False(x,y,...) construct((Nil),__VA_ARGS__)

 eval(fromTo,P3,P7)
={0x3,0x4,0x5,0x6,0x7}

// Test2 x y checks if x is not evenly divisible by y.
//
// test2 6 3: False
// test2 7 3: True
// test2 9 3: False
//
// test2 :: Integer -> Integer -> Bool
// test2 x y = (x `rem` y) /= 0
//
// It is strict in x and y but neither duplicates nor recurses with them.
//
#define _test2(x,y,...) reduce(notequal,(second,(quotientRemainder,x,y)),Z,__VA_ARGS__)

 eval(test2,P6,P3)
=bool_False
 eval(test2,P7,P3)
=bool_True
 eval(test2,P9,P3)
=bool_False


// Test1 x checks if x is prime.
//
// test1 1: True
// test1 3: True
// test1 4: False
// test1 9: False
//
// test1 :: Integer -> Bool
// test1 !x = all (test2 x) (fromTo 2 (x `quot` 2))
//
// It duplicates x to two functions that are both strict in it.
//
#define _test1( x,...) reduce1(test10,x,__VA_ARGS__)
#define _test10(x,...) reduce(all,(test2,x),(fromTo,P2,(first,(quotientRemainder,x,P2))),__VA_ARGS__)

 eval(test1,P1)
=bool_True
 eval(test1,P3)
=bool_True
 eval(test1,P4)
=bool_False
 eval(test1,P9)
=bool_False


// primes is the infinite lazy list of primes starting with 1.
//
// take 7 primes: [1,2,3,5,7,11,13]
//
// primes :: [Integer]
// primes = filter test1 (from 1)
//
#define primes (filter,(test1),(from,P1))

 eval(take,P5,primes)
={0x1,0x2,0x3,0x5,0x7}

// sieve x ys ps returns (y,p) from ys and ps such that y+p=2*x or blows up.
//
//   ys - descending order with "all (< x) ys"
//   ps - ascending order with "last ys = head ps" and "all (> x) (tail ps)".
//
// It's purpose is to consume two lists of primes in a merge like fashion to locate the two that sum to 2*x.
//
// sieve 6 [5,3,2,1] [5,7,11,13]: (5,7)
//
// sieve :: Integer -> [Integer] -> [Integer] -> (Integer,Integer)
// sieve  x []       _      = error ( show x )
// sieve !x (!y:ys) (!p:ps) =
//   case compare (y+p) (2*x) of
//     EQ -> (y,p)
//     GT -> sieve x    ys  (p:ps)
//     LT -> sieve x (y:ys)    ps
//
// It is strict in x, y, and p and recurses with them.
//
#define _sieve(x,ys,ps,...) caseReduce2(sieve,ys,ps,x,__VA_ARGS__)
#define _sieve_list_Cons_list_Cons(          y,ys,p,ps,x,...) reduce3(sieve_list_Cons_list_Cons0,x,y,p,ys,ps,__VA_ARGS__)
#define _sieve_list_Cons_list_Cons0(x,y,p,     ys,  ps,  ...) caseReduce1(sieve_list_Cons_list_Cons0,(compare,(add,y,p),(multiply,P2,x)),y,ys,p,ps,x,__VA_ARGS__)
#define _sieve_list_Cons_list_Cons0_order_EQ(y,ys,p,ps,x,...) construct((Tuple2,y,p),__VA_ARGS__)
#define _sieve_list_Cons_list_Cons0_order_GT(y,ys,p,ps,x,...) reduce(sieve,x,        ys ,(Cons,p,ps),__VA_ARGS__)
#define _sieve_list_Cons_list_Cons0_order_LT(y,ys,p,ps,x,...) reduce(sieve,x,(Cons,y,ys),        ps ,__VA_ARGS__)
#define _sieve_list_Nil_list_Cons(                p,ps,x,...) eval(show,x)

 eval(sieve,P6,L4(P5,P3,P2,P1),L4(P5,P7,P11,P13))
=(0x5,0x7)

// shift x ys ps removes values less than x from ps and prepends them in reverse to ys.
//
//   ys - descending order with "all (< x) ys"
//   ps - ascending order with "all (> head ys) ps" and "some (>= x) ps"
//
// It's purpose is to prep two lists of primes that can be consumed in a merge like fashion to see if it is
// possible to sum to 2*x with primes.  This preped lists can then be re-used as the input to the next shift for
// the next 2*x search.
//
// shift :: Integer -> [Integer] -> [Integer] -> ([Integer],[Integer])
// shift !x ys (!p:ps) =
//   case p < x of
//     True  -> shift x (p:ys) ps
//     False -> (p:ys,p:ps)
//
// shift 7 [3,2,1] [5,7,11]: ([7,5,3,2,1],[7,11])
//
// It is strict in p and x, duplicates p and recursed with both p and x.
//
#define _shift(x,ys,ps,...) caseReduce1(shift,ps,x,ys,__VA_ARGS__)
#define _shift_list_Cons(p,ps,            x,ys,...) reduce2(shift_list_Cons0,p,x,ps,ys,__VA_ARGS__)
#define _shift_list_Cons0(p,x,         ps,  ys,...) caseReduce1(shift_list_Cons0,(lesser,p,x),p,ps,x,ys,__VA_ARGS__)
#define _shift_list_Cons0_bool_True( p,ps,x,ys,...) reduce(shift,x,(Cons,p,ys),ps,__VA_ARGS__)
#define _shift_list_Cons0_bool_False(p,ps,x,ys,...) construct((Tuple2,(Cons,p,ys),(Cons,p,ps)),__VA_ARGS__)

 eval(shift,P7,L3(P3,P2,P1),L3(P5,P7,P11))
=({0x7,0x5,0x3,0x2,0x1},{0x7,0xb})

// goldbachs is the infinite lazy list of prime pairs summing to the even numbers starting with 2.
//
// It is computed from the infinite lazy list of primes by slowly peeling the head of the prime list of as a
// reversed list containig all the primes less than half of the desired even number sum.  The two lists are them
// incrementally filtered/merged to locate the two primes that add up.
//
// The nice thing about this approach is the two lists required for the next even number sum are just slight tweaks
// of the two required for the current even number sum (shift another prime off the prime list to the reversed list
// if required).  It also means primes that are closer in value to each other are tested first for summing which
// seems to be which most succesfull ones are.
//
// take 8 goldbachs: [(1,1),(2,2),(3,3),(3,5),(5,5),(5,7),(7,7),(5,11)]
//
// loop1 :: Integer -> [Integer] -> [Integer] -> [(Integer,Integer)]
// loop1 x ys ps = sieve x ys ps : loop0 (x+1) (tail ys) ps
//
// loop0 :: Integer -> [Integer] -> [Integer] -> [(Integer,Integer)]
// loop0 !x ys ps = uncurry (loop1 x) (shift x ys ps)
//
// goldbachs :: [(Integer,Integer)]
// goldbachs = loop0 1 [] prime
//
// Both loops duplicate and recurse with x (loop0 always recieved a reduced x though so it is okay).
//
#define _loop1(x,ys,ps,...) construct((Cons,(sieve,x,ys,ps),(loop0,(add,x,P1),(tail,ys),ps)),__VA_ARGS__)

#define _loop0( x,ys,ps,...) reduce1(loop00,x,ys,ps,__VA_ARGS__)
#define _loop00(x,ys,ps,...) reduce(uncurry,(loop1,x),(shift,x,ys,ps),__VA_ARGS__)

#define goldbachs (loop0,P1,(Nil),primes)

 eval(take,P8,goldbachs)
={(0x1,0x1),(0x2,0x2),(0x3,0x3),(0x3,0x5),(0x5,0x5),(0x5,0x7),(0x7,0x7),(0x5,0xb)}
