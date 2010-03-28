/*
Copyright (c) 2010, Malcolm Humphreys.  All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

* Neither the names of SMPTE, Malcolm Humphreys, nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

(This is the Modified BSD License)
*/

/**
 * @file
 * @breif this file defines the dpx data types
 */



#ifndef DPX_TYPES_H
#define DPX_TYPES_H

#include <stdint.h>
#include <cmath>
#include <iostream>



// DPX data types
typedef uint8_t u8_dpx;
typedef uint16_t u16_dpx;
typedef uint32_t u32_dpx;
typedef float r32_dpx;
typedef char ascii_dpx;
typedef char tbd_dpx;



// DPX data types undefined values
static u8_dpx u8_dpx_undef = 0xFF;
static u16_dpx u16_dpx_undef = 0xFFFF;
static u32_dpx u32_dpx_undef = 0xFFFFFFFF;
static r32_dpx r32_dpx_undef = 0xFFFFFFFF;
static ascii_dpx ascii_dpx_undef = 0x0;
static tbd_dpx tbd_dpx_undef = 0x0;



// unsigned 16-bit integer byteswap
static inline void
bswap(uint16_t *x) {
    *x = (*x >> 8) | (*x << 8);
}

// unsigned 32-bit integer byteswap
static inline void
bswap(uint32_t *x) {
    *x = ((*x << 8)&0xFF00FF00) | ((*x >> 8)&0x00FF00FF);
    *x = (*x >> 16) | (*x << 16);
}

// 32-bit real number byteswap
static inline void
bswap(float *x) {
    union {uint32_t i; float f;} u;
    u.f = *x;
    bswap(&u.i);
    *x = u.f;
}



// Set DPX types to undefined value
static inline void
set_undefined(u8_dpx *x) {
    *x = u8_dpx_undef;
}

static inline void
set_undefined(u16_dpx *x) {
    *x = u16_dpx_undef;
}

static inline void
set_undefined(u16_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        *x = u16_dpx_undef;
        x++;
    }
}

static inline void
set_undefined(r32_dpx *x) {
    *x = r32_dpx_undef;
}

static inline void
set_undefined(r32_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        *x = r32_dpx_undef;
        x++;
    }
}

static inline void
set_undefined(u32_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        *x = u32_dpx_undef;
        x++;
    }
}

static inline void
set_undefined(u32_dpx *x) {
    *x = u32_dpx_undef;
}

static inline void
set_undefined(ascii_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        *x = ascii_dpx_undef;
        x++;
    }
}



// Check if DPX types have a defined value
static inline bool
defined(u8_dpx x) {
    if(x == u8_dpx_undef || std::isnan(x))
        return false;
    return true;
}

static inline bool
defined(u16_dpx x) {
    if(x == u16_dpx_undef || std::isnan(x))
        return false;
    return true;
}

static inline bool
defined(u16_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        if(*x != u16_dpx_undef || std::isnan(*x))
            return true;
        x++;
    }
    return false;
}

static inline bool
defined(u32_dpx x) {
    if(x == u32_dpx_undef)
        return false;
    return true;
}

static inline bool
defined(u32_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        if(*x != u32_dpx_undef || std::isnan(*x))
            return true;
        x++;
    }
    return false;
}

static inline bool
defined(r32_dpx x) {
    if(x == r32_dpx_undef || std::isnan(x))
        return false;
    return true;
}

static inline bool
defined(ascii_dpx x) {
    if(x == ascii_dpx_undef)
        return false;
    return true;
}

static inline bool
defined(ascii_dpx *x, int size) {
    for(unsigned int i = 0; i < size; ++i) {
        if(*x != ascii_dpx_undef)
            return true;
        x++;
    }
    return false;
}



#endif // DPX_TYPES_H
