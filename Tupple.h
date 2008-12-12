//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2, or (at your
// option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef TUPPLE_H_INCLUDED
#define TUPPLE_H_INCLUDED


#define tupple_T0                 (tupple_Tupple0)
#define tupple_T1(x0)             (tupple_Tupple1,x0)
#define tupple_T2(x0,x1)          (tupple_Tupple2,x0,x1)
#define tupple_T3(x0,x1,x2)       (tupple_Tupple3,x0,x1,x2)
#define tupple_T4(x0,x1,x2,x3)    (tupple_Tupple4,x0,x1,x2,x3)
#define tupple_T5(x0,x1,x2,x3,x4) (tupple_Tupple5,x0,x1,x2,x3,x4)

#define _tupple_Tupple0(...)                reduce_construct((tupple_Tupple0)               ,__VA_ARGS__)
#define _tupple_Tupple1(x0,...)             reduce_construct((tupple_Tupple1,x0)            ,__VA_ARGS__)
#define _tupple_Tupple2(x0,x1,...)          reduce_construct((tupple_Tupple2,x0,x1)         ,__VA_ARGS__)
#define _tupple_Tupple3(x0,x1,x2,...)       reduce_construct((tupple_Tupple3,x0,x1,x2)      ,__VA_ARGS__)
#define _tupple_Tupple4(x0,x1,x2,x3,...)    reduce_construct((tupple_Tupple4,x0,x1,x2,x3)   ,__VA_ARGS__)
#define _tupple_Tupple5(x0,x1,x2,x3,x4,...) reduce_construct((tupple_Tupple5,x0,x1,x2,x3,x4),__VA_ARGS__)


#define _tupple_first(x,...)                     reduce_caseReduce1(tupple_first,x,__VA_ARGS__)
#define _tupple_first_tupple_Tupple2(x0,x1,...)  reduce_continue(x0,__VA_ARGS__)

#define _tupple_second(x,...)                    reduce_caseReduce1(tupple_first,x,__VA_ARGS__)
#define _tupple_second_tupple_Tupple2(x0,x1,...) reduce_continue(x1,__VA_ARGS__)

#define _tupple_curry(f,x0,x1,...) reduce_continue(f,(tupple_Tupple2,x0,x1),__VA_ARGS__)

#define _tupple_uncurry(f,x,...)                    reduce_caseReduce1(tupple_uncurry,x,f,__VA_ARGS__)
#define _tupple_uncurry_tupple_Tupple2(x0,x1,f,...) reduce_continue(f,x0,x1,__VA_ARGS__)


#define _show_show_tupple_Tupple0(...)                reduce_construct((show_Output,(())),__VA_ARGS__)
#define _show_show_tupple_Tupple1(x0,...)             reduce_reduce(show_parenthesis,                (show_show,x0)                                                                                                                ,__VA_ARGS__)
#define _show_show_tupple_Tupple2(x0,x1,...)          reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_show,x1)                                                                                                ),__VA_ARGS__)
#define _show_show_tupple_Tupple3(x0,x1,x2,...)       reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_show,x2)                                                                )),__VA_ARGS__)
#define _show_show_tupple_Tupple4(x0,x1,x2,x3,...)    reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2)                                ))),__VA_ARGS__)
#define _show_show_tupple_Tupple5(x0,x1,x2,x3,x4,...) reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2))))),__VA_ARGS__)

#define _show_showPrecedence_tupple_Tupple0(...)                reduce_construct((show_Output,(())),__VA_ARGS__)
#define _show_showPrecedence_tupple_Tupple1(x0,...)             reduce_reduce(show_parenthesis,                (show_show,x0)                                                                                                                ,__VA_ARGS__)
#define _show_showPrecedence_tupple_Tupple2(x0,x1,...)          reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_show,x1)                                                                                                ),__VA_ARGS__)
#define _show_showPrecedence_tupple_Tupple3(x0,x1,x2,...)       reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_show,x2)                                                                )),__VA_ARGS__)
#define _show_showPrecedence_tupple_Tupple4(x0,x1,x2,x3,...)    reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2)                                ))),__VA_ARGS__)
#define _show_showPrecedence_tupple_Tupple5(x0,x1,x2,x3,x4,...) reduce_reduce(show_parenthesis,(show_joinComma,(show_show,x0),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_joinComma,(show_show,x1),(show_show,x2))))),__VA_ARGS__)



#ifndef TUPPLE_QUALIFIED_ONLY
  #define T0 tupple_T0
  #define T1 tupple_T1
  #define T2 tupple_T2
  #define T3 tupple_T3
  #define T4 tupple_T4
  #define T5 tupple_T5

  #define Tupple0 tupple_Tupple0
  #define Tupple1 tupple_Tupple1
  #define Tupple2 tupple_Tupple2
  #define Tupple3 tupple_Tupple3
  #define Tupple4 tupple_Tupple4
  #define Tupple5 tupple_Tupple5
#endif // TUPPLE_QUALIFIED_ONLY

#endif // TUPPLE_H_INCLUDED
