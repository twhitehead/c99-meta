//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "Equal.h"


#define _order_LT(...) reduce_construct((order_LT),__VA_ARGS__)
#define _order_EQ(...) reduce_construct((order_EQ),__VA_ARGS__)
#define _order_GT(...) reduce_construct((order_GT),__VA_ARGS__)


#define _order_compare(x,y,...)      reduce_caseReduce2(order_compare,x,y,__VA_ARGS__)
#define _order_lesser(x,y,...)       reduce_caseReduce2(order_lesser,x,y,__VA_ARGS__)
#define _order_lesserequal(x,y,...)  reduce_caseReduce2(order_lesserequal,x,y,__VA_ARGS__)
#define _order_greaterequal(x,y,...) reduce_caseReduce2(order_greaterequal,x,y,__VA_ARGS__)
#define _order_greater(x,y,...)      reduce_caseReduce2(order_greater,x,y,__VA_ARGS__)
#define _order_maximum(x,y,...)      reduce_caseReduce2(order_maximum,x,y,__VA_ARGS__)
#define _order_minimum(x,y,...)      reduce_caseReduce2(order_minimum,x,y,__VA_ARGS__)


// #define _order_compare_TYPE_TYPE(x,y,...)                   reduce_caseReduce1(order_compare_TYPE_TYPE,(equal_equal_TYPE_TYPE,x,y),x,y,__VA_ARGS__)
// #define _order_compare_TYPE_TYPE_bool_True(x,y,...)         reduce_construct((order_EQ),__VA_ARGS__)
// #define _order_compare_TYPE_TYPE_bool_False(x,y,...)        reduce_caseReduce1(order_compare_TYPE_TYPE_bool_False,(order_lesserequal_TYPE_TYPE,x,y),__VA_ARGS__)
// #define _order_compare_TYPE_TYPE_bool_False_bool_True(...)  reduce_construct((order_LT),__VA_ARGS__)
// #define _order_compare_TYPE_TYPE_bool_False_bool_False(...) reduce_construct((order_GT),__VA_ARGS__)
//
// #define _order_lesser_TYPE_TYPE(x,y,...)       reduce_reduce(equal_equal,   (order_compare_TYPE_TYPE,x,y),order_LT,__VA_ARGS__)
// #define _order_lesserequal_TYPE_TYPE(x,y,...)  reduce_reduce(equal_notequal,(order_compare_TYPE_TYPE,x,y),order_GT,__VA_ARGS__)
// #define _order_greaterequal_TYPE_TYPE(x,y,...) reduce_reduce(equal_notequal,(order_compare_TYPE_TYPE,x,y),order_LT,__VA_ARGS__)
// #define _order_greater_TYPE_TYPE(x,y,...)      reduce_reduce(equal_equal,   (order_compare_TYPE_TYPE,x,y),order_GT,__VA_ARGS__)
// #define _order_maximum_TYPE_TYPE(x,y,...)      reduce_reduce(_if,(order_lesserequal_TYPE_TYPE,x,y),y,x),__VA_ARGS__)
// #define _order_minimum_TYPE_TYPE(x,y,...)      reduce_reduce(_if,(order_lesserequal_TYPE_TYPE,x,y),x,y),__VA_ARGS__)


#define _equal_equal_order_LT_order_LT(...)   reduce_construct((bool_True) ,__VA_ARGS__)
#define _equal_equal_order_LT_order_EQ(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_LT_order_GT(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_EQ_order_LT(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_EQ_order_EQ(...)   reduce_construct((bool_True) ,__VA_ARGS__)
#define _equal_equal_order_EQ_order_GT(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_GT_order_LT(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_GT_order_EQ(...)   reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_order_GT_order_GT(...)   reduce_construct((bool_True) ,__VA_ARGS__)


#define _show_show_order_LT(...) reduce_construct((show_Output,(order_LT)),__VA_ARGS__)
#define _show_show_order_EQ(...) reduce_construct((show_Output,(order_EQ)),__VA_ARGS__)
#define _show_show_order_GT(...) reduce_construct((show_Output,(order_GT)),__VA_ARGS__)

#define _show_showPrecedence_order_LT(...) reduce_construct((show_Output,(order_LT)),__VA_ARGS__)
#define _show_showPrecedence_order_EQ(...) reduce_construct((show_Output,(order_EQ)),__VA_ARGS__)
#define _show_showPrecedence_order_GT(...) reduce_construct((show_Output,(order_GT)),__VA_ARGS__)


#ifndef ORDER_QUALIFIED_ONLY
  #define LT order_LT
  #define EQ order_EQ
  #define GT order_GT

  #define compare      order_compare
  #define lesser       order_lesser
  #define lesserequal  order_lesserequal
  #define greaterequal order_greaterequal
  #define greater      order_greater
  #define maximum      order_maximum
  #define minimum      order_minimum
#endif // ORDER_QUALIFIED_ONLY

#endif // ORDER_H_INCLUDED
