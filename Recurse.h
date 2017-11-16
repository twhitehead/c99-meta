//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef RECURSE_H_INCLUDED
#define RECURSE_H_INCLUDED

// There is a problem.  Each macro is disabled during its own expansion to
// prevent recursion.  We need recursion though, and it is just lame to have to
// provide hundreds of slightly different named versions of each macro in order
// to simulate it.  Instead, we provide one set of recursion simulating macros
// (through incrementing a prefix) and all other macros expand inside them and
// return directions on what to do next (i.e., recurse or output with the name
// of a continuation macro and argument list or quit).
//
// This still leaves the problem of repeating our recursion simulator hundreds
// (ideally thousands) of times.  We circuvent the worst part of this by
// nesting several such simulated recursers.  Nesting a recurse that supports
// M recursions N times, gives M^N recursions in c*M*N lines of code, where
// c is the number of macros required to support on recursion.
//
// For any given M^N, it is not difficult to show the minimum c*M*N occurs when
// M = e.  The best integer choice is M = 3 followed by M = 2 or M = 4 (at
// about five percent worse).  We use M = 4 as it is both a power of two and
// increases the work done in the inner loop.  As our c = 6, we can achieve
// 65536 recursions with only 192 lines of code, or, to demonstrate how this
// scales, 18446744073709551616 recursions with 768 lines of code.  This limit
// is a non-issue as the sun will burn out before it is reached.
//
// A subtle detail in each recurser is that they must necessarily add a leading
// underscore (or some such thing) when invoking continuations in order not to
// corrupt futher other references to the same continuation.  That is, given
//
//   #define x(y)  x(y+1)
//   #define u(v)  x(1) u_(v)
//   #define u_(v) v
//
// the expansion of u(x(1)) is u(x(1)) -> u(x(1+1)) -> x(1) u_(x(1+1)) ->
// x(1+1) x(1+1).  However, 
// 
//   #define _x(y) x(y+1)
//   #define u(v)  _x(1) u_(v)
//   #define u_(v) _##v
//
// expands u(_x(1)) to x(1+1) x(1+1+1).  Evidently, macros return something
// more than just plain tex, something that prevents further expansion of
// macros that were non-expandable at the time of their creation, and something
// we can get around by using the ## operator to alter the returned text.


#define _recurse_expand(...)  __VA_ARGS__
#define _recurse_first(x,...) x
#define _recurse_rest(x,...)  (__VA_ARGS__)

#define _recurse_apply(f,...) _##f(__VA_ARGS__)


#define _recurse_dMask0(d,...)   _recurse_dMask0_##d(__VA_ARGS__)
#define _recurse_dMask0_(d,...)  (,__VA_ARGS__)
#define _recurse_dMask0_0(d,...) (d,__VA_ARGS__)
#define _recurse_dMask0_1(d,...) (,__VA_ARGS__)
#define _recurse_dMask0_2(d,...) (,__VA_ARGS__)
#define _recurse_dMask0_3(d,...) (,__VA_ARGS__)
#define _recurse_dMask1(d,...)   _recurse_dMask1_##d(__VA_ARGS__)
#define _recurse_dMask1_(d,...)  (,__VA_ARGS__)
#define _recurse_dMask1_0(d,...) (,__VA_ARGS__)
#define _recurse_dMask1_1(d,...) (d,__VA_ARGS__)
#define _recurse_dMask1_2(d,...) (,__VA_ARGS__)
#define _recurse_dMask1_3(d,...) (,__VA_ARGS__)
#define _recurse_dMask2(d,...)   _recurse_dMask2_##d(__VA_ARGS__)
#define _recurse_dMask2_(d,...)  (,__VA_ARGS__)
#define _recurse_dMask2_0(d,...) (,__VA_ARGS__)
#define _recurse_dMask2_1(d,...) (,__VA_ARGS__)
#define _recurse_dMask2_2(d,...) (d,__VA_ARGS__)
#define _recurse_dMask2_3(d,...) (,__VA_ARGS__)
#define _recurse_dMask3(d,...)   _recurse_dMask3_##d(__VA_ARGS__)
#define _recurse_dMask3_(d,...)  (,__VA_ARGS__)
#define _recurse_dMask3_0(d,...) (,__VA_ARGS__)
#define _recurse_dMask3_1(d,...) (,__VA_ARGS__)
#define _recurse_dMask3_2(d,...) (,__VA_ARGS__)
#define _recurse_dMask3_3(d,...) (d,__VA_ARGS__)

#define _recurse_dBuild(x3,x2,x1,x0) (_recurse_dBuild_##x3,_recurse_dBuild_##x2,_recurse_dBuild_##x1,_recurse_dBuild_##x0)
#define _recurse_dBuild_  ,
#define _recurse_dBuild_0 0,0
#define _recurse_dBuild_1 0,1
#define _recurse_dBuild_2 0,2
#define _recurse_dBuild_3 0,3
#define _recurse_dBuild_4 1,0
#define _recurse_dBuild_5 1,1
#define _recurse_dBuild_6 1,2
#define _recurse_dBuild_7 1,3
#define _recurse_dBuild_8 2,0
#define _recurse_dBuild_9 2,1
#define _recurse_dBuild_a 2,2
#define _recurse_dBuild_b 2,3
#define _recurse_dBuild_c 3,0
#define _recurse_dBuild_d 3,1
#define _recurse_dBuild_e 3,2
#define _recurse_dBuild_f 3,3

#define recurse_recurse(...)     _recurse_recurse0(RECURSE_DEBUG,(),(__VA_ARGS__))
#define _recurse_recurse0(d,o,f) _recurse_00(_recurse_dBuild d,o,f)

#define _recurse_00(d,o,f)             _recurse_000(d,o,_recurse_10(_recurse_dMask0 d,(),f))
#define _recurse_01(d,o,f)             _recurse_010(d,o,_recurse_10(_recurse_dMask1 d,(),f))
#define _recurse_02(d,o,f)             _recurse_020(d,o,_recurse_10(_recurse_dMask2 d,(),f))
#define _recurse_03(d,o,f)             _recurse_030(d,o,_recurse_10(_recurse_dMask3 d,(),f))
#define _recurse_000(...)              _recurse_001(__VA_ARGS__)
#define _recurse_010(...)              _recurse_011(__VA_ARGS__)
#define _recurse_020(...)              _recurse_021(__VA_ARGS__)
#define _recurse_030(...)              _recurse_031(__VA_ARGS__)
#define _recurse_001(d,o,c,...)        _recurse_00_##c(d,o,__VA_ARGS__)
#define _recurse_011(d,o,c,...)        _recurse_01_##c(d,o,__VA_ARGS__)
#define _recurse_021(d,o,c,...)        _recurse_02_##c(d,o,__VA_ARGS__)
#define _recurse_031(d,o,c,...)        _recurse_03_##c(d,o,__VA_ARGS__)
#define _recurse_00_Recurse(d,o0,o1,f) _recurse_01(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_01_Recurse(d,o0,o1,f) _recurse_02(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_02_Recurse(d,o0,o1,f) _recurse_03(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_03_Recurse(d,o0,o1,f) _recurse_expand o0 _recurse_expand o1 "ERROR: reached maximum recursion depth: "#f
#define _recurse_00_Output(d,o0,o1,f)  _recurse_01(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_01_Output(d,o0,o1,f)  _recurse_02(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_02_Output(d,o0,o1,f)  _recurse_03(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_03_Output(d,o0,o1,f)  _recurse_expand o0 _recurse_expand o1 "ERROR: reached maximum recursion depth: "#f
#define _recurse_00_Quit(d,o0,o1)      _recurse_expand o0 _recurse_expand o1
#define _recurse_01_Quit(d,o0,o1)      _recurse_expand o0 _recurse_expand o1
#define _recurse_02_Quit(d,o0,o1)      _recurse_expand o0 _recurse_expand o1
#define _recurse_03_Quit(d,o0,o1)      _recurse_expand o0 _recurse_expand o1

#define _recurse_10(d,o,f)             _recurse_100(d,o,_recurse_20(_recurse_dMask0 d,(),f))
#define _recurse_11(d,o,f)             _recurse_110(d,o,_recurse_20(_recurse_dMask1 d,(),f))
#define _recurse_12(d,o,f)             _recurse_120(d,o,_recurse_20(_recurse_dMask2 d,(),f))
#define _recurse_13(d,o,f)             _recurse_130(d,o,_recurse_20(_recurse_dMask3 d,(),f))
#define _recurse_100(...)              _recurse_101(__VA_ARGS__)
#define _recurse_110(...)              _recurse_111(__VA_ARGS__)
#define _recurse_120(...)              _recurse_121(__VA_ARGS__)
#define _recurse_130(...)              _recurse_131(__VA_ARGS__)
#define _recurse_101(d,o,c,...)        _recurse_10_##c(d,o,__VA_ARGS__)
#define _recurse_111(d,o,c,...)        _recurse_11_##c(d,o,__VA_ARGS__)
#define _recurse_121(d,o,c,...)        _recurse_12_##c(d,o,__VA_ARGS__)
#define _recurse_131(d,o,c,...)        _recurse_13_##c(d,o,__VA_ARGS__)
#define _recurse_10_Recurse(d,o0,o1,f) _recurse_11(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_11_Recurse(d,o0,o1,f) _recurse_12(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_12_Recurse(d,o0,o1,f) _recurse_13(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_13_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_10_Output(d,o0,o1,f)  _recurse_11(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_11_Output(d,o0,o1,f)  _recurse_12(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_12_Output(d,o0,o1,f)  _recurse_13(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_13_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_10_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_11_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_12_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_13_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_20(d,o,f)             _recurse_200(d,o,_recurse_30(_recurse_dMask0 d,(),f))
#define _recurse_21(d,o,f)             _recurse_210(d,o,_recurse_30(_recurse_dMask1 d,(),f))
#define _recurse_22(d,o,f)             _recurse_220(d,o,_recurse_30(_recurse_dMask2 d,(),f))
#define _recurse_23(d,o,f)             _recurse_230(d,o,_recurse_30(_recurse_dMask3 d,(),f))
#define _recurse_200(...)              _recurse_201(__VA_ARGS__)
#define _recurse_210(...)              _recurse_211(__VA_ARGS__)
#define _recurse_220(...)              _recurse_221(__VA_ARGS__)
#define _recurse_230(...)              _recurse_231(__VA_ARGS__)
#define _recurse_201(d,o,c,...)        _recurse_20_##c(d,o,__VA_ARGS__)
#define _recurse_211(d,o,c,...)        _recurse_21_##c(d,o,__VA_ARGS__)
#define _recurse_221(d,o,c,...)        _recurse_22_##c(d,o,__VA_ARGS__)
#define _recurse_231(d,o,c,...)        _recurse_23_##c(d,o,__VA_ARGS__)
#define _recurse_20_Recurse(d,o0,o1,f) _recurse_21(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_21_Recurse(d,o0,o1,f) _recurse_22(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_22_Recurse(d,o0,o1,f) _recurse_23(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_23_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_20_Output(d,o0,o1,f)  _recurse_21(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_21_Output(d,o0,o1,f)  _recurse_22(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_22_Output(d,o0,o1,f)  _recurse_23(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_23_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_20_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_21_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_22_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_23_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_30(d,o,f)             _recurse_300(d,o,_recurse_40(_recurse_dMask0 d,(),f))
#define _recurse_31(d,o,f)             _recurse_310(d,o,_recurse_40(_recurse_dMask1 d,(),f))
#define _recurse_32(d,o,f)             _recurse_320(d,o,_recurse_40(_recurse_dMask2 d,(),f))
#define _recurse_33(d,o,f)             _recurse_330(d,o,_recurse_40(_recurse_dMask3 d,(),f))
#define _recurse_300(...)              _recurse_301(__VA_ARGS__)
#define _recurse_310(...)              _recurse_311(__VA_ARGS__)
#define _recurse_320(...)              _recurse_321(__VA_ARGS__)
#define _recurse_330(...)              _recurse_331(__VA_ARGS__)
#define _recurse_301(d,o,c,...)        _recurse_30_##c(d,o,__VA_ARGS__)
#define _recurse_311(d,o,c,...)        _recurse_31_##c(d,o,__VA_ARGS__)
#define _recurse_321(d,o,c,...)        _recurse_32_##c(d,o,__VA_ARGS__)
#define _recurse_331(d,o,c,...)        _recurse_33_##c(d,o,__VA_ARGS__)
#define _recurse_30_Recurse(d,o0,o1,f) _recurse_31(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_31_Recurse(d,o0,o1,f) _recurse_32(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_32_Recurse(d,o0,o1,f) _recurse_33(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_33_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_30_Output(d,o0,o1,f)  _recurse_31(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_31_Output(d,o0,o1,f)  _recurse_32(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_32_Output(d,o0,o1,f)  _recurse_33(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_33_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_30_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_31_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_32_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_33_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_40(d,o,f)             _recurse_400(d,o,_recurse_50(_recurse_dMask0 d,(),f))
#define _recurse_41(d,o,f)             _recurse_410(d,o,_recurse_50(_recurse_dMask1 d,(),f))
#define _recurse_42(d,o,f)             _recurse_420(d,o,_recurse_50(_recurse_dMask2 d,(),f))
#define _recurse_43(d,o,f)             _recurse_430(d,o,_recurse_50(_recurse_dMask3 d,(),f))
#define _recurse_400(...)              _recurse_401(__VA_ARGS__)
#define _recurse_410(...)              _recurse_411(__VA_ARGS__)
#define _recurse_420(...)              _recurse_421(__VA_ARGS__)
#define _recurse_430(...)              _recurse_431(__VA_ARGS__)
#define _recurse_401(d,o,c,...)        _recurse_40_##c(d,o,__VA_ARGS__)
#define _recurse_411(d,o,c,...)        _recurse_41_##c(d,o,__VA_ARGS__)
#define _recurse_421(d,o,c,...)        _recurse_42_##c(d,o,__VA_ARGS__)
#define _recurse_431(d,o,c,...)        _recurse_43_##c(d,o,__VA_ARGS__)
#define _recurse_40_Recurse(d,o0,o1,f) _recurse_41(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_41_Recurse(d,o0,o1,f) _recurse_42(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_42_Recurse(d,o0,o1,f) _recurse_43(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_43_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_40_Output(d,o0,o1,f)  _recurse_41(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_41_Output(d,o0,o1,f)  _recurse_42(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_42_Output(d,o0,o1,f)  _recurse_43(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_43_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_40_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_41_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_42_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_43_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_50(d,o,f)             _recurse_500(d,o,_recurse_60(_recurse_dMask0 d,(),f))
#define _recurse_51(d,o,f)             _recurse_510(d,o,_recurse_60(_recurse_dMask1 d,(),f))
#define _recurse_52(d,o,f)             _recurse_520(d,o,_recurse_60(_recurse_dMask2 d,(),f))
#define _recurse_53(d,o,f)             _recurse_530(d,o,_recurse_60(_recurse_dMask3 d,(),f))
#define _recurse_500(...)              _recurse_501(__VA_ARGS__)
#define _recurse_510(...)              _recurse_511(__VA_ARGS__)
#define _recurse_520(...)              _recurse_521(__VA_ARGS__)
#define _recurse_530(...)              _recurse_531(__VA_ARGS__)
#define _recurse_501(d,o,c,...)        _recurse_50_##c(d,o,__VA_ARGS__)
#define _recurse_511(d,o,c,...)        _recurse_51_##c(d,o,__VA_ARGS__)
#define _recurse_521(d,o,c,...)        _recurse_52_##c(d,o,__VA_ARGS__)
#define _recurse_531(d,o,c,...)        _recurse_53_##c(d,o,__VA_ARGS__)
#define _recurse_50_Recurse(d,o0,o1,f) _recurse_51(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_51_Recurse(d,o0,o1,f) _recurse_52(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_52_Recurse(d,o0,o1,f) _recurse_53(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_53_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_50_Output(d,o0,o1,f)  _recurse_51(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_51_Output(d,o0,o1,f)  _recurse_52(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_52_Output(d,o0,o1,f)  _recurse_53(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_53_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_50_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_51_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_52_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_53_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_60(d,o,f)             _recurse_600(d,o,_recurse_7(_recurse_dMask0 d,(),f))
#define _recurse_61(d,o,f)             _recurse_610(d,o,_recurse_7(_recurse_dMask1 d,(),f))
#define _recurse_62(d,o,f)             _recurse_620(d,o,_recurse_7(_recurse_dMask2 d,(),f))
#define _recurse_63(d,o,f)             _recurse_630(d,o,_recurse_7(_recurse_dMask3 d,(),f))
#define _recurse_600(...)              _recurse_601(__VA_ARGS__)
#define _recurse_610(...)              _recurse_611(__VA_ARGS__)
#define _recurse_620(...)              _recurse_621(__VA_ARGS__)
#define _recurse_630(...)              _recurse_631(__VA_ARGS__)
#define _recurse_601(d,o,c,...)        _recurse_60_##c(d,o,__VA_ARGS__)
#define _recurse_611(d,o,c,...)        _recurse_61_##c(d,o,__VA_ARGS__)
#define _recurse_621(d,o,c,...)        _recurse_62_##c(d,o,__VA_ARGS__)
#define _recurse_631(d,o,c,...)        _recurse_63_##c(d,o,__VA_ARGS__)
#define _recurse_60_Recurse(d,o0,o1,f) _recurse_61(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_61_Recurse(d,o0,o1,f) _recurse_62(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_62_Recurse(d,o0,o1,f) _recurse_63(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_63_Recurse(d,o0,o1,f) Recurse,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_60_Output(d,o0,o1,f)  _recurse_61(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_61_Output(d,o0,o1,f)  _recurse_62(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_62_Output(d,o0,o1,f)  _recurse_63(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_63_Output(d,o0,o1,f)  Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_60_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_61_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_62_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_63_Quit(d,o0,o1)      Quit,(_recurse_expand o0 _recurse_expand o1)

#define _recurse_7(d,o,f)             _recurse_70(_recurse_first d,o,f)
#define _recurse_70(d,o,f)            _recurse_700(d,o,_recurse_apply f)
#define _recurse_71(d,o,f)            _recurse_710(d,o,_recurse_apply f)
#define _recurse_72(d,o,f)            _recurse_720(d,o,_recurse_apply f)
#define _recurse_73(d,o,f)            _recurse_730(d,o,_recurse_apply f)
#define _recurse_700(d,...)           _recurse_701_##d(d,__VA_ARGS__)
#define _recurse_710(d,...)           _recurse_711_##d(d,__VA_ARGS__)
#define _recurse_720(d,...)           _recurse_721_##d(d,__VA_ARGS__)
#define _recurse_730(d,...)           _recurse_731_##d(d,__VA_ARGS__)
#define _recurse_701_(d,o,c,...)      _recurse_70_##c(d,o,__VA_ARGS__)
#define _recurse_701_0(d,o,c,...)     Quit,(_recurse_expand o "COMMAND: "#c" "#__VA_ARGS__)
#define _recurse_701_1(d,o,c,...)     _recurse_70_##c(d,o,__VA_ARGS__)
#define _recurse_701_2(d,o,c,...)     _recurse_70_##c(d,o,__VA_ARGS__)
#define _recurse_701_3(d,o,c,...)     _recurse_70_##c(d,o,__VA_ARGS__)
#define _recurse_711_(d,o,c,...)      _recurse_71_##c(d,o,__VA_ARGS__)
#define _recurse_711_0(d,o,c,...)     _recurse_71_##c(d,o,__VA_ARGS__)
#define _recurse_711_1(d,o,c,...)     Quit,(_recurse_expand o "COMMAND: "#c" "#__VA_ARGS__)
#define _recurse_711_2(d,o,c,...)     _recurse_71_##c(d,o,__VA_ARGS__)
#define _recurse_711_3(d,o,c,...)     _recurse_71_##c(d,o,__VA_ARGS__)
#define _recurse_721_(d,o,c,...)      _recurse_72_##c(d,o,__VA_ARGS__)
#define _recurse_721_0(d,o,c,...)     _recurse_72_##c(d,o,__VA_ARGS__)
#define _recurse_721_1(d,o,c,...)     _recurse_72_##c(d,o,__VA_ARGS__)
#define _recurse_721_2(d,o,c,...)     Quit,(_recurse_expand o "COMMAND: "#c" "#__VA_ARGS__)
#define _recurse_721_3(d,o,c,...)     _recurse_72_##c(d,o,__VA_ARGS__)
#define _recurse_731_(d,o,c,...)      _recurse_73_##c(d,o,__VA_ARGS__)
#define _recurse_731_0(d,o,c,...)     _recurse_73_##c(d,o,__VA_ARGS__)
#define _recurse_731_1(d,o,c,...)     _recurse_73_##c(d,o,__VA_ARGS__)
#define _recurse_731_2(d,o,c,...)     _recurse_73_##c(d,o,__VA_ARGS__)
#define _recurse_731_3(d,o,c,...)     Quit,(_recurse_expand o "COMMAND: "#c" "#__VA_ARGS__)
#define _recurse_70_Recurse(d,o,f)    _recurse_71(d,o,f)
#define _recurse_71_Recurse(d,o,f)    _recurse_72(d,o,f)
#define _recurse_72_Recurse(d,o,f)    _recurse_73(d,o,f)
#define _recurse_73_Recurse(d,o,f)    Recurse,o,f
#define _recurse_70_Output(d,o0,o1,f) _recurse_71(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_71_Output(d,o0,o1,f) _recurse_72(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_72_Output(d,o0,o1,f) _recurse_73(d,(_recurse_expand o0 _recurse_expand o1),f)
#define _recurse_73_Output(d,o0,o1,f) Output,(_recurse_expand o0 _recurse_expand o1),f
#define _recurse_70_Quit(d,o0,o1)     Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_71_Quit(d,o0,o1)     Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_72_Quit(d,o0,o1)     Quit,(_recurse_expand o0 _recurse_expand o1)
#define _recurse_73_Quit(d,o0,o1)     Quit,(_recurse_expand o0 _recurse_expand o1)


#ifndef RECURSE_DEBUG
  #define RECURSE_DEBUG (,,,)
#endif // RECURSE_DEBUG

#ifndef RECURSE_QUALIFIED_ONLY
  #define recurse recurse_recurse
#endif // RECURSE_QUALIFIED_ONLY


#endif // RECURSE_INCLUDED
