//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2, or (at your
// option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef REDUCE_H_INCLUDED
#define REDUCE_H_INCLUDED

#include "Recurse.h"
#include "Raw.h"

// This implements a friendlier interface to build with on top of the recursion
// system.  It looks like a lazy functional programming language (something
// like the spineless tagless G (STG) machine) being reduced implemented on a
// stack (something like forth).
//
// The basic reduction operations provided are:
//
//   Eager(f,x1,...,xN,__VA_ARGS__)
//
//     Push x1,...,xN and tail call f.
//
//   EagerCaseN(f,x1,...,xN,__VA_ARGS__)
//
//     Push ..._t1,...,..._tN, where x1,...,xN are in the form (t1,..._t1),...,
//     (tN,..._tN), and tail call f_##t1##..._##tN.
//
//   LazyN(f,x1,...,xN,__VA_ARGS__)
//
//     Evaluate x1,...,xN (for each one, push its continuation and tail call
//     it), push the results, and tail call f.
//
//   LazyCaseN(f,x1,...,xN,__VA_ARGS__)
//
//     Evaluate x1,...,xN to (t1,..._t1),...,(tN,..._tN) (for each one, push its
//     continuation and call it), push ..._t1,...,..._tN, and tail call
//     f_##t1##..._##tN.  This is like the STG's case expression.
//
//   Return(x,__VA_ARGS__)
//
//     Continue with x (expand x onto the stack and tail call it).  This is like
//     the STG's function application.  It is more efficient, but maybe not
//     advised, to invoke f directly when there is no recursion.
//
//   Construct(x,__VA_ARGS__)
//
//     Return the basic type x (pop off the continuation, push x, push the
//     continuation, and tail call it).  This is like the STG's constructor
//     application.
//
//   Output(o,f,__VA_ARGS__)
//
//     Output o and then tail call f.
//
//   Error(o)
//
//     Output error o and then quit.
//
// There is also a Mixed((k1,...,kN),f,x1,...,xN), where xi is treated as in
// Eager, EagerCase, Lazy, or LazyCase when ki is respecively E, EC, L, or LC.
//
// There is no equivalent of the STG's let expression, as there is no heap
// (while one could be simulated, it is likely the cost of copying expressions
// and duplicating some reductions is much less).


#define reduce_eval(...) recurse_recurse(__VA_ARGS__,(reduce_eval0))
#define _reduce_eval0(...) _reduce_eval1(__VA_ARGS__)
#define _reduce_eval1(x,_) Quit,("RESULT: "#x)


#define reduce_Eager(...) Recurse,(__VA_ARGS__)
#define _reduce_Eager(...) Recurse,(__VA_ARGS__)


#define reduce_EagerCase1(f,x0,...) Recurse,(_raw_identifier2_(f,_,_raw_expandJust1(x0)),_raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define reduce_EagerCase2(f,x0,x1,...) _reduce_EagerCase10(f,_raw_identifier1_(_,_raw_expandJust1(x1)),x0,_raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define reduce_EagerCase3(f,x0,x1,x2,...) _reduce_EagerCase20(f,_raw_identifier1_(_,_raw_expandJust1(x2)),x0,x1,_raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define reduce_EagerCase4(f,x0,x1,x2,x3,...) _reduce_EagerCase30(f,_raw_identifier1_(_,_raw_expandJust1(x3)),x0,x1,x2,_raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define reduce_EagerCase5(f,x0,x1,x2,x3,x4,...) _reduce_EagerCase40(f,_raw_identifier1_(_,_raw_expandJust1(x4)),x0,x1,x2,x3,_raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))

#define _reduce_EagerCase1(f,x0,...)     Recurse,(_raw_identifier2_(f,_,_raw_expandJust1(x0)),_raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define _reduce_EagerCase10(f,ft,x0,...) Recurse,(_raw_identifier3_(f,_,_raw_expandJust1(x0),ft),_raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define _reduce_EagerCase2(f,x0,x1,...)     _reduce_EagerCase10(f,_raw_identifier1_(_,_raw_expandJust1(x1)),x0,_raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define _reduce_EagerCase20(f,ft,x0,x1,...) _reduce_EagerCase10(f,_raw_identifier2_(_,_raw_expandJust1(x1),ft),x0,_raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define _reduce_EagerCase3(f,x0,x1,x2,...)     _reduce_EagerCase20(f,_raw_identifier1_(_,_raw_expandJust1(x2)),x0,x1,_raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define _reduce_EagerCase30(f,ft,x0,x1,x2,...) _reduce_EagerCase20(f,_raw_identifier2_(_,_raw_expandJust1(x2),ft),x0,x1,_raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define _reduce_EagerCase4(f,x0,x1,x2,x3,...)     _reduce_EagerCase30(f,_raw_identifier1_(_,_raw_expandJust1(x3)),x0,x1,x2,_raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define _reduce_EagerCase40(f,ft,x0,x1,x2,x3,...) _reduce_EagerCase30(f,_raw_identifier2_(_,_raw_expandJust1(x3),ft),x0,x1,x2,_raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define _reduce_EagerCase5(f,x0,x1,x2,x3,x4,...)     _reduce_EagerCase40(f,_raw_identifier1_(_,_raw_expandJust1(x4)),x0,x1,x2,x3,_raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))
#define _reduce_EagerCase50(f,ft,x0,x1,x2,x3,x4,...) _reduce_EagerCase40(f,_raw_identifier2_(_,_raw_expandJust1(x4),ft),x0,x1,x2,x3,_raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))


#define reduce_Lazy1(f,x0,...) Recurse,(_raw_expand(x0),(f),__VA_ARGS__)
#define reduce_Lazy2(f,x0,x1,...) Recurse,(_raw_expand(x1),(reduce_Lazy20,f,x0),__VA_ARGS__)
#define reduce_Lazy3(f,x0,x1,x2,...) Recurse,(_raw_expand(x2),(reduce_Lazy30,f,x0,x1),__VA_ARGS__)
#define reduce_Lazy4(f,x0,x1,x2,x3,...) Recurse,(_raw_expand(x3),(reduce_Lazy40,f,x0,x1,x2),__VA_ARGS__)
#define reduce_Lazy5(f,x0,x1,x2,x3,x4,...) Recurse,(_raw_expand(x4),(reduce_Lazy50,f,x0,x1,x2,x3),__VA_ARGS__)

#define _reduce_Lazy1(f,x0,...)  Recurse,(_raw_expand(x0),(f),__VA_ARGS__)
#define _reduce_Lazy2(f,x0,x1,...)  Recurse,(_raw_expand(x1),(reduce_Lazy20,f,x0),__VA_ARGS__)
#define _reduce_Lazy20(f,x0,y1,...) reduce_Lazy1(f,x0,y1,__VA_ARGS__)
#define _reduce_Lazy3(f,x0,x1,x2,...)  Recurse,(_raw_expand(x2),(reduce_Lazy30,f,x0,x1),__VA_ARGS__)
#define _reduce_Lazy30(f,x0,x1,y2,...) reduce_Lazy2(f,x0,x1,y2,__VA_ARGS__)
#define _reduce_Lazy4(f,x0,x1,x2,x3,...)  Recurse,(_raw_expand(x3),(reduce_Lazy40,f,x0,x1,x2),__VA_ARGS__)
#define _reduce_Lazy40(f,x0,x1,x2,y3,...) reduce_Lazy3(f,x0,x1,x2,y3,__VA_ARGS__)
#define _reduce_Lazy5(f,x0,x1,x2,x3,x4,...)  Recurse,(_raw_expand(x4),(reduce_Lazy50,f,x0,x1,x2,x3),__VA_ARGS__)
#define _reduce_Lazy50(f,x0,x1,x2,x3,y4,...) reduce_Lazy4(f,x0,x1,x2,x3,y4,__VA_ARGS__)


#define reduce_LazyCase1(f,x0,...) Recurse,(_raw_expand(x0),(reduce_LazyCase10,f,),__VA_ARGS__)
#define reduce_LazyCase2(f,x0,x1,...) Recurse,(_raw_expand(x1),(reduce_LazyCase20,f,,x0),__VA_ARGS__)
#define reduce_LazyCase3(f,x0,x1,x2,...) Recurse,(_raw_expand(x2),(reduce_LazyCase30,f,,x0,x1),__VA_ARGS__)
#define reduce_LazyCase4(f,x0,x1,x2,x3,...) Recurse,(_raw_expand(x3),(reduce_LazyCase40,f,,x0,x1,x2),__VA_ARGS__)
#define reduce_LazyCase5(f,x0,x1,x2,x3,x4,...) Recurse,(_raw_expand(x4),(reduce_LazyCase50,f,,x0,x1,x2,x3),__VA_ARGS__)

#define _reduce_LazyCase1(f,x0,...)     Recurse,(_raw_expand(x0),(reduce_LazyCase10,f,),__VA_ARGS__)
#define _reduce_LazyCase10(f,ft,y0,...) Recurse,(_raw_identifier3_(f,_,_raw_expandJust1(y0),ft),_raw_expandDrop1Merge(_raw_expand(y0),__VA_ARGS__))
#define _reduce_LazyCase2(f,x0,x1,...)     Recurse,(_raw_expand(x1),(reduce_LazyCase20,f,,x0),__VA_ARGS__)
#define _reduce_LazyCase20(f,ft,x0,y1,...) Recurse,(_raw_expand(x0),(reduce_LazyCase10,f,_raw_identifier2_(_,_raw_expandJust1(y1),ft)),_raw_expandDrop1Merge(_raw_expand(y1),__VA_ARGS__))
#define _reduce_LazyCase3(f,x0,x1,x2,...)     Recurse,(_raw_expand(x2),(reduce_LazyCase30,f,,x0,x1),__VA_ARGS__)
#define _reduce_LazyCase30(f,ft,x0,x1,y2,...) Recurse,(_raw_expand(x1),(reduce_LazyCase20,f,_raw_identifier2_(_,_raw_expandJust1(y2),ft),x0),_raw_expandDrop1Merge(_raw_expand(y2),__VA_ARGS__))
#define _reduce_LazyCase4(f,x0,x1,x2,x3,...)     Recurse,(_raw_expand(x3),(reduce_LazyCase40,f,,x0,x1,x2),__VA_ARGS__)
#define _reduce_LazyCase40(f,ft,x0,x1,x2,y3,...) Recurse,(_raw_expand(x2),(reduce_LazyCase30,f,_raw_identifier2_(_,_raw_expandJust1(y3),ft),x0,x1),_raw_expandDrop1Merge(_raw_expand(y3),__VA_ARGS__))
#define _reduce_LazyCase5(f,x0,x1,x2,x3,x4,...)     Recurse,(_raw_expand(x4),(reduce_LazyCase50,f,,x0,x1,x2,x3),__VA_ARGS__)
#define _reduce_LazyCase50(f,ft,x0,x1,x2,x3,y4,...) Recurse,(_raw_expand(x3),(reduce_LazyCase40,f,_raw_identifier2_(_,_raw_expandJust1(y4),ft),x0,x1,x2),_raw_expandDrop1Merge(_raw_expand(y4),__VA_ARGS__))


#define reduce_Mixed(a,f,...)      Recurse,(_raw_identifier2_(reduce_Mixed,_,_raw_expandJust1(a)),_tupple_drop1(a),f,(reduce_Mixed2),__VA_ARGS__)

#define _reduce_Mixed(a,f,...)     Recurse,(_raw_identifier2_(reduce_Mixed,_,_raw_expandJust1(a)),_tupple_drop1(a),f,(reduce_Mixed2),__VA_ARGS__)
#define _reduce_Mixed1(a,f,c,...)  Recurse,(_raw_identifier2_(reduce_Mixed,_,_raw_expandJust1(a)),_tupple_drop1(a),f,c,__VA_ARGS__)
#define _reduce_Mixed2(f,ft,c,...) Recurse,(_raw_identifier1_(f,ft),_raw_expand(c))
#define _reduce_Mixed_(a,f,c,...)  Recurse,(_raw_expandJust1(c),f,,(__VA_ARGS__),_raw_expandDrop1(c))

#define _reduce_Mixed_E(a,f,c,x,...)     _reduce_Mixed1(a,f,(reduce_Mixed_E0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_Mixed_E0(f,ft,c,x,g,...) Recurse,(g,f,ft,_tupple_insert1((x),c),__VA_ARGS__)
#define _reduce_Mixed_EC(a,f,c,x,...)     _reduce_Mixed1(a,f,(reduce_Mixed_EC0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_Mixed_EC0(f,ft,c,x,g,...) Recurse,(g,f,_raw_identifier2_(_,_raw_expandJust1(x),ft),_raw_expandDrop1Merge(_raw_expand(x),_raw_expand(c)),__VA_ARGS__)

#define _reduce_Mixed_L(a,f,c,x,...)     _reduce_Mixed1(a,f,(reduce_Mixed_L0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_Mixed_L0(f,ft,c,x,...)   Recurse,(_raw_expand(x),(reduce_Mixed_L1,f,ft,c),__VA_ARGS__)
#define _reduce_Mixed_L1(f,ft,c,y,g,...) _##g(f,ft,_tupple_insert1((y),c),__VA_ARGS__)

#define _reduce_Mixed_LC(a,f,c,x,...)     _reduce_Mixed1(a,f,(reduce_Mixed_LC0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_Mixed_LC0(f,ft,c,x,...)   Recurse,(_raw_expand(x),(reduce_Mixed_LC1,f,ft,c),__VA_ARGS__)
#define _reduce_Mixed_LC1(f,ft,c,y,g,...) _##g(f,_raw_identifier2_(_,_raw_expandJust1(y),ft),_raw_expandDrop1Merge(_raw_expand(y),_raw_expand(c)),__VA_ARGS__)


#define reduce_Return(x,...)  Recurse,(_raw_expand(x),__VA_ARGS__)
#define _reduce_Return(x,...) Recurse,(_raw_expand(x),__VA_ARGS__)

#define reduce_Construct(x,f,...)  Recurse,(_raw_expand(f),x,__VA_ARGS__)
#define _reduce_Construct(x,f,...) Recurse,(_raw_expand(f),x,__VA_ARGS__)

#define reduce_Output(o,f,...)  Output,o,(_raw_expand(f),__VA_ARGS__)
#define _reduce_Output(o,f,...) Output,o,(_raw_expand(f),__VA_ARGS__)

#define reduce_Error(o,...)  Quit,("ERROR: "#o)
#define _reduce_Error(o,...) Quit,("ERROR: "#o)


#ifndef REDUCE_QUALIFIED_ONLY
  #define eval   reduce_eval

  #define Eager reduce_Eager

  #define EagerCase1 reduce_EagerCase1
  #define EagerCase2 reduce_EagerCase2
  #define EagerCase3 reduce_EagerCase3
  #define EagerCase4 reduce_EagerCase4
  #define EagerCase5 reduce_EagerCase5

  #define Lazy1 reduce_Lazy1
  #define Lazy2 reduce_Lazy2
  #define Lazy3 reduce_Lazy3
  #define Lazy4 reduce_Lazy4
  #define Lazy5 reduce_Lazy5

  #define LazyCase1 reduce_LazyCase1
  #define LazyCase2 reduce_LazyCase2
  #define LazyCase3 reduce_LazyCase3
  #define LazyCase4 reduce_LazyCase4
  #define LazyCase5 reduce_LazyCase5

  #define Mixed reduce_Mixed

  #define Return    return_Return
  #define Construct reduce_Construct
  #define Output    reduce_Output
  #define Error     reduce_Error
#endif // REDUCE_QUALIFIED_ONLY


#endif // REDUCE_H_INCLUDED
