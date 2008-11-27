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


#define _tupple_Tupple1(x0,...)             reduce_construct((tupple_Tupple1,x0),            __VA_ARGS__)
#define _tupple_Tupple2(x0,x1,...)          reduce_construct((tupple_Tupple2,x0,x1),         __VA_ARGS__)
#define _tupple_Tupple3(x0,x1,x2,...)       reduce_construct((tupple_Tupple3,x0,x1,x2),      __VA_ARGS__)
#define _tupple_Tupple4(x0,x1,x2,x3,...)    reduce_construct((tupple_Tupple4,x0,x1,x2,x3),   __VA_ARGS__)
#define _tupple_Tupple5(x0,x1,x2,x3,x4,...) reduce_construct((tupple_Tupple5,x0,x1,x2,x3,x4),__VA_ARGS__)


#define _tupple_first(x,...)  reduce_caseReduce1(tupple_first,x,__VA_ARGS__)
#define _tupple_first_tupple_Tupple2(x0,x1,...)  reduce_return(x0,__VA_ARGS__)

#define _tupple_second(x,...) reduce_caseReduce1(tupple_first,x,__VA_ARGS__)
#define _tupple_second_tupple_Tupple2(x0,x1,...) reduce_return(x1,__VA_ARGS__)

#define _tupple_curry(f,x,...) reduce_caseReduce1(tupple_curry,x,f,__VA_ARGS__)
#define _tupple_curry_tupple_Tupple2(x0,x1,f,...) reduce_return(f,x0,x1,__VA_ARGS__)

#define _tupple_uncurry(f,x0,x1,...) reduce_return(f,(tupple_Tupple2,x0,x1),__VA_ARGS__)


#endif // TUPPLE_H_INCLUDED
