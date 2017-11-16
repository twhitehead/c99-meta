//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Reduce.h"
#include "Equal.h"
#include "Order.h"
#include "Maybe.h"
#include "Tuple.h"
#include "Bool.h"
#include "Integer.h"
#include "Function.h"


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
#define _list_append_list_Nil(ys,...)       reduce_continue(ys,__VA_ARGS__)

#define _list_filter(f,xs,...)                        reduce_caseReduce1(list_filter,xs,f,__VA_ARGS__)
#define _list_filter_list_Cons(x,xs,f,...)            reduce_caseReduce1(list_filter_list_Cons,reduce_apply(f,x),f,x,xs,__VA_ARGS__)
#define _list_filter_list_Cons_bool_True(f,x,xs,...)  reduce_construct((list_Cons,x,(filter,f,xs)),__VA_ARGS__)
#define _list_filter_list_Cons_bool_False(f,x,xs,...) reduce_reduce(list_filter,f,xs,__VA_ARGS__)
#define _list_filter_list_Nil(f,...)                  reduce_construct((list_Nil),__VA_ARGS__)

#define _list_concat(xss,...) reduce_reduce(list_foldr,(list_append),(list_Nil),xss,__VA_ARGS__)

#define _list_head(xs,...)             reduce_caseReduce1(list_head,xs,__VA_ARGS__)
#define _list_head_list_Cons(x,xs,...) reduce_continue(x,__VA_ARGS__)
#define _list_head_list_Nil(...)       reduce_error("list_head: empty list")

#define _list_tail(xs,...)             reduce_caseReduce1(list_tail,xs,__VA_ARGS__)
#define _list_tail_list_Cons(x,xs,...) reduce_continue(xs,__VA_ARGS__)
#define _list_tail_list_Nil(...)       reduce_error("list_tail: empty list")

#define _list_last(xs,...)                           reduce_caseReduce1(list_last,xs,__VA_ARGS__)
#define _list_last_list_Cons(x,xs,...)               reduce_caseReduce1(list_last_list_Cons,xs,x,__VA_ARGS__)
#define _list_last_list_Cons_list_Cons(x1,xs,x0,...) reduce_caseReduce1(list_last_list_Cons,xs,x1,__VA_ARGS__)
#define _list_last_list_Cons_list_Nil(x0,...)        reduce_continue(x0,__VA_ARGS__)
#define _list_last_list_Nil(...)                     reduce_error("list_last: empty list")

#define _list_initial(xs,...)                           reduce_caseReduce1(list_initial,xs,__VA_ARGS__)
#define _list_initial_list_Cons(x,xs,...)               reduce_caseReduce1(list_initial_list_Cons,xs,x,__VA_ARGS__)
#define _list_initial_list_Cons_list_Cons(x1,xs,x0,...) reduce_construct((list_Cons,x0,(list_initial,(list_Cons,x1,xs))),__VA_ARGS__)
#define _list_initial_list_Cons_list_Nil(x0,...)        reduce_construct((list_Nil),__VA_ARGS__)
#define _list_initial_list_Nil(...)                     reduce_error("list_initial: empty list")

#define _list_null(xs,...)             reduce_caseReduce1(list_null,xs,__VA_ARGS__)
#define _list_null_list_Cons(x,xs,...) reduce_construct((bool_False),__VA_ARGS__)
#define _list_null_list_Nil(...)       reduce_construct((bool_True) ,__VA_ARGS__)

#define _list_length(xs,...)             reduce_caseReduce1(list_length,xs,__VA_ARGS__)
#define _list_length_list_Cons(x,xs,...) reduce_reduce(numeric_add,integer_P1,(list_length,xs),__VA_ARGS__)
#define _list_length_list_Nil(...)       reduce_continue(integer_Z,__VA_ARGS__)

#define _list_index(xs,i,...)                      reduce_caseReduce2(list_index,(order_compare,i,integer_Z),xs,i,__VA_ARGS__)
#define _list_index_order_LT_list_Cons(x,xs,i,...) reduce_error("list_index: negative index")
#define _list_index_order_LT_list_Nil(      i,...) reduce_error("list_index: negative index")
#define _list_index_order_EQ_list_Cons(x,xs,i,...) reduce_continue(x,__VA_ARGS__)
#define _list_index_order_EQ_list_Nil(      i,...) reduce_error("list_index: index too large")
#define _list_index_order_GT_list_Cons(x,xs,i,...) reduce_reduce(list_index,xs,(numeric_subtract,i,integer_P1),__VA_ARGS__)
#define _list_index_order_GT_list_Nil(      i,...) reduce_error("list_index: index too large")

#define _list_foldl(f,y,xs,...)             reduce_caseReduce1(list_foldl,xs,f,y,__VA_ARGS__)
#define _list_foldl_list_Cons(x,xs,f,y,...) reduce_reduce(list_foldl,f,reduce_apply(f,y,x),xs,__VA_ARGS__)
#define _list_foldl_list_Nil(f,y,...)       reduce_continue(y,__VA_ARGS__)

#define _list_foldl1(f,xs,...)             reduce_caseReduce1(list_foldl1,xs,f,__VA_ARGS__)
#define _list_foldl1_list_Cons(x,xs,f,...) reduce_reduce(list_foldl,f,x,xs,__VA_ARGS__)
#define _list_foldl1_list_Nil(...)         reduce_error("list_foldl1: empty list")

#define _list_scanl(f,y,xs,...)             reduce_caseReduce1(list_scanl,xs,f,y,__VA_ARGS__)
#define _list_scanl_list_Cons(x,xs,f,y,...) reduce_construct((list_Cons,y,(list_scanl,f,reduce_apply(f,y,x),xs)),__VA_ARGS__)
#define _list_scanl_list_Nil(      f,y,...) reduce_construct((list_Cons,y,(list_Nil)),__VA_ARGS__)

#define _list_scanl1(f,xs,...)             reduce_caseReduce1(list_scanl1,xs,f,__VA_ARGS__)
#define _list_scanl1_list_Cons(x,xs,f,...) reduce_reduce(list_scanl,f,x,xs,__VA_ARGS__)
#define _list_scanl1_list_Nil(      f,...) reduce_construct((list_Nil),__VA_ARGS__)

#define _list_foldr(f,y,xs,...)             reduce_caseReduce1(list_foldr,xs,f,y,__VA_ARGS__)
#define _list_foldr_list_Cons(x,xs,f,y,...) reduce_continue(f,x,(foldr,f,y,xs),__VA_ARGS__)
#define _list_foldr_list_Nil(f,y,...)       reduce_continue(y,__VA_ARGS__)

#define _list_foldr1(f,xs,...)                           reduce_caseReduce1(list_foldr1,xs,f,__VA_ARGS__)
#define _list_foldr1_list_Cons(x,xs,f,...)               reduce_caseReduce1(list_foldr1_list_Cons,xs,f,x,__VA_ARGS__)
#define _list_foldr1_list_Cons_list_Cons(x1,xs,f,x0,...) reduce_continue(f,x0,(list_foldr1_list_Cons,x1,xs,f),__VA_ARGS__)
#define _list_foldr1_list_Cons_list_Nil(f,x0,...)        reduce_continue(x0,__VA_ARGS__)
#define _list_foldr1_list_Nil(...)                       reduce_error("list_foldr1: empty list")

#define _list_scanr(f,y,xs,...)                       reduce_caseReduce1(list_scanr,xs,f,y,__VA_ARGS__)
#define _list_scanr_list_Cons(x,xs,f,y,...)           reduce_caseReduce1(list_scanr_list_Cons,(list_scanr,f,y,xs),f,x,__VA_ARGS__)
#define _list_scanr_list_Cons_list_Cons(y,ys,f,x,...) reduce_construct((list_Cons,reduce_apply(f,x,y),(list_Cons,y,ys)),__VA_ARGS__)
#define _list_scanr_list_Nil(      f,y,...)           reduce_construct((list_Cons,y,(list_Nil)),__VA_ARGS__)

#define _list_scanr1(f,xs,...)                         reduce_caseReduce1(list_scanr1,xs,f,__VA_ARGS__)
#define _list_scanr1_list_Cons(x,xs,f,...)             reduce_caseReduce1(list_scanr1_list_Cons,(list_scanr1,f,xs),f,x,__VA_ARGS__)
#define _list_scanr1_list_Cons_list_Cons(y,ys,f,x,...) reduce_construct((list_Cons,reduce_apply(f,x,y),(list_Cons,y,ys)),__VA_ARGS__)
#define _list_scanr1_list_Cons_list_Nil(      f,x,...) reduce_construct((list_Cons,x,(list_Nil)),__VA_ARGS__)
#define _list_scanr1_list_Nil(      f,...)             reduce_construct((list_Nil),__VA_ARGS__)

#define _list_iterate(f,x,...) reduce_construct((list_Cons,x,(list_iterate,f,reduce_apply(f,x))),__VA_ARGS__)

#define _list_repeat(x,...) reduce_construct((list_Cons,x,(list_repeat,x)),__VA_ARGS__)

#define _list_replicate(i,x,...) reduce_reduce(list_take,i,(list_repeat,x),__VA_ARGS__)

#define _list_cycle(xs,...)                          reduce_caseReduce1(list_cycle,xs,xs,__VA_ARGS__)
#define _list_cycle_list_Cons(y,ys,xs,...)           reduce_construct((list_Cons,y,(reduce_caseReduce1,list_cycle_list_Cons,ys,xs)),__VA_ARGS__)
#define _list_cycle_list_Cons_list_Cons(y,ys,xs,...) reduce_construct((list_Cons,y,(reduce_caseReduce1,list_cycle_list_Cons,ys,xs)),__VA_ARGS__)
#define _list_cycle_list_Cons_list_Nil(      xs,...) reduce_caseReduce1(list_cycle,xs,xs,__VA_ARGS__)
#define _list_cycle_list_Nil(      xs,...)           reduce_error("list_cycle: empty list")

#define _list_take(i,xs,...)                      reduce_caseReduce1(list_take,(order_compare,i,integer_Z),i,xs,__VA_ARGS__)
#define _list_take_order_LT(i,xs,...)             reduce_construct((list_Nil),__VA_ARGS__)
#define _list_take_order_EQ(i,xs,...)             reduce_construct((list_Nil),__VA_ARGS__)
#define _list_take_order_GT(i,xs,...)             reduce_caseReduce1(list_take_order_GT,xs,i,__VA_ARGS__)
#define _list_take_order_GT_list_Cons(x,xs,i,...) reduce_construct((list_Cons,x,(list_take,(numeric_subtract,i,P1),xs)),__VA_ARGS__)
#define _list_take_order_GT_list_Nil(      i,...) reduce_construct((list_Nil),__VA_ARGS__)

#define _list_drop(i,xs,...)                      reduce_caseReduce1(list_drop,(order_compare,i,integer_Z),i,xs,__VA_ARGS__)
#define _list_drop_order_LT(i,xs,...)             reduce_continue(xs,__VA_ARGS__)
#define _list_drop_order_EQ(i,xs,...)             reduce_continue(xs,__VA_ARGS__)
#define _list_drop_order_GT(i,xs,...)             reduce_caseReduce1(list_drop_order_GT,xs,i,__VA_ARGS__)
#define _list_drop_order_GT_list_Cons(x,xs,i,...) reduce_reduce(list_drop,(numeric_subtract,i,P1),xs,__VA_ARGS__)
#define _list_drop_order_GT_list_Nil(      i,...) reduce_construct((list_Nil),__VA_ARGS__)

#define _list_splitAt(i,xs,...) reduce_construct((tuple_Tuple2,(list_take,i,xs),(list_drop,i,xs)),__VA_ARGS__)

#define _list_takeWhile(c,xs,...)                        reduce_caseReduce1(list_takeWhile,xs,c,__VA_ARGS__)
#define _list_takeWhile_list_Cons(x,xs,c,...)            reduce_caseReduce1(list_takeWhile_list_Cons,reduce_apply(c,x),c,x,xs,__VA_ARGS__)
#define _list_takeWhile_list_Cons_bool_True( c,x,xs,...) reduce_construct((list_Cons,x,(list_takeWhile,c,xs)),__VA_ARGS__)
#define _list_takeWhile_list_Cons_bool_False(c,x,xs,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_takeWhile_list_Nil(      c,...)            reduce_construct((list_Nil),__VA_ARGS__)

#define _list_dropWhile(c,xs,...)                        reduce_caseReduce1(list_dropWhile,xs,c,__VA_ARGS__)
#define _list_dropWhile_list_Cons(x,xs,c,...)            reduce_caseReduce1(list_dropWhile_list_Cons,reduce_apply(c,x),c,x,xs,__VA_ARGS__)
#define _list_dropWhile_list_Cons_bool_True( c,x,xs,...) reduce_reduce(list_dropWhile,c,xs,__VA_ARGS__)
#define _list_dropWhile_list_Cons_bool_False(c,x,xs,...) reduce_construct((list_Cons,x,xs),__VA_ARGS__)
#define _list_dropWhile_list_Nil(      c,...)            reduce_construct((list_Nil),__VA_ARGS__)

#define _list_span(c,xs,...) reduce_construct((tuple_Tuple2,(list_takeWhile,c,xs),(list_dropWhile,c,xs)),__VA_ARGS__)

#define _list_break(c,xs,...) reduce_construct((tuple_Tuple2,(list_takeWhile,(function_compose,(bool_not),c),xs),(list_dropWhile,(function_compose,(bool_not),c),xs)),__VA_ARGS__)

#define _list_reverse(xs,...)                reduce_caseReduce1(list_reverse,xs,(list_Nil)      ,__VA_ARGS__)
#define _list_reverse_list_Cons(x,xs,ys,...) reduce_caseReduce1(list_reverse,xs,(list_Cons,x,ys),__VA_ARGS__)
#define _list_reverse_list_Nil(      ys,...) reduce_continue(ys,__VA_ARGS__)

#define _list_and(xs,...) reduce_reduce(list_foldr,(bool_and),(bool_True) ,xs,__VA_ARGS__)
#define _list_or( xs,...) reduce_reduce(list_foldr,(bool_or), (bool_False),xs,__VA_ARGS__)

#define _list_any(p,xs,...) reduce_reduce(list_or, (list_map,p,xs),__VA_ARGS__)
#define _list_all(p,xs,...) reduce_reduce(list_and,(list_map,p,xs),__VA_ARGS__)

#define _list_element(   x,xs,...) reduce_reduce(list_any,(equal_equal   ,x),xs,__VA_ARGS__)
#define _list_notelement(x,xs,...) reduce_reduce(list_all,(equal_notequal,x),xs,__VA_ARGS__)

#define _list_lookup(k,xs,...)                              reduce_caseReduce1(list_lookup,xs,k,__VA_ARGS__)
#define _list_lookup_list_Cons(x,xs,k,...)                  reduce_caseReduce1(list_lookup_list_Cons,x,xs,k,__VA_ARGS__)
#define _list_lookup_list_Cons_tuple_Tuple2(xk,xv,xs,k,...) reduce_reduce(bool_if,(equal_equal,xk,k),(maybe_Just,xv),(list_lookup,k,xs),__VA_ARGS__)
#define _list_lookup_list_Nil(k,...)                        reduce_construct((maybe_Nothing),__VA_ARGS__)

#define _list_sum(    xs,...) reduce_reduce(list_foldl,(numeric_add)     ,integer_Z ,xs,__VA_ARGS__)
#define _list_product(xs,...) reduce_reduce(list_foldl,(numeric_multiply),integer_P1,xs,__VA_ARGS__)

#define _list_maximum(xs,...) reduce_reduce(list_foldl1,(order_maximum),xs,__VA_ARGS__)
#define _list_minimum(xs,...) reduce_reduce(list_foldl1,(order_minimum),xs,__VA_ARGS__)

#define _list_zip( xs,ys,...)    reduce_reduce(list_zipWith ,(tuple_Tuple2),xs,ys   ,__VA_ARGS__)
#define _list_zip3(xs,ys,zs,...) reduce_reduce(list_zipWith3,(tuple_Tuple3),xs,ys,zs,__VA_ARGS__)

#define _list_zipWith(f,xs,ys,...)                         reduce_caseReduce2(list_zipWith,xs,ys,f,__VA_ARGS__)
#define _list_zipWith_list_Cons_list_Cons(x,xs,y,ys,f,...) reduce_construct((list_Cons,reduce_apply(f,x,y),(list_zipWith,f,xs,ys)),__VA_ARGS__)
#define _list_zipWith_list_Cons_list_Nil( x,xs     ,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith_list_Nil_list_Cons(      y,ys,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith_list_Nil_list_Nil(            f,...) reduce_construct((list_Nil),__VA_ARGS__)

#define _list_zipWith3(f,xs,ys,zs,...)                                     reduce_caseReduce3(list_zipWith3,xs,ys,zs,f,__VA_ARGS__)
#define _list_zipWith3_list_Cons_list_Cons_list_Cons(x,xs,y,ys,z,zs,f,...) reduce_construct((list_Cons,reduce_apply(f,x,y,z),(list_zipWith3,f,xs,ys,zs)),__VA_ARGS__)
#define _list_zipWith3_list_Cons_list_Cons_list_Nil( x,xs,y,ys     ,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Cons_list_Nil_list_Cons( x,xs     ,z,zs,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Cons_list_Nil_list_Nil(  x,xs          ,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Nil_list_Cons_list_Cons(      y,ys,z,zs,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Nil_list_Cons_list_Nil(       y,ys     ,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Nil_list_Nil_list_Cons(            z,zs,f,...) reduce_construct((list_Nil),__VA_ARGS__)
#define _list_zipWith3_list_Nil_list_Nil_list_Nil(                  f,...) reduce_construct((list_Nil),__VA_ARGS__)

#define _list_unzip(xs,...)                                  reduce_reduce(list_foldr,(reduce_caseReduce2,list_unzip),(tuple_Tuple2,(list_Nil),(list_Nil)),xs,__VA_ARGS__)
#define _list_unzip_tuple_Tuple2_tuple_Tuple2(x,y,xs,ys,...) reduce_construct((tuple_Tuple2,(list_Cons,x,xs),(list_Cons,y,ys)),__VA_ARGS__)

#define _list_unzip3(xs,...)                                       reduce_reduce(list_foldr,(reduce_caseReduce2,list_unzip3),(tuple_Tuple3,(list_Nil),(list_Nil),(list_Nil)),xs,__VA_ARGS__)
#define _list_unzip3_tuple_Tuple3_tuple_Tuple3(x,y,z,xs,ys,zs,...) reduce_construct((tuple_Tuple3,(list_Cons,x,xs),(list_Cons,y,ys),(list_Cons,z,zs)),__VA_ARGS__)


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


#define _show_show_list_Cons(x,xs,...) reduce_reduce(show_braces,(foldr1,(show_joinComma),(list_map,(show_show),(list_Cons,x,xs))),__VA_ARGS__)
#define _show_show_list_Nil(...)       reduce_construct((show_Output,({})),__VA_ARGS__)

#define _show_showPrecedence_list_Cons(x,xs,...) reduce_reduce(show_braces,(foldr1,(show_joinComma),(list_map,(show_show),(list_Cons,x,xs))),__VA_ARGS__)
#define _show_showPrecedence_list_Nil(...)       reduce_construct((show_Output,({})),__VA_ARGS__)


#ifndef LIST_QUALIFIED_ONLY
  #define L0 list_L0
  #define L1 list_L1
  #define L2 list_L2
  #define L3 list_L3
  #define L4 list_L4
  #define L5 list_L5

  #define Cons list_Cons
  #define Nil  list_Nil

  #define map        list_map
  #define append     list_append
  #define filter     list_filter
  #define concat     list_concat
  #define head       list_head
  #define tail       list_tail
  #define last       list_last
  #define initial    list_initial
  #define null       list_null
  #define length     list_length
  #define index      list_index
  #define foldl      list_foldl
  #define foldl1     list_foldl1
  #define scanl      list_scanl
  #define scanl1     list_scanl1
  #define foldr      list_foldr
  #define foldr1     list_foldr1
  #define scanr      list_scanr
  #define scanr1     list_scanr1
  #define iterate    list_iterate
  #define repeat     list_repeat
  #define replicate  list_replicate
  #define cycle      list_cycle
  #define take       list_take
  #define drop       list_drop
  #define splitAt    list_splitAt
  #define takeWhile  list_takeWhile
  #define dropWhile  list_dropWhile
  #define span       list_span
  #define _break     list_break
  #define reverse    list_reverse
  #define any        list_any
  #define all        list_all
  #define element    list_element
  #define notelement list_notelement
  #define lookup     list_lookup
  #define sum        list_sum
  #define product    list_product
  #define zip        list_zip
  #define zip3       list_zip3
  #define zipWith    list_zipWith
  #define zipWith3   list_zipWith3
  #define unzip      list_unzip
  #define unzip3     list_unzip3
#endif // LIST_QUALIFIED_ONLY

#endif // LIST_H_INCLUDED
