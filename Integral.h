//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef INTEGRAL_H_INCLUDED
#define INTEGRAL_H_INCLUDED

#include "Reduce.h"


#define _integral_quotient(x,y,...)  reduce_caseReduce2(integral_quotient,x,y,__VA_ARGS__)
#define _integral_remainder(x,y,...) reduce_caseReduce2(integral_remainder,x,y,__VA_ARGS__)
#define _integral_divide(x,y,...)    reduce_caseReduce2(integral_divide,x,y,__VA_ARGS__)
#define _integral_modulus(x,y,...)   reduce_caseReduce2(integral_modulus,x,y,__VA_ARGS__)

#define _integral_quotientRemainder(x,y,...) reduce_caseReduce2(integral_quotientRemainder,x,y,__VA_ARGS__)
#define _integral_divideModulus(x,y,...)     reduce_caseReduce2(integral_divideModulus,x,y,__VA_ARGS__)


#ifndef INTEGRAL_QUALIFIED_ONLY
  #define quotient  integral_quotient
  #define remainder integral_remainder
  #define divide    integral_divide
  #define modulus   integral_modulus

  #define quotientRemainder integral_quotientRemainder
  #define divideModulus     integral_divideModulus
#endif // INTEGRAL_QUALIFIED_ONLY

#endif // INTEGRAL_H_INCLUDED
