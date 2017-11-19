#include "../Integer.h"
#include "../Tuple.h"
#include "../List.h"
#include "../Equal.h"
#include "../Order.h"


// The following code computes two lists
//
//   primes :: [Integer]               -- infinite list of prime numbers
//   goldbaches :: [(Integer,Integer)] -- infinite list of primes summing to even numbers
//
// The equivalent Haskell code is show in comments above and units test are included below.
//
//  - whether x is prime or not is determined by test dividing by all 2..x/2.
//  - the goldbach numbers for 2*x are determined by subtracting all primes in x..1 and
//    checking to see if the resulting number if prime in x..2*x
//
// For the later, should a solution not be found in x..1, an exception is generated with
// the number that disproves Goldbach's conjecture (all even numbers are the sum of two primes).


// from :: Integer -> [Integer]
// from !x = x : from (x+1)
//
// take 7 (from 2): [2,3,4,5,6,7,8]
#define _from(x,...) reduce1(from0,x,__VA_ARGS__)
#define _from0(x,...) construct((Cons,x,(from,(add,x,P1))),__VA_ARGS__)

 eval(take,P7,(from,P2))
={0x2,0x3,0x4,0x5,0x6,0x7,0x8}


// fromTo :: Integer -> Integer -> [Integer]
// fromTo !x !y = case x <= y of
//   True  -> x : fromTo (x+1) y
//   False -> []
//
// fromTo 3 7: [3,4,5,6,7]
#define _fromTo( x,y,...) reduce2(fromTo0,x,y,__VA_ARGS__)
#define _fromTo0(x,y,...) caseReduce1(fromTo0,(lesserequal,x,y),x,y,__VA_ARGS__)
#define _fromTo0_bool_True( x,y,...) construct((Cons,x,(fromTo,(add,x,P1),y)),__VA_ARGS__)
#define _fromTo0_bool_False(x,y,...) construct((Nil),__VA_ARGS__)

 eval(fromTo,P3,P7)
={0x3,0x4,0x5,0x6,0x7}


// test2 :: Integer -> Integer -> Bool
// test2 x y = (x `rem` y) /= 0
//
// test2 6 3: True
// test2 7 3: False
#define _test2(x,y,...) reduce(notequal,(second,(quotientRemainder,x,y)),Z,__VA_ARGS__)

 eval(test2,P6,P3)
=bool_False
 eval(test2,P7,P3)
=bool_True
 eval(test2,P9,P3)
=bool_False


// test1 :: Integer -> Bool
// test1 !x = all (test2 x) (fromTo 2 (x `quot` 2))
//
// test1 1: True
// test1 3: True
// test1 4: False
// test1 9: False
#define _test1( x,...) reduce1(test10,x,__VA_ARGS__)
#define _test10(x,...) reduce(all,(test2,x),(fromTo,P2,(first,(quotientRemainder,x,P2))),__VA_ARGS__)

 eval(test1,P1)
=bool_True
 eval(test1,P3)
=bool_True
 eval(test1,P4)
=bool_False
 eval(test1,P9)
=bool_False


// primes :: [Integer]
// primes = filter test1 (from 1)
//
// take 7 primes: [1,2,3,5,7,11,13]
#define primes (filter,(test1),(from,P1))

 eval(take,P5,primes)
={0x1,0x2,0x3,0x5,0x7}


// sieve :: Integer -> [Integer] -> [Integer] -> (Integer,Integer)
// sieve x []     _      = error ( show x )
// sieve x (y:ys) (p:ps) =
//   case compare (y+p) (2*x) of
//     EQ -> (y,p)
//     GT -> sieve x    ys  (p:ps)
//     LT -> sieve x (y:ys)    ps
//
// sieve 6 [5,3,2,1] [5,7,11,13,error "shouldn't require this"]: (5,7)
#define _sieve(x,ys,ps,...) caseReduce2(sieve0,ys,ps,x,__VA_ARGS__)
#define _sieve0_list_Cons_list_Cons(         y,ys,p,ps,x,...) caseReduce1(sieve0_list_Cons_list_Cons,(compare,(add,y,p),(multiply,P2,x)),y,ys,p,ps,x,__VA_ARGS__)
#define _sieve0_list_Cons_list_Cons_order_EQ(y,ys,p,ps,x,...) construct((Tuple2,y,p),__VA_ARGS__)
#define _sieve0_list_Cons_list_Cons_order_GT(y,ys,p,ps,x,...) reduce(sieve,x,        ys ,(Cons,p,ps),__VA_ARGS__)
#define _sieve0_list_Cons_list_Cons_order_LT(y,ys,p,ps,x,...) reduce(sieve,x,(Cons,y,ys),        ps ,__VA_ARGS__)
#define _sieve0_list_Nil_list_Cons(               p,ps,x,...) eval(show,x)

 eval(sieve,P6,L4(P5,P3,P2,P1),L5(P5,P7,P11,P13,(error,"shouldn't require this")))
=(0x5,0x7)


// shift :: Integer -> [Integer] -> [Integer] -> ([Integer],[Integer])
// shift x ys (p:ps) =
//   case p < x of
//     True  -> shift x (p:ys) ps
//     False -> (p:ys,p:ps)
//
// shift 7 [3,2,1] [5,7,11,error "shouldn't require this"]: ([7,5,3,2,1],[7,11,error "shouldn't require this"])
#define _shift(x,ys,ps,...) caseReduce1(shift,ps,x,ys,__VA_ARGS__)
#define _shift_list_Cons(           p,ps,x,ys,...) caseReduce1(shift_list_Cons,(lesser,p,x),p,ps,x,ys,__VA_ARGS__)
#define _shift_list_Cons_bool_True( p,ps,x,ys,...) reduce(shift,x,(Cons,p,ys),ps,__VA_ARGS__)
#define _shift_list_Cons_bool_False(p,ps,x,ys,...) construct((Tuple2,(Cons,p,ys),(Cons,p,ps)),__VA_ARGS__)

 eval(shift,P7,L3(P3,P2,P1),L3(P5,P7,P11))
=({0x7,0x5,0x3,0x2,0x1},{0x7,0xb})


// loop1 :: Integer -> [Integer] -> [Integer] -> [(Integer,Integer)]
// loop1 x ys ps = sieve x ys ps : loop0 (x+1) (tail ys) ps
//
// loop0 :: Integer -> [Integer] -> [Integer] -> [(Integer,Integer)]
// loop0 x ys ps = uncurry (loop1 x) (shift x ys ps)
//
// goldbachs :: [(Integer,Integer)]
// goldbachs = loop0 1 [] prime
//
// take 8 goldbachs: [(1,1),(2,2),(3,3),(3,5),(5,5),(5,7),(7,7),(5,11)]
#define _loop1(x,ys,ps,...) construct((Cons,(sieve,x,ys,ps),(loop0,(add,x,P1),(tail,ys),ps)),__VA_ARGS__)

#define _loop0(x,ys,ps,...) reduce(uncurry,(loop1,x),(shift,x,ys,ps),__VA_ARGS__)

#define goldbachs (loop0,P1,(Nil),primes)

 eval(take,P8,goldbachs)
={(0x1,0x1),(0x2,0x2),(0x3,0x3),(0x3,0x5),(0x5,0x5),(0x5,0x7),(0x7,0x7),(0x5,0xb)}
