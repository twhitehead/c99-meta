//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef MAYBE_H_INCLUDED
#define MAYBE_H_INCLUDED

#include "Reduce.h"


#define _maybe_Nothing(...) reduce_construct((maybe_Nothing),__VA_ARGS__)
#define _maybe_Just(x,...)  reduce_construct((maybe_Just,x) ,__VA_ARGS__)


#define _show_show_maybe_Nothing(...) reduce_construct((show_Output,(maybe_Nothing)),__VA_ARGS__)
#define _show_show_maybe_Just(x,...)  reduce_reduce(show_joinApply,(show_Output,(Just)),(show_show,x),__VA_ARGS__)

#define _show_showPrecedence_Nothing(...) reduce_construct((show_Output,(Nothing)),__VA_ARGS__)
#define _show_showPrecedence_Just(x,...)  reduce_reduce(show_joinApply,(show_Output,(Just)),(show_show,x),__VA_ARGS__)


#ifndef MAYBE_QUALIFIED_ONLY
  #define Nothing maybe_Nothing
  #define Just    maybe_Just
#endif // MAYBE_QUALIFIED_ONLY

#endif // MAYBE_H_INCLUDED
