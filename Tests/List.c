#include "../List.h"
#include "../Integer.h"
#include "../Equal.h"
#include "../Order.h"

//#undef RECURSE_DEBUG
//#define RECURSE_DEBUG (0,0,0,6)

  ------ map ------

 eval(map,(add,P1),L2(P1,P2))
={0x2,0x3}

  ------ append ------

eval(append,L2(P1,P2),L3(P3,P4,P5))
={0x1,0x2,0x3,0x4,0x5}

  ------ filter ------

eval(filter,(notequal,P3),L5(P1,P2,P3,P4,P5))
={0x1,0x2,0x4,0x5}

  ------ concat ------

eval(concat,L3(L2(P1,P2),L0,L3(P3,P4,P5)))
={0x1,0x2,0x3,0x4,0x5}

  ------ head ------

 eval(head,L0)
=ERROR: "list_head: empty list"

 eval(head,L2(P1,P2))
=0x1

  ------ tail ------

 eval(tail,L0)
=ERROR: "list_tail: empty list"

 eval(tail,L3(P1,P2,P3))
={0x2,0x3}

  ------ last ------

 eval(last,L0)
=ERROR: "list_last: empty list"

 eval(last,L3(P1,P2,P3))
=0x3

  ------ initial ------

 eval(initial,L0)
=ERROR: "list_initial: empty list"

 eval(initial,L3(P1,P2,P3))
={0x1,0x2}

 ------- null ------

 eval(null,L0)
=bool_True

 eval(null,L2(P1,P2))
=bool_False

 ------- length ------

 eval(length,L3(P1,P2,P3))
=0x3

 ------- index ------

 eval(index,L3(P1,P2,P3),N1)
=ERROR: "list_index: negative index"

 eval(index,L0,N1)
=ERROR: "list_index: negative index"

 eval(index,L3(P1,P2,P3),P1)
=0x2

 eval(index,L3(P1,P2,P3),P3)
=ERROR: "list_index: index too large"

 eval(index,L3(P1,P2,P3),P4)
=ERROR: "list_index: index too large"

 ------- foldl ------

 eval(foldl,(subtract),P1,L3(P2,P3,P4))
=-0x8

 ------- foldl1 ------

 eval(foldl1,(subtract),L0)
=ERROR: "list_foldl1: empty list"

 eval(foldl1,(subtract),L4(P1,P2,P3,P4))
=-0x8

 ------- scanl ------

 eval(scanl,(subtract),P1,L3(P2,P3,P4))
={0x1,-0x1,-0x4,-0x8}

 ------- scanl1 ------

 eval(scanl1,(subtract),L4(P1,P2,P3,P4))
={0x1,-0x1,-0x4,-0x8}

 ------- foldr ------

 eval(foldr,(subtract),P4,L3(P1,P2,P3))
=-0x2

 ------- foldr1 ------

 eval(foldr1,(subtract),L0)
=ERROR: "list_foldr1: empty list"

 eval(foldr1,(subtract),L4(P1,P2,P3,P4))
=-0x2

 ------- scanr ------

 eval(scanr,(subtract),P4,L3(P1,P2,P3))
={-0x2,0x3,-0x1,0x4}

 ------- scanr1 ------

 eval(scanr1,(subtract),L4(P1,P2,P3,P4))
={-0x2,0x3,-0x1,0x4}

 ------- iterate ------

 eval(take,P4,(iterate,(add,P1),Z))
={0x0,0x1,0x2,0x3}

 ------- repeat ------

 eval(take,P4,(repeat,P1))
={0x1,0x1,0x1,0x1}

 ------- replicate ------

 eval(replicate,P4,P1)
={0x1,0x1,0x1,0x1}

 ------- cycle ------

 eval(cycle,L0)
=ERROR: "list_cycle: empty list"

 eval(take,P5,(cycle,L2(P1,P2)))
={0x1,0x2,0x1,0x2,0x1}

 ------- take ------

 eval(take,N1,L4(P1,P2,P3,P4))
={}

 eval(take,N1,L0)
={}

 eval(take,Z,L4(P1,P2,P3,P4))
={}

 eval(take,Z,L4(P1,P2,P3,P4))
={}

 eval(take,P3,L4(P1,P2,P3,P4))
={0x1,0x2,0x3}

 eval(take,P3,L2(P1,P2))
={0x1,0x2}

 ------- drop ------

 eval(drop,N1,L4(P1,P2,P3,P4))
={0x1,0x2,0x3,0x4}

 eval(drop,N1,L0)
={}

 eval(drop,Z,L4(P1,P2,P3,P4))
={0x1,0x2,0x3,0x4}

 eval(drop,Z,L4(P1,P2,P3,P4))
={0x1,0x2,0x3,0x4}

 eval(drop,P3,L4(P1,P2,P3,P4))
={0x4}

 eval(drop,P3,L2(P1,P2))
={}

 ------- splitAt ------

 eval(splitAt,N1,L4(P1,P2,P3,P4))
=({},{0x1,0x2,0x3,0x4})

 eval(splitAt,N1,L0)
=({},{})

 eval(splitAt,Z,L4(P1,P2,P3,P4))
=({},{0x1,0x2,0x3,0x4})

 eval(splitAt,Z,L4(P1,P2,P3,P4))
=({},{0x1,0x2,0x3,0x4})

 eval(splitAt,P3,L4(P1,P2,P3,P4))
=({0x1,0x2,0x3},{0x4})

 eval(splitAt,P3,L2(P1,P2))
=({0x1,0x2},{})

 ------- takeWhile ------

 eval(takeWhile,(greater,P3),L0)
={}

 eval(takeWhile,(greater,P3),L4(P1,P2,P3,P4))
={0x1,0x2}

 eval(takeWhile,(greater,P5),L4(P1,P2,P3,P4))
={0x1,0x2,0x3,0x4}

 ------- dropWhile ------

 eval(dropWhile,(greater,P3),L0)
={}

 eval(dropWhile,(greater,P3),L4(P1,P2,P3,P4))
={0x3,0x4}

 eval(dropWhile,(greater,P1),L4(P1,P2,P3,P4))
={0x1,0x2,0x3,0x4}

 ------- span ------

 eval(span,(greater,P3),L0)
=({},{})

 eval(span,(greater,P3),L4(P1,P2,P3,P4))
=({0x1,0x2},{0x3,0x4})

 eval(span,(greater,P5),L4(P1,P2,P3,P4))
=({0x1,0x2,0x3,0x4},{})

 ------- _break ------

 eval(_break,(lesser,P3),L0)
=({},{})

 eval(_break,(lesser,P2),L4(P1,P2,P3,P4))
=({0x1,0x2},{0x3,0x4})

 eval(_break,(lesser,P5),L4(P1,P2,P3,P4))
=({0x1,0x2,0x3,0x4},{})

 ------- reverse ------

 eval(reverse,L4(P1,P2,P3,P4))
={0x4,0x3,0x2,0x1}

 ------- list_and ------

 eval(list_and,L0)
=bool_True

 eval(list_and,L4(T,T,F,T))
=bool_False

 ------- list_or ------

 eval(list_or,L0)
=bool_False

 eval(list_or,L4(F,F,T,F))
=bool_True

 ------- any ------

 eval(any,(equal,P2),L0)
=bool_False

 eval(any,(equal,P2),L4(P1,P2,P3,P4))
=bool_True

 ------- all ------

 eval(all,(notequal,P2),L0)
=bool_True

 eval(all,(notequal,P2),L4(P1,P2,P3,P4))
=bool_False

 ------- element ------

 eval(element,P2,L0)
=bool_False

 eval(element,P2,L4(P1,P2,P3,P4))
=bool_True

 ------- notelement ------

 eval(notelement,P2,L0)
=bool_True

 eval(notelement,P2,L4(P1,P2,P3,P4))
=bool_False

 ------- lookup ------

 eval(lookup,P2,L4(T2(P1,P2),T2(P3,P4),T2(P5,P6),T2(P7,P8)))
=Nothing

 eval(lookup,P3,L4(T2(P1,P2),T2(P3,P4),T2(P5,P6),T2(P7,P8)))
=Just(0x4)

 ------- sum ------

 eval(sum,L4(P1,P2,P3,P4))
=0xa

 ------- product ------

 eval(product,L4(P1,P2,P3,P4))
=0x18

 ------- list_maximum ------

 eval(list_maximum,L4(P1,P2,P3,P4))
=0x4

 ------- list_minimum ------

 eval(list_minimum,L4(P1,P2,P3,P4))
=0x1

 ------- zip ------

 eval(zip,L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x2,0x1),(0x3,0x2),(0x4,0x3)}

 eval(zip,L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x2,0x1),(0x3,0x2),(0x4,0x3)}

 eval(zip,L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x2,0x1),(0x3,0x2),(0x4,0x3),(0x5,0x4)}

 ------- zip3 ------

 eval(zip3,L3(P3,P4,P5),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L3(P3,P4,P5),L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L3(P3,P4,P5),L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L4(P3,P4,P5,P6),L3(P2,P3,P4),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L4(P3,P4,P5,P6),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L4(P3,P4,P5,P6),L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zip3,L4(P3,P4,P5,P6),L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3),(0x6,0x5,0x4)}

-------- zipWith ------

 eval(zipWith,(Tuple2),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x2,0x1),(0x3,0x4),(0x4,0x5)}

 eval(zipWith,(Tuple2),L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x2,0x1),(0x3,0x4),(0x4,0x5)}

 eval(zipWith,(Tuple2),L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x2,0x1),(0x3,0x4),(0x4,0x5),(0x5,0x4)}

 ------- zipWith3 ------

 eval(zipWith3,(Tuple3),L3(P3,P4,P5),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L3(P3,P4,P5),L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L3(P3,P4,P5),L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L4(P3,P4,P5,P6),L3(P2,P3,P4),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L4(P3,P4,P5,P6),L3(P2,P3,P4),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L4(P3,P4,P5,P6),L4(P2,P3,P4,P5),L3(P1,P2,P3))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3)}

 eval(zipWith3,(Tuple3),L4(P3,P4,P5,P6),L4(P2,P3,P4,P5),L4(P1,P2,P3,P4))
={(0x3,0x2,0x1),(0x4,0x3,0x2),(0x5,0x4,0x3),(0x6,0x5,0x4)}

 ------- unzip ------

 eval(unzip,L3(T2(P2,P1),T2(P3,P2),T2(P4,P3)))
=({0x2,0x3,0x4},{0x1,0x2,0x3})

 ------- unzip3 ------

 eval(unzip3,L3(T3(P3,P2,P1),T3(P4,P3,P2),T3(P5,P4,P3)))
=({0x3,0x4,0x5},{0x2,0x3,0x4},{0x1,0x2,0x3})
