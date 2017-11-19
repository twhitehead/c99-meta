//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
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
//   Reduce(f,x1,...,xN,__VA_ARGS__)
//
//     Push x1,...,xN and tail call f.
//
//   ReduceN(f,x1,...,xN,__VA_ARGS__)
//
//     Evaluate x1,...,xN (for each one, push its continuation and tail call
//     it), push the results, and tail call f.
//
//   CaseN(f,x1,...,xN,__VA_ARGS__)
//
//     Push ..._t1,...,..._tN, where x1,...,xN are in the form (t1,..._t1),...,
//     (tN,..._tN), and tail call f_##t1##..._##tN.
//
//   CaseReduceN(f,x1,...,xN,__VA_ARGS__)
//
//     Evaluate x1,...,xN to (t1,..._t1),...,(tN,..._tN) (for each one, push its
//     continuation and call it), push ..._t1,...,..._tN, and tail call
//     f_##t1##..._##tN.  This is like the STG's case expression.
//
//   Continue(x,__VA_ARGS__)
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
// There is also a Mixed((k1,...,kN),f,x1,...,xN), where xi is treated as is
// or as in Reduce, Case, or CaseReduce when ki is respecively I, R, C, CR.
//
// There is no equivalent of the STG's let expression, as there is no heap
// (while one could be simulated, it is likely the cost of copying expressions
// and duplicating some reductions is much less).


#define reduce_eval(...)                recurse_recurse(reduce_caseReduce1,reduce_eval,(show,(__VA_ARGS__)))
#define _reduce_eval_show_Output(o,...) Quit,o


#define reduce_apply(f,...) (_raw_expand(f),__VA_ARGS__)


#define reduce_reduce(...)  Recurse,(__VA_ARGS__)
#define _reduce_reduce(...) Recurse,(__VA_ARGS__)


#define reduce_reduce1(f,x0,...)             Recurse,(_raw_expand(x0),(                f),            __VA_ARGS__)
#define reduce_reduce2(f,x0,x1,...)          Recurse,(_raw_expand(x1),(reduce_reduce20,f,x0),         __VA_ARGS__)
#define reduce_reduce3(f,x0,x1,x2,...)       Recurse,(_raw_expand(x2),(reduce_reduce30,f,x0,x1),      __VA_ARGS__)
#define reduce_reduce4(f,x0,x1,x2,x3,...)    Recurse,(_raw_expand(x3),(reduce_reduce40,f,x0,x1,x2),   __VA_ARGS__)
#define reduce_reduce5(f,x0,x1,x2,x3,x4,...) Recurse,(_raw_expand(x4),(reduce_reduce50,f,x0,x1,x2,x3),__VA_ARGS__)

#define _reduce_reduce1( f,x0,...)             Recurse,(_raw_expand(x0),(                f),            __VA_ARGS__)
#define _reduce_reduce2( f,x0,x1,...)          Recurse,(_raw_expand(x1),(reduce_reduce20,f,x0),         __VA_ARGS__)
#define _reduce_reduce20(f,x0,y1,...)          reduce_reduce1(f,x0,y1,         __VA_ARGS__)
#define _reduce_reduce3( f,x0,x1,x2,...)       Recurse,(_raw_expand(x2),(reduce_reduce30,f,x0,x1),      __VA_ARGS__)
#define _reduce_reduce30(f,x0,x1,y2,...)       reduce_reduce2(f,x0,x1,y2,      __VA_ARGS__)
#define _reduce_reduce4( f,x0,x1,x2,x3,...)    Recurse,(_raw_expand(x3),(reduce_reduce40,f,x0,x1,x2),   __VA_ARGS__)
#define _reduce_reduce40(f,x0,x1,x2,y3,...)    reduce_reduce3(f,x0,x1,x2,y3,   __VA_ARGS__)
#define _reduce_reduce5( f,x0,x1,x2,x3,x4,...) Recurse,(_raw_expand(x4),(reduce_reduce50,f,x0,x1,x2,x3),__VA_ARGS__)
#define _reduce_reduce50(f,x0,x1,x2,x3,y4,...) reduce_reduce4(f,x0,x1,x2,x3,y4,__VA_ARGS__)


#define reduce_case1(f,x0,...)                  Recurse,(_raw_expandFuse3_(f,_,_raw_expandJust1(x0)),                  _raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define reduce_case2(f,x0,x1,...)               _reduce_case10(f,_raw_expandFuse2_(_,_raw_expandJust1(x1)),x0,         _raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define reduce_case3(f,x0,x1,x2,...)            _reduce_case20(f,_raw_expandFuse2_(_,_raw_expandJust1(x2)),x0,x1,      _raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define reduce_case4(f,x0,x1,x2,x3,...)         _reduce_case30(f,_raw_expandFuse2_(_,_raw_expandJust1(x3)),x0,x1,x2,   _raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define reduce_case5(f,x0,x1,x2,x3,x4,...)      _reduce_case40(f,_raw_expandFuse2_(_,_raw_expandJust1(x4)),x0,x1,x2,x3,_raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))

#define _reduce_case1( f,x0,...)                Recurse,(_raw_expandFuse3_(f,_,_raw_expandJust1(x0)),                     _raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define _reduce_case10(f,ft,x0,...)             Recurse,(_raw_expandFuse4_(f,_,_raw_expandJust1(x0),ft),                  _raw_expandDrop1Merge(_raw_expand(x0),__VA_ARGS__))
#define _reduce_case2( f,x0,x1,...)             _reduce_case10(f,_raw_expandFuse2_(_,_raw_expandJust1(x1)),x0,            _raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define _reduce_case20(f,ft,x0,x1,...)          _reduce_case10(f,_raw_expandFuse3_(_,_raw_expandJust1(x1),ft),x0,         _raw_expandDrop1Merge(_raw_expand(x1),__VA_ARGS__))
#define _reduce_case3( f,x0,x1,x2,...)          _reduce_case20(f,_raw_expandFuse2_(_,_raw_expandJust1(x2)),x0,x1,         _raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define _reduce_case30(f,ft,x0,x1,x2,...)       _reduce_case20(f,_raw_expandFuse3_(_,_raw_expandJust1(x2),ft),x0,x1,      _raw_expandDrop1Merge(_raw_expand(x2),__VA_ARGS__))
#define _reduce_case4( f,x0,x1,x2,x3,...)       _reduce_case30(f,_raw_expandFuse2_(_,_raw_expandJust1(x3)),x0,x1,x2,      _raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define _reduce_case40(f,ft,x0,x1,x2,x3,...)    _reduce_case30(f,_raw_expandFuse3_(_,_raw_expandJust1(x3),ft),x0,x1,x2,   _raw_expandDrop1Merge(_raw_expand(x3),__VA_ARGS__))
#define _reduce_case5( f,x0,x1,x2,x3,x4,...)    _reduce_case40(f,_raw_expandFuse2_(_,_raw_expandJust1(x4)),x0,x1,x2,x3,   _raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))
#define _reduce_case50(f,ft,x0,x1,x2,x3,x4,...) _reduce_case40(f,_raw_expandFuse3_(_,_raw_expandJust1(x4),ft),x0,x1,x2,x3,_raw_expandDrop1Merge(_raw_expand(x4),__VA_ARGS__))


#define reduce_caseReduce1(f,x0,...)                  Recurse,(_raw_expand(x0),(reduce_caseReduce10,f,),            __VA_ARGS__)
#define reduce_caseReduce2(f,x0,x1,...)               Recurse,(_raw_expand(x1),(reduce_caseReduce20,f,,x0),         __VA_ARGS__)
#define reduce_caseReduce3(f,x0,x1,x2,...)            Recurse,(_raw_expand(x2),(reduce_caseReduce30,f,,x0,x1),      __VA_ARGS__)
#define reduce_caseReduce4(f,x0,x1,x2,x3,...)         Recurse,(_raw_expand(x3),(reduce_caseReduce40,f,,x0,x1,x2),   __VA_ARGS__)
#define reduce_caseReduce5(f,x0,x1,x2,x3,x4,...)      Recurse,(_raw_expand(x4),(reduce_caseReduce50,f,,x0,x1,x2,x3),__VA_ARGS__)

#define _reduce_caseReduce1( f,x0,...)                Recurse,(_raw_expand(x0),(reduce_caseReduce10,f,),            __VA_ARGS__)
#define _reduce_caseReduce10(f,ft,y0,...)             Recurse,(_raw_expandFuse4_(f,_,_raw_expandJust1(y0),ft),_raw_expandDrop1Merge(_raw_expand(y0),__VA_ARGS__))
#define _reduce_caseReduce2( f,x0,x1,...)             Recurse,(_raw_expand(x1),(reduce_caseReduce20,f,,x0),         __VA_ARGS__)
#define _reduce_caseReduce20(f,ft,x0,y1,...)          Recurse,(_raw_expand(x0),(reduce_caseReduce10,f,_raw_expandFuse3_(_,_raw_expandJust1(y1),ft)),         _raw_expandDrop1Merge(_raw_expand(y1),__VA_ARGS__))
#define _reduce_caseReduce3( f,x0,x1,x2,...)          Recurse,(_raw_expand(x2),(reduce_caseReduce30,f,,x0,x1),      __VA_ARGS__)
#define _reduce_caseReduce30(f,ft,x0,x1,y2,...)       Recurse,(_raw_expand(x1),(reduce_caseReduce20,f,_raw_expandFuse3_(_,_raw_expandJust1(y2),ft),x0),      _raw_expandDrop1Merge(_raw_expand(y2),__VA_ARGS__))
#define _reduce_caseReduce4( f,x0,x1,x2,x3,...)       Recurse,(_raw_expand(x3),(reduce_caseReduce40,f,,x0,x1,x2),   __VA_ARGS__)
#define _reduce_caseReduce40(f,ft,x0,x1,x2,y3,...)    Recurse,(_raw_expand(x2),(reduce_caseReduce30,f,_raw_expandFuse3_(_,_raw_expandJust1(y3),ft),x0,x1),   _raw_expandDrop1Merge(_raw_expand(y3),__VA_ARGS__))
#define _reduce_caseReduce5( f,x0,x1,x2,x3,x4,...)    Recurse,(_raw_expand(x4),(reduce_caseReduce50,f,,x0,x1,x2,x3),__VA_ARGS__)
#define _reduce_caseReduce50(f,ft,x0,x1,x2,x3,y4,...) Recurse,(_raw_expand(x3),(reduce_caseReduce40,f,_raw_expandFuse3_(_,_raw_expandJust1(y4),ft),x0,x1,x2),_raw_expandDrop1Merge(_raw_expand(y4),__VA_ARGS__))


#define reduce_mixed(    a,f,...)           Recurse,(_raw_expandFuse3_(reduce_mixed1,_,_raw_expandJust1(a)),_raw_drop1(a),f,(reduce_mixed2),__VA_ARGS__)
#define _reduce_mixed(   a,f,...)           Recurse,(_raw_expandFuse3_(reduce_mixed1,_,_raw_expandJust1(a)),_raw_drop1(a),f,(reduce_mixed2),__VA_ARGS__)

#define _reduce_mixed1(  a,f,c,...)         Recurse,(_raw_expandFuse3_(reduce_mixed1,_,_raw_expandJust1(a)),_raw_drop1(a),f,c              ,__VA_ARGS__)

#define _reduce_mixed1_( a,f,c,...)         Recurse,(_raw_expandJust1(c),f,,(__VA_ARGS__),_raw_expandDrop1(c))

#define _reduce_mixed1_I(a,f,c,x,...)       _reduce_mixed1(a,f,(reduce_mixed1_I0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_mixed1_I0( f,ft,c,x,g,...)  Recurse,(g,f,ft                                         ,_raw_insert1((x),c)                           ,__VA_ARGS__)

#define _reduce_mixed1_R(a,f,   c,x,...)    _reduce_mixed1(a,f,(reduce_mixed1_R0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_mixed1_R0( f,ft,c,x,...)    Recurse,(_raw_expand(x),(reduce_mixed1_R1, f,ft,c),__VA_ARGS__)
#define _reduce_mixed1_R1( f,ft,c,y,g,...)  _##g(      f,ft                                         ,_raw_insert1((y),c)                           ,__VA_ARGS__)

#define _reduce_mixed1_C(a,f,   c,x,...)    _reduce_mixed1(a,f,(reduce_mixed1_C0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_mixed1_C0( f,ft,c,x,g,...)  Recurse,(g,f,_raw_expandFuse3_(_,_raw_expandJust1(x),ft),_raw_drop1Merge(_raw_expand(x),_raw_expand(c)),__VA_ARGS__)

#define _reduce_mixed1_CR(a,f,   c,x,...)   _reduce_mixed1(a,f,(reduce_mixed1_CR0,x,_raw_expand(c)),__VA_ARGS__)
#define _reduce_mixed1_CR0( f,ft,c,x,...)   Recurse,(_raw_expand(x),(reduce_mixed1_CR1,f,ft,c),__VA_ARGS__)
#define _reduce_mixed1_CR1( f,ft,c,y,g,...) _##g(      f,_raw_expandFuse3_(_,_raw_expandJust1(y),ft),_raw_drop1Merge(_raw_expand(y),_raw_expand(c)),__VA_ARGS__)

#define _reduce_mixed2(     f,ft,c,...)     Recurse,(_raw_expandFuse2_(f,ft),_raw_expand(c))


#define reduce_continue( x,...) Recurse,(_raw_expand(x),__VA_ARGS__)
#define _reduce_continue(x,...) Recurse,(_raw_expand(x),__VA_ARGS__)

#define reduce_construct( x,f,...) Recurse,(_raw_expand(f),x,__VA_ARGS__)
#define _reduce_construct(x,f,...) Recurse,(_raw_expand(f),x,__VA_ARGS__)

#define reduce_output( o,f,...) Output,o,(_raw_expand(f),__VA_ARGS__)
#define _reduce_output(o,f,...) Output,o,(_raw_expand(f),__VA_ARGS__)

#define reduce_error( o,...) Quit,(ERROR: o)
#define _reduce_error(o,...) Quit,(ERROR: o)


#ifndef REDUCE_QUALIFIED_ONLY
  #define eval   reduce_eval
  #define apply  reduce_apply

  #define reduce reduce_reduce

  #define reduce1 reduce_reduce1
  #define reduce2 reduce_reduce2
  #define reduce3 reduce_reduce3
  #define reduce4 reduce_reduce4
  #define reduce5 reduce_reduce5

  #define case1 reduce_case1
  #define case2 reduce_case2
  #define case3 reduce_case3
  #define case4 reduce_case4
  #define case5 reduce_case5

  #define caseReduce1 reduce_caseReduce1
  #define caseReduce2 reduce_caseReduce2
  #define caseReduce3 reduce_caseReduce3
  #define caseReduce4 reduce_caseReduce4
  #define caseReduce5 reduce_caseReduce5

  #define mixed reduce_mixed

  #define continue  reduce_continue
  #define construct reduce_construct
  #define output    reduce_output
  #define error     reduce_error
#endif // REDUCE_QUALIFIED_ONLY


#endif // REDUCE_H_INCLUDED
