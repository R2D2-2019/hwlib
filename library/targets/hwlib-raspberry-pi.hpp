#// ==========================================================================
//
// File      : hwlib-raspberry-pi.hpp
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// this file contains Doxygen lines
/// @file

#ifndef HWLIB_RASPBERRY_PI_H
#define HWLIB_RASPBERRY_PI_H

#define _HWLIB_TARGET_WAIT_US_BUSY
#include "../hwlib-all.hpp"

#include <stdint.h>

#include <wiringPi.h>

namespace raspberry_pi {

/// raspbery pi 2/3 pin names
///
/// These are the pins of the raspberry pi 2/3. 
/// These pins are the actual pin position so d3 is pin 3 on the pi
enum class pins {
   d3, d5, d7, d8, d10, d11, d12, d13, d15, d16, 
   d18, d19, d21, d22, d23, d24, d26, d27, d28, 
   d29, d31, d32, d33, d35, d36, d37, d38, d40,
/// \cond INTERNAL    
   SIZE_THIS_IS_NOT_A_PIN
/// \endcond   
};
   
/// \cond INTERNAL 

struct pin_info_type { 
   uint8_t wiring_pi; 
   uint8_t rpi_bcm; 
};

const pin_info_type pin_info_array[ (int) pins::SIZE_THIS_IS_NOT_A_PIN ] = {
   { 8, 2 },  // d3
   { 9, 3 },  // d5
   { 7, 4 },  // d7
   { 15, 14 },  // d8
   { 16, 15 },  // d10
   { 0, 17 },  // d11
   { 1, 18 },  // d12
   { 2, 27 },  // d13
   { 3, 22 },  // d15
   { 4, 23 },  // d16
   { 5, 24 },  // d18
   { 12, 10 },  // d19
   { 13, 9 },  // d21
   { 6, 25 },  // d22
   { 14, 11 },  // d23
   { 10, 8 },  // d24
   { 11, 7 },  // d26
   { 30, 0 },  // d27
   { 31, 1 },  // d28
   { 21, 5 },  // d29
   { 22, 6 },  // d31
   { 26, 12 },  // d32
   { 23, 13 },  // d33
   { 24, 19 },  // d35
   { 27, 16 },  // d36
   { 25, 26 },  // d37   
   { 28, 20 },  // d38
   { 29, 21 },  // d40
};

const pin_info_type & HWLIB_WEAK pin_info( pins name ){
   uint_fast8_t n = static_cast< uint_fast8_t>( name );
   if( n >= static_cast< uint_fast8_t>( pins::SIZE_THIS_IS_NOT_A_PIN )){
      HWLIB_PANIC_WITH_LOCATION;
   }
   return pin_info_array[ n ];
}

/**
 * @brief inits wiringpi
 * 
 */
static void init(){
   wiringPiSetup();
}

/// pin_in implementation for an raspberry pi 2/3
class pin_in : public hwlib::pin_in {
private:
   uint8_t wiring_pi;
   uint8_t rpi_bcm;
 
public:
   pin_in( uint8_t wiring_pi, uint8_t rpi_bcm ): 
      wiring_pi(wiring_pi), 
      rpi_bcm(rpi_bcm)
   {
       pinMode(wiring_pi, INPUT);
   }
   
   pin_in( pins name ): 
      pin_in{ 
         pin_info( name ).wiring_pi,
         pin_info( name ).rpi_bcm 
      }
   {}
   
   bool read() override {
      return digitalRead(wiring_pi);
   }
   
   void refresh() override {}
   
   void pullup_enable(){
      pullUpDnControl(wiring_pi, 2);
   }

   void pullup_disable(){
      pullUpDnControl(wiring_pi, 0);
   }

   void pulldown_enable(){
      pullUpDnControl(wiring_pi, 1);
   }

   void pulldown_disable(){
      pullUpDnControl(wiring_pi, 0);
   }

};

/// pin_out implementation for a the raspberry pi 2/3
class pin_out : public hwlib::pin_out {
private:
   uint8_t wiring_pi;
   uint8_t rpi_bcm;
   
public:

   /// Raspberry pi pin_out constructor from raspberry pi 2/3 wiring_pi and rpi_bcm
   ///
   /// This call creates a pin_out from an raspberry pi 2/3 wiring_pi and rpi_bcm
   /// number pair.
   ///
   /// This constructor sets the pin direction to output.
   pin_out( uint8_t wiring_pi, uint8_t rpi_bcm ): 
      wiring_pi(wiring_pi), 
      rpi_bcm(rpi_bcm)
   {
       pinMode(wiring_pi, OUTPUT);
   }
   
   /// Raspberry pi pin_out constructor from raspberry pi 2/3 pin name
   ///
   /// This call creates a pin_out from an raspberry pi 2/3 pin name.
   ///
   /// This constructor sets the pin direction to output.
   pin_out( pins name ): 
      pin_out{ 
         pin_info( name ).wiring_pi,
         pin_info( name ).rpi_bcm 
      }
   {}
   
   void write( bool v ) override {
       digitalWrite(wiring_pi, v);
   }

   void flush() override {}

};

}; // namespace HWLIB_RASPBERRY_PI_H

namespace hwlib {

namespace target = ::raspberry_pi;

void wait_ns( int_fast32_t n );
void wait_us( int_fast32_t n );
void wait_ms( int_fast32_t n ); 

#define HWLIB_USE_HW_UART 

void HWLIB_WEAK uart_putc( char c ){
   //TODO add uart
}

bool HWLIB_WEAK uart_char_available(){
   return false; // TODO add uart
}

char HWLIB_WEAK uart_getc( ){
   return 'A'; // TODO add uart
}

#ifdef _HWLIB_ONCE

uint64_t now_ns(){
   return micros() * 1000;
}   

uint64_t now_us(){
   return micros();
}   

uint64_t now_ms(){
   return millis();
}   

void HWLIB_WEAK wait_us_busy( int_fast32_t n ){
   auto end = now_us() + n;
   while( now_us() < end ){}
}

#endif

}; //namespace hwlib   

#endif // RPI_HPP
