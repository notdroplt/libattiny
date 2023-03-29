/**
 * @file climits.hpp
 * @author notdroplt (117052412+notdroplt@users.noreply.github.com)
 * @brief numeric limits interface 
 * @version 
 * @date 2023-02-02
 * 
 * @copyright Copyright (c) 2023
 * 
 * information from: https://en.cppreference.com/w/cpp/header/climits
 */

#ifndef TINYSTD_CLIMITS_H
#define TINYSTD_CLIMITS_H 1

#ifdef CHAR_BIT
#   undef CHAR_BIT
#endif
#define CHAR_BIT 8 /*!< 8 bits in a byte */

#ifdef MB_LEN_MAX
#   undef MB_LEN_MAX
#endif
#define MB_LEN_MAX 1 /*!< number of bytes in a multibyte character*/

#ifdef CHAR_MIN
#   undef CHAR_MIN
#endif 
#define CHAR_MIN ((char)-128) /*!< smallest number in a char value*/

#ifdef CHAR_MAX
#   undef CHAR_MAX
#endif 
#define CHAR_MAX ((char)127) /*!< biggest number in a char value*/

#ifdef SCHAR_MIN
#   undef SCHAR_MIN
#endif 
#define SCHAR_MIN ((signed char)-128) /*!< smallest signed char number*/

#ifdef SHRT_MIN
#   undef SHRT_MIN
#endif 
#define SHRT_MIN ((signed short)-32768) /*!< smallest signed short number*/

#ifdef SINT_MIN
#   undef SINT_MIN
#endif 
#define SINT_MIN ((signed int)-2147483648) /*!< smallest signed int number*/

#ifdef SLONG_MIN
#   undef SLONG_MIN
#endif 
#define SLONG_MIN ((signed long)-9223372036854775808L) /*!< smallest signed long number*/

#ifdef SLLONG_MIN
#   undef SLLONG_MIN
#endif 
#define SLLONG_MIN ((signed long long)-9223372036854775808LL) /*!< smallest signed long long number*/

#ifdef SCHAR_MAX
#   undef SCHAR_MAX
#endif 
#define SCHAR_MAX ((signed char)127) /*!< biggest signed char number*/

#ifdef SHRT_MAX
#   undef SHRT_MAX
#endif 
#define SHRT_MAX ((signed short)32767) /*!< biggest signed short number*/

#ifdef SINT_MAX
#   undef SINT_MAX
#endif 
#define SINT_MAX ((signed int)2147483647) /*!< biggest signed int number*/

#ifdef SLONG_MAX
#   undef SLONG_MAX
#endif 
#define SLONG_MAX ((signed long)9223372036854775807L) /*!< biggest signed long number*/

#ifdef SLLONG_MAX
#   undef SLLONG_MAX
#endif 
#define SLLONG_MAX ((signed long long)9223372036854775807LL) /*!< biggest signed long long number*/

#ifdef UCHAR_MAX
#   undef UCHAR_MAX
#endif 
#define UCHAR_MAX ((unsigned char)255) /*!< biggest unsigned char number*/

#ifdef USHRT_MAX
#   undef USHRT_MAX
#endif 
#define USHRT_MAX ((unsigned short)65535) /*!< biggest unsigned short number*/

#ifdef UINT_MAX
#   undef UINT_MAX
#endif 
#define UINT_MAX ((unsigned int)4294967295) /*!< biggest unsigned int number*/

#ifdef ULONG_MAX
#   undef ULONG_MAX
#endif 
#define ULONG_MAX ((unsigned long)18446744073709551615L) /*!< biggest unsigned long number*/

#ifdef ULLONG_MAX
#   undef ULLONG_MAX
#endif 
#define ULLONG_MAX ((signed long long)18446744073709551616LL) /*!< biggest unsigned long long number*/

#endif 