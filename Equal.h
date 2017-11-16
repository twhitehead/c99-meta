//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef EQUAL_H_INCLUDED
#define EQUAL_H_INCLUDED

#include "Reduce.h"
#include "Bool.h"


#define _equal_equal(x,y,...)    reduce_caseReduce2(equal_equal,x,y,__VA_ARGS__)
#define _equal_notequal(x,y,...) reduce_caseReduce2(equal_notequal,x,y,__VA_ARGS__)


#ifndef EQUAL_QUALIFIED_ONLY
  #define equal    equal_equal
  #define notequal equal_notequal
#endif // EQUAL_QUALIFIED_ONLY

#endif // EQUAL_H_INCLUDED
