// ==========================================================================
//
// File      : hwlib-all.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : wouter@voti.nl 2017-2019
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// This file includes all target-independent hwlib files 
// (except hwlib-doxygen.hpp, which contains only Doxygen stuff)
// to add a file, add it here and in the Makefile.inc
//
// C/C++ library files are included here rather than in the individual
// library files.
// The individual hwlib header files depend on the order in which they 
// are included here, and don't have multiple-include guards.
// They are not meant to be included individually.
//
// In normal use, this file is included by a target-specific hwlib file.

#ifndef HWLIB_ALL_H
#define HWLIB_ALL_H

#include <cstdint>
#include <array>
//#include <stddef.h>
#include <type_traits>

#include "core/hwlib-defines.hpp"
#include "core/hwlib-panic.hpp"
#include "core/hwlib-common.hpp"
#include "core/hwlib-wait.hpp"

#include "pins/hwlib-pin.hpp"
#include "pins/hwlib-pin-dummies.hpp"
#include "pins/hwlib-pin-stores.hpp"
#include "pins/hwlib-pin-from-pin.hpp"
#include "pins/hwlib-pin-invert.hpp"
#include "pins/hwlib-pin-all.hpp"
#include "pins/hwlib-pin-direct.hpp"
#include "pins/hwlib-pin-demos.hpp"


#include "ports/hwlib-port.hpp"
#include "ports/hwlib-port-from-port.hpp"
#include "ports/hwlib-port-from-pins.hpp"
#include "ports/hwlib-port-invert.hpp"
#include "ports/hwlib-port-all.hpp"
#include "ports/hwlib-port-direct.hpp"
#include "ports/hwlib-port-demos.hpp"

#include "char-io/hwlib-ostream.hpp"
#include "char-io/hwlib-istream.hpp"
#include "char-io/hwlib-bb-uart.hpp"
#include "char-io/hwlib-console.hpp"
#include "core/hwlib-xy.hpp"
#include "char-io/hwlib-terminal.hpp"
#include "char-io/hwlib-terminal-demos.hpp"

#include "core/hwlib-test.hpp"
#include "core/hwlib-string.hpp"

#include "core/hwlib-adc.hpp"
#include "core/hwlib-dac.hpp"
#include "core/hwlib-dac-demos.hpp"
#include "core/hwlib-i2c.hpp"
#include "core/hwlib-spi.hpp"

#include "graphics/hwlib-graphics-color.hpp"
#include "graphics/hwlib-graphics-image.hpp"
#include "graphics/hwlib-graphics-font.hpp"
#include "graphics/hwlib-graphics-window.hpp"
#include "graphics/hwlib-graphics-drawables.hpp"
#include "graphics/hwlib-graphics-window-decorators.hpp"
#include "graphics/hwlib-graphics-window-demos.hpp"
#include "graphics/hwlib-graphics-window-terminal.hpp"
#include "graphics/hwlib-graphics-font-8x8.hpp"
#include "graphics/hwlib-graphics-font-16x16.hpp"

#include "peripherals/hwlib-pcf8574.hpp"
#include "peripherals/hwlib-pcf8591.hpp"
#include "peripherals/hwlib-hc595.hpp"
#include "peripherals/hwlib-hd44780.hpp"
#include "peripherals/hwlib-glcd-5510.hpp"
#include "peripherals/hwlib-glcd-oled.hpp"
#include "peripherals/hwlib-matrix-keypad.hpp"

#include "pins/hwlib-pin-test.hpp"

#endif // HWLIB_ALL_H
