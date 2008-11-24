#include "../Integer.h"


//#undef RECURSE_DEBUG
//#define RECURSE_DEBUG (0,0,0,7)

  ------ equal ------

eval(equal,(Integer,(N,0,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,1,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(N,0,N)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(N,0,N)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(N,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(P,P)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(P,1,P)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(P,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_True)"

eval(equal,(Integer,(P,1,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(bool_False)"

eval(equal,(Integer,(P,0,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(bool_True)"


  ------ compare ------

eval(compare,(Integer,(N,0,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(N,0,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(N,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(P,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(P,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(N,0,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(N,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(P,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(P,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,1,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,0,N)),(Integer,(N,0,N)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(N,0,N)),(Integer,(N,N)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(P,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(P,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,N)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,N)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,N)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,N)),(Integer,(P,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,N)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,N)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(N,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,P)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,P)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,P)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(P,P)),(Integer,(P,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,P)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,P)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,P)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,P)),(Integer,(N,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,P)),(Integer,(P,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,P)),(Integer,(P,1,P)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(P,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(N,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(P,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(N,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(P,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(P,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(order_EQ)"

eval(compare,(Integer,(P,1,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_LT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(N,N)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(P,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(order_GT)"

eval(compare,(Integer,(P,0,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(order_EQ)"


  ------ lesser ------

eval(lesser,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(lesser,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(lesser,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(bool_True)"


  ------ lesserequal ------

eval(lesserequal,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(bool_False)"

eval(lesserequal,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(bool_True)"

eval(lesserequal,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(bool_True)"


  ------ greaterequal ------

eval(greaterequal,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(bool_True)"

eval(greaterequal,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(bool_True)"

eval(greaterequal,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"


  ------ greater ------

eval(greater,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(bool_True)"

eval(greater,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(bool_False)"

eval(greater,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(bool_False)"


  ------ maximum ------

eval(maximum,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,P)"

eval(maximum,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(maximum,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"


  ------ minimum ------

eval(minimum,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(minimum,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(minimum,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,N))"


  ------ add ------

eval(add,(Integer,(N,0,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(N,0,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(N,1,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(N,1,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(N,1,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(N,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(add,(Integer,(N,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,(Integer,(N,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,(Integer,(N,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(N,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(N,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(N,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(N,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(N,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(N,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"

eval(add,(Integer,(N,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,(Integer,(N,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(N,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(N,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(N,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(N,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(add,(Integer,(P,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(P,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(P,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(P,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(P,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,(Integer,(P,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(add,(Integer,(P,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(P,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(P,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(P,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(P,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(P,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,(Integer,(P,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(add,(Integer,(P,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(P,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,(Integer,(P,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(add,(Integer,(P,1,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,(Integer,(P,1,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(add,(Integer,(P,0,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"


  ------ subtract ------

eval(subtract,(Integer,(N,0,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,(Integer,(N,0,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,N))"                             

eval(subtract,(Integer,(N,0,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,N))"                         

eval(subtract,(Integer,(N,0,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,(Integer,(N,0,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"                     

eval(subtract,(Integer,(N,0,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,(Integer,(N,0,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,(Integer,(N,0,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,0,N))"                       

eval(subtract,(Integer,(N,0,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"                         

eval(subtract,(Integer,(N,1,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,1,P))"                           

eval(subtract,(Integer,(N,1,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,(Integer,(N,1,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,N))"                           

eval(subtract,(Integer,(N,1,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,0,N))"                       

eval(subtract,(Integer,(N,1,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,(Integer,(N,1,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,(Integer,(N,1,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                       

eval(subtract,(Integer,(N,1,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,(Integer,(N,1,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,0,N))"                         

eval(subtract,(Integer,(N,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"                       

eval(subtract,(Integer,(N,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,P))"                         

eval(subtract,(Integer,(N,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,P))"                         

eval(subtract,(Integer,(N,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"                       

eval(subtract,(Integer,(N,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,0,N))"                     

eval(subtract,(Integer,(N,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,(Integer,(N,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,(Integer,(N,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,(Integer,(N,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"                       

eval(subtract,(Integer,(N,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,(Integer,(N,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"                     

eval(subtract,(Integer,(N,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,1,P))"                     

eval(subtract,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,P))"                     

eval(subtract,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(N,N))"                     

eval(subtract,(Integer,(N,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"                     

eval(subtract,(Integer,(N,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,(Integer,(N,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"                     

eval(subtract,(Integer,(N,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,1,1,0,N))"                     

eval(subtract,(Integer,(P,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                   

eval(subtract,(Integer,(P,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,(Integer,(P,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"                   

eval(subtract,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,P))"                   

eval(subtract,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"                     

eval(subtract,(Integer,(P,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,N))"                       

eval(subtract,(Integer,(P,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"                       

eval(subtract,(Integer,(P,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                     

eval(subtract,(Integer,(P,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"                       

eval(subtract,(Integer,(P,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"                     

eval(subtract,(Integer,(P,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                     

eval(subtract,(Integer,(P,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,(Integer,(P,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"                   

eval(subtract,(Integer,(P,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,1,P))"                     

eval(subtract,(Integer,(P,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,P))"                         

eval(subtract,(Integer,(P,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,N))"                           

eval(subtract,(Integer,(P,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"                         

eval(subtract,(Integer,(P,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"                         

eval(subtract,(Integer,(P,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"                       

eval(subtract,(Integer,(P,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"                       

eval(subtract,(Integer,(P,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"                     

eval(subtract,(Integer,(P,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"                     

eval(subtract,(Integer,(P,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"                     

eval(subtract,(Integer,(P,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"                         

eval(subtract,(Integer,(P,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"                             

eval(subtract,(Integer,(P,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,N))"                             

eval(subtract,(Integer,(P,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(subtract,(Integer,(P,1,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,0,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(subtract,(Integer,(P,0,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"


  ------ multiply ------

eval(multiply,(Integer,(N,0,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,0,0,1,P))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,(Integer,(N,0,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,0,0,N))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,0,0,1,P))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,1,1,1,0,N))"

eval(multiply,(Integer,(N,1,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,(Integer,(N,0,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,(Integer,(N,0,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,(Integer,(N,0,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(N,0,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,(Integer,(N,0,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(N,0,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,(Integer,(N,0,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(N,0,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,(Integer,(N,0,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,(Integer,(N,N)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(N,N)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,(Integer,(N,N)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,(Integer,(N,N)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(multiply,(Integer,(N,N)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(N,N)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,N))"

eval(multiply,(Integer,(N,N)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,(Integer,(N,N)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,(Integer,(N,N)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(P,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(P,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,(Integer,(P,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,(Integer,(P,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(multiply,(Integer,(P,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(multiply,(Integer,(P,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,(Integer,(P,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,(Integer,(P,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,0,N))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,P))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,(Integer,(P,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,1,1,1,0,N))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,1,0,N))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,1,0,N))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,1,P))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,1,1,P))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,1,0,0,1,P))"

eval(multiply,(Integer,(P,1,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(N,0,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,0,0,N))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,1,0,N))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,0,0,0,N))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,0,0,N))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,P))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,0,1,P))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(P,1,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,1,1,P))"

eval(multiply,(Integer,(P,0,0,1,P)),(Integer,(P,0,0,1,P)))
="RESULT: ""(integer_Integer,(P,0,0,0,0,1,P))"


  ------ absolute ------

eval(absolute,(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(absolute,(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(absolute,(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"


  ------ sign ------

eval(sign,(Integer,(N,1,0,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,(Integer,(N,0,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,(Integer,(N,N)))
="RESULT: ""(integer_Integer,(N,N))"

eval(sign,(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(sign,(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(sign,(Integer,(P,0,1,P)))
="RESULT: ""(integer_Integer,(P,1,P))"


  ------ negate ------

eval(negate,(Integer,(N,N)))
="RESULT: ""(integer_Integer,(P,1,P))"

eval(negate,(Integer,(P,P)))
="RESULT: ""(integer_Integer,(P,P))"

eval(negate,(Integer,(P,1,P)))
="RESULT: ""(integer_Integer,(N,N))"


  ------ quotientRemainder ------

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,1,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,1,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(N,N)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(N,N)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,P)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,P)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,0,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,1,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,1,1,P)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,P)),(integer_Integer,(P,1,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(N,0,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(N,1,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,N)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(N,0,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(N,N)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(N,0,0,N)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(N,0,N)),(integer_Integer,(P,P)))
="ERROR: ""\"integer_quotientRemainder_: division by zero\""

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,0,1,P)),(integer_Integer,(P,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,1,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,1,P)))"

eval(quotientRemainder,(integer_Integer,(P,0,0,1,P)),(integer_Integer,(P,0,0,1,P)))
="RESULT: ""(tupple_Tupple2,(integer_Integer,(P,1,P)),(integer_Integer,(P,P)))"
