// ============================================================================
//
// file : src/hwlib.hpp
//
// These files makes HwLib usable as an Arduino library
//
// ============================================================================

#ifndef _HWLIB_INCLUDED
#define _HWLIB_INCLUDED

#if defined(ARDUINO_ARCH_AVR)
   #define _HWLIB_TARGET_OK
   #undef putc
   #undef abs
   #include "../library/hwlib-arduino-uno.hpp"
#endif

#if defined(ARDUINO_ARCH_SAM)
   #define _HWLIB_TARGET_OK
   #include "../library/hwlib-arduino-due.hpp"
#endif

#ifndef _HWLIB_TARGET_OK
   #error no valid ARDUINO_* target for HwLib
#endif

#endif // #ifndef _HWLIB_INCLUDED