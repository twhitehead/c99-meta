#include "../Integer.h"


//#undef RECURSE_DEBUG
//#define RECURSE_DEBUG (0,0,0,7)

  ------ equal ------

eval(equal,N4,N4)
=bool_True

eval(equal,N4,N3)
=bool_False

eval(equal,N4,N2)
=bool_False

eval(equal,N4,N1)
=bool_False

eval(equal,N4,Z)
=bool_False

eval(equal,N4,P1)
=bool_False

eval(equal,N4,P2)
=bool_False

eval(equal,N4,P3)
=bool_False

eval(equal,N4,P4)
=bool_False

eval(equal,N3,N4)
=bool_False

eval(equal,N3,N3)
=bool_True

eval(equal,N3,N2)
=bool_False

eval(equal,N3,N1)
=bool_False

eval(equal,N3,Z)
=bool_False

eval(equal,N3,P1)
=bool_False

eval(equal,N3,P2)
=bool_False

eval(equal,N3,P3)
=bool_False

eval(equal,N3,P4)
=bool_False

eval(equal,N2,N4)
=bool_False

eval(equal,N2,N3)
=bool_False

eval(equal,N2,N2)
=bool_True

eval(equal,N2,N1)
=bool_False

eval(equal,N2,Z)
=bool_False

eval(equal,N2,P1)
=bool_False

eval(equal,N2,P2)
=bool_False

eval(equal,N2,P3)
=bool_False

eval(equal,N2,P4)
=bool_False

eval(equal,N1,N4)
=bool_False

eval(equal,N1,N3)
=bool_False

eval(equal,N1,N2)
=bool_False

eval(equal,N1,N1)
=bool_True

eval(equal,N1,Z)
=bool_False

eval(equal,N1,P1)
=bool_False

eval(equal,N1,P2)
=bool_False

eval(equal,N1,P3)
=bool_False

eval(equal,N1,P4)
=bool_False

eval(equal,Z,N4)
=bool_False

eval(equal,Z,N3)
=bool_False

eval(equal,Z,N2)
=bool_False

eval(equal,Z,N1)
=bool_False

eval(equal,Z,Z)
=bool_True

eval(equal,Z,P1)
=bool_False

eval(equal,Z,P2)
=bool_False

eval(equal,Z,P3)
=bool_False

eval(equal,Z,P4)
=bool_False

eval(equal,P1,N4)
=bool_False

eval(equal,P1,N3)
=bool_False

eval(equal,P1,N2)
=bool_False

eval(equal,P1,N1)
=bool_False

eval(equal,P1,Z)
=bool_False

eval(equal,P1,P1)
=bool_True

eval(equal,P1,P2)
=bool_False

eval(equal,P1,P3)
=bool_False

eval(equal,P1,P4)
=bool_False

eval(equal,P2,N4)
=bool_False

eval(equal,P2,N3)
=bool_False

eval(equal,P2,N2)
=bool_False

eval(equal,P2,N1)
=bool_False

eval(equal,P2,Z)
=bool_False

eval(equal,P2,P1)
=bool_False

eval(equal,P2,P2)
=bool_True

eval(equal,P2,P3)
=bool_False

eval(equal,P2,P4)
=bool_False

eval(equal,P3,N4)
=bool_False

eval(equal,P3,N3)
=bool_False

eval(equal,P3,N2)
=bool_False

eval(equal,P3,N1)
=bool_False

eval(equal,P3,Z)
=bool_False

eval(equal,P3,P1)
=bool_False

eval(equal,P3,P2)
=bool_False

eval(equal,P3,P3)
=bool_True

eval(equal,P3,P4)
=bool_False

eval(equal,P4,N4)
=bool_False

eval(equal,P4,N3)
=bool_False

eval(equal,P4,N2)
=bool_False

eval(equal,P4,N1)
=bool_False

eval(equal,P4,Z)
=bool_False

eval(equal,P4,P1)
=bool_False

eval(equal,P4,P2)
=bool_False

eval(equal,P4,P3)
=bool_False

eval(equal,P4,P4)
=bool_True


  ------ compare ------

eval(compare,N4,N4)
=order_EQ

eval(compare,N4,N3)
=order_LT

eval(compare,N4,N2)
=order_LT

eval(compare,N4,N1)
=order_LT

eval(compare,N4,Z)
=order_LT

eval(compare,N4,P1)
=order_LT

eval(compare,N4,P2)
=order_LT

eval(compare,N4,P3)
=order_LT

eval(compare,N4,P4)
=order_LT

eval(compare,N3,N4)
=order_GT

eval(compare,N3,N3)
=order_EQ

eval(compare,N3,N2)
=order_LT

eval(compare,N3,N1)
=order_LT

eval(compare,N3,Z)
=order_LT

eval(compare,N3,P1)
=order_LT

eval(compare,N3,P2)
=order_LT

eval(compare,N3,P3)
=order_LT

eval(compare,N3,P4)
=order_LT

eval(compare,N2,N4)
=order_GT

eval(compare,N2,N3)
=order_GT

eval(compare,N2,N2)
=order_EQ

eval(compare,N2,N1)
=order_LT

eval(compare,N2,Z)
=order_LT

eval(compare,N2,P1)
=order_LT

eval(compare,N2,P2)
=order_LT

eval(compare,N2,P3)
=order_LT

eval(compare,N2,P4)
=order_LT

eval(compare,N1,N4)
=order_GT

eval(compare,N1,N3)
=order_GT

eval(compare,N1,N2)
=order_GT

eval(compare,N1,N1)
=order_EQ

eval(compare,N1,Z)
=order_LT

eval(compare,N1,P1)
=order_LT

eval(compare,N1,P2)
=order_LT

eval(compare,N1,P3)
=order_LT

eval(compare,N1,P4)
=order_LT

eval(compare,Z,N4)
=order_GT

eval(compare,Z,N3)
=order_GT

eval(compare,Z,N2)
=order_GT

eval(compare,Z,N1)
=order_GT

eval(compare,Z,Z)
=order_EQ

eval(compare,Z,P1)
=order_LT

eval(compare,Z,P2)
=order_LT

eval(compare,Z,P3)
=order_LT

eval(compare,Z,P4)
=order_LT

eval(compare,P1,N4)
=order_GT

eval(compare,P1,N3)
=order_GT

eval(compare,P1,N2)
=order_GT

eval(compare,P1,N1)
=order_GT

eval(compare,P1,Z)
=order_GT

eval(compare,P1,P1)
=order_EQ

eval(compare,P1,P2)
=order_LT

eval(compare,P1,P3)
=order_LT

eval(compare,P1,P4)
=order_LT

eval(compare,P2,N4)
=order_GT

eval(compare,P2,N3)
=order_GT

eval(compare,P2,N2)
=order_GT

eval(compare,P2,N1)
=order_GT

eval(compare,P2,Z)
=order_GT

eval(compare,P2,P1)
=order_GT

eval(compare,P2,P2)
=order_EQ

eval(compare,P2,P3)
=order_LT

eval(compare,P2,P4)
=order_LT

eval(compare,P3,N4)
=order_GT

eval(compare,P3,N3)
=order_GT

eval(compare,P3,N2)
=order_GT

eval(compare,P3,N1)
=order_GT

eval(compare,P3,Z)
=order_GT

eval(compare,P3,P1)
=order_GT

eval(compare,P3,P2)
=order_GT

eval(compare,P3,P3)
=order_EQ

eval(compare,P3,P4)
=order_LT

eval(compare,P4,N4)
=order_GT

eval(compare,P4,N3)
=order_GT

eval(compare,P4,N2)
=order_GT

eval(compare,P4,N1)
=order_GT

eval(compare,P4,Z)
=order_GT

eval(compare,P4,P1)
=order_GT

eval(compare,P4,P2)
=order_GT

eval(compare,P4,P3)
=order_GT

eval(compare,P4,P4)
=order_EQ


  ------ lesser ------

eval(lesser,Z,Z)
=bool_False

eval(lesser,Z,N1)
=bool_False

eval(lesser,N1,Z)
=bool_True


  ------ lesserequal ------

eval(lesserequal,Z,N1)
=bool_False

eval(lesserequal,Z,Z)
=bool_True

eval(lesserequal,N1,Z)
=bool_True


  ------ greaterequal ------

eval(greaterequal,Z,N1)
=bool_True

eval(greaterequal,Z,Z)
=bool_True

eval(greaterequal,N1,Z)
=bool_False


  ------ greater ------

eval(greater,Z,N1)
=bool_True

eval(greater,Z,Z)
=bool_False

eval(greater,N1,Z)
=bool_False


  ------ maximum ------

eval(maximum,Z,N1)
=0x0

eval(maximum,Z,Z)
=0x0

eval(maximum,N1,Z)
=0x0


  ------ minimum ------

eval(minimum,Z,N1)
=-0x1

eval(minimum,N1,N1)
=-0x1

eval(minimum,N1,Z)
=-0x1


  ------ numeric_add ------

eval(numeric_add,N4,N4)
=-0x8

eval(numeric_add,N4,N3)
=-0x7

eval(numeric_add,N4,N2)
=-0x6

eval(numeric_add,N4,N1)
=-0x5

eval(numeric_add,N4,Z)
=-0x4

eval(numeric_add,N4,P1)
=-0x3

eval(numeric_add,N4,P2)
=-0x2

eval(numeric_add,N4,P3)
=-0x1

eval(numeric_add,N4,P4)
=0x0

eval(numeric_add,N3,N4)
=-0x7

eval(numeric_add,N3,N3)
=-0x6

eval(numeric_add,N3,N2)
=-0x5

eval(numeric_add,N3,N1)
=-0x4

eval(numeric_add,N3,Z)
=-0x3

eval(numeric_add,N3,P1)
=-0x2

eval(numeric_add,N3,P2)
=-0x1

eval(numeric_add,N3,P3)
=0x0

eval(numeric_add,N3,P4)
=0x1

eval(numeric_add,N2,N4)
=-0x6

eval(numeric_add,N2,N3)
=-0x5

eval(numeric_add,N2,N2)
=-0x4

eval(numeric_add,N2,N1)
=-0x3

eval(numeric_add,N2,Z)
=-0x2

eval(numeric_add,N2,P1)
=-0x1

eval(numeric_add,N2,P2)
=0x0

eval(numeric_add,N2,P3)
=0x1

eval(numeric_add,N2,P4)
=0x2

eval(numeric_add,N1,N4)
=-0x5

eval(numeric_add,N1,N3)
=-0x4

eval(numeric_add,N1,N2)
=-0x3

eval(numeric_add,N1,N1)
=-0x2

eval(numeric_add,N1,Z)
=-0x1

eval(numeric_add,N1,P1)
=0x0

eval(numeric_add,N1,P2)
=0x1

eval(numeric_add,N1,P3)
=0x2

eval(numeric_add,N1,P4)
=0x3

eval(numeric_add,Z,N4)
=-0x4

eval(numeric_add,Z,N3)
=-0x3

eval(numeric_add,Z,N2)
=-0x2

eval(numeric_add,Z,N1)
=-0x1

eval(numeric_add,Z,Z)
=0x0

eval(numeric_add,Z,P1)
=0x1

eval(numeric_add,Z,P2)
=0x2

eval(numeric_add,Z,P3)
=0x3

eval(numeric_add,Z,P4)
=0x4

eval(numeric_add,P1,N4)
=-0x3

eval(numeric_add,P1,N3)
=-0x2

eval(numeric_add,P1,N2)
=-0x1

eval(numeric_add,P1,N1)
=0x0

eval(numeric_add,P1,Z)
=0x1

eval(numeric_add,P1,P1)
=0x2

eval(numeric_add,P1,P2)
=0x3

eval(numeric_add,P1,P3)
=0x4

eval(numeric_add,P1,P4)
=0x5

eval(numeric_add,P2,N4)
=-0x2

eval(numeric_add,P2,N3)
=-0x1

eval(numeric_add,P2,N2)
=0x0

eval(numeric_add,P2,N1)
=0x1

eval(numeric_add,P2,Z)
=0x2

eval(numeric_add,P2,P1)
=0x3

eval(numeric_add,P2,P2)
=0x4

eval(numeric_add,P2,P3)
=0x5

eval(numeric_add,P2,P4)
=0x6

eval(numeric_add,P3,N4)
=-0x1

eval(numeric_add,P3,N3)
=0x0

eval(numeric_add,P3,N2)
=0x1

eval(numeric_add,P3,N1)
=0x2

eval(numeric_add,P3,Z)
=0x3

eval(numeric_add,P3,P1)
=0x4

eval(numeric_add,P3,P2)
=0x5

eval(numeric_add,P3,P3)
=0x6

eval(numeric_add,P3,P4)
=0x7

eval(numeric_add,P4,N4)
=0x0

eval(numeric_add,P4,N3)
=0x1

eval(numeric_add,P4,N2)
=0x2

eval(numeric_add,P4,N1)
=0x3

eval(numeric_add,P4,Z)
=0x4

eval(numeric_add,P4,P1)
=0x5

eval(numeric_add,P4,P2)
=0x6

eval(numeric_add,P4,P3)
=0x7

eval(numeric_add,P4,P4)
=0x8


  ------ numeric_subtract ------

eval(numeric_subtract,N4,N4)
=0x0

eval(numeric_subtract,N4,N3)
=-0x1

eval(numeric_subtract,N4,N2)
=-0x2

eval(numeric_subtract,N4,N1)
=-0x3

eval(numeric_subtract,N4,Z)
=-0x4

eval(numeric_subtract,N4,P1)
=-0x5

eval(numeric_subtract,N4,P2)
=-0x6

eval(numeric_subtract,N4,P3)
=-0x7

eval(numeric_subtract,N4,P4)
=-0x8

eval(numeric_subtract,N3,N4)
=0x1

eval(numeric_subtract,N3,N3)
=0x0

eval(numeric_subtract,N3,N2)
=-0x1

eval(numeric_subtract,N3,N1)
=-0x2

eval(numeric_subtract,N3,Z)
=-0x3

eval(numeric_subtract,N3,P1)
=-0x4

eval(numeric_subtract,N3,P2)
=-0x5

eval(numeric_subtract,N3,P3)
=-0x6

eval(numeric_subtract,N3,P4)
=-0x7

eval(numeric_subtract,N2,N4)
=0x2

eval(numeric_subtract,N2,N3)
=0x1

eval(numeric_subtract,N2,N2)
=0x0

eval(numeric_subtract,N2,N1)
=-0x1

eval(numeric_subtract,N2,Z)
=-0x2

eval(numeric_subtract,N2,P1)
=-0x3

eval(numeric_subtract,N2,P2)
=-0x4

eval(numeric_subtract,N2,P3)
=-0x5

eval(numeric_subtract,N2,P4)
=-0x6

eval(numeric_subtract,N1,N4)
=0x3

eval(numeric_subtract,N1,N3)
=0x2

eval(numeric_subtract,N1,N2)
=0x1

eval(numeric_subtract,N1,N1)
=0x0

eval(numeric_subtract,N1,Z)
=-0x1

eval(numeric_subtract,N1,P1)
=-0x2

eval(numeric_subtract,N1,P2)
=-0x3

eval(numeric_subtract,N1,P3)
=-0x4

eval(numeric_subtract,N1,P4)
=-0x5

eval(numeric_subtract,Z,N4)
=0x4

eval(numeric_subtract,Z,N3)
=0x3

eval(numeric_subtract,Z,N2)
=0x2

eval(numeric_subtract,Z,N1)
=0x1

eval(numeric_subtract,Z,Z)
=0x0

eval(numeric_subtract,Z,P1)
=-0x1

eval(numeric_subtract,Z,P2)
=-0x2

eval(numeric_subtract,Z,P3)
=-0x3

eval(numeric_subtract,Z,P4)
=-0x4

eval(numeric_subtract,P1,N4)
=0x5

eval(numeric_subtract,P1,N3)
=0x4

eval(numeric_subtract,P1,N2)
=0x3

eval(numeric_subtract,P1,N1)
=0x2

eval(numeric_subtract,P1,Z)
=0x1

eval(numeric_subtract,P1,P1)
=0x0

eval(numeric_subtract,P1,P2)
=-0x1

eval(numeric_subtract,P1,P3)
=-0x2

eval(numeric_subtract,P1,P4)
=-0x3

eval(numeric_subtract,P2,N4)
=0x6

eval(numeric_subtract,P2,N3)
=0x5

eval(numeric_subtract,P2,N2)
=0x4

eval(numeric_subtract,P2,N1)
=0x3

eval(numeric_subtract,P2,Z)
=0x2

eval(numeric_subtract,P2,P1)
=0x1

eval(numeric_subtract,P2,P2)
=0x0

eval(numeric_subtract,P2,P3)
=-0x1

eval(numeric_subtract,P2,P4)
=-0x2

eval(numeric_subtract,P3,N4)
=0x7

eval(numeric_subtract,P3,N3)
=0x6

eval(numeric_subtract,P3,N2)
=0x5

eval(numeric_subtract,P3,N1)
=0x4

eval(numeric_subtract,P3,Z)
=0x3

eval(numeric_subtract,P3,P1)
=0x2

eval(numeric_subtract,P3,P2)
=0x1

eval(numeric_subtract,P3,P3)
=0x0

eval(numeric_subtract,P3,P4)
=-0x1

eval(numeric_subtract,P4,N4)
=0x8

eval(numeric_subtract,P4,N3)
=0x7

eval(numeric_subtract,P4,N2)
=0x6

eval(numeric_subtract,P4,N1)
=0x5

eval(numeric_subtract,P4,Z)
=0x4

eval(numeric_subtract,P4,P1)
=0x3

eval(numeric_subtract,P4,P2)
=0x2

eval(numeric_subtract,P4,P3)
=0x1

eval(numeric_subtract,P4,P4)
=0x0


  ------ numeric_multiply ------

eval(numeric_multiply,N4,N4)
=0x10

eval(numeric_multiply,N4,N3)
=0xc

eval(numeric_multiply,N4,N2)
=0x8

eval(numeric_multiply,N4,N1)
=0x4

eval(numeric_multiply,N4,Z)
=0x0

eval(numeric_multiply,N4,P1)
=-0x4

eval(numeric_multiply,N4,P2)
=-0x8

eval(numeric_multiply,N4,P3)
=-0xc

eval(numeric_multiply,N4,P4)
=-0x10

eval(numeric_multiply,N3,N4)
=0xc

eval(numeric_multiply,N3,N3)
=0x9

eval(numeric_multiply,N3,N2)
=0x6

eval(numeric_multiply,N3,N1)
=0x3

eval(numeric_multiply,N3,Z)
=0x0

eval(numeric_multiply,N3,P1)
=-0x3

eval(numeric_multiply,N3,P2)
=-0x6

eval(numeric_multiply,N3,P3)
=-0x9

eval(numeric_multiply,N3,P4)
=-0xc

eval(numeric_multiply,N2,N4)
=0x8

eval(numeric_multiply,N2,N3)
=0x6

eval(numeric_multiply,N2,N2)
=0x4

eval(numeric_multiply,N2,N1)
=0x2

eval(numeric_multiply,N2,Z)
=0x0

eval(numeric_multiply,N2,P1)
=-0x2

eval(numeric_multiply,N2,P2)
=-0x4

eval(numeric_multiply,N2,P3)
=-0x6

eval(numeric_multiply,N2,P4)
=-0x8

eval(numeric_multiply,N1,N4)
=0x4

eval(numeric_multiply,N1,N3)
=0x3

eval(numeric_multiply,N1,N2)
=0x2

eval(numeric_multiply,N1,N1)
=0x1

eval(numeric_multiply,N1,Z)
=0x0

eval(numeric_multiply,N1,P1)
=-0x1

eval(numeric_multiply,N1,P2)
=-0x2

eval(numeric_multiply,N1,P3)
=-0x3

eval(numeric_multiply,N1,P4)
=-0x4

eval(numeric_multiply,Z,N4)
=0x0

eval(numeric_multiply,Z,N3)
=0x0

eval(numeric_multiply,Z,N2)
=0x0

eval(numeric_multiply,Z,N1)
=0x0

eval(numeric_multiply,Z,Z)
=0x0

eval(numeric_multiply,Z,P1)
=0x0

eval(numeric_multiply,Z,P2)
=0x0

eval(numeric_multiply,Z,P3)
=0x0

eval(numeric_multiply,Z,P4)
=0x0

eval(numeric_multiply,P1,N4)
=-0x4

eval(numeric_multiply,P1,N3)
=-0x3

eval(numeric_multiply,P1,N2)
=-0x2

eval(numeric_multiply,P1,N1)
=-0x1

eval(numeric_multiply,P1,Z)
=0x0

eval(numeric_multiply,P1,P1)
=0x1

eval(numeric_multiply,P1,P2)
=0x2

eval(numeric_multiply,P1,P3)
=0x3

eval(numeric_multiply,P1,P4)
=0x4

eval(numeric_multiply,P2,N4)
=-0x8

eval(numeric_multiply,P2,N3)
=-0x6

eval(numeric_multiply,P2,N2)
=-0x4

eval(numeric_multiply,P2,N1)
=-0x2

eval(numeric_multiply,P2,Z)
=0x0

eval(numeric_multiply,P2,P1)
=0x2

eval(numeric_multiply,P2,P2)
=0x4

eval(numeric_multiply,P2,P3)
=0x6

eval(numeric_multiply,P2,P4)
=0x8

eval(numeric_multiply,P3,N4)
=-0xc

eval(numeric_multiply,P3,N3)
=-0x9

eval(numeric_multiply,P3,N2)
=-0x6

eval(numeric_multiply,P3,N1)
=-0x3

eval(numeric_multiply,P3,Z)
=0x0

eval(numeric_multiply,P3,P1)
=0x3

eval(numeric_multiply,P3,P2)
=0x6

eval(numeric_multiply,P3,P3)
=0x9

eval(numeric_multiply,P3,P4)
=0xc

eval(numeric_multiply,P4,N4)
=-0x10

eval(numeric_multiply,P4,N3)
=-0xc

eval(numeric_multiply,P4,N2)
=-0x8

eval(numeric_multiply,P4,N1)
=-0x4

eval(numeric_multiply,P4,Z)
=0x0

eval(numeric_multiply,P4,P1)
=0x4

eval(numeric_multiply,P4,P2)
=0x8

eval(numeric_multiply,P4,P3)
=0xc

eval(numeric_multiply,P4,P4)
=0x10


  ------ numeric_absolute ------

eval(numeric_absolute,N1)
=0x1

eval(numeric_absolute,Z)
=0x0

eval(numeric_absolute,P1)
=0x1


  ------ numeric_sign ------

eval(numeric_sign,N3)
=-0x1

eval(numeric_sign,N2)
=-0x1

eval(numeric_sign,N1)
=-0x1

eval(numeric_sign,Z)
=0x0

eval(numeric_sign,P1)
=0x1

eval(numeric_sign,P2)
=0x1


  ------ numeric_negate ------

eval(numeric_negate,N1)
=0x1

eval(numeric_negate,Z)
=0x0

eval(numeric_negate,P1)
=-0x1


  ------ quotientRemainder ------

eval(quotientRemainder,N4,N4)
=(0x1,0x0)

eval(quotientRemainder,N4,N3)
=(0x1,-0x1)

eval(quotientRemainder,N4,N2)
=(0x2,0x0)

eval(quotientRemainder,N4,N1)
=(0x4,0x0)

eval(quotientRemainder,N4,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,N4,P1)
=(-0x4,0x0)

eval(quotientRemainder,N4,P2)
=(-0x2,0x0)

eval(quotientRemainder,N4,P3)
=(-0x1,-0x1)

eval(quotientRemainder,N4,P4)
=(-0x1,0x0)

eval(quotientRemainder,N3,N4)
=(0x0,-0x3)

eval(quotientRemainder,N3,N3)
=(0x1,0x0)

eval(quotientRemainder,N3,N2)
=(0x1,-0x1)

eval(quotientRemainder,N3,N1)
=(0x3,0x0)

eval(quotientRemainder,N3,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,N3,P1)
=(-0x3,0x0)

eval(quotientRemainder,N3,P2)
=(-0x1,-0x1)

eval(quotientRemainder,N3,P3)
=(-0x1,0x0)

eval(quotientRemainder,N3,P4)
=(0x0,-0x3)

eval(quotientRemainder,N2,N4)
=(0x0,-0x2)

eval(quotientRemainder,N2,N3)
=(0x0,-0x2)

eval(quotientRemainder,N2,N2)
=(0x1,0x0)

eval(quotientRemainder,N2,N1)
=(0x2,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,N2,P1)
=(-0x2,0x0)

eval(quotientRemainder,N2,P2)
=(-0x1,0x0)

eval(quotientRemainder,N2,P3)
=(0x0,-0x2)

eval(quotientRemainder,N2,P4)
=(0x0,-0x2)

eval(quotientRemainder,N1,N4)
=(0x0,-0x1)

eval(quotientRemainder,N1,N3)
=(0x0,-0x1)

eval(quotientRemainder,N1,N2)
=(0x0,-0x1)

eval(quotientRemainder,N1,N1)
=(0x1,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,N1,P1)
=(-0x1,0x0)

eval(quotientRemainder,N1,P2)
=(0x0,-0x1)

eval(quotientRemainder,N1,P3)
=(0x0,-0x1)

eval(quotientRemainder,N1,P4)
=(0x0,-0x1)

eval(quotientRemainder,Z,N4)
=(0x0,0x0)

eval(quotientRemainder,Z,N3)
=(0x0,0x0)

eval(quotientRemainder,Z,N2)
=(0x0,0x0)

eval(quotientRemainder,Z,N1)
=(0x0,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,Z,P1)
=(0x0,0x0)

eval(quotientRemainder,Z,P2)
=(0x0,0x0)

eval(quotientRemainder,Z,P3)
=(0x0,0x0)

eval(quotientRemainder,Z,P4)
=(0x0,0x0)

eval(quotientRemainder,P1,N4)
=(0x0,0x1)

eval(quotientRemainder,P1,N3)
=(0x0,0x1)

eval(quotientRemainder,P1,N2)
=(0x0,0x1)

eval(quotientRemainder,P1,N1)
=(-0x1,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,P1,P1)
=(0x1,0x0)

eval(quotientRemainder,P1,P2)
=(0x0,0x1)

eval(quotientRemainder,P1,P3)
=(0x0,0x1)

eval(quotientRemainder,P1,P4)
=(0x0,0x1)

eval(quotientRemainder,P2,N4)
=(0x0,0x2)

eval(quotientRemainder,P2,N3)
=(0x0,0x2)

eval(quotientRemainder,P2,N2)
=(-0x1,0x0)

eval(quotientRemainder,P2,N1)
=(-0x2,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,P2,P1)
=(0x2,0x0)

eval(quotientRemainder,P2,P2)
=(0x1,0x0)

eval(quotientRemainder,P2,P3)
=(0x0,0x2)

eval(quotientRemainder,P2,P4)
=(0x0,0x2)

eval(quotientRemainder,P3,N4)
=(0x0,0x3)

eval(quotientRemainder,P3,N3)
=(-0x1,0x0)

eval(quotientRemainder,P3,N2)
=(-0x1,0x1)

eval(quotientRemainder,P3,N1)
=(-0x3,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,P3,P1)
=(0x3,0x0)

eval(quotientRemainder,P3,P2)
=(0x1,0x1)

eval(quotientRemainder,P3,P3)
=(0x1,0x0)

eval(quotientRemainder,P3,P4)
=(0x0,0x3)

eval(quotientRemainder,P4,N4)
=(-0x1,0x0)

eval(quotientRemainder,P4,N3)
=(-0x1,0x1)

eval(quotientRemainder,P4,N2)
=(-0x2,0x0)

eval(quotientRemainder,P4,N1)
=(-0x4,0x0)

eval(quotientRemainder,N2,Z)
=ERROR: "integer_quotientRemainder_: division by zero"

eval(quotientRemainder,P4,P1)
=(0x4,0x0)

eval(quotientRemainder,P4,P2)
=(0x2,0x0)

eval(quotientRemainder,P4,P3)
=(0x1,0x1)

eval(quotientRemainder,P4,P4)
=(0x1,0x0)
