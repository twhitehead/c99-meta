//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef RAW_H_INCLUDED
#define RAW_H_INCLUDED


#define _raw_expand_(...) __VA_ARGS__

#define _raw_expandQuote_(...) _raw_expandQuote0(__VA_ARGS__)
#define _raw_expandQuote0(...) #__VA_ARGS__

#define _raw_expandJust1_(x0,...)             x0
#define _raw_expandJust2_(x0,x1,...)          x1
#define _raw_expandJust3_(x0,x1,x2,...)       x2
#define _raw_expandJust4_(x0,x1,x2,x3,...)    x3
#define _raw_expandJust5_(x0,x1,x2,x3,x4,...) x4

#define _raw_expandTake1_(x0,...)             x0
#define _raw_expandTake2_(x0,x1,...)          x0,x1
#define _raw_expandTake3_(x0,x1,x2,...)       x0,x1,x2
#define _raw_expandTake4_(x0,x1,x2,x3,...)    x0,x1,x2,x3
#define _raw_expandTake5_(x0,x1,x2,x3,x4,...) x0,x1,x2,x3,x4

#define _raw_expandDrop1_(x0,...)             __VA_ARGS__
#define _raw_expandDrop2_(x0,x1,...)          __VA_ARGS__
#define _raw_expandDrop3_(x0,x1,x2,...)       __VA_ARGS__
#define _raw_expandDrop4_(x0,x1,x2,x3,...)    __VA_ARGS__
#define _raw_expandDrop5_(x0,x1,x2,x3,x4,...) __VA_ARGS__

#define _raw_expandFuse1_(...)             _raw_expandFuse10(__VA_ARGS__)
#define _raw_expandFuse10(i0)              i0
#define _raw_expandFuse2_(...)             _raw_expandFuse20(__VA_ARGS__)
#define _raw_expandFuse20(i0,i1)           i0##i1
#define _raw_expandFuse3_(...)             _raw_expandFuse30(__VA_ARGS__)
#define _raw_expandFuse30(i0,i1,i2)        i0##i1##i2
#define _raw_expandFuse4_(...)             _raw_expandFuse40(__VA_ARGS__)
#define _raw_expandFuse40(i0,i1,i2,i3)     i0##i1##i2##i3
#define _raw_expandFuse5_(...)             _raw_expandFuse50(__VA_ARGS__)
#define _raw_expandFuse50(i0,i1,i2,i3,i4)  i0##i1##i2##i3##i4


#define _raw_expand(x) _raw_expand_ x

#define _raw_expandQuote(x) _raw_expandQuote_ x

#define _raw_expandJust1(x) _raw_expandJust1_ x
#define _raw_expandJust2(x) _raw_expandJust2_ x
#define _raw_expandJust3(x) _raw_expandJust3_ x
#define _raw_expandJust4(x) _raw_expandJust4_ x
#define _raw_expandJust5(x) _raw_expandJust5_ x

#define _raw_expandTake1(x) _raw_expandTake1_ x
#define _raw_expandTake2(x) _raw_expandTake2_ x
#define _raw_expandTake3(x) _raw_expandTake3_ x
#define _raw_expandTake4(x) _raw_expandTake4_ x
#define _raw_expandTake5(x) _raw_expandTake5_ x

#define _raw_expandDrop1(x) _raw_expandDrop1_ x
#define _raw_expandDrop2(x) _raw_expandDrop1_ x
#define _raw_expandDrop3(x) _raw_expandDrop1_ x
#define _raw_expandDrop4(x) _raw_expandDrop1_ x
#define _raw_expandDrop5(x) _raw_expandDrop1_ x

#define _raw_expandJust1Merge(...) _raw_expandJust1_(__VA_ARGS__)
#define _raw_expandJust2Merge(...) _raw_expandJust2_(__VA_ARGS__)
#define _raw_expandJust3Merge(...) _raw_expandJust3_(__VA_ARGS__)
#define _raw_expandJust4Merge(...) _raw_expandJust4_(__VA_ARGS__)
#define _raw_expandJust5Merge(...) _raw_expandJust5_(__VA_ARGS__)

#define _raw_expandTake1Merge(...) _raw_expandTake1_(__VA_ARGS__)
#define _raw_expandTake2Merge(...) _raw_expandTake2_(__VA_ARGS__)
#define _raw_expandTake3Merge(...) _raw_expandTake3_(__VA_ARGS__)
#define _raw_expandTake4Merge(...) _raw_expandTake4_(__VA_ARGS__)
#define _raw_expandTake5Merge(...) _raw_expandTake5_(__VA_ARGS__)

#define _raw_expandDrop1Merge(...) _raw_expandDrop1_(__VA_ARGS__)
#define _raw_expandDrop2Merge(...) _raw_expandDrop2_(__VA_ARGS__)
#define _raw_expandDrop3Merge(...) _raw_expandDrop3_(__VA_ARGS__)
#define _raw_expandDrop4Merge(...) _raw_expandDrop4_(__VA_ARGS__)
#define _raw_expandDrop5Merge(...) _raw_expandDrop5_(__VA_ARGS__)

#define _raw_expandFuse1(i0)             _raw_expandFuse1_(_raw_expand_ i0)
#define _raw_expandFuse2(i0,i1)          _raw_expandFuse2_(_raw_expand_ i0,_raw_expand_ i1)
#define _raw_expandFuse3(i0,i1,i2)       _raw_expandFuse3_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2)
#define _raw_expandFuse4(i0,i1,i2,i3)    _raw_expandFuse4_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2,_raw_expand_ i3)
#define _raw_expandFuse5(i0,i1,i2,i3,i4) _raw_expandFuse5_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2,_raw_expand_ i3,_raw_expand_ i4)


#define _raw_quote(x) (_raw_expandQuote_ x)

#define _raw_just1(x) (_raw_expandJust1_ x)
#define _raw_just2(x) (_raw_expandJust2_ x)
#define _raw_just3(x) (_raw_expandJust3_ x)
#define _raw_just4(x) (_raw_expandJust4_ x)
#define _raw_just5(x) (_raw_expandJust5_ x)

#define _raw_take1(x) (_raw_expandTake1_ x)
#define _raw_take2(x) (_raw_expandTake2_ x)
#define _raw_take3(x) (_raw_expandTake3_ x)
#define _raw_take4(x) (_raw_expandTake4_ x)
#define _raw_take5(x) (_raw_expandTake5_ x)

#define _raw_drop1(x) (_raw_expandDrop1_ x)
#define _raw_drop2(x) (_raw_expandDrop2_ x)
#define _raw_drop3(x) (_raw_expandDrop3_ x)
#define _raw_drop4(x) (_raw_expandDrop4_ x)
#define _raw_drop5(x) (_raw_expandDrop5_ x)

#define _raw_fuse1(i0)             (_raw_expandFuse1_(_raw_expand_ i0))
#define _raw_fuse2(i0,i1)          (_raw_expandFuse2_(_raw_expand_ i0,_raw_expand_ i1))
#define _raw_fuse3(i0,i1,i2)       (_raw_expandFuse3_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2))
#define _raw_fuse4(i0,i1,i2,i3)    (_raw_expandFuse4_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2,_raw_expand_ i3))
#define _raw_fuse5(i0,i1,i2,i3,i4) (_raw_expandFuse5_(_raw_expand_ i0,_raw_expand_ i1,_raw_expand_ i2,_raw_expand_ i3,_raw_expand_ i4))


#define _raw_just1Merge(...) (_raw_expandJust1_(__VA_ARGS__))
#define _raw_just2Merge(...) (_raw_expandJust2_(__VA_ARGS__))
#define _raw_just3Merge(...) (_raw_expandJust3_(__VA_ARGS__))
#define _raw_just4Merge(...) (_raw_expandJust4_(__VA_ARGS__))
#define _raw_just5Merge(...) (_raw_expandJust5_(__VA_ARGS__))

#define _raw_take1Merge(...) (_raw_expandTake1_(__VA_ARGS__))
#define _raw_take2Merge(...) (_raw_expandTake2_(__VA_ARGS__))
#define _raw_take3Merge(...) (_raw_expandTake3_(__VA_ARGS__))
#define _raw_take4Merge(...) (_raw_expandTake4_(__VA_ARGS__))
#define _raw_take5Merge(...) (_raw_expandTake5_(__VA_ARGS__))

#define _raw_drop1Merge(...) (_raw_expandDrop1_(__VA_ARGS__))
#define _raw_drop2Merge(...) (_raw_expandDrop2_(__VA_ARGS__))
#define _raw_drop3Merge(...) (_raw_expandDrop3_(__VA_ARGS__))
#define _raw_drop4Merge(...) (_raw_expandDrop4_(__VA_ARGS__))
#define _raw_drop5Merge(...) (_raw_expandDrop5_(__VA_ARGS__))


#define _raw_replace1(x0,x) (_raw_expand_ x0,_raw_expandDrop1_ x)
#define _raw_replace2(x1,x) (_raw_expandTake1_ x,_raw_expand_ x1,_raw_expandDrop2_ x)
#define _raw_replace3(x2,x) (_raw_expandTake2_ x,_raw_expand_ x2,_raw_expandDrop3_ x)
#define _raw_replace4(x3,x) (_raw_expandTake3_ x,_raw_expand_ x3,_raw_expandDrop4_ x)
#define _raw_replace5(x4,x) (_raw_expandTake4_ x,_raw_expand_ x4,_raw_expandDrop5_ x)

#define _raw_insert1(x0,x) (_raw_expand_ x0,_raw_expand_ x)
#define _raw_insert2(x1,x) (_raw_expandTake1_ x,_raw_expand_ x1,_raw_expandDrop1_ x)
#define _raw_insert3(x2,x) (_raw_expandTake2_ x,_raw_expand_ x2,_raw_expandDrop2_ x)
#define _raw_insert4(x2,x) (_raw_expandTake3_ x,_raw_expand_ x3,_raw_expandDrop3_ x)
#define _raw_insert5(x2,x) (_raw_expandTake4_ x,_raw_expand_ x4,_raw_expandDrop4_ x)

#define _raw_delete1(x) (_raw_expandDrop1_ x)
#define _raw_delete2(x) (_raw_expandTake1_ x,_raw_expandDrop2_ x)
#define _raw_delete3(x) (_raw_expandTake2_ x,_raw_expandDrop3_ x)
#define _raw_delete4(x) (_raw_expandTake3_ x,_raw_expandDrop4_ x)
#define _raw_delete5(x) (_raw_expandTake4_ x,_raw_expandDrop5_ x)


#define _raw_concatenate1(x0)             x0
#define _raw_concatenate2(x0,x1)          (_raw_expand_ x0,_raw_expand_ x1)
#define _raw_concatenate3(x0,x1,x2)       (_raw_expand_ x0,_raw_expand_ x1,_raw_expand_ x2)
#define _raw_concatenate4(x0,x1,x2,x3)    (_raw_expand_ x0,_raw_expand_ x1,_raw_expand_ x2,_raw_expand_ x3)
#define _raw_concatenate5(x0,x1,x2,x3,x4) (_raw_expand_ x0,_raw_expand_ x1,_raw_expand_ x2,_raw_expand_ x3,_raw_expand_ x4)


#endif // RAW_H_INCLUDED
