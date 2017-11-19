//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef TUPPLE_H_INCLUDED
#define TUPPLE_H_INCLUDED


#define tuple_T0                 (tuple_Tuple0)
#define tuple_T1(x0)             (tuple_Tuple1,x0)
#define tuple_T2(x0,x1)          (tuple_Tuple2,x0,x1)
#define tuple_T3(x0,x1,x2)       (tuple_Tuple3,x0,x1,x2)
#define tuple_T4(x0,x1,x2,x3)    (tuple_Tuple4,x0,x1,x2,x3)
#define tuple_T5(x0,x1,x2,x3,x4) (tuple_Tuple5,x0,x1,x2,x3,x4)

#define _tuple_Tuple0(...)                reduce_construct((tuple_Tuple0)               ,__VA_ARGS__)
#define _tuple_Tuple1(x0,...)             reduce_construct((tuple_Tuple1,x0)            ,__VA_ARGS__)
#define _tuple_Tuple2(x0,x1,...)          reduce_construct((tuple_Tuple2,x0,x1)         ,__VA_ARGS__)
#define _tuple_Tuple3(x0,x1,x2,...)       reduce_construct((tuple_Tuple3,x0,x1,x2)      ,__VA_ARGS__)
#define _tuple_Tuple4(x0,x1,x2,x3,...)    reduce_construct((tuple_Tuple4,x0,x1,x2,x3)   ,__VA_ARGS__)
#define _tuple_Tuple5(x0,x1,x2,x3,x4,...) reduce_construct((tuple_Tuple5,x0,x1,x2,x3,x4),__VA_ARGS__)


#define _tuple_first(x,...)                   reduce_caseReduce1(tuple_first,x,__VA_ARGS__)
#define _tuple_first_tuple_Tuple2(x0,x1,...)  reduce_continue(x0,__VA_ARGS__)

#define _tuple_second(x,...)                  reduce_caseReduce1(tuple_second,x,__VA_ARGS__)
#define _tuple_second_tuple_Tuple2(x0,x1,...) reduce_continue(x1,__VA_ARGS__)

#define _tuple_curry(f,x0,x1,...) reduce_continue(f,(tuple_Tuple2,x0,x1),__VA_ARGS__)

#define _tuple_uncurry(f,x,...)                  reduce_caseReduce1(tuple_uncurry,x,f,__VA_ARGS__)
#define _tuple_uncurry_tuple_Tuple2(x0,x1,f,...) reduce_continue(f,x0,x1,__VA_ARGS__)


#define _show_show_tuple_Tuple0(...)                reduce_construct((show_Output,(())),__VA_ARGS__)
#define _show_show_tuple_Tuple1(x0,...)             reduce_reduce(show_parenthesis,                (show_show,x0)                                                                                                                ,__VA_ARGS__)
#define _show_show_tuple_Tuple2(x0,x1,...)          reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_show,x1)                                                                                                ),__VA_ARGS__)
#define _show_show_tuple_Tuple3(x0,x1,x2,...)       reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_show,x2)                                                                )),__VA_ARGS__)
#define _show_show_tuple_Tuple4(x0,x1,x2,x3,...)    reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2)                                ))),__VA_ARGS__)
#define _show_show_tuple_Tuple5(x0,x1,x2,x3,x4,...) reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2))))),__VA_ARGS__)

#define _show_showPrecedence_tuple_Tuple0(...)                reduce_construct((show_Output,(())),__VA_ARGS__)
#define _show_showPrecedence_tuple_Tuple1(x0,...)             reduce_reduce(show_parenthesis,                (show_show,x0)                                                                                                                ,__VA_ARGS__)
#define _show_showPrecedence_tuple_Tuple2(x0,x1,...)          reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_show,x1)                                                                                                ),__VA_ARGS__)
#define _show_showPrecedence_tuple_Tuple3(x0,x1,x2,...)       reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_show,x2)                                                                )),__VA_ARGS__)
#define _show_showPrecedence_tuple_Tuple4(x0,x1,x2,x3,...)    reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2)                                ))),__VA_ARGS__)
#define _show_showPrecedence_tuple_Tuple5(x0,x1,x2,x3,x4,...) reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2))))),__VA_ARGS__)



#ifndef TUPPLE_QUALIFIED_ONLY
  #define T0 tuple_T0
  #define T1 tuple_T1
  #define T2 tuple_T2
  #define T3 tuple_T3
  #define T4 tuple_T4
  #define T5 tuple_T5

  #define Tuple0 tuple_Tuple0
  #define Tuple1 tuple_Tuple1
  #define Tuple2 tuple_Tuple2
  #define Tuple3 tuple_Tuple3
  #define Tuple4 tuple_Tuple4
  #define Tuple5 tuple_Tuple5

  #define first   tuple_first
  #define second  tuple_second
  #define curry   tuple_curry
  #define uncurry tuple_uncurry
#endif // TUPPLE_QUALIFIED_ONLY

#endif // TUPPLE_H_INCLUDED
