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



#ifndef DPX_HEADER_H
#define DPX_HEADER_H

#include "dpxTypes.h"
#include "dpxCodes.h"
#include "dpxTimeCode.h"



typedef struct _DPXFileHeader {
    
    // DPX magic number and byte order
    // "SDPX" (0x53445058 hex) most significant
    // "XPDS" (0x58504453 hex) least significant
    u32_dpx magic_number; // Core Set
    // offset to the image data from the start of the file (in bytes)
    u32_dpx offset; // Core Set
    // version number of header format (V1.0 || V2.0)
    ascii_dpx header_format[8]; // Core Set
    // total image file size (in bytes)
    u32_dpx image_file_size; // Core Set
    // indicates that all header fields other than frame related ones
    // (film.count, film.frame_position, tv.time_code,  tv.field_number) are
    // the same as the previous frame. (read-time shortcut)
    u32_dpx ditto_key;
    // generic header length (in bytes)
    u32_dpx generic_header_length;
    // industry specific header length (in bytes)
    u32_dpx industry_header_length;
    // user-defined header length (in bytes)
    u32_dpx user_header_length;
    // image filename
    ascii_dpx image_filename[100];
    // creation date+time (defined as YYYY:MM:DD:HH:MM:SS:LTZ)
    ascii_dpx creation_datetime[24];
    // name of the creator
    ascii_dpx creator[100];
    // name of the project
    ascii_dpx project_name[200];
    // right to use or copyright statement
    ascii_dpx copyright_statement[200];
    // image data encrypted if not set to FFFFFFFF
    u32_dpx encryption_key;
    // reserved for future use
    tbd_dpx reserved[104];
    
} DPXFileHeader;



typedef struct _DPXImageHeader {
    
    // orientation of the image data required for display (Core Set = 0)
    // @see Orientation::Code in dpxCodes.h
    u16_dpx image_orientation; // Core Set
    // number of image elements in the file 1-8
    u16_dpx no_elements; // Core Set
    // number of pixels per line (width)
    u32_dpx line_pixels; // Core Set
    // number of pixel lines per file (height)
    u32_dpx image_lines; // Core Set
    struct {
        // Data sign (Core Set = unsigned)
        // @see DataSign::Code in dpxCodes.h
        u32_dpx sign; // Core Set
        // minimum expected code value
        u32_dpx ref_low_data;
        // signal level or measured value of the ref_low_data
        r32_dpx ref_low_quantity;
        // maximum expected code value
        u32_dpx ref_high_data;
        // signal level or measured value of the ref_high_data
        r32_dpx ref_high_quantity;
        // defines the components and pixel-packing order of the image element
        // @see Descriptor::Code in dpxCodes.h
        u8_dpx descriptor; // Core Set
        // transfer function used to compress the data from linear
        // @see Transfer::Dpx_1::Code or Transfer::Dpx_2::Code in dpxCodes.h
        u8_dpx transfer; // Core Set
        // color reference primaries or color responses
        // @see Colorimetric::Dpx_1::Code in dpxCodes.h
        // @see Colorimetric::Dpx_2::Code in dpxCodes.h
        u8_dpx colorimetric; // Core Set
        // number of bits for each component in element (all components match)
        // @see BitSize::Code in dpxCodes.h
        u8_dpx bit_size; // Core Set
        // data-packing mode
        // @see DataPacking::Code in dpxCodes.h
        u16_dpx packing; // Core Set
        // defines if element is run-length encoded
        // @see DataEncoding::Code in dpxCodes.h
        u16_dpx encoding; // Core Set
        // offset to the elements data from the start of the file (in bytes)
        u32_dpx offset; // Core Set
        // no of padded bytes at the end of each line (default = 0)
        u32_dpx eo_line_padding;
        // no of padded bytes at the end of each image element (default = 0)
        u32_dpx eo_image_padding;
        // description of image element
        ascii_dpx description[32];
        
    } element[8];
    
    // reserved for future use
    tbd_dpx reserved[52];
    
} DPXImageHeader;



typedef struct _DPXImageOrientation {
    
    // line offset (in pixels) from the first pixel in the original image
    u32_dpx x_offset;
    // frame offset (in lines) from first line in the original contiguous image
    u32_dpx y_offset;
    // X image center in pixel units
    r32_dpx x_center;
    // Y image center in line units
    r32_dpx y_center;
    // number of pixels per line in the original image
    u32_dpx x_orig_size;
    // number of lines per image in the original image
    u32_dpx y_orig_size;
    // extracted or processed filename of the source image
    ascii_dpx source_image_filename[100];
    // extracted or processed creation time of the source image
    // (defined as YYYY:MM:DD:HH:MM:SS:LTZ)
    ascii_dpx source_creation_datetime[24];
    // input device name
    ascii_dpx input_device_dev[32];
    // input device serial number
    ascii_dpx input_device_serial[32];
    // (X-left, X-right, Y-top, Y-bottom) value defines the eroded border width
    u16_dpx border_validity[4];
    // specified as a ratio (x = horizontal/vertical)
    u32_dpx pixel_aspect[2];
    // reserved for future use
    tbd_dpx reserved[28];
    
} DPXImageOrientation;



typedef struct _DPXMotionPictureFilm {
    
    // film mfg ID code
    ascii_dpx mfg_id[2];
    // film type
    ascii_dpx type[2];
    // offset in perfs
    ascii_dpx perf_offset[2];
    // prefix
    ascii_dpx prefix[6];
    // count
    ascii_dpx count[4];
    // format ident e.g. Academy
    ascii_dpx format[32];
    // frame number in the image sequence
    u32_dpx frame_position;
    // total number of frames in the image sequence
    u32_dpx sequence_length;
    // specifies how many 'frames' to hold the current frame
    u32_dpx held_count;
    // frame rate of original (frames/s)
    r32_dpx frame_rate;
    // shutter angle in degrees of the motion-picture camera
    r32_dpx shutter_angle;
    // field that labels select frames as key frames or wedge frames, etc.
    ascii_dpx frame_ident[32];
    // field for recording production information from the camera slates.
    ascii_dpx slate_info[100];
    // reserved for future use
    tbd_dpx reserved[56];
    
} DPXMotionPictureFilm;



typedef struct _DPXTelevision {
    
    // SMPTE time code (encoded into 32bit word)
    u32_dpx time_code;
    // SMPTE user bits (encoded into 32bit word)
    u32_dpx user_bits;
    // interlace (0 = noninterlaced; 1 = 2:1 interlace)
    u8_dpx interlace;
    // field number of the first field in the file
    // 0    where field designation is inappropriate
    // 1|2  for component video
    // 1-4  for NTSC or component video decoded from NTSC
    // 1-12 for PAL or component video decoded from PAL
    u8_dpx field_number;
    // video signal standard
    // @see VideoSignal::Code in dpxCodes.h
    u8_dpx video_signal;
    // zero (for byte alignment)
    u8_dpx zero;
    // horizontal sampling rate (Hz) at which samples were acquired
    r32_dpx horizontal_sampling;
    // vertical sampling rate (Hz) at which the scanning of the whole extent of
    // the image is repeated, even if each such scan is incomplete
    r32_dpx vertical_sampling;
    // temporal sampling rate or frame rate (Hz)
    r32_dpx temporal_sampling;
    // time offset from sync to first pixel (microseconds)
    r32_dpx time_offset;
    // gamma defines the power law exponent that represents the gamma
    // correction applied to a video image. (Y = X 1/gamma)
    r32_dpx gamma;
    // Defines the digital code value representing reference black (camera lens
    // capped, RGB signal set to 0 mV).
    r32_dpx black_level;
    // linear gain applied to signals below the breakpoint
    r32_dpx black_gain;
    // signal level above which the gamma law is applied
    r32_dpx breakpoint;
    // digital code value representing reference white (90% reflectance white
    // card, RGB signal set to 700 mV)
    r32_dpx ref_white_level;
    // temporal sampling aperture of the television camera
    r32_dpx integration_times;
    // reserved for future use
    tbd_dpx reserved[76];
    
} DPXTelevision;



/**

Not-Yet-Supported

USER_DEFINED_DATA {
75  2048  32  ASCII  User identification 
76  2080  xx  TBD    User defined ---- Postage stamp, processing logs, etc. 
                     Length is variable with maximum length of 1 Mbyte. 
} USER_DEFINED_DATA



IMAGE_DATA {
77  xxxx  xx  Array  Image data should start at block boundary (8-K blocks are
                     U8*4 recommended for efficient use of tape-storage devices).
} IMAGE_DATA

**/

typedef struct _DPXHeader {
    DPXFileHeader        file;
    DPXImageHeader       image;
    DPXImageOrientation  orient;
    DPXMotionPictureFilm film;
    DPXTelevision        tv;
} DPXHeader;



#endif // DPX_HEADER_H
