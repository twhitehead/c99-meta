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


#define _expand_id1(...)    _expand_id10(__VA_ARGS__)
#define _expand_id10(i0,i1) i0##i1
#define _expand_id2(...)       _expand_id20(__VA_ARGS__)
#define _expand_id20(i0,i1,i2) i0##i1##i2
#define _expand_id3(...)          _expand_id30(__VA_ARGS__)
#define _expand_id30(i0,i1,i2,i3) i0##i1##i2##i3
#define _expand_id4(...)             _expand_id40(__VA_ARGS__)
#define _expand_id40(i0,i1,i2,i3,i4) i0##i1##2##i3##i4
#define _expand_id5(...)                _expand_id50(__VA_ARGS__)
#define _expand_id50(i0,i1,i2,i3,i4,i5) i0##i1##i2##i3##i4##i5


#define _expand_all_(...) __VA_ARGS__

#define _expand_just1_(x0,...)             x0
#define _expand_just2_(x0,x1,...)          x1
#define _expand_just3_(x0,x1,x2,...)       x2
#define _expand_just4_(x0,x1,x2,x3,...)    x3
#define _expand_just5_(x0,x1,x2,x3,x4,...) x4

#define _expand_take1_(x0,...)             x0
#define _expand_take2_(x0,x1,...)          x0,x1
#define _expand_take3_(x0,x1,x2,...)       x0,x1,x2
#define _expand_take4_(x0,x1,x2,x3,...)    x0,x1,x2,x3
#define _expand_take5_(x0,x1,x2,x3,x4,...) x0,x1,x2,x3,x4

#define _expand_drop1_(x0,...)             __VA_ARGS__
#define _expand_drop2_(x0,x1,...)          __VA_ARGS__
#define _expand_drop3_(x0,x1,x2,...)       __VA_ARGS__
#define _expand_drop4_(x0,x1,x2,x3,...)    __VA_ARGS__
#define _expand_drop5_(x0,x1,x2,x3,x4,...) __VA_ARGS__


#define _expand_all(x) _expand_all_ x

#define _expand_just1(x) _expand_just1_ x
#define _expand_just2(x) _expand_just2_ x
#define _expand_just3(x) _expand_just3_ x
#define _expand_just4(x) _expand_just4_ x
#define _expand_just5(x) _expand_just5_ x

#define _expand_take1(x) _expand_take1_ x
#define _expand_take2(x) _expand_take2_ x
#define _expand_take3(x) _expand_take3_ x
#define _expand_take4(x) _expand_take4_ x
#define _expand_take5(x) _expand_take5_ x

#define _expand_drop1(x) _expand_drop1_ x
#define _expand_drop2(x) _expand_drop1_ x
#define _expand_drop3(x) _expand_drop1_ x
#define _expand_drop4(x) _expand_drop1_ x
#define _expand_drop5(x) _expand_drop1_ x


#define _expand_just1Merge(...) _expand_just1_(__VA_ARGS__)
#define _expand_just2Merge(...) _expand_just2_(__VA_ARGS__)
#define _expand_just3Merge(...) _expand_just3_(__VA_ARGS__)
#define _expand_just4Merge(...) _expand_just4_(__VA_ARGS__)
#define _expand_just5Merge(...) _expand_just5_(__VA_ARGS__)

#define _expand_take1Merge(...) _expand_take1_(__VA_ARGS__)
#define _expand_take2Merge(...) _expand_take2_(__VA_ARGS__)
#define _expand_take3Merge(...) _expand_take3_(__VA_ARGS__)
#define _expand_take4Merge(...) _expand_take4_(__VA_ARGS__)
#define _expand_take5Merge(...) _expand_take5_(__VA_ARGS__)

#define _expand_drop1Merge(...) _expand_drop1_(__VA_ARGS__)
#define _expand_drop2Merge(...) _expand_drop2_(__VA_ARGS__)
#define _expand_drop3Merge(...) _expand_drop3_(__VA_ARGS__)
#define _expand_drop4Merge(...) _expand_drop4_(__VA_ARGS__)
#define _expand_drop5Merge(...) _expand_drop5_(__VA_ARGS__)


#define _tupple_tupple1_(x0,...) reduce_Construct((x0),__VA_ARGS__)
#define _tupple_tupple2_(x0,x1,...) reduce_Construct((x0,x1),__VA_ARGS__)
#define _tupple_tupple3_(x0,x1,x2,...) reduce_Construct((x0,x1,x2),__VA_ARGS__)
#define _tupple_tupple4_(x0,x1,x2,x3,...) reduce_Construct((x0,x1,x2,x3),__VA_ARGS__)
#define _tupple_tupple5_(x0,x1,x2,x3,x4,...) reduce_Construct((x0,x1,x2,x3,x4),__VA_ARGS__)


#define _tupple_just1(x) (_expand_just1_ x)
#define _tupple_just2(x) (_expand_just2_ x)
#define _tupple_just3(x) (_expand_just3_ x)
#define _tupple_just4(x) (_expand_just4_ x)
#define _tupple_just5(x) (_expand_just5_ x)

#define _tupple_take1(x) (_expand_take1_ x)
#define _tupple_take2(x) (_expand_take2_ x)
#define _tupple_take3(x) (_expand_take3_ x)
#define _tupple_take4(x) (_expand_take4_ x)
#define _tupple_take5(x) (_expand_take5_ x)

#define _tupple_drop1(x) (_expand_drop1_ x)
#define _tupple_drop2(x) (_expand_drop2_ x)
#define _tupple_drop3(x) (_expand_drop3_ x)
#define _tupple_drop4(x) (_expand_drop4_ x)
#define _tupple_drop5(x) (_expand_drop5_ x)


#define _tupple_just1Merge(...) (_expand_just1_(__VA_ARGS__))
#define _tupple_just2Merge(...) (_expand_just2_(__VA_ARGS__))
#define _tupple_just3Merge(...) (_expand_just3_(__VA_ARGS__))
#define _tupple_just4Merge(...) (_expand_just4_(__VA_ARGS__))
#define _tupple_just5Merge(...) (_expand_just5_(__VA_ARGS__))

#define _tupple_take1Merge(...) (_expand_take1_(__VA_ARGS__))
#define _tupple_take2Merge(...) (_expand_take2_(__VA_ARGS__))
#define _tupple_take3Merge(...) (_expand_take3_(__VA_ARGS__))
#define _tupple_take4Merge(...) (_expand_take4_(__VA_ARGS__))
#define _tupple_take5Merge(...) (_expand_take5_(__VA_ARGS__))

#define _tupple_drop1Merge(...) (_expand_drop1_(__VA_ARGS__))
#define _tupple_drop2Merge(...) (_expand_drop2_(__VA_ARGS__))
#define _tupple_drop3Merge(...) (_expand_drop3_(__VA_ARGS__))
#define _tupple_drop4Merge(...) (_expand_drop4_(__VA_ARGS__))
#define _tupple_drop5Merge(...) (_expand_drop5_(__VA_ARGS__))


#define _tupple_replace1(x0,x) (_expand_all_ x0,_expand_drop1_ x)
#define _tupple_replace2(x1,x) (_expand_take1_ x,_expand_all_ x1,_expand_drop2_ x)
#define _tupple_replace3(x2,x) (_expand_take2_ x,_expand_all_ x2,_expand_drop3_ x)
#define _tupple_replace4(x3,x) (_expand_take3_ x,_expand_all_ x3,_expand_drop4_ x)
#define _tupple_replace5(x4,x) (_expand_take4_ x,_expand_all_ x4,_expand_drop5_ x)

#define _tupple_insert1(x0,x) (_expand_all_ x0,_expand_all_ x)
#define _tupple_insert2(x1,x) (_expand_take1_ x,_expand_all_ x1,_expand_drop1_ x)
#define _tupple_insert3(x2,x) (_expand_take2_ x,_expand_all_ x2,_expand_drop2_ x)
#define _tupple_insert4(x2,x) (_expand_take3_ x,_expand_all_ x3,_expand_drop3_ x)
#define _tupple_insert5(x2,x) (_expand_take4_ x,_expand_all_ x4,_expand_drop4_ x)

#define _tupple_delete1(x) (_expand_drop1_ x)
#define _tupple_delete2(x) (_expand_take1_ x,_expand_drop2_ x)
#define _tupple_delete3(x) (_expand_take2_ x,_expand_drop3_ x)
#define _tupple_delete4(x) (_expand_take3_ x,_expand_drop4_ x)
#define _tupple_delete5(x) (_expand_take4_ x,_expand_drop5_ x)


#define _tupple_concatenate(x,y)  (_expand_all_ x,_expand_all_ y)
#define _tupple_deliminate(t,x,y) (_expand_all_ x,_expand_all_ t,_expand_all_ y)
#define _tupple_append(t,x)       (_expand_all_ x,_expand_all_ t)


#endif // TUPPLE_H_INCLUDED
