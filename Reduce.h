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

// This implements a friendlier interface to build with on top of the recursion
// system.  It looks like a lazy functional programming language (something
// like the spineless tagless G (STG) machine) being reduced implemented on a
// stack (something like forth).
//
// The basic primitive operations provided are:
//
//   ForceN(f,x0,...,xN,__VA_ARGS__)
//
//     - Evaluate x0,...,xN to (t0,tc0),...,(t0,tcN) (for each one, push a
//       continuation and it onto the stack and tail call it) and call
//       f_##t0##...##tN with tc0,...,tcN (push tcN,...,tc0 onto the stack and
//       tail-call f_##t0##...##tN).  This is like the STG's case expression.
//
//   Continue(f,__VA_ARGS__)
//
//     - Continue with f (expand f onto the stack and tail call it). This
//       is like the STG's function application.  It is more efficient to, but
//       maybe not advised, to invoke f directly when there is no recursion.
//
//   Return(x,__VA_ARGS__)
//
//     - Return the basic type x (pop the continuation off the top, push the
//       type and closure for x, and tail call the continuation).  This is like
//       the STG's constructor application.
//
//   Output(o,f,__VA_ARGS__)
//
//     - Output o and then tail call f.
//
//   Error(o)
//
//     - Output error o and then quit.
//
// There is no equivalent of the STG's let expression, as there is no heap
// (while one could be simulated, it is likely the cost of copying expressions
// and duplicating some reductions is much less).

#define _reduce_expand(...) __VA_ARGS__
#define _reduce_first(x,...) x
#define _reduce_rest(x,...)  (__VA_ARGS__)


#define reduce_eval(...)      recurse_recurse(__VA_ARGS__,reduce_eval0)
#define _reduce_eval0(...)    _reduce_eval1(__VA_ARGS__)
#define _reduce_eval1(t,tc,_) Quit,("RESULT: "#t#tc)


#define reduce_Force1(f,x0,...)        _reduce_Force10(f,,x0,__VA_ARGS__)
#define _reduce_Force10(f,ft,x0,...)   Recurse,(_reduce_expand x0,reduce_Force11,f,ft,__VA_ARGS__)
#define _reduce_Force11(t,tc,f,ft,...) _reduce_Force12(f,ft,t,_reduce_expand tc,__VA_ARGS__)
#define _reduce_Force12(f,ft,t,...)    _##f##_##t##ft (__VA_ARGS__)

#define reduce_Force2(f,x0,x1,...)        _reduce_Force20(f,,x1,x0,__VA_ARGS__)
#define _reduce_Force20(f,ft,x1,...)      Recurse,(_reduce_expand x1,reduce_Force21,f,ft,__VA_ARGS__)
#define _reduce_Force21(t,tc,f,ft,x0,...) _reduce_Force22(f,ft,t,x0,_reduce_expand tc,__VA_ARGS__)
#define _reduce_Force22(f,ft,t,...)       _reduce_Force10(f,t##ft,__VA_ARGS__)

#define reduce_Force3(f,x0,x1,x2,...)        _reduce_Force30(f,,x2,x1,x0,__VA_ARGS__)
#define _reduce_Force30(f,ft,x2,...)         Recurse,(_reduce_expand x2,reduce_Force31,f,ft,__VA_ARGS__)
#define _reduce_Force31(t,tc,f,ft,x1,x0,...) _reduce_Force32(f,ft,t,x1,x0,_reduce_expand tc,__VA_ARGS__)
#define _reduce_Force32(f,ft,t,...)          _reduce_Force20(f,t##ft,__VA_ARGS__)

#define reduce_Force4(f,x0,x1,x2,x3,...)        _reduce_Force40(f,,x3,x2,x1,x0,__VA_ARGS__)
#define _reduce_Force40(f,ft,x3,...)            Recurse,(_reduce_expand x3,reduce_Force41,f,ft,__VA_ARGS__)
#define _reduce_Force41(t,tc,f,ft,x2,x1,x0,...) _reduce_Force42(f,ft,t,x2,x1,x0,_reduce_expand tc,__VA_ARGS__)
#define _reduce_Force42(f,ft,t,...)             _reduce_Force30(f,t##ft,__VA_ARGS__)

#define reduce_Force5(f,x0,x1,x2,x3,x4,...)        _reduce_Force50(f,,x4,x3,x2,x1,x0,__VA_ARGS__)
#define _reduce_Force50(f,ft,x4,...)               Recurse,(_reduce_expand x3,reduce_Force51,f,ft,__VA_ARGS__)
#define _reduce_Force51(t,tc,f,ft,x3,x2,x1,x0,...) _reduce_Force52(f,ft,t,x3,x2,x1,x0,_reduce_expand tc,__VA_ARGS__)
#define _reduce_Force52(f,ft,t,...)                _reduce_Force40(f,t##ft,__VA_ARGS__)


#define reduce_Return(x,f,...) Recurse,(f,_reduce_first x,_reduce_rest x,__VA_ARGS__)

#define reduce_Continue(f,...) Recurse,(f,__VA_ARGS__)

#define reduce_Output(o,f,...) Output,o,(f,__VA_ARGS__)

#define reduce_Error(o,...)    Quit,("ERROR: "#o)


#ifndef REDUCE_QUALIFIED_ONLY
  #define eval   reduce_eval

  #define Force1 reduce_Force1
  #define Force2 reduce_Force2
  #define Force3 reduce_Force3
  #define Force4 reduce_Force4
  #define Force5 reduce_Force5

  #define Continue reduce_Continue
  #define Return   reduce_Return
  #define Output   reduce_Output
  #define Error    reduce_Error
#endif // REDUCE_QUALIFIED_ONLY


#endif // REDUCE_H_INCLUDED
