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
 * @breif this is a little class for decoding a SMPTE timecode in a dpx file
 */



#ifndef DPX_TIME_CODE_H
#define DPX_TIME_CODE_H

#include <iostream>
#include <iomanip>
#include "dpxTypes.h"



/** SMPTE 12M timecode (hh:mm:ss:ff)
 * |------------------------------------------------------------------|
 * | 31..28 | 27..24 | 23..20 | 19..16 | 15..12 | 11..8 | 7..4 | 3..0 |
 * |   h    |   h    |   m    |   m    |    s   |   s   |  F   |  F   |
 * |------------------------------------------------------------------|
 */
class TimeCode {
    
public:
    
    TimeCode(u32_dpx code) {
        
        m_code = code;
        
        // LSB structure
        typedef struct packed_timecode {
            u8_dpx f_t;
            u8_dpx s_t;
            u8_dpx m_t;
            u8_dpx h_t;
        } packed_timecode;
        
        typedef union {
            u32_dpx in;
            packed_timecode out;
        } unpacked_timecode;
        
        unpacked_timecode decode;
        decode.in = m_code;
        frames = decode.out.f_t;
        seconds = decode.out.s_t;
        minutes = decode.out.m_t;
        hours = decode.out.h_t;
        
    };
    
    ~TimeCode() {
    };
    
    int frames;
    int seconds;
    int minutes;
    int hours;
    
private:
    
    u32_dpx m_code;
    
};

/** operator<< stream insertion for the TimeCode class */
inline std::ostream&
operator<< (std::ostream& out, TimeCode code) {
    // hh:mm:ss:ff
    out << std::setw(2) << std::setfill('0') << code.hours   << ":"
        << std::setw(2) << std::setfill('0') << code.minutes << ":"
        << std::setw(2) << std::setfill('0') << code.seconds << ":"
        << std::setw(2) << std::setfill('0') << code.frames;
    return out;
}



/** SMPTE 12M userbits
 * |------------------------------------------------------------------|
 * | 31..28 | 27..24 | 23..20 | 19..16 | 15..12 | 11..8 | 7..4 | 3..0 |
 * |   UB8  |   UB7  |   UB6  |   UB5  |   UB4  |  UB3  |  UB2 |  UB1 |
 * |------------------------------------------------------------------|
 */

/* Not Yet Supported */

#endif // DPX_TIME_CODE_H
