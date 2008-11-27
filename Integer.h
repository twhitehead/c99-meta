//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2, or (at your
// option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include "Tupple.h"
#include "Reduce.h"
#include "Equal.h"
#include "Order.h"
#include "Numeric.h"
#include "Integral.h"


// This implements the integers.  They are stored in two's complement as
// (S,b0,b1,...,bn,S), where S is either P for positive or N for negative,
// b0,...,bn are the bits, and n is such that bn = 1 if S is positive and
// bn = 0 if S is negative (i.e., only the minimum number of bits are stored).
//
// The expectation behind this implementation is that standard use will revolve
// around numbers close to zero (especially for non-addition or -subtraction).

#define integer_N5 (integer_Integer,(N,1,1,0,N))
#define integer_N4 (integer_Integer,(N,0,0,N))
#define integer_N3 (integer_Integer,(N,1,0,N))
#define integer_N2 (integer_Integer,(N,0,N))
#define integer_N1 (integer_Integer,(N,N))
#define integer_Z  (integer_Integer,(P,P))
#define integer_P1 (integer_Integer,(P,1,P))
#define integer_P2 (integer_Integer,(P,0,1,P))
#define integer_P3 (integer_Integer,(P,1,1,P))
#define integer_P4 (integer_Integer,(P,0,0,1,P))
#define integer_P5 (integer_Integer,(P,1,0,1,P))

#define _integer_Integer(x,...) reduce_construct((integer_Integer,x),__VA_ARGS__)

#define _integer_case1(...)       _integer_case10(__VA_ARGS__)
#define _integer_case10(f,i0,...) _##f##_##i0(__VA_ARGS__)
#define _integer_case2(...)          _integer_case20(__VA_ARGS__)
#define _integer_case20(f,i0,i1,...) _##f##_##i0##_##i1(__VA_ARGS__)
#define _integer_case3(...)             _integer_case30(__VA_ARGS__)
#define _integer_case30(f,i0,i1,i2,...) _##f##_##i0##_##i1##_##i2(__VA_ARGS__)


// Addition is implemented via a standard ripple-carry adder.  We track both
// high-order-zeros- and high-order-ones-stripped solutions (zp and zn,
// respectively) to allow pruning.  The 0P1 and P01 cases are not shortcuts
// as there may still be leading digits to prune.

#define _numeric_add_integer_Integer_integer_Integer(x,y,...) reduce_reduce1(integer_Integer,(integer_add_,x,y),__VA_ARGS__)

#define _integer_add_(x,y,...) reduce_case3(integer_add,_raw_just2(x),_raw_just2(y),(0),(I),(I),(I),_raw_drop2(x),_raw_drop2(y),_raw_just1(x),_raw_just1(y),__VA_ARGS__)

#define _integer_add_0_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_0_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_0_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_0_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)

#define _integer_add_0_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(xs,_raw_concatenate3(z,(0),x)),__VA_ARGS__)
#define _integer_add_0_P_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(P),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)
#define _integer_add_0_N_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(N),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)
#define _integer_add_0_N_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(N),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),(),__VA_ARGS__)

#define _integer_add_1_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_1_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_1_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_1_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)

#define _integer_add_1_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(xs,_raw_concatenate3(z,(1),x)),__VA_ARGS__)
#define _integer_add_1_P_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(P),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),(),__VA_ARGS__)
#define _integer_add_1_N_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(N),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),(),__VA_ARGS__)
#define _integer_add_1_N_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,_raw_just1(x),(N),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)

#define _integer_add_P_0_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(ys,_raw_concatenate3(z,(0),y)),__VA_ARGS__)
#define _integer_add_P_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,(P),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_P_1_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(ys,_raw_concatenate3(z,(1),y)),__VA_ARGS__)
#define _integer_add_P_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,(P),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)

#define _integer_add_P_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)
#define _integer_add_P_P_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(z, (1,P))),__VA_ARGS__)
#define _integer_add_P_N_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)
#define _integer_add_P_N_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)

#define _integer_add_N_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,(N),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_N_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,(N),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_N_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_add,(N),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)
#define _integer_add_N_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_add,(N),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)

#define _integer_add_N_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)
#define _integer_add_N_P_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)
#define _integer_add_N_N_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(z, (0,N))),__VA_ARGS__)
#define _integer_add_N_N_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)


// Subtraction is implemented via a standard ripple-borrow subtractor.  The
// details are the same as the adder.  The 0N0 and 1P1 cases are not shortcuts
// as there may still be leading digits to prune.

#define _numeric_subtract_integer_Integer_integer_Integer(x,y,...) reduce_reduce1(integer_Integer,(integer_subtract_,x,y),__VA_ARGS__)
#define _numeric_negate_integer_Integer(x,...)                     reduce_reduce1(integer_Integer,(integer_subtract_,(P,P),x),__VA_ARGS__)

#define _integer_subtract_(x,y,...) reduce_case3(integer_subtract,_raw_just2(x),_raw_just2(y),(0),(I),(I),(I),_raw_drop2(x),_raw_drop2(y),_raw_just1(x),_raw_just1(y),__VA_ARGS__)

#define _integer_subtract_0_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_0_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_0_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_0_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)

#define _integer_subtract_0_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(xs,_raw_concatenate3(z,(0),x)),__VA_ARGS__)
#define _integer_subtract_0_P_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),(P),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)
#define _integer_subtract_0_N_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),(N),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)
#define _integer_subtract_0_N_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(xs,_raw_concatenate3(z,(0),x)),__VA_ARGS__)

#define _integer_subtract_1_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_1_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_1_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_1_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),_raw_drop1(y),__VA_ARGS__)

#define _integer_subtract_1_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1(xs,_raw_concatenate3(z,(1),x)),__VA_ARGS__)
#define _integer_subtract_1_P_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),(P),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),(),__VA_ARGS__)
#define _integer_subtract_1_N_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),(N),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),_raw_drop1(x),(),__VA_ARGS__)
#define _integer_subtract_1_N_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,_raw_just1(x),(N),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,_raw_drop1(x),(),__VA_ARGS__)

#define _integer_subtract_P_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(P),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_P_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(P),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_P_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(P),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_P_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(P),_raw_just1(y),(1),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)

#define _integer_subtract_P_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)
#define _integer_subtract_P_P_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)
#define _integer_subtract_P_N_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(z, (1,P))),__VA_ARGS__)
#define _integer_subtract_P_N_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)

#define _integer_subtract_N_0_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(N),_raw_just1(y),(0),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_N_0_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(N),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_N_1_0(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(N),_raw_just1(y),(0),_raw_concatenate2(z,(0)),zp,_raw_concatenate2(z,(0)),(),_raw_drop1(y),__VA_ARGS__)
#define _integer_subtract_N_1_1(z,zp,zn,x,y,...)       reduce_case3(integer_subtract,(N),_raw_just1(y),(1),_raw_concatenate2(z,(1)),_raw_concatenate2(z,(1)),zn,(),_raw_drop1(y),__VA_ARGS__)

#define _integer_subtract_N_P_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)
#define _integer_subtract_N_P_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(z, (0,N))),__VA_ARGS__)
#define _integer_subtract_N_N_0(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((P),_raw_concatenate2(zp,(P))),  __VA_ARGS__)
#define _integer_subtract_N_N_1(z,zp,zn,x,y,xs,ys,...) reduce_construct(_raw_replace1((N),_raw_concatenate2(zn,(N))),  __VA_ARGS__)


// Multiplication is implemented via a standard shift adder.  Again, both
// high-order-zeros- and high-order-ones-stripped solutions (zp and zn,
// respectively) are tracked to allow pruning.
//
// A negative q in the p*q case is handled by subtracting p*2^(n+1) from the
// final shift-add solution.  This standard correction follows from q actually
// being 2^(n+1)+q in two's complement (so p*q is actually p*2^(n+1) + p*q).

#define _numeric_multiply_integer_Integer_integer_Integer(x,y,...) reduce_reduce1(integer_Integer,(integer_multiply_,x,y),__VA_ARGS__)

#define _integer_multiply_(x,y,...) reduce_case1(integer_multiply,_raw_just2(y),(P,P),(I),(I),(I),x,_raw_drop2(y),__VA_ARGS__)

#define _integer_multiply_0(z1,z0,zp,zn,x,y,...)  reduce_case1(integer_multiply,_raw_just1(y),_integer_multiply_shift(z1,z0,zp,zn),x,_raw_drop1(y),__VA_ARGS__)
#define _integer_multiply_1(z1,z0,zp,zn,x,y,...)  reduce_reduce1(integer_multiply_0,(integer_add_,     z1,x),z0,zp,zn,x,y,__VA_ARGS__)
#define _integer_multiply_P(z1,z0,zp,zn,x,y,...)  reduce_construct(_integer_multiply_finish(z1,z0,zp,zn),__VA_ARGS__)
#define _integer_multiply_N(z1,z0,zp,zn,x,y,...)  reduce_reduce1(integer_multiply_P,(integer_subtract_,z1,x),z0,zp,zn,x,y,__VA_ARGS__)

#define _integer_multiply_shift(z1,z0,zp,zn)   _integer_case1(integer_multiply_shift,_raw_expandJust2(z1),z1,z0,zp,zn)
#define _integer_multiply_shift_0(z1,z0,zp,zn) _raw_delete2(z1),_raw_concatenate2(z0,(0)),zp,_raw_concatenate2(z0,(0))
#define _integer_multiply_shift_1(z1,z0,zp,zn) _raw_delete2(z1),_raw_concatenate2(z0,(1)),_raw_concatenate2(z0,(1)),zn
#define _integer_multiply_shift_P(z1,z0,zp,zn) (P,P),_raw_concatenate2(z0,(0)),zp,_raw_concatenate2(z0,(0))
#define _integer_multiply_shift_N(z1,z0,zp,zn) (N,N),_raw_concatenate2(z0,(1)),_raw_concatenate2(z0,(1)),zn

#define _integer_multiply_finish(z1,z0,zp,zn) _integer_case1(integer_multiply_finish,_raw_expandJust2(z1),_raw_just1(z1),_raw_replace1(z0,z1),_raw_concatenate2(zp,(P)),_raw_concatenate2(zn,(N)))
#define _integer_multiply_finish_0(s,z,zp,zn) _raw_replace1(s,z)
#define _integer_multiply_finish_1(s,z,zp,zn) _raw_replace1(s,z)
#define _integer_multiply_finish_P(s,z,zp,zn) _raw_replace1(s,zp)
#define _integer_multiply_finish_N(s,z,zp,zn) _raw_replace1(s,zn)


// Division is implemented via the standard non-restoring long-division method.
//
// Signs are handled by varying the operation (i.e., addition vs subtraction)
// that is employed at each step to produce the smallest remainder.  Pre- and
// post-offsets of one are used to handle a zero remainder representing two
// possibilities with a negative divisor (dending on whether the remainder of
// the dividend is zero or not) and a negative quotient not being just the bit
// flipped version of a positive quotient.
//
// It may have made more sense to have just taken absolute values (i.e., only
// implemented positive division) are then set the sign of the results.

#define _integral_quotientRemainder_integer_Integer_integer_Integer(x,y,...)  reduce_reduce1(integer_quotientRemainder_wrap,(integer_quotientRemainder_,x,y),__VA_ARGS__)

#define _integer_quotientRemainder_(x,y,...) reduce_caseReduce2(integer_quotientRemainder,(integer_sign_,x,(N),(P),(P)),(integer_sign_,y,(N),(0),(P)),x,y,__VA_ARGS__)
#define _integer_quotientRemainder_wrap(y,...) reduce_construct((tupple_Tupple2,(integer_Integer,_raw_expandJust1(y)),(integer_Integer,_raw_expandJust2(y))),__VA_ARGS__)

#define _integer_quotientRemainder_N_N(x,y,...) reduce_reduce2(integer_quotientRemainder0,(integer_subtract_,(N,N),y),(reduce_reduce1,integer_quotientRemainder_reverse,(integer_subtract_,x,(P,1,P))),(P,P),y,integer_add_,integer_subtract_,0,1,__VA_ARGS__)
#define _integer_quotientRemainder_N_0(x,y,...) reduce_error("integer_quotientRemainder_: division by zero")
#define _integer_quotientRemainder_N_P(x,y,...) reduce_reduce2(integer_quotientRemainder0,(integer_add_,     (N,N),y),(reduce_reduce1,integer_quotientRemainder_reverse,(integer_subtract_,x,(P,1,P))),(N,N),y,integer_subtract_,integer_add_,1,0,__VA_ARGS__)
#define _integer_quotientRemainder_P_N(x,y,...) reduce_reduce2(integer_quotientRemainder0,(integer_add_,     (P,P),y),(               integer_quotientRemainder_reverse,x),                            (N,N),y,integer_add_,integer_subtract_,0,1,__VA_ARGS__)
#define _integer_quotientRemainder_P_0(x,y,...) reduce_error("integer_quotientRemainder_: division by zero")
#define _integer_quotientRemainder_P_P(x,y,...) reduce_reduce2(integer_quotientRemainder0,(integer_subtract_,(P,P),y),(               integer_quotientRemainder_reverse,x),                            (P,P),y,integer_subtract_,integer_add_,1,0,__VA_ARGS__)

#define _integer_quotientRemainder0(r,x,q,y,cp,cn,p,n,...) reduce_case2(integer_quotientRemainder1,_raw_just1(r),_raw_just1(x),r,q,x,y,cp,cn,p,n,__VA_ARGS__)
#define _integer_quotientRemainder1(r,q,x,y,cp,cn,p,n,...) reduce_case2(integer_quotientRemainder1,_raw_just1(r),_raw_just1(x),r,q,x,y,cp,cn,p,n,__VA_ARGS__)

#define _integer_quotientRemainder1_N_N(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder_finish,(integer_add_,r,(P,1,P)),                      _integer_quotientRemainder_shift(n,q),__VA_ARGS__)
#define _integer_quotientRemainder1_N_0(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder1,(cn,_integer_quotientRemainder_shift(0,r),y),_integer_quotientRemainder_shift(n,q),_raw_drop1(x),y,cp,cn,p,n,__VA_ARGS__)
#define _integer_quotientRemainder1_N_1(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder1,(cn,_integer_quotientRemainder_shift(1,r),y),_integer_quotientRemainder_shift(n,q),_raw_drop1(x),y,cp,cn,p,n,__VA_ARGS__)
#define _integer_quotientRemainder1_N_P(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder_finish,(cn,r,y),                                      _integer_quotientRemainder_shift(n,q) ,__VA_ARGS__)

#define _integer_quotientRemainder1_P_N(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder_finish,(reduce_reduce1,integer_add_,(cp,r,y),(P,1,P)),_integer_quotientRemainder_shift(p,q),__VA_ARGS__)
#define _integer_quotientRemainder1_P_0(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder1,(cp,_integer_quotientRemainder_shift(0,r),y),_integer_quotientRemainder_shift(p,q),_raw_drop1(x),y,cp,cn,p,n,__VA_ARGS__)
#define _integer_quotientRemainder1_P_1(r,q,x,y,cp,cn,p,n,...) reduce_reduce1(integer_quotientRemainder1,(cp,_integer_quotientRemainder_shift(1,r),y),_integer_quotientRemainder_shift(p,q),_raw_drop1(x),y,cp,cn,p,n,__VA_ARGS__)
#define _integer_quotientRemainder1_P_P(r,q,x,y,cp,cn,p,n,...) reduce_reduce( integer_quotientRemainder_finish,r,                                             _integer_quotientRemainder_shift(p,q),__VA_ARGS__)

#define _integer_quotientRemainder_shift(b,x) _integer_case2(integer_quotientRemainder_shift,b,_raw_expandJust2(x),x)
#define _integer_quotientRemainder_shift_0_0(x) _raw_insert2((0),x)
#define _integer_quotientRemainder_shift_0_1(x) _raw_insert2((0),x)
#define _integer_quotientRemainder_shift_0_P(x) x
#define _integer_quotientRemainder_shift_0_N(x) _raw_insert2((0),x)
#define _integer_quotientRemainder_shift_1_0(x) _raw_insert2((1),x)
#define _integer_quotientRemainder_shift_1_1(x) _raw_insert2((1),x)
#define _integer_quotientRemainder_shift_1_P(x) _raw_insert2((1),x)
#define _integer_quotientRemainder_shift_1_N(x) x

#define _integer_quotientRemainder_finish(r,q,...) reduce_caseReduce1(integer_quotientRemainder_finish,(integer_sign_,q,(N),(P),(P)),q,r,__VA_ARGS__)
#define _integer_quotientRemainder_finish_N(q,r,...) reduce_reduce1(integer_quotientRemainder_finish_P,(integer_add_,q,(P,1,P)),r,__VA_ARGS__)
#define _integer_quotientRemainder_finish_P(q,r,...) reduce_construct((q,r),__VA_ARGS__)

#define _integer_quotientRemainder_reverse(x,...) reduce_case1(integer_quotientRemainder_reverse,_raw_just2(x),(_raw_expandJust1(x),_raw_expandJust1(x)),_raw_drop2(x),__VA_ARGS__)

#define _integer_quotientRemainder_reverse_0(z,x,...) reduce_case1(integer_quotientRemainder_reverse,_raw_just1(x),_raw_insert2((0),z),_raw_drop1(x),__VA_ARGS__)
#define _integer_quotientRemainder_reverse_1(z,x,...) reduce_case1(integer_quotientRemainder_reverse,_raw_just1(x),_raw_insert2((1),z),_raw_drop1(x),__VA_ARGS__)
#define _integer_quotientRemainder_reverse_P(z,x,...) reduce_construct(_raw_drop1(z),__VA_ARGS__)
#define _integer_quotientRemainder_reverse_N(z,x,...) reduce_construct(_raw_drop1(z),__VA_ARGS__)


// Comparison is as would be expected, with a seperate equal/not equal check
// provided seperate from the lesser/equal/greater check for efficiency.

#define _equal_equal_integer_Integer_integer_Integer(x,y,...)    reduce_reduce(integer_equal_,x,y,(bool_True),(bool_False),__VA_ARGS__)
#define _equal_notequal_integer_Integer_integer_Integer(x,y,...) reduce_reduce(integer_equal_,x,y,(bool_False),(bool_True),__VA_ARGS__)

#define _integer_equal_(x,y,t,f,...) reduce_case2(integer_equal,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),t,f,__VA_ARGS__)

#define _integer_equal_P_P(x,y,t,f,...)  reduce_case2(integer_equal0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),t,f,__VA_ARGS__)
#define _integer_equal_P_N(x,y,t,f,...)  reduce_construct(f,__VA_ARGS__)
#define _integer_equal_N_P(x,y,t,f,...)  reduce_construct(f,__VA_ARGS__)
#define _integer_equal_N_N(x,y,t,f,...)  reduce_case2(integer_equal0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),t,f,__VA_ARGS__)

#define _integer_equal0_0_0(x,y,t,f,...) reduce_case2(integer_equal0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),t,f,__VA_ARGS__)
#define _integer_equal0_0_1(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_0_P(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_0_N(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)

#define _integer_equal0_1_0(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_1_1(x,y,t,f,...) reduce_case2(integer_equal0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),t,f,__VA_ARGS__)
#define _integer_equal0_1_P(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_1_N(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)

#define _integer_equal0_P_0(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_P_1(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_P_P(x,y,t,f,...) reduce_construct(t,__VA_ARGS__)

#define _integer_equal0_N_0(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_N_1(x,y,t,f,...) reduce_construct(f,__VA_ARGS__)
#define _integer_equal0_N_N(x,y,t,f,...) reduce_construct(t,__VA_ARGS__)


#define _order_compare_integer_Integer_integer_Integer(x,y,...)      reduce_reduce(integer_compare_,x,y,(order_LT),(order_EQ),(order_GT),__VA_ARGS__)

#define _order_lesser_integer_Integer_integer_Integer(x,y,...)       reduce_reduce(integer_compare_,x,y,(bool_True), (bool_False),(bool_False),__VA_ARGS__)
#define _order_lesserequal_integer_Integer_integer_Integer(x,y,...)  reduce_reduce(integer_compare_,x,y,(bool_True), (bool_True), (bool_False),__VA_ARGS__)
#define _order_greaterequal_integer_Integer_integer_Integer(x,y,...) reduce_reduce(integer_compare_,x,y,(bool_False),(bool_True), (bool_True), __VA_ARGS__)
#define _order_greater_integer_Integer_integer_Integer(x,y,...)      reduce_reduce(integer_compare_,x,y,(bool_False),(bool_False),(bool_True), __VA_ARGS__)

#define _order_maximum_integer_Integer_integer_Integer(x,y,...) reduce_reduce(integer_compare_,x,y,(integer_Integer,y),(integer_Integer,x),(integer_Integer,x),__VA_ARGS__)
#define _order_minimum_integer_Integer_integer_Integer(x,y,...) reduce_reduce(integer_compare_,x,y,(integer_Integer,x),(integer_Integer,x),(integer_Integer,y),__VA_ARGS__)

#define _integer_compare_(x,y,lt,eq,gt,...) reduce_case2(integer_compare,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,eq,gt,__VA_ARGS__)

#define _integer_compare_P_P(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,eq,gt,__VA_ARGS__)
#define _integer_compare_P_N(x,y,lt,eq,gt,...) reduce_construct(gt,__VA_ARGS__)
#define _integer_compare_N_P(x,y,lt,eq,gt,...) reduce_construct(lt,__VA_ARGS__)
#define _integer_compare_N_N(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,eq,gt,__VA_ARGS__)

#define _integer_compare0_0_0(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,eq,gt,__VA_ARGS__)
#define _integer_compare0_0_1(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,lt,gt,__VA_ARGS__)
#define _integer_compare0_0_P(x,y,lt,eq,gt,...) reduce_construct(gt,__VA_ARGS__)
#define _integer_compare0_0_N(x,y,lt,eq,gt,...) reduce_construct(lt,__VA_ARGS__)

#define _integer_compare0_1_0(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,gt,gt,__VA_ARGS__)
#define _integer_compare0_1_1(x,y,lt,eq,gt,...) reduce_case2(integer_compare0,_raw_just1(x),_raw_just1(y),_raw_drop1(x),_raw_drop1(y),lt,eq,gt,__VA_ARGS__)
#define _integer_compare0_1_P(x,y,lt,eq,gt,...) reduce_construct(gt,__VA_ARGS__)
#define _integer_compare0_1_N(x,y,lt,eq,gt,...) reduce_construct(lt,__VA_ARGS__)

#define _integer_compare0_P_0(x,y,lt,eq,gt,...) reduce_construct(lt,__VA_ARGS__)
#define _integer_compare0_P_1(x,y,lt,eq,gt,...) reduce_construct(lt,__VA_ARGS__)
#define _integer_compare0_P_P(x,y,lt,eq,gt,...) reduce_construct(eq,__VA_ARGS__)

#define _integer_compare0_N_0(x,y,lt,eq,gt,...) reduce_construct(gt,__VA_ARGS__)
#define _integer_compare0_N_1(x,y,lt,eq,gt,...) reduce_construct(gt,__VA_ARGS__)
#define _integer_compare0_N_N(x,y,lt,eq,gt,...) reduce_construct(eq,__VA_ARGS__)


// Sign related stuff is a no brainer.

#define _numeric_absolute_integer_Integer(x,...) reduce_reduce1(integer_Integer,(integer_absolute_,x),__VA_ARGS__)

#define _integer_absolute_(x,...)  reduce_case1(integer_absolute,_raw_just1(x),x,__VA_ARGS__)
#define _integer_absolute_P(x,...) reduce_construct(x,__VA_ARGS__)
#define _integer_absolute_N(x,...) reduce_reduce(integer_subtract_,(P,P),x,__VA_ARGS__)


#define _numeric_sign_integer_Integer(x,...) reduce_reduce1(integer_Integer,(integer_sign_,x,(N,N),(P,P),(P,1,P)),__VA_ARGS__)

#define _integer_sign_(x,n,z,p,...) reduce_case2(integer_sign,_raw_just1(x),_raw_just2(x),n,z,p,__VA_ARGS__)
#define _integer_sign_P_0(n,z,p,...) reduce_construct(p,__VA_ARGS__)
#define _integer_sign_P_1(n,z,p,...) reduce_construct(p,__VA_ARGS__)
#define _integer_sign_P_P(n,z,p,...) reduce_construct(z,__VA_ARGS__)
#define _integer_sign_N_0(n,z,p,...) reduce_construct(n,__VA_ARGS__)
#define _integer_sign_N_1(n,z,p,...) reduce_construct(n,__VA_ARGS__)
#define _integer_sign_N_N(n,z,p,...) reduce_construct(n,__VA_ARGS__)


// The rest is all boilerplate.

#ifndef INTEGER_QUALIFIED_ONLY
  #define N5 integer_N5
  #define N4 integer_N4
  #define N3 integer_N3
  #define N2 integer_N2
  #define N1 integer_N1
  #define Z  integer_Z
  #define P1 integer_P1
  #define P2 integer_P2
  #define P3 integer_P3
  #define P4 integer_P4
  #define P5 integer_P5

  #define Integer integer_Integer
#endif // INTEGER_QUALIFIED_ONLY

#endif // INTEGER_H_INCLUDED
