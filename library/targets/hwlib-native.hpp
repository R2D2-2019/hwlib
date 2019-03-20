// ==========================================================================
//
// File      : hwlib-native.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : wouter@voti.nl 2017-2019
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// this file contains Doxygen lines
/// @file

#ifdef __unix__                    /* __unix__ is usually defined by compilers targeting Unix systems */
   #define OS_Linux
   #include <sys/time.h>
   #define EPOCH_DIFF 11644473600LL
#elif defined(_WIN32) || defined(WIN32)     /* _Win32 is usually defined by compilers targeting 32 or   64 bit Windows systems */
   #define OS_Windows
   #include <windows.h>
#endif

#ifndef HWLIB_NATIVE_H
#define HWLIB_NATIVE_H

#define _HWLIB_TARGET_WAIT_US_BUSY
#include "../hwlib-all.hpp"
#include <iostream>

namespace hwlib {

#ifdef _HWLIB_ONCE 

uint64_t now_ticks(){
   // https://stackoverflow.com/questions/1695288/getting-the-current-time-in-milliseconds-from-the-system-clock-in-windows 
   #ifdef OS_Linux
      struct timeval tv;
      unsigned long long result = EPOCH_DIFF;
      gettimeofday(&tv, NULL);
      result += tv.tv_sec;
      result *= 10000000LL;
      result += tv.tv_usec * 10;
      return result;

   #else
      FILETIME ft_now;
      GetSystemTimeAsFileTime( &ft_now );
      uint64_t ll_now = (LONGLONG)ft_now.dwLowDateTime + ((LONGLONG)(ft_now.dwHighDateTime) << 32LL);   
      return ll_now / 10;
   #endif
}   

uint64_t ticks_per_us(){
   return 1;
}   

uint64_t now_us(){
   return now_ticks() / ticks_per_us();
}   

void wait_us_busy( int_fast32_t n ){
   auto end = now_us() + n;
   while( now_us() < end ){}
}

/*

void wait_ns( int_fast32_t n ){
   wait_us( n / 1'000 );
}

void wait_us( int_fast32_t n ){
   
}

void wait_ms( int_fast32_t n ){
   wait_us( n * 1'000 );
}

uint_fast64_t now_us(){
   return 0;
}   
 
*/

void uart_putc( char c ){
   std::cout << c << std::flush;
}

char uart_getc(){
   return std::getchar();   
}

bool HWLIB_WEAK uart_char_available(){
   return 1;
}

#endif // #ifdef HBLIB_ONCE

}; // namespace hwlib

#endif // HWLIB_NATIVE_H
