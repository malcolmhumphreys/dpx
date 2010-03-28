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
 * @breif this file defines the dpx header code values
 */



#ifndef DPX_CODES_H
#define DPX_CODES_H

#include <iostream>
#include <iomanip>



namespace DataSign {

/** Defines the sign of the data in element n */
typedef enum {
    Unsigned = 0,
    Signed = 1,
} Code;

/** operator<< stream insertion for the DataSign enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code sign) {
         if(sign == Unsigned)
        out << "unsigned";
    else if(sign == Signed)
        out << "signed"; 
    else
        out << "Unknown sign code";
    return out;
}

} // DataSign namespace



namespace Descriptor {

/** Defines components that make up an image element and their pixel packing
 * order. */
typedef enum {
    UserDefined = 0,     // User defined (or unspecified single component)
    Red = 1,             // Red (R)
    Green = 2,           // Green (G)
    Blue = 3,            // Blue (B)
    Alpha = 4,           // Alpha (matte)
    Luma = 6,            // Luma (Y)
    ColorDifference = 7, // Color Difference (CB, CR, subsampled by two)
    DepthZ = 8,          // Depth (Z)
    CompositeVideo = 9,  // Composite Video
    // Codes 10 to 49 are reserved for future single components //
    RGB = 50,            // R, G, B
    RGBA = 51,           // R, G, B, Alpha (A)
    ABGR = 52,           // A, B, G, R
    // Codes 53 to 99 are reserved for future RGB ++ formats //
    CB_Y_CR_Y = 100,     // CB, Y, CR, Y (4:2:2) [based on SMPTE 125M]
    CB_Y_A_CR_Y_A = 101, // CB, Y, A, CR, Y, A (4:2:2:4)
    CB_Y_CR = 102,       // CB, Y, CR (4:4:4)
    CB_Y_CR_A = 103,     // CB, Y, CR, A (4:4:4:4)
    // Codes 104 to 149 - Reserved for future CBYCR ++ formats //
    // User defined n-component elements //
    UserDefined2Components = 150,
    UserDefined3Components = 151,
    UserDefined4Components = 152,
    UserDefined5Components = 153,
    UserDefined6Components = 154,
    UserDefined7Components = 155,
    UserDefined8Components = 156,
    // Codes 157 to 254 are reserved for future formats //
} Code;

/** operator<< stream insertion for the Descriptor enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code descriptor) {
         if(descriptor == UserDefined)
        out << "User defined (or unspecified single component)";
    else if (descriptor == Red)
        out << "R";
    else if (descriptor == Green)
        out << "G";
    else if (descriptor == Blue)
        out << "B";
    else if (descriptor == Alpha)
        out << "A";
    else if (descriptor == Luma)
        out << "Luma (Y)";
    else if (descriptor == ColorDifference)
        out << "Color Difference (CB, CR, subsampled by two)";
    else if (descriptor == DepthZ)
        out << "Z";
    else if (descriptor == CompositeVideo)
        out << "Composite video";
    else if (descriptor == RGB)
        out << "RGB";
    else if (descriptor == RGBA)
        out << "RGBA";
    else if (descriptor == ABGR)
        out << "ABGR";
    else if (descriptor == CB_Y_CR_Y)
        out << "CB, Y, CR, Y (4:2:2)";
    else if (descriptor == CB_Y_A_CR_Y_A)
        out << "CB, Y, A, CR, Y, A (4:2:2:4)";
    else if (descriptor == CB_Y_CR)
        out << "CB, Y, CR (4:4:4)";
    else if (descriptor == CB_Y_CR_A)
        out << "CB, Y, CR, A (4:4:4:4)";
    else if (descriptor == UserDefined2Components)
        out << "User-defined 2-component element";
    else if (descriptor == UserDefined3Components)
        out << "User-defined 3-component element";
    else if (descriptor == UserDefined4Components)
        out << "User-defined 4-component element";
    else if (descriptor == UserDefined5Components)
        out << "User-defined 5-component element";
    else if (descriptor == UserDefined6Components)
        out << "User-defined 6-component element";
    else if (descriptor == UserDefined7Components)
        out << "User-defined 7-component element";
    else if (descriptor == UserDefined8Components)
        out << "User-defined 8-component element";
    else
        out << "Reserved for future formats";
    return out;
}

} // Descriptor namespace



namespace Orientation {

/** Defines the orientation of the image data required for display.
 * @note The standard orientation for core set images (code 0) is left to right
 * (line direction) and top to bottom (frame direction) */
typedef enum {
    LeftRight_TopBottom = 0, // Line: Left to right Frame: Top to bottom
    RightLeft_TopBottom = 1, // line: Right to left Frame: Top to bottom
    LeftRight_BottomTop = 2, // Line: left to right Frame: Bottom to top
    RightLeft_BottomTop = 3, // Line: right to left Frame: Bottom to top
    TopBottom_LeftRight = 4, // Line: top to bottom Frame: Left to right
    TopBottom_RightLeft = 5, // Line: top to bottom Frame: Right to left
    BottomTop_LeftRight = 6, // Line: bottom to top Frame: Left to right
    BottomTop_RightLeft = 7, // Line: bottom to top Frame: Right to left
    // Codes 8 to 254 - Reserved for future use //
} Code;

/** operator<< stream insertion for the Orientation enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code orient) {
    if(orient == LeftRight_TopBottom)
        out << "Line: Left to right Frame: Top to bottom";
    else if(orient == RightLeft_TopBottom)
        out << "Line: Right to left Frame: Top to bottom";
    else if(orient == LeftRight_BottomTop)
        out << "Line: Left to right Frame: Bottom to top";
    else if(orient == RightLeft_BottomTop)
        out << "Line: Right to left Frame: Bottom to top";
    else if(orient == TopBottom_LeftRight)
        out << "Line: Top to bottom Frame: Left to right";
    else if(orient == TopBottom_RightLeft)
        out << "Line: Top to bottom Frame: Right to left";
    else if(orient == BottomTop_LeftRight)
        out << "Line: Bottom to top Frame: Left to right";
    else if(orient == BottomTop_RightLeft)
        out << "Line: Bottom to top Frame: Right to left";
    else
        out << "Reserved for future use";
    return out;
}

} // Orientation namespace



namespace BitSize {

/** Defines the number of bits for each component in an image element. All components must
 * have the same bit depth. */
typedef enum {
    BitInt1 = 1,     // 1 bit integer
    BitInt8 = 8,     // 8 bit integer
    BitInt10 = 10,   // 10 bit integer
    BitInt12 = 12,   // 12 bit integer
    BitInt16 = 16,   // 16 bit integer
    BitFloat32 = 32, // 32 bit float
    BitFloat64 = 64, // 64 bit float
} Code;

/** operator<< stream insertion for the BitSize enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code encoding) {
    
         if(encoding == BitInt1)
         out << "1 bit integer";
    else if(encoding == BitInt8)
        out << "8 bit integer";
    else if(encoding == BitInt10)
        out << "10 bit integer";
    else if(encoding == BitInt12)
        out << "12 bit integer";
    else if(encoding == BitInt16)
        out << "16 bit integer";
    else if(encoding == BitFloat32)
        out << "32 bit float";
    else if(encoding == BitFloat64)
        out << "64 bit float";
    else
        out << "Unknown bit size";
    return out;
}

} // BitSize namespace



namespace DataPacking {

/** Defines the data packing mode for element n */
typedef enum {
    Packed = 0,        // Packed into 32-bit words
    FilledMethodA = 1, // Filled to 32-bit words, method A
    FilledMethodB = 2, // Filled to 32-bit words, method B (DPX v2.0)
    // Codes 3 to 7 are reserved for future use //
} Code;

/** operator<< stream insertion for the DataPacking enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code packing) {
    if(packing == Packed)
        out << "Packed into 32-bit words";
    else if(packing == FilledMethodA)
        out << "Filled to 32-bit words, method A";
    else if(packing == FilledMethodB)
        out << "Filled to 32-bit words, method B";
    else
        out << "Reserved for future use";
    return out;
}

} // DataPacking namespace



namespace DataEncoding {

/** Defines whether or not the element n is run-length encoded. */
typedef enum {
    NoEncoding = 0,
    RunLength = 1,
    // Codes 2 to 7 are reserved for future use
} Code;

/** operator<< stream insertion for the DataEncoding enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code encoding) {
         if(encoding == NoEncoding)
        out << "No encoding applied";
    else if(encoding == RunLength)
        out << "Run-length encoded";
    else
        out << "Reserved for future use";
    return out;
}

} // DataEncoding namespace



namespace VideoSignal {

/** Defines the video signal standard */
typedef enum {
    Undefined = 0,
    NTSC = 1,
    PAL = 2,
    PAL_M = 3,
    SECAM = 4,
    // Codes 5 to 49 are reserved for other composite video
    // YCBCR ITU-R 601-5 525-line, 2:1 interlace, 4:3 aspect ratio
    ITU_R601_5_525Line_2_1Interlace_4_3Aspect = 50,
    // YCBCR ITU-R 601-5 625-line, 2:1 interlace, 4:3 aspect ratio
    ITU_R601_5_625Line_2_1Interlace_4_3Aspect = 51,
    // Codes 52 to 99 are reserved for future component video
    // YCBCR ITU-R 601-5 525-line, 2:1 interlace, 16:9 aspect ratio
    ITU_R601_5_525Line_2_1Interlace_16_9Aspect = 100,
    // YCBCR ITU-R 601-5 625-line, 2:1 interlace, 16:9 aspect ratio
    ITU_R601_5_625Line_2_1Interlace_16_9Aspect = 101,
    // Codes 102 to 149 are reserved for future widescreen
    // YCBCR 1050-line, 2:1 interlace, 16:9 aspect ratio
    YCBCR_1050Line_2_1Interlace_16_9Aspect = 150,
    // YCBCR 1125-line, 2:1 interlace, 16:9 aspect ratio (SMPTE 274M)
    YCBCR_1125Line_2_1Interlace_16_9Aspect_274M = 151,
    // YCBCR 1250-line, 2:1 interlace, 16:9 aspect ratio
    YCBCR_1250Line_2_1Interlace_16_9Aspect = 152,
    // YCBCR 1125-line, 2:1 interlace, 16:9 aspect ratio (SMPTE 240M)
    YCBCR_1125Line_2_1Interlace_16_9Aspect_240M = 153, // (DPX v2.0)
    // Codes 154 to 199 are reserved for future high-definition interlace
    // YCBCR 525-line, 1:1 progressive, 16:9 aspect ratio
    YCBCR_525Line_1_1Progressive_16_9Aspect = 200,
    // YCBCR 625-line, 1:1 progressive, 16:9 aspect ratio
    YCBCR_625Line_1_1Progressive_16_9Aspect = 201,
    // YCBCR 750-line, 1:1 progressive, 16:9 aspect ratio (SMPTE 296M)
    YCBCR_750Line_1_1Progressive_16_9Aspect_296M = 202,
    // YCBCR 1125-line, 1:1 progressive, 16:9 aspect ratio (SMPTE 274M)
    YCBCR_1125Line_1_1Progressive_16_9Aspect_274M = 203, // (DPX v2.0)
    // Codes 204 to 254 are reserved for future high-definition progressive
} Code;

/** operator<< stream insertion for the VideoSignal enumeration */
inline std::ostream& operator<<(std::ostream& out, Code signal)
{
         if(signal == Undefined)
        out << "Undefined";
    else if(signal == NTSC)
        out << "NTSC";
    else if(signal == PAL)
        out << "PAL";
    else if(signal == PAL_M)
        out << "PAL-M";
    else if(signal == SECAM)
        out << "SECAM";
    else if(signal == ITU_R601_5_525Line_2_1Interlace_4_3Aspect)
        out << "YCBCR ITU-R 601-5 525-line, 2:1 interlace, 4:3 aspect ratio";
    else if(signal == ITU_R601_5_625Line_2_1Interlace_4_3Aspect)
        out << "YCBCR ITU-R 601-5 625-line, 2:1 interlace, 4:3 aspect ratio";
    else if(signal == ITU_R601_5_525Line_2_1Interlace_16_9Aspect)
        out << "YCBCR ITU-R 601-5 525-line, 2:1 interlace, 16:9 aspect ratio";
    else if(signal == ITU_R601_5_625Line_2_1Interlace_16_9Aspect)
        out << "YCBCR ITU-R 601-5 625-line, 2:1 interlace, 16:9 aspect ratio";     
    else if(signal == YCBCR_1050Line_2_1Interlace_16_9Aspect)
        out << "YCBCR 1050-line, 2:1 interlace, 16:9 aspect ratio";
    else if(signal == YCBCR_1125Line_2_1Interlace_16_9Aspect_274M)
        out << "YCBCR 1125-line, 2:1 interlace, 16:9 aspect ratio (SMPTE 274M)";
    else if(signal == YCBCR_1250Line_2_1Interlace_16_9Aspect)
        out << "YCBCR 1250-line, 2:1 interlace, 16:9 aspect ratio";
    else if(signal == YCBCR_1125Line_2_1Interlace_16_9Aspect_240M)
        out << "YCBCR 1125-line, 2:1 interlace, 16:9 aspect ratio (SMPTE 240M)";
    else if(signal == YCBCR_525Line_1_1Progressive_16_9Aspect)
        out << "YCBCR 525-line, 1:1 progressive, 16:9 aspect ratio";
    else if(signal == YCBCR_625Line_1_1Progressive_16_9Aspect)
        out << "YCBCR 625-line, 1:1 progressive, 16:9 aspect ratio";
    else if(signal == YCBCR_750Line_1_1Progressive_16_9Aspect_296M)
        out << "YCBCR 750-line, 1:1 progressive, 16:9 aspect ratio (SMPTE 296M)";
    else if(signal == YCBCR_1125Line_1_1Progressive_16_9Aspect_274M)
        out << "YCBCR 1125-line, 1:1 progressive, 16:9 aspect ratio (SMPTE 274M)";
    else
        out << "Reserved for future use";
    return out;
}

} // VideoSignal namespace



namespace Transfer {

/** Defines the amplitude transfer function used to transform the data from a
 * linear original. The inverse of the transfer function is needed to recreate a
 * linear image element */

namespace Dpx_1 {

// DPX 1.0
typedef enum {
    UserDefined = 0,
    PrintingDensity = 1,
    Linear = 2,
    Logarithmic = 3,
    UnspecifiedVideo = 4,
    SMTPE_240M = 5,
    CCIR_709_1 = 6,
    CCIR_601_2_625 = 7,
    CCIR_601_2_525 = 8,
    CompositeVideo_NTSC = 9, // see SMPTE 170M
    CompositeVideo_PAL = 10, // see ITU-R 624-4
    ZDepth_Linear = 11,
    // Z (depth) - homogeneous (distance to screen and angle of
    // view must also be specified in user-defined section)
    ZDepth_Homogeneous = 12,
    // Codes 13 to 254 are reserved for future use //
} Code;

/** operator<< stream insertion for the Transfer enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code transfer) {
    if(transfer == UserDefined)
        out << "User Defined";
    else if(transfer == PrintingDensity)
        out << "Printing Density";
    else if(transfer == Linear)
        out << "Linear";
    else if(transfer == Logarithmic)
        out << "Logarithmic";
    else if(transfer == UnspecifiedVideo)
        out << "Unspecified Video";
    else if(transfer == SMTPE_240M)
        out << "SMTPE 240M";
    else if(transfer == CCIR_709_1)
        out << "CCIR 709-1";
    else if(transfer == CCIR_601_2_625)
        out << "CCIR 601-2 625 Lines";
    else if(transfer == CCIR_601_2_525)
        out << "CCIR 601-2 525 Lines";
    else if(transfer == CompositeVideo_NTSC)
        out << "CompositeVideo NTSC";
    else if(transfer == CompositeVideo_PAL)
        out << "CompositeVideo PAL";
    else if(transfer == ZDepth_Linear)
        out << "ZDepth Linear";
    else if(transfer == ZDepth_Homogeneous)
        out << "ZDepth Homogeneous";
    else
        out << "Reserved for future use";
    return out;
}

} // Dpx_1 namespace

namespace Dpx_2 {

// DPX 2.0
typedef enum {
    UserDefined = 0,
    PrintingDensity = 1,
    Linear = 2,
    Logarithmic = 3,
    UnspecifiedVideo = 4,
    SMTPE_274M = 5,     // (DPX 2.0)
    ITU_R709_4 = 6,     // (DPX 2.0)
    ITU_R601_5_625 = 7, // (DPX 2.0)
    ITU_R601_5_525 = 8, // (DPX 2.0)
    CompositeVideo_NTSC = 9, // see SMPTE 170M
    CompositeVideo_PAL = 10, // see ITU-R 624-4
    ZDepth_Linear = 11,
    // Z (depth) - homogeneous (distance to screen and angle of
    // view must also be specified in user-defined section)
    ZDepth_Homogeneous = 12,
    // Codes 13 to 254 are reserved for future use //
} Code;

/** operator<< stream insertion for the Transfer enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code transfer) {
    if(transfer == UserDefined)
        out << "User Defined";
    else if(transfer == PrintingDensity)
        out << "Printing Density";
    else if(transfer == Linear)
        out << "Linear";
    else if(transfer == Logarithmic)
        out << "Logarithmic";
    else if(transfer == UnspecifiedVideo)
        out << "Unspecified Video";
    else if(transfer == SMTPE_274M)
        out << "SMTPE 274M";
    else if(transfer == ITU_R709_4)
        out << "ITU-R 709-4";
    else if(transfer == ITU_R601_5_625)
        out << "ITU-R 601-5 625 Lines";
    else if(transfer == ITU_R601_5_525)
        out << "ITU-R 601-5 525 Lines";
    else if(transfer == CompositeVideo_NTSC)
        out << "CompositeVideo NTSC";
    else if(transfer == CompositeVideo_PAL)
        out << "CompositeVideo PAL";
    else if(transfer == ZDepth_Linear)
        out << "ZDepth Linear";
    else if(transfer == ZDepth_Homogeneous)
        out << "ZDepth Homogeneous";
    else
        out << "Reserved for future use";
    return out;
}

} // Dpx_2 namespace

} // Transfer namespace



namespace Colorimetric {

/** Defines the appropriate color reference primaries (for additive color
 * systems like television) or color responses (for printing density) */

namespace Dpx_1 {

 typedef enum {
     UserDefined = 0,         // User defined
     PrintingDensity = 1,     // Printing density
     NotApplicable2 = 2,      // Not applicable
     NotApplicable3 = 3,      // Not applicable
     UnspecifiedVideo = 4,    // Unspecified video
     SMTPE_240M = 5,          // SMPTE 240M
     CCIR_709_1 = 6,          // CCIR 709-1
     CCIR_601_2_625 = 7,      // ITU-R 601-5 system B or G (625)
     CCIR_601_2_525 = 8,      // ITU-R 601-5 system M (525)
     CompositeVideo_NTSC = 9, // Composite video (NTSC); see SMPTE 170M
     CompositeVideo_PAL = 10, // Composite video (PAL); see ITU-R 624-4
     NotApplicable11 = 11,    // Not applicable
     NotApplicable12 = 12,    // Not applicable
     // Codes 13 to 254 are reserved for future use
 } Code;

 /** operator<< stream insertion for the Colorimetric enumeration */
 inline std::ostream&
 operator<< (std::ostream& out, Code colorimetric) {
     if(colorimetric == UserDefined)
         out << "User Defined";
     else if(colorimetric == PrintingDensity)
         out << "Printing Density";
     else if(colorimetric == NotApplicable2)
         out << "NotApplicable2";
     else if(colorimetric == NotApplicable3)
         out << "NotApplicable3";
     else if(colorimetric == UnspecifiedVideo)
         out << "Unspecified Video";
     else if(colorimetric == SMTPE_240M)
         out << "SMTPE 240M";
     else if(colorimetric == CCIR_709_1)
         out << "CCIR 709-1";
     else if(colorimetric == CCIR_601_2_625)
         out << "CCIR 601-2 625 Lines";
     else if(colorimetric == CCIR_601_2_525)
         out << "CCIR 601-2 525 Lines";
     else if(colorimetric == CompositeVideo_NTSC)
         out << "Composite Video NTSC";
     else if(colorimetric == CompositeVideo_PAL)
         out << "Composite Video PAL";
     else if(colorimetric == NotApplicable11)
         out << "NotApplicable11";
     else if(colorimetric == NotApplicable12)
         out << "NotApplicable12";
     else
         out << "Reserved for future use";
     return out;
 }

 } // Dpx_1 namespace

namespace Dpx_2 {

typedef enum {
    UserDefined = 0,         // User defined
    PrintingDensity = 1,     // Printing density
    NotApplicable2 = 2,      // Not applicable
    NotApplicable3 = 3,      // Not applicable
    UnspecifiedVideo = 4,    // Unspecified video
    SMTPE_274M = 5,          // SMPTE 274M
    ITU_R709_4 = 6,          // ITU-R 709-4
    ITU_R601_5_625 = 7,      // ITU-R 601-5 system B or G (625)
    ITU_R601_5_525 = 8,      // ITU-R 601-5 system M (525)
    CompositeVideo_NTSC = 9, // Composite video (NTSC); see SMPTE 170M
    CompositeVideo_PAL = 10, // Composite video (PAL); see ITU-R 624-4
    NotApplicable11 = 11,    // Not applicable
    NotApplicable12 = 12,    // Not applicable
    // Codes 13 to 254 are reserved for future use
} Code;

/** operator<< stream insertion for the Colorimetric enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code colorimetric) {
    if(colorimetric == UserDefined)
        out << "User Defined";
    else if(colorimetric == PrintingDensity)
        out << "Printing Density";
    else if(colorimetric == NotApplicable2)
        out << "NotApplicable2";
    else if(colorimetric == NotApplicable3)
        out << "NotApplicable3";
    else if(colorimetric == UnspecifiedVideo)
        out << "Unspecified Video";
    else if(colorimetric == SMTPE_274M)
        out << "SMTPE 274M";
    else if(colorimetric == ITU_R709_4)
        out << "ITU-R 709-4";
    else if(colorimetric == ITU_R601_5_625)
        out << "ITU-R 601-5 625 Lines";
    else if(colorimetric == ITU_R601_5_525)
        out << "ITU-R 601-5 525 Lines";
    else if(colorimetric == CompositeVideo_NTSC)
        out << "Composite Video NTSC";
    else if(colorimetric == CompositeVideo_PAL)
        out << "Composite Video PAL";
    else if(colorimetric == NotApplicable11)
        out << "NotApplicable11";
    else if(colorimetric == NotApplicable12)
        out << "NotApplicable12";
    else
        out << "Reserved for future use";
    return out;
}

} // Dpx_2 namespace

} // Colorimetric namespace



namespace Interlace {

/** defines tv interlace codes */
typedef enum {
    NonInterlaced = 0,
    Interlace = 1, // 2:1 interlace
} Code;

/** operator<< stream insertion for the Interlace enumeration */
inline std::ostream&
operator<< (std::ostream& out, Code sign) {
         if(sign == NonInterlaced)
        out << "non-interlaced";
    else if(sign == Interlace)
        out << "2:1 interlace";
    else
        out << "Unknown interlace code";
    return out;
}

} // Interlace namespace



#endif // DPX_CODES_H