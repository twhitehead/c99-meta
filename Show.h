//---------------------------------------------------------------------------//
// Copyright (C) 2008 Tyson Whitehead
//
// This code is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
//---------------------------------------------------------------------------//

#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED

#include "Reduce.h"

// C operator precedence table (weakest to strongest)
//
//   0  ,                                            (left-to-right)
//   1  =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=  (right-to-left)
//   2  ?:                                           (right-to-left)
//   3  ||                                           (left-to-right)
//   4  &&                                           (left-to-right)
//   5  |                                            (left-to-right)
//   6  ^                                            (left-to-right)
//   7  &                                            (left-to-right)
//   8  ==, !=                                       (left-to-right)
//   9  <, <=, >, >=                                 (left-to-right)
//  10  <<, >>                                       (left-to-right)
//  11  +, -                                         (left-to-right)
//  12  *, /, %                                      (left-to-right)
//  13  ++, --, +, -, !, ~, (type), *, &             (right-to-left)
//  14  (arguments), [], ., ->, ++, --               (left-to-right)

#define _show_Output(o,...) reduce_construct((show_Output,o),__VA_ARGS__)


#define _show_parenthesis(o,...)             reduce_caseReduce1(show_parenthesis,o,__VA_ARGS__)
#define _show_parenthesis_show_Output(o,...) reduce_construct((show_Output,(o)),__VA_ARGS__)

#define _show_brackets(o,...)             reduce_caseReduce1(show_brackets,o,__VA_ARGS__)
#define _show_brackets_show_Output(o,...) reduce_construct((show_Output,([_raw_expand(o)])),__VA_ARGS__)

#define _show_braces(o,...)             reduce_caseReduce1(show_braces,o,__VA_ARGS__)
#define _show_braces_show_Output(o,...) reduce_construct((show_Output,({_raw_expand(o)})),__VA_ARGS__)

#define _show_quote(o,...)             reduce_caseReduce1(show_quote,o,__VA_ARGS__)
#define _show_quote_show_Output(o,...) reduce_construct((show_Output,_raw_quote(o)),__VA_ARGS__)

#define _show_joinComma(o0,o1,...)                         reduce_caseReduce2(show_joinComma,o0,o1,__VA_ARGS__)
#define _show_joinComma_show_Output_show_Output(o0,o1,...) reduce_construct((show_Output,(_raw_expand(o0),_raw_expand(o1))),__VA_ARGS__)

#define _show_joinSpace(o0,o1,...)                         reduce_caseReduce2(show_joinSpace,o0,o1,__VA_ARGS__)
#define _show_joinSpace_show_Output_show_Output(o0,o1,...) reduce_construct((show_Output,(_raw_expand(o0) _raw_expand(o1))),__VA_ARGS__)

#define _show_joinApply(o0,o1,...)                         reduce_caseReduce2(show_joinApply,o0,o1,__VA_ARGS__)
#define _show_joinApply_show_Output_show_Output(o0,o1,...) reduce_construct((show_Output,(_raw_expand(o0)o1)),__VA_ARGS__)


#define _show_show(x,...)             reduce_caseReduce1(show_show,x,__VA_ARGS__)
#define _show_showPrecedence(i,x,...) reduce_mixed((I,CR),showPrecedence,i,x,__VA_ARGS__)


// #define _show_show_TYPE(x,...)        reduce_reduce(show_showsPrec_TYPE,integer_Z,x,__VA_ARGS__)
// #define _show_showsPrec_TYPE(i,x,...) reduce_reduce(show_show_TYPE,x,__VA_ARGS__)


#define _show_show_show_Output(o,...)        reduce_construct((show_Output,_raw_quote(o)),__VA_ARGS__)
#define _show_showsPrec_show_Output(i,o,...) reduce_reduce((show_Output,_raw_quote(o)),__VA_ARGS__)


#ifndef SHOW_QUALIFIED_ONLY
  #define show           show_show
  #define showPrecedence show_showPrecedence
#endif // SHOW_QUALIFIED_ONLY

#endif // EQUAL_H_INCLUDED
