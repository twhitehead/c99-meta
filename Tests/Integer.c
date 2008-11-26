#include "../Integer.h"


//#undef RECURSE_DEBUG
//#define RECURSE_DEBUG (0,0,0,7)

  ------ equal ------

eval(equal,N4,N4)
="RESULT: ""(bool_True)"

eval(equal,N4,N3)
="RESULT: ""(bool_False)"

eval(equal,N4,N2)
="RESULT: ""(bool_False)"

eval(equal,N4,N1)
="RESULT: ""(bool_False)"

eval(equal,N4,Z)
="RESULT: ""(bool_False)"

eval(equal,N4,P1)
="RESULT: ""(bool_False)"

eval(equal,N4,P2)
="RESULT: ""(bool_False)"

eval(equal,N4,P3)
="RESULT: ""(bool_False)"

eval(equal,N4,P4)
="RESULT: ""(bool_False)"

eval(equal,N3,N4)
="RESULT: ""(bool_False)"

eval(equal,N3,N3)
="RESULT: ""(bool_True)"

eval(equal,N3,N2)
="RESULT: ""(bool_False)"

eval(equal,N3,N1)
="RESULT: ""(bool_False)"

eval(equal,N3,Z)
="RESULT: ""(bool_False)"

eval(equal,N3,P1)
="RESULT: ""(bool_False)"

eval(equal,N3,P2)
="RESULT: ""(bool_False)"

eval(equal,N3,P3)
="RESULT: ""(bool_False)"

eval(equal,N3,P4)
="RESULT: ""(bool_False)"

eval(equal,N2,N4)
="RESULT: ""(bool_False)"

eval(equal,N2,N3)
="RESULT: ""(bool_False)"

eval(equal,N2,N2)
="RESULT: ""(bool_True)"

eval(equal,N2,N1)
="RESULT: ""(bool_False)"

eval(equal,N2,Z)
="RESULT: ""(bool_False)"

eval(equal,N2,P1)
="RESULT: ""(bool_False)"

eval(equal,N2,P2)
="RESULT: ""(bool_False)"

eval(equal,N2,P3)
="RESULT: ""(bool_False)"

eval(equal,N2,P4)
="RESULT: ""(bool_False)"

eval(equal,N1,N4)
="RESULT: ""(bool_False)"

eval(equal,N1,N3)
="RESULT: ""(bool_False)"

eval(equal,N1,N2)
="RESULT: ""(bool_False)"

eval(equal,N1,N1)
="RESULT: ""(bool_True)"

eval(equal,N1,Z)
="RESULT: ""(bool_False)"

eval(equal,N1,P1)
="RESULT: ""(bool_False)"

eval(equal,N1,P2)
="RESULT: ""(bool_False)"

eval(equal,N1,P3)
="RESULT: ""(bool_False)"

eval(equal,N1,P4)
="RESULT: ""(bool_False)"

eval(equal,Z,N4)
="RESULT: ""(bool_False)"

eval(equal,Z,N3)
="RESULT: ""(bool_False)"

eval(equal,Z,N2)
="RESULT: ""(bool_False)"

eval(equal,Z,N1)
="RESULT: ""(bool_False)"

eval(equal,Z,Z)
="RESULT: ""(bool_True)"

eval(equal,Z,P1)
="RESULT: ""(bool_False)"

eval(equal,Z,P2)
="RESULT: ""(bool_False)"

eval(equal,Z,P3)
="RESULT: ""(bool_False)"

eval(equal,Z,P4)
="RESULT: ""(bool_False)"

eval(equal,P1,N4)
="RESULT: ""(bool_False)"

eval(equal,P1,N3)
="RESULT: ""(bool_False)"

eval(equal,P1,N2)
="RESULT: ""(bool_False)"

eval(equal,P1,N1)
="RESULT: ""(bool_False)"

eval(equal,P1,Z)
="RESULT: ""(bool_False)"

eval(equal,P1,P1)
="RESULT: ""(bool_True)"

eval(equal,P1,P2)
="RESULT: ""(bool_False)"

eval(equal,P1,P3)
="RESULT: ""(bool_False)"

eval(equal,P1,P4)
="RESULT: ""(bool_False)"

eval(equal,P2,N4)
="RESULT: ""(bool_False)"

eval(equal,P2,N3)
="RESULT: ""(bool_False)"

eval(equal,P2,N2)
="RESULT: ""(bool_False)"

eval(equal,P2,N1)
="RESULT: ""(bool_False)"

eval(equal,P2,Z)
="RESULT: ""(bool_False)"

eval(equal,P2,P1)
="RESULT: ""(bool_False)"

eval(equal,P2,P2)
="RESULT: ""(bool_True)"

eval(equal,P2,P3)
="RESULT: ""(bool_False)"

eval(equal,P2,P4)
="RESULT: ""(bool_False)"

eval(equal,P3,N4)
="RESULT: ""(bool_False)"

eval(equal,P3,N3)
="RESULT: ""(bool_False)"

eval(equal,P3,N2)
="RESULT: ""(bool_False)"

eval(equal,P3,N1)
="RESULT: ""(bool_False)"

eval(equal,P3,Z)
="RESULT: ""(bool_False)"

eval(equal,P3,P1)
="RESULT: ""(bool_False)"

eval(equal,P3,P2)
="RESULT: ""(bool_False)"

eval(equal,P3,P3)
="RESULT: ""(bool_True)"

eval(equal,P3,P4)
="RESULT: ""(bool_False)"

eval(equal,P4,N4)
="RESULT: ""(bool_False)"

eval(equal,P4,N3)
="RESULT: ""(bool_False)"

eval(equal,P4,N2)
="RESULT: ""(bool_False)"

eval(equal,P4,N1)
="RESULT: ""(bool_False)"

eval(equal,P4,Z)
="RESULT: ""(bool_False)"

eval(equal,P4,P1)
="RESULT: ""(bool_False)"

eval(equal,P4,P2)
="RESULT: ""(bool_False)"

eval(equal,P4,P3)
="RESULT: ""(bool_False)"

eval(equal,P4,P4)
="RESULT: ""(bool_True)"


  ------ compare ------

eval(compare,N4,N4)
="RESULT: ""(order_EQ)"

eval(compare,N4,N3)
="RESULT: ""(order_LT)"

eval(compare,N4,N2)
="RESULT: ""(order_LT)"

eval(compare,N4,N1)
="RESULT: ""(order_LT)"

eval(compare,N4,Z)
="RESULT: ""(order_LT)"

eval(compare,N4,P1)
="RESULT: ""(order_LT)"

eval(compare,N4,P2)
="RESULT: ""(order_LT)"

eval(compare,N4,P3)
="RESULT: ""(order_LT)"

eval(compare,N4,P4)
="RESULT: ""(order_LT)"

eval(compare,N3,N4)
="RESULT: ""(order_GT)"

eval(compare,N3,N3)
="RESULT: ""(order_EQ)"

eval(compare,N3,N2)
="RESULT: ""(order_LT)"

eval(compare,N3,N1)
="RESULT: ""(order_LT)"

eval(compare,N3,Z)
="RESULT: ""(order_LT)"

eval(compare,N3,P1)
="RESULT: ""(order_LT)"

eval(compare,N3,P2)
="RESULT: ""(order_LT)"

eval(compare,N3,P3)
="RESULT: ""(order_LT)"

eval(compare,N3,P4)
="RESULT: ""(order_LT)"

eval(compare,N2,N4)
="RESULT: ""(order_GT)"

eval(compare,N2,N3)
="RESULT: ""(order_GT)"

eval(compare,N2,N2)
="RESULT: ""(order_EQ)"

eval(compare,N2,N1)
="RESULT: ""(order_LT)"

eval(compare,N2,Z)
="RESULT: ""(order_LT)"

eval(compare,N2,P1)
="RESULT: ""(order_LT)"

eval(compare,N2,P2)
="RESULT: ""(order_LT)"

eval(compare,N2,P3)
="RESULT: ""(order_LT)"

eval(compare,N2,P4)
="RESULT: ""(order_LT)"

eval(compare,N1,N4)
="RESULT: ""(order_GT)"

eval(compare,N1,N3)
="RESULT: ""(order_GT)"

eval(compare,N1,N2)
="RESULT: ""(order_GT)"

eval(compare,N1,N1)
="RESULT: ""(order_EQ)"

eval(compare,N1,Z)
="RESULT: ""(order_LT)"

eval(compare,N1,P1)
="RESULT: ""(order_LT)"

eval(compare,N1,P2)
="RESULT: ""(order_LT)"

eval(compare,N1,P3)
="RESULT: ""(order_LT)"

eval(compare,N1,P4)
="RESULT: ""(order_LT)"

eval(compare,Z,N4)
="RESULT: ""(order_GT)"

eval(compare,Z,N3)
="RESULT: ""(order_GT)"

eval(compare,Z,N2)
="RESULT: ""(order_GT)"

eval(compare,Z,N1)
="RESULT: ""(order_GT)"

eval(compare,Z,Z)
="RESULT: ""(order_EQ)"

eval(compare,Z,P1)
="RESULT: ""(order_LT)"

eval(compare,Z,P2)
="RESULT: ""(order_LT)"

eval(compare,Z,P3)
="RESULT: ""(order_LT)"

eval(compare,Z,P4)
="RESULT: ""(order_LT)"

eval(compare,P1,N4)
="RESULT: ""(order_GT)"

eval(compare,P1,N3)
="RESULT: ""(order_GT)"

eval(compare,P1,N2)
="RESULT: ""(order_GT)"

eval(compare,P1,N1)
="RESULT: ""(order_GT)"

eval(compare,P1,Z)
="RESULT: ""(order_GT)"

eval(compare,P1,P1)
="RESULT: ""(order_EQ)"

eval(compare,P1,P2)
="RESULT: ""(order_LT)"

eval(compare,P1,P3)
="RESULT: ""(order_LT)"

eval(compare,P1,P4)
="RESULT: ""(order_LT)"

eval(compare,P2,N4)
="RESULT: ""(order_GT)"

eval(compare,P2,N3)
="RESULT: ""(order_GT)"

eval(compare,P2,N2)
="RESULT: ""(order_GT)"

eval(compare,P2,N1)
="RESULT: ""(order_GT)"

eval(compare,P2,Z)
="RESULT: ""(order_GT)"

eval(compare,P2,P1)
="RESULT: ""(order_GT)"

eval(compare,P2,P2)
="RESULT: ""(order_EQ)"

eval(compare,P2,P3)
="RESULT: ""(order_LT)"

eval(compare,P2,P4)
="RESULT: ""(order_LT)"

eval(compare,P3,N4)
="RESULT: ""(order_GT)"

eval(compare,P3,N3)
="RESULT: ""(order_GT)"

eval(compare,P3,N2)
="RESULT: ""(order_GT)"

eval(compare,P3,N1)
="RESULT: ""(order_GT)"

eval(compare,P3,Z)
="RESULT: ""(order_GT)"

eval(compare,P3,P1)
="RESULT: ""(order_GT)"

eval(compare,P3,P2)
="RESULT: ""(order_GT)"

eval(compare,P3,P3)
="RESULT: ""(order_EQ)"

eval(compare,P3,P4)
="RESULT: ""(order_LT)"

eval(compare,P4,N4)
="RESULT: ""(order_GT)"

eval(compare,P4,N3)
="RESULT: ""(order_GT)"

eval(compare,P4,N2)
="RESULT: ""(order_GT)"

eval(compare,P4,N1)
="RESULT: ""(order_GT)"

eval(compare,P4,Z)
="RESULT: ""(order_GT)"

eval(compare,P4,P1)
="RESULT: ""(order_GT)"

eval(compare,P4,P2)
="RESULT: ""(order_GT)"

eval(compare,P4,P3)
="RESULT: ""(order_GT)"

eval(compare,P4,P4)
="RESULT: ""(order_EQ)"


  ------ lesser ------

eval(lesser,Z,Z)
="RESULT: ""(bool_False)"

eval(lesser,Z,N1)
="RESULT: ""(bool_False)"

eval(lesser,N1,Z)
="RESULT: ""(bool_True)"


  ------ lesserequal ------

eval(lesserequal,Z,N1)
="RESULT: ""(bool_False)"

eval(lesserequal,Z,Z)
="RESULT: ""(bool_True)"

eval(lesserequal,N1,Z)
="RESULT: ""(bool_True)"


  ------ greaterequal ------

eval(greaterequal,Z,N1)
="RESULT: ""(bool_True)"

eval(greaterequal,Z,Z)
="RESULT: ""(bool_True)"

eval(greaterequal,N1,Z)
="RESULT: ""(bool_False)"


  ------ greater ------

eval(greater,Z,N1)
="RESULT: ""(bool_True)"

eval(greater,Z,Z)
="RESULT: ""(bool_False)"

eval(greater,N1,Z)
="RESULT: ""(bool_False)"


  ------ maximum ------

eval(maximum,Z,N1)
="RESULT: ""(integer_Integer,(P,P)"

eval(maximum,Z,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(maximum,N1,Z)
="RESULT: ""(integer_Integer,(P,P))"


  ------ minimum ------

eval(minimum,Z,N1)
="RESULT: ""(integer_Integer,(N,N))"

eval(minimum,N1,N1)
="RESULT: ""(integer_Integer,(N,N))"

eval(minimum,N1,Z)
="RESULT: ""(integer_Integer,(N,N))"


  ------ add ------

eval(add,N4,N4)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(add,N4,N3)
="RESULT: ""(integer_Integer,(N,1,0,0,N))"

eval(add,N4,N2)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,N4,N1)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,N4,Z)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,N4,P1)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,N4,P2)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,N4,P3)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,N4,P4)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,N3,N4)
="RESULT: ""(integer_Integer,(N,1,0,0,N))"

eval(add,N3,N3)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,N3,N2)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,N3,N1)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,N3,Z)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,N3,P1)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,N3,P2)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,N3,P3)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,N3,P4)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,N2,N4)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,N2,N3)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,N2,N2)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,N2,N1)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,N2,Z)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,N2,P1)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,N2,P2)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,N2,P3)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,N2,P4)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,N1,N4)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,N1,N3)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,N1,N2)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,N1,N1)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,N1,Z)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,N1,P1)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,N1,P2)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,N1,P3)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,N1,P4)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,Z,N4)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,Z,N3)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,Z,N2)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,Z,N1)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,Z,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,Z,P1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,Z,P2)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,Z,P3)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,Z,P4)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,P1,N4)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,P1,N3)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,P1,N2)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,P1,N1)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,P1,Z)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,P1,P1)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,P1,P2)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,P1,P3)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,P1,P4)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,P2,N4)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,P2,N3)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,P2,N2)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,P2,N1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,P2,Z)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,P2,P1)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,P2,P2)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,P2,P3)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,P2,P4)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,P3,N4)
="RESULT: ""(integer_Integer,(N,N))"

eval(add,P3,N3)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,P3,N2)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,P3,N1)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,P3,Z)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,P3,P1)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,P3,P2)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,P3,P3)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,P3,P4)
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(add,P4,N4)
="RESULT: ""(integer_Integer,(P,P))"

eval(add,P4,N3)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,P4,N2)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,P4,N1)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,P4,Z)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,P4,P1)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,P4,P2)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,P4,P3)
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(add,P4,P4)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"


  ------ subtract ------

eval(subtract,N4,N4)
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,N4,N3)
="RESULT: ""(integer_Integer,(N,N))"                             

eval(subtract,N4,N2)
="RESULT: ""(integer_Integer,(N,0,N))"                         

eval(subtract,N4,N1)
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,N4,Z)
="RESULT: ""(integer_Integer,(N,0,0,N))"                     

eval(subtract,N4,P1)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,N4,P2)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,N4,P3)
="RESULT: ""(integer_Integer,(N,1,0,0,N))"                       

eval(subtract,N4,P4)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"                         

eval(subtract,N3,N4)
="RESULT: ""(integer_Integer,(P,1,P))"                           

eval(subtract,N3,N3)
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,N3,N2)
="RESULT: ""(integer_Integer,(N,N))"                           

eval(subtract,N3,N1)
="RESULT: ""(integer_Integer,(N,0,N))"                       

eval(subtract,N3,Z)
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,N3,P1)
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,N3,P2)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                       

eval(subtract,N3,P3)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,N3,P4)
="RESULT: ""(integer_Integer,(N,1,0,0,N))"                         

eval(subtract,N2,N4)
="RESULT: ""(integer_Integer,(P,0,1,P))"                       

eval(subtract,N2,N3)
="RESULT: ""(integer_Integer,(P,1,P))"                         

eval(subtract,N2,N2)
="RESULT: ""(integer_Integer,(P,P))"                         

eval(subtract,N2,N1)
="RESULT: ""(integer_Integer,(N,N))"                       

eval(subtract,N2,Z)
="RESULT: ""(integer_Integer,(N,0,N))"                     

eval(subtract,N2,P1)
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,N2,P2)
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,N2,P3)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,N2,P4)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,N1,N4)
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,N1,N3)
="RESULT: ""(integer_Integer,(P,0,1,P))"                     

eval(subtract,N1,N2)
="RESULT: ""(integer_Integer,(P,1,P))"                     

eval(subtract,N1,N1)
="RESULT: ""(integer_Integer,(P,P))"                     

eval(subtract,N1,Z)
="RESULT: ""(integer_Integer,(N,N))"                     

eval(subtract,N1,P1)
="RESULT: ""(integer_Integer,(N,0,N))"                     

eval(subtract,N1,P2)
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,N1,P3)
="RESULT: ""(integer_Integer,(N,0,0,N))"                     

eval(subtract,N1,P4)
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,Z,N4)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                   

eval(subtract,Z,N3)
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,Z,N2)
="RESULT: ""(integer_Integer,(P,0,1,P))"                   

eval(subtract,Z,N1)
="RESULT: ""(integer_Integer,(P,1,P))"                   

eval(subtract,Z,Z)
="RESULT: ""(integer_Integer,(P,P))"                     

eval(subtract,Z,P1)
="RESULT: ""(integer_Integer,(N,N))"                       

eval(subtract,Z,P2)
="RESULT: ""(integer_Integer,(N,0,N))"                       

eval(subtract,Z,P3)
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,Z,P4)
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,P1,N4)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"                     

eval(subtract,P1,N3)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                     

eval(subtract,P1,N2)
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,P1,N1)
="RESULT: ""(integer_Integer,(P,0,1,P))"                   

eval(subtract,P1,Z)
="RESULT: ""(integer_Integer,(P,1,P))"                     

eval(subtract,P1,P1)
="RESULT: ""(integer_Integer,(P,P))"                         

eval(subtract,P1,P2)
="RESULT: ""(integer_Integer,(N,N))"                           

eval(subtract,P1,P3)
="RESULT: ""(integer_Integer,(N,0,N))"                         

eval(subtract,P1,P4)
="RESULT: ""(integer_Integer,(N,1,0,N))"                         

eval(subtract,P2,N4)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"                       

eval(subtract,P2,N3)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"                       

eval(subtract,P2,N2)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                     

eval(subtract,P2,N1)
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,P2,Z)
="RESULT: ""(integer_Integer,(P,0,1,P))"                     

eval(subtract,P2,P1)
="RESULT: ""(integer_Integer,(P,1,P))"                         

eval(subtract,P2,P2)
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,P2,P3)
="RESULT: ""(integer_Integer,(N,N))"                             

eval(subtract,P2,P4)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(subtract,P3,N4)
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(subtract,P3,N3)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(subtract,P3,N2)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(subtract,P3,N1)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(subtract,P3,Z)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(subtract,P3,P1)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(subtract,P3,P2)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(subtract,P3,P3)
="RESULT: ""(integer_Integer,(P,P))"

eval(subtract,P3,P4)
="RESULT: ""(integer_Integer,(N,N))"

eval(subtract,P4,N4)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(subtract,P4,N3)
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(subtract,P4,N2)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(subtract,P4,N1)
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(subtract,P4,Z)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(subtract,P4,P1)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(subtract,P4,P2)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(subtract,P4,P3)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(subtract,P4,P4)
="RESULT: ""(integer_Integer,(P,P))"


  ------ multiply ------

eval(multiply,N4,N4)
="RESULT: ""(integer_Integer,(P,0,0,0,0,1,P))"

eval(multiply,N4,N3)
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,N4,N2)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,N4,N1)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,N4,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,N4,P1)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,N4,P2)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,N4,P3)
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,N4,P4)
="RESULT: ""(integer_Integer,(N,0,0,0,0,N))"

eval(multiply,N3,N4)
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,N3,N3)
="RESULT: ""(integer_Integer,(P,1,0,0,1,P))"

eval(multiply,N3,N2)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,N3,N1)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,N3,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,N3,P1)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,N3,P2)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,N3,P3)
="RESULT: ""(integer_Integer,(N,1,1,1,0,N))"

eval(multiply,N3,P4)
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,N2,N4)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,N2,N3)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,N2,N2)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,N2,N1)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,N2,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,N2,P1)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,N2,P2)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,N2,P3)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,N2,P4)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,N1,N4)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,N1,N3)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,N1,N2)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,N1,N1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(multiply,N1,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,N1,P1)
="RESULT: ""(integer_Integer,(N,N))"

eval(multiply,N1,P2)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,N1,P3)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,N1,P4)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,Z,N4)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,N3)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,N2)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,N1)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,P1)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,P2)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,P3)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,Z,P4)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,P1,N4)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,P1,N3)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,P1,N2)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,P1,N1)
="RESULT: ""(integer_Integer,(N,N))"

eval(multiply,P1,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,P1,P1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(multiply,P1,P2)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,P1,P3)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,P1,P4)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,P2,N4)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,P2,N3)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,P2,N2)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,P2,N1)
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,P2,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,P2,P1)
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,P2,P2)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,P2,P3)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,P2,P4)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,P3,N4)
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,P3,N3)
="RESULT: ""(integer_Integer,(N,1,1,1,0,N))"

eval(multiply,P3,N2)
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,P3,N1)
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,P3,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,P3,P1)
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,P3,P2)
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,P3,P3)
="RESULT: ""(integer_Integer,(P,1,0,0,1,P))"

eval(multiply,P3,P4)
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,P4,N4)
="RESULT: ""(integer_Integer,(N,0,0,0,0,N))"

eval(multiply,P4,N3)
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,P4,N2)
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,P4,N1)
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,P4,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,P4,P1)
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,P4,P2)
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,P4,P3)
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,P4,P4)
="RESULT: ""(integer_Integer,(P,0,0,0,0,1,P))"


  ------ absolute ------

eval(absolute,N1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(absolute,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(absolute,P1)
="RESULT: ""(integer_Integer,(P,1,P))"


  ------ sign ------

eval(sign,N3)
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,N2)
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,N1)
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(sign,P1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(sign,P2)
="RESULT: ""(integer_Integer,(P,1,P))"


  ------ negate ------

eval(negate,N1)
="RESULT: ""(integer_Integer,(P,1,P))"

eval(negate,Z)
="RESULT: ""(integer_Integer,(P,P))"

eval(negate,P1)
="RESULT: ""(integer_Integer,(N,N))"


  ------ quotientRemainder ------

eval(quotientRemainder,N4,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N4,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N4,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N4,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N4,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,N4,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N4,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N4,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N4,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N3,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,1,0,N)))"

eval(quotientRemainder,N3,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N3,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N3,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N3,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,N3,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N3,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N3,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N3,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,1,0,N)))"

eval(quotientRemainder,N2,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,N2,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,N2,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,N2,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,N2,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,N1,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N1,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N1,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N1,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,N1,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N1,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N1,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,N1,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,Z,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,Z,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,Z,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P1,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P1,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P1,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P1,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,P1,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P1,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P1,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P1,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P2,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,P2,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,P2,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P2,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,P2,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P2,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P2,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,P2,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,P3,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,1,P)))"

eval(quotientRemainder,P3,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P3,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P3,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,P3,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P3,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P3,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P3,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,1,P)))"

eval(quotientRemainder,P4,N4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P4,N3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P4,N2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P4,N1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,N2,Z)
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,P4,P1)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P4,P2)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,P4,P3)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,P4,P4)
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"
