//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2, or (at your
// option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Reduce.h"
#include "Equal.h"
#include "Order.h"


#define list_L0                 (list_Nil)
#define list_L1(x0)             (list_Cons,x0,(list_Nil))
#define list_L2(x0,x1)          (list_Cons,x0,(list_Cons,x1,(list_Nil)))
#define list_L3(x0,x1,x2)       (list_Cons,x0,(list_Cons,x1,(list_Cons,x2,(list_Nil))))
#define list_L4(x0,x1,x2,x3)    (list_Cons,x0,(list_Cons,x1,(list_Cons,x2,(list_Cons,x3,(list_Nil)))))
#define list_L5(x0,x1,x2,x3,x4) (list_Cons,x0,(list_Cons,x1,(list_Cons,x2,(list_Cons,x3,(list_Cons,x4,(list_Nil))))))


#define _list_Cons(x,xs,...) reduce_construct((list_Cons,x,xs),__VA_ARGS__)
#define _list_Nil(...)       reduce_construct((list_Nil),__VA_ARGS__)


#define _list_map(f,xs,...)             reduce_caseReduce1(list_map,xs,f,__VA_ARGS__)
#define _list_map_list_Cons(x,xs,f,...) reduce_construct((list_Cons,reduce_apply(f,x),(map,f,xs)),__VA_ARGS__)
#define _list_map_list_Nil(f,...)       reduce_construct((list_Nil),__VA_ARGS__)

#define _list_append(xs,ys,...)             reduce_caseReduce1(list_append,xs,ys,__VA_ARGS__)
#define _list_append_list_Cons(x,xs,ys,...) reduce_construct((list_Cons,x,(append,xs,ys)),__VA_ARGS__)
#define _list_append_list_Nil(ys,...)       reduce_return(ys,__VA_ARGS__)

#define _list_filter(f,xs,...)                        reduce_caseReduce1(list_filter,xs,f,__VA_ARGS__)
#define _list_filter_list_Cons(x,xs,f,...)            reduce_caseReduce1(list_filter_list_Cons,reduce_apply(f,x),f,x,xs,__VA_ARGS__)
#define _list_filter_list_Cons_bool_True(f,x,xs,...)  reduce_construct((list_Cons,x,(filter,f,xs)),__VA_ARGS__)
#define _list_filter_list_Cons_bool_False(f,x,xs,...) reduce_reduce(list_filter,f,xs,__VA_ARGS__)
#define _list_filter_list_Nil(f,...)                  reduce_construct((list_Nil),__VA_ARGS__)

#define _list_concat(xss,...) reduce_reduce(list_foldr,append,(list_Nil),xss,__VA_ARGS__)

#define _list_head(xs,...)             reduce_caseReduce1(list_head,xs,__VA_ARGS__)
#define _list_head_list_Cons(x,xs,...) reduce_return(x,__VA_ARGS__)
#define _list_head_list_Nil(...)       reduce_error("list_head: empty list")

#define _list_tail(xs,...)             reduce_caseReduce1(list_tail,xs,__VA_ARGS__)
#define _list_tail_list_Cons(x,xs,...) reduce_return(xs,__VA_ARGS__)
#define _list_tail_list_Nil(...)       reduce_error("list_tail: empty list")

#define _list_last(xs,...)                           reduce_caseReduce1(list_last,xs,__VA_ARGS__)
#define _list_last_list_Cons(x,xs,...)               reduce_caseReduce1(list_last_list_Cons,xs,x,__VA_ARGS__)
#define _list_last_list_Cons_list_Cons(x1,xs,x0,...) reduce_caseReduce1(list_last_list_Cons,xs,x1,__VA_ARGS__)
#define _list_last_list_Cons_list_Nil(x0,...)        reduce_return(x0,__VA_ARGS__)
#define _list_last_list_Nil(...)                     reduce_error("list_last: empty list")

#define _list_init(xs,...)                           reduce_caseReduce1(list_init,xs,__VA_ARGS__)
#define _list_init_list_Cons(x,xs,...)               reduce_caseReduce1(list_init_list_Cons,xs,x,__VA_ARGS__)
#define _list_init_list_Cons_list_Cons(x1,xs,x0,...) reduce_construct((list_Cons,x0,(init_list_Cons,x1,xs)),__VA_ARGS__)
#define _list_init_list_Cons_list_Nil(x0,...)        reduce_construct((list_Nil),__VA_ARGS__)
#define _list_init_list_Nil(...)                     reduce_error("list_init: empty list")

#define _list_foldl(f,y,xs,...)             reduce_caseReduce1(list_foldl,xs,f,y,__VA_ARGS__)
#define _list_foldl_list_Cons(x,xs,f,y,...) reduce_reduce(list_foldl,f,reduce_apply(f,y,x),xs,__VA_ARGS__)
#define _list_foldl_list_Nil(f,y,...)       reduce_return(y,__VA_ARGS__)

#define _list_foldl1(f,xs,...)             reduce_caseReduce1(list_foldl1,xs,f,__VA_ARGS__)
#define _list_foldl1_list_Cons(x,xs,f,...) reduce_reduce(list_foldl,f,x,xs,__VA_ARGS__)
#define _list_foldl1_list_Nil(...)         reduce_error("list_foldl1: empty list")

#define _list_foldr(f,y,xs,...)             reduce_caseReduce1(list_foldr,xs,f,y,__VA_ARGS__)
#define _list_foldr_list_Cons(x,xs,f,y,...) reduce_return(f,x,(foldr,f,y,xs),__VA_ARGS__)
#define _list_foldr_list_Nil(f,y,...)       reduce_return(y,__VA_ARGS__)

#define _list_foldr1(f,xs,...)                           reduce_caseReduce1(list_foldr1,xs,f,__VA_ARGS__)
#define _list_foldr1_list_Cons(x,xs,f,...)               reduce_caseReduce1(list_foldr1_list_Cons,xs,f,x,__VA_ARGS__)
#define _list_foldr1_list_Cons_list_Cons(x1,xs,f,x0,...) reduce_return(f,x0,(list_foldr1_list_Cons,x1,xs,f),__VA_ARGS__)
#define _list_foldr1_list_Cons_list_Nil(f,x0,...)        reduce_return(x0,__VA_ARGS__)
#define _list_foldr1_list_Nil(...)                       reduce_error("list_foldr1: empty list")


#define _equal_equal_list_Cons_list_Cons(x,xs,y,ys,...) reduce_reduce(bool_and,(equal_equal,x,y),(equal_equal,xs,ys),__VA_ARGS__)
#define _equal_equal_list_Cons_list_Nil(x,xs,...)       reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_list_Nil_list_Cons(y,ys,...)       reduce_construct((bool_False),__VA_ARGS__)
#define _equal_equal_list_Nil_list_Nil(...)             reduce_construct((bool_True),__VA_ARGS__)

#define _order_compare_list_Cons_list_Cons(x,xs,y,ys,...)      reduce_caseReduce1(order_compare_list_Cons_list_Cons,(order_compare,x,y),xs,ys,__VA_ARGS__)
#define _order_compare_list_Cons_list_Cons_order_LT(xs,ys,...) reduce_construct((order_LT),__VA_ARGS__)
#define _order_compare_list_Cons_list_Cons_order_EQ(xs,ys,...) reduce_reduce(order_compare,xs,ys,__VA_ARGS__)
#define _order_compare_list_Cons_list_Cons_order_GT(xs,ys,...) reduce_construct((order_GT),__VA_ARGS__)
#define _order_compare_list_Cons_list_Nil(x,xs,...)            reduce_construct((order_LT),__VA_ARGS__)
#define _order_compare_list_Nil_list_Cons(y,ys,...)            reduce_construct((order_GT),__VA_ARGS__)
#define _order_compare_list_Nil_list_Nil(...)                  reduce_construct((order_EQ),__VA_ARGS__)


#ifndef LIST_QUALIFIED_ONLY
  #define List0 list_List0
  #define List1 list_List1
  #define List2 list_List2
  #define List3 list_List3
  #define List4 list_List4
  #define List5 list_List5

  #define Cons list_Cons
  #define Nil  list_Nil

  #define map    list_map
  #define append list_append
  #define filter list_filter
  #define concat list_concat
  #define head   list_head
  #define tail   list_tail
  #define last   list_last
  #define init   list_init
  #define foldl  list_foldl
  #define foldl1 list_foldl1
  #define foldr  list_foldr
  #define foldr1 list_foldr1
#endif // LIST_QUALIFIED_ONLY

#endif // LIST_H_INCLUDED
