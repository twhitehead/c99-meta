//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "Reduce.h"


#define _function_compose(f,g,x,...) reduce_continue(reduce_apply(f,reduce_apply(g,x)),__VA_ARGS__)


#ifndef FUNCTION_QUALIFIED_ONLY
  #define compose function_compose
#endif // FUNCTION_QUALIFIED_ONLY

#endif // FUNCTION_H_INCLUDED
