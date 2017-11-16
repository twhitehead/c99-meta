//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef BOOL_H_INCLUDED
#define BOOL_H_INCLUDED

#include "Reduce.h"
#include "Equal.h"


#define bool_T (bool_True)
#define bool_F (bool_False)


#define _bool_True(...)  reduce_construct((bool_True),__VA_ARGS__)
#define _bool_False(...) reduce_construct((bool_False),__VA_ARGS__)


#define _bool_if(b,t,f,...)          reduce_caseReduce1(bool_if,b,t,f,__VA_ARGS__)
#define _bool_if_bool_True(t,f,...)  reduce_continue(t,__VA_ARGS__)
#define _bool_if_bool_False(t,f,...) reduce_continue(f,__VA_ARGS__)

#define _bool_not(b,...)          reduce_caseReduce1(bool_not,b,__VA_ARGS__)
#define _bool_not_bool_True(...)  reduce_construct((bool_False),__VA_ARGS__)
#define _bool_not_bool_False(...) reduce_construct((bool_True),__VA_ARGS__)

#define _bool_and(x,...)                    reduce_caseReduce1(bool_and,x,__VA_ARGS__)
#define _bool_and_bool_True(y,...)          reduce_caseReduce1(bool_and_bool_True,y,__VA_ARGS__)
#define _bool_and_bool_True_bool_True(...)  reduce_construct((bool_True),__VA_ARGS__)
#define _bool_and_bool_True_bool_False(...) reduce_construct((bool_False),__VA_ARGS__)
#define _bool_and_bool_False(y,...)         reduce_construct((bool_False),__VA_ARGS__)

#define _bool_or(x,...)                     reduce_caseReduce1(bool_or,x,__VA_ARGS__)
#define _bool_or_bool_True(y,...)           reduce_construct((bool_True),__VA_ARGS__)
#define _bool_or_bool_False(y,...)          reduce_caseReduce1(bool_or_bool_False,y,__VA_ARGS__)
#define _bool_or_bool_False_bool_True(...)  reduce_construct((bool_True),__VA_ARGS__)
#define _bool_or_bool_False_bool_False(...) reduce_construct((bool_False),__VA_ARGS__)


#define _equal_equal_bool_True_bool_True(...)   reduce_construct((bool_True),__VA_ARGS__)
#define _equal_equal_bool_True_bool_False(...)  reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_bool_False_bool_True(...)  reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_bool_False_bool_False(...) reduce_construct((bool_True),__VA_ARGS__)

#define _equal_notequal_bool_True_bool_True(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_notequal_bool_True_bool_False(...)  reduce_construct((bool_True),__VA_ARGS__)
#define _equal_notequal_bool_False_bool_True(...)  reduce_construct((bool_True),__VA_ARGS__)
#define _equal_notequal_bool_False_bool_False(...) reduce_construct((bool_False),__VA_ARGS__)


#define _show_show_bool_True(...)  reduce_construct((show_Output,(bool_True) ),__VA_ARGS__)
#define _show_show_bool_False(...) reduce_construct((show_Output,(bool_False)),__VA_ARGS__)

#define _show_showPrecedence_bool_True(...)  reduce_construct((show_Output,(bool_True) ),__VA_ARGS__)
#define _show_showPrecedence_bool_False(...) reduce_construct((show_Output,(bool_False)),__VA_ARGS__)


#ifndef BOOL_QUALIFIED_ONLY
  #define T bool_T
  #define F bool_F

  #define True  bool_True
  #define False bool_False

  #define _if bool_if
  #define not bool_not
  #define and bool_and
  #define or  bool_or
#endif // BOOL_QUALIFIED_ONLY

#endif // BOOL_H_INCLUDED
