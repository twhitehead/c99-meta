//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef NUMERIC_H_INCLUDED
#define NUMERIC_H_INCLUDED

#include "Reduce.h"


#define _numeric_add(x,y,...)      reduce_caseReduce2(numeric_add,x,y,__VA_ARGS__)
#define _numeric_subtract(x,y,...) reduce_caseReduce2(numeric_subtract,x,y,__VA_ARGS__)
#define _numeric_multiply(x,y,...) reduce_caseReduce2(numeric_multiply,x,y,__VA_ARGS__)
#define _numeric_absolute(x,...)   reduce_caseReduce1(numeric_absolute,x,__VA_ARGS__)
#define _numeric_sign(x,...)       reduce_caseReduce1(numeric_sign,x,__VA_ARGS__)
#define _numeric_negate(x,...)     reduce_caseReduce1(numeric_negate,x,__VA_ARGS__)


#ifndef NUMERIC_QUALIFIED_ONLY
  #define add      numeric_add
  #define subtract numeric_subtract
  #define multiply numeric_multiply
  #define absolute numeric_absolute
  #define sign     numeric_sign
  #define negate   numeric_negate
#endif // NUMERIC_QUALIFIED_ONLY

#endif // NUMERIC_H_INCLUDED
