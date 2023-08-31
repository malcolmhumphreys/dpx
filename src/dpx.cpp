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

#include <iostream>
#include <fstream>
#include <cstdio>
#include "dpx.h"

DPXHeader
DpxReader::header () {
    return m_header;
}

void
DpxReader::init () {
    
    //
    m_filename = "";
    
    // fill header with undefined values //
    m_header = DPXHeader();
    
    // file
    set_undefined(&m_header.file.magic_number);
    set_undefined(&m_header.file.offset);
    set_undefined(&m_header.file.header_format[0],
        sizeof(m_header.file.header_format));
    set_undefined(&m_header.file.image_file_size);
    set_undefined(&m_header.file.ditto_key);
    set_undefined(&m_header.file.generic_header_length);
    set_undefined(&m_header.file.industry_header_length);
    set_undefined(&m_header.file.user_header_length);
    set_undefined(&m_header.file.image_filename[0],
        sizeof(m_header.file.image_filename));
    set_undefined(&m_header.file.creation_datetime[0],
        sizeof(m_header.file.creation_datetime));
    set_undefined(&m_header.file.creator[0],
        sizeof(m_header.file.creator));
    set_undefined(&m_header.file.project_name[0],
        sizeof(m_header.file.project_name));
    set_undefined(&m_header.file.copyright_statement[0],
        sizeof(m_header.file.copyright_statement));
    set_undefined(&m_header.file.encryption_key);
    
    // image
    set_undefined(&m_header.image.image_orientation);
    set_undefined(&m_header.image.no_elements);
    set_undefined(&m_header.image.line_pixels);
    set_undefined(&m_header.image.image_lines);
    for(unsigned int e = 0; e < std::min((int)m_header.image.no_elements, 8); ++e) {
        set_undefined(&m_header.image.element[e].sign);
        set_undefined(&m_header.image.element[e].ref_low_data);
        set_undefined(&m_header.image.element[e].ref_low_quantity);
        set_undefined(&m_header.image.element[e].ref_high_data);
        set_undefined(&m_header.image.element[e].ref_high_quantity);
        set_undefined(&m_header.image.element[e].descriptor);
        set_undefined(&m_header.image.element[e].transfer);
        set_undefined(&m_header.image.element[e].colorimetric);
        set_undefined(&m_header.image.element[e].bit_size);
        set_undefined(&m_header.image.element[e].packing);
        set_undefined(&m_header.image.element[e].encoding);
        set_undefined(&m_header.image.element[e].offset);
        set_undefined(&m_header.image.element[e].eo_line_padding);
        set_undefined(&m_header.image.element[e].eo_image_padding);
        set_undefined(&m_header.image.element[e].description[0],
            sizeof(m_header.image.element[e].description));
    }
    
    // orient
    set_undefined(&m_header.orient.x_offset);
    set_undefined(&m_header.orient.y_offset);
    set_undefined(&m_header.orient.x_center);
    set_undefined(&m_header.orient.y_center);
    set_undefined(&m_header.orient.x_orig_size);
    set_undefined(&m_header.orient.y_orig_size);
    set_undefined(&m_header.orient.source_image_filename[0],
        sizeof(m_header.orient.source_image_filename));
    set_undefined(&m_header.orient.source_creation_datetime[0],
        sizeof(m_header.orient.source_creation_datetime));
    set_undefined(&m_header.orient.input_device_dev[0],
        sizeof(m_header.orient.input_device_dev));
    set_undefined(&m_header.orient.input_device_serial[0],
        sizeof(m_header.orient.input_device_serial));
    set_undefined(&m_header.orient.border_validity[0],
        sizeof(m_header.orient.border_validity));
    set_undefined(&m_header.orient.pixel_aspect[0],
        sizeof(m_header.orient.pixel_aspect));
    
    // film
    set_undefined(&m_header.film.mfg_id[0],
        sizeof(m_header.film.mfg_id));
    set_undefined(&m_header.film.type[0],
        sizeof(m_header.film.type));
    set_undefined(&m_header.film.perf_offset[0],
        sizeof(m_header.film.perf_offset));
    set_undefined(&m_header.film.prefix[0],
        sizeof(m_header.film.prefix));
    set_undefined(&m_header.film.count[0],
        sizeof(m_header.film.count));
    set_undefined(&m_header.film.format[0],
        sizeof(m_header.film.format));
    set_undefined(&m_header.film.frame_position);
    set_undefined(&m_header.film.sequence_length);
    set_undefined(&m_header.film.held_count);
    set_undefined(&m_header.film.frame_rate);
    set_undefined(&m_header.film.shutter_angle);
    set_undefined(&m_header.film.frame_ident[0],
        sizeof(m_header.film.frame_ident));
    set_undefined(&m_header.film.slate_info[0],
        sizeof(m_header.film.slate_info));
    
    // tv
    set_undefined(&m_header.tv.time_code);
    set_undefined(&m_header.tv.user_bits);
    set_undefined(&m_header.tv.interlace);
    set_undefined(&m_header.tv.field_number);
    set_undefined(&m_header.tv.video_signal);
    set_undefined(&m_header.tv.zero);
    set_undefined(&m_header.tv.horizontal_sampling);
    set_undefined(&m_header.tv.vertical_sampling);
    set_undefined(&m_header.tv.temporal_sampling);
    set_undefined(&m_header.tv.time_offset);
    set_undefined(&m_header.tv.gamma);
    set_undefined(&m_header.tv.black_level);
    set_undefined(&m_header.tv.black_gain);
    set_undefined(&m_header.tv.breakpoint);
    set_undefined(&m_header.tv.ref_white_level);
    set_undefined(&m_header.tv.integration_times);
}

bool
DpxReader::is_dpx (string filename) {
    
    // try and open the file
    ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        return false;
    }
    
    // read the magic_number from the file
    u32_dpx magic_number;
    ifs.read(reinterpret_cast<char*>(&magic_number), sizeof(magic_number));
    if(ifs.fail()) {
        return false;
    }
    
    if(magic_number == 0x53445058 || // "SDPX" (0x53445058 hex)
       magic_number == 0x58504453) { // "XPDS" (0x58504453 hex)
        return true;
    } else {
        std::cout << "The file [" << filename
                  << "] is not a DPX" << std::endl;
    }
    
    return false;
}

string
DpxReader::curr_filename () {
    return m_filename;
}

bool
DpxReader::supported () {
    
    if(curr_filename() == "")
        return false;
    
    bool support = true;
    for(unsigned int e = 0; e < std::min((int)m_header.image.no_elements, 8); ++e) {
        
        //&m_header.image.element[e].sign
        
        // components and packing order
        switch(m_header.image.element[e].descriptor) {
            case Descriptor::RGB:
            case Descriptor::RGBA:
                break;
            default:
                std::cout << "We don't support ["
                          << (Descriptor::Code)m_header.image.element[e].descriptor
                          << "] components and packing order" << std::endl;
                support = false;
                break;
        }
        
        // data bit size
        switch(m_header.image.element[e].bit_size) {
            case BitSize::BitInt10:
                break;
            default:
                std::cout << "We don't yet support ["
                          << (BitSize::Code)m_header.image.element[e].bit_size
                          << "] bit depth" << std::endl;
                support = false;
                break;
        }
        
        // data packing style
        switch(m_header.image.element[e].packing) {
            case DataPacking::FilledMethodA:
                break;
            default:
                std::cout << "We don't yet support ["
                          << (DataPacking::Code)m_header.image.element[e].packing
                          << "] data packing style" << std::endl;
                support = false;
                break;
        }
        
        //&m_header.image.element[e].encoding
    }
    
    return support;
}

bool
DpxReader::is_complete () {
    
    ifstream ifs(m_filename.c_str());
    if (!ifs.is_open()) {
        return false;
    }
    
    ifs.seekg(0, std::ios::end);
    if(m_header.file.image_file_size == ifs.tellg())
        return true;
    
    return false;
}

bool
DpxReader::open (string filename) {
    
    // fill header with undefined values
    init();
    
    // try and open the file
    ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        return false;
    }
    
    // read header into DpxHeader struct
    ifs.read(reinterpret_cast<char*>(&m_header), sizeof(m_header));
    if(ifs.fail()) {
        return false;
    }
    
    // store the name
    m_filename = filename;
    
    // does the file need to swap bytes
    m_byteswap = false;
    if(m_header.file.magic_number == 0x58504453) {
        
        m_byteswap = true;
        
        // file
        bswap(&m_header.file.offset);
        bswap(&m_header.file.image_file_size);
        bswap(&m_header.file.ditto_key);
        bswap(&m_header.file.generic_header_length);
        bswap(&m_header.file.industry_header_length);
        bswap(&m_header.file.user_header_length);
        bswap(&m_header.file.encryption_key);
        
        // image
        bswap(&m_header.image.image_orientation);
        bswap(&m_header.image.no_elements);
        bswap(&m_header.image.line_pixels);
        bswap(&m_header.image.image_lines);
        for(unsigned int e = 0; e < 8; ++e) {
            bswap(&m_header.image.element[e].sign);
            bswap(&m_header.image.element[e].ref_low_data);
            bswap(&m_header.image.element[e].ref_low_quantity);
            bswap(&m_header.image.element[e].ref_high_data);
            bswap(&m_header.image.element[e].ref_high_quantity);
            bswap(&m_header.image.element[e].packing);
            bswap(&m_header.image.element[e].encoding);
            bswap(&m_header.image.element[e].offset);
            bswap(&m_header.image.element[e].eo_line_padding);
            bswap(&m_header.image.element[e].eo_image_padding);
        }
        
        // orient
        bswap(&m_header.orient.x_offset);
        bswap(&m_header.orient.y_offset);
        bswap(&m_header.orient.x_center);
        bswap(&m_header.orient.y_center);
        bswap(&m_header.orient.x_orig_size);
        bswap(&m_header.orient.y_orig_size);
        for(unsigned int i = 0; i < 4; ++i)
            bswap(&m_header.orient.border_validity[i]);
        for(unsigned int i = 0; i < 2; ++i)
            bswap(&m_header.orient.pixel_aspect[i]);
        
        // film
        bswap(&m_header.film.frame_position);
        bswap(&m_header.film.sequence_length);
        bswap(&m_header.film.held_count);
        bswap(&m_header.film.frame_rate);
        bswap(&m_header.film.shutter_angle);
        
        // tv
        bswap(&m_header.tv.time_code);
        bswap(&m_header.tv.user_bits);
        bswap(&m_header.tv.horizontal_sampling);
        bswap(&m_header.tv.vertical_sampling);
        bswap(&m_header.tv.temporal_sampling);
        bswap(&m_header.tv.time_offset);
        bswap(&m_header.tv.gamma);
        bswap(&m_header.tv.black_level);
        bswap(&m_header.tv.black_gain);
        bswap(&m_header.tv.breakpoint);
        bswap(&m_header.tv.ref_white_level);
        bswap(&m_header.tv.integration_times);
    }
    
    // USER_DEFINED_DATA
    // IMAGE_DATA
    
    return true;
}

bool
DpxReader::close () {
    return false;
}

/** operator<< stream insertion for the DpxReader class */
std::ostream&
operator<< (std::ostream& out, DpxReader& io) {
    
    if(io.curr_filename() == "") return out;
    
    // file
    if(defined(io.header().file.magic_number))
    {
        u32_dpx magic = io.header().file.magic_number;
        out << "- dpx:file.magic_number: "
            << (char*)&magic << std::endl;
    }
    if(defined(io.header().file.offset))
        out << "- dpx:file.offset: "
            << io.header().file.offset << std::endl;
    if(defined(&io.header().file.header_format[0],
        sizeof(io.header().file.header_format)))
        out << "- dpx:file.header_format: "
            << io.header().file.header_format << std::endl;
    if(defined(io.header().file.image_file_size))
        out << "- dpx:file.image_file_size: "
            << io.header().file.image_file_size << std::endl;
    if(defined(io.header().file.ditto_key))
        out << "- dpx:file.ditto_key: "
            << io.header().file.ditto_key << std::endl;
    if(defined(io.header().file.generic_header_length))
        out << "- dpx:file.generic_header_length: "
            << io.header().file.generic_header_length << std::endl;
    if(defined(io.header().file.industry_header_length))
        out << "- dpx:file.industry_header_length: "
            << io.header().file.industry_header_length << std::endl;
    if(defined(io.header().file.user_header_length))
        out << "- dpx:file.user_header_length: "
            << io.header().file.user_header_length << std::endl;
    if(defined(&io.header().file.image_filename[0],
        sizeof(io.header().file.image_filename)))
        out << "- dpx:file.image_filename: "
            << io.header().file.image_filename << std::endl;
    if(defined(&io.header().file.creation_datetime[0],
        sizeof(io.header().file.creation_datetime)))
        out << "- dpx:file.creation_datetime: "
            << io.header().file.creation_datetime << std::endl;
    if(defined(&io.header().file.creator[0],
        sizeof(io.header().file.creator)))
        out << "- dpx:file.creator: "
            << io.header().file.creator << std::endl;
    if(defined(&io.header().file.project_name[0],
        sizeof(io.header().file.project_name)))
        out << "- dpx:file.project_name: "
            << io.header().file.project_name << std::endl;
    if(defined(&io.header().file.copyright_statement[0],
        sizeof(io.header().file.copyright_statement)))
        out << "- dpx:file.copyright_statement: "
            << io.header().file.copyright_statement << std::endl;
    if(defined(io.header().file.encryption_key))
        out << "- dpx:file.encryption_key: "
            << io.header().file.encryption_key << std::endl;
    
    // image
    if(defined(io.header().image.image_orientation))
        out << "- dpx:image.image_orientation: "
            << (Orientation::Code)io.header().image.image_orientation << std::endl;
    if(defined(io.header().image.no_elements))
        out << "- dpx:image.no_elements: "
            << io.header().image.no_elements << std::endl;
    if(defined(io.header().image.line_pixels))
        out << "- dpx:image.line_pixels: "
            << io.header().image.line_pixels << std::endl;
    if(defined(io.header().image.image_lines))
        out << "- dpx:image.image_lines: "
            << io.header().image.image_lines << std::endl;
    for(unsigned int e = 0; e < std::min((int)io.header().image.no_elements, 8); ++e) {
        if(defined(io.header().image.element[e].sign))
            out << "- dpx:image[" << e << "].sign: "
                << (DataSign::Code)io.header().image.element[e].sign << std::endl;
        if(defined(io.header().image.element[e].ref_low_data))
            out << "- dpx:image[" << e << "].ref_low_data: "
                << io.header().image.element[e].ref_low_data << std::endl;
        if(defined(io.header().image.element[e].ref_low_quantity))
            out << "- dpx:image[" << e << "].ref_low_quantity: "
                << io.header().image.element[e].ref_low_quantity << std::endl;
        if(defined(io.header().image.element[e].ref_high_data))
            out << "- dpx:image[" << e << "].ref_high_data: "
                << io.header().image.element[e].ref_high_data << std::endl;
        if(defined(io.header().image.element[e].ref_high_quantity))
            out << "- dpx:image[" << e << "].ref_high_quantity: "
                << io.header().image.element[e].ref_high_quantity << std::endl;
        if(defined(io.header().image.element[e].descriptor))
            out << "- dpx:image[" << e << "].descriptor: "
                << (Descriptor::Code)io.header().image.element[e].descriptor << std::endl;
        if(defined(io.header().image.element[e].transfer))
            out << "- dpx:image[" << e << "].transfer: "
                << (Transfer::Dpx_2::Code)io.header().image.element[e].transfer << std::endl;
        if(defined(io.header().image.element[e].colorimetric))
            out << "- dpx:image[" << e << "].colorimetric: "
                << (Colorimetric::Dpx_2::Code)io.header().image.element[e].colorimetric << std::endl;
        if(defined(io.header().image.element[e].bit_size))
            out << "- dpx:image[" << e << "].bit_size: "
                << (BitSize::Code)io.header().image.element[e].bit_size << std::endl;
        if(defined(io.header().image.element[e].packing))
            out << "- dpx:image[" << e << "].packing: "
                << (DataPacking::Code)io.header().image.element[e].packing << std::endl;
        if(defined(io.header().image.element[e].encoding))
            out << "- dpx:image[" << e << "].encoding: "
                << (DataEncoding::Code)io.header().image.element[e].encoding << std::endl;
        if(defined(io.header().image.element[e].offset))
            out << "- dpx:image[" << e << "].offset: "
                << io.header().image.element[e].offset << std::endl;
        if(defined(io.header().image.element[e].eo_line_padding))
            out << "- dpx:image[" << e << "].eo_line_padding: "
                << io.header().image.element[e].eo_line_padding << std::endl;
        if(defined(io.header().image.element[e].eo_image_padding))
            out << "- dpx:image[" << e << "].eo_image_padding: "
                << io.header().image.element[e].eo_image_padding << std::endl;
        if(defined(&io.header().image.element[e].description[0],
            sizeof(io.header().image.element[e].description)))
            out << "- dpx:image[" << e << "].description: "
                << io.header().image.element[e].description << std::endl;
    }
    
    // orient
    if(defined(io.header().orient.x_offset))
        out << "- dpx:orient.x_offset: "
            << io.header().orient.x_offset << std::endl;
    if(defined(io.header().orient.y_offset))
        out << "- dpx:orient.y_offset: "
            << io.header().orient.y_offset << std::endl;
    if(defined(io.header().orient.x_center))
        out << "- dpx:orient.x_center: "
            << io.header().orient.x_center << std::endl;
    if(defined(io.header().orient.y_center))
        out << "- dpx:orient.y_center: "
            << io.header().orient.y_center << std::endl;
    if(defined(io.header().orient.x_orig_size))
        out << "- dpx:orient.x_orig_size: "
            << io.header().orient.x_orig_size << std::endl;
    if(defined(io.header().orient.y_orig_size))
        out << "- dpx:orient.y_orig_size: "
            << io.header().orient.y_orig_size << std::endl;
    if(defined(&io.header().orient.source_image_filename[0],
        sizeof(io.header().orient.source_image_filename)))
        out << "- dpx:orient.source_image_filename: "
            << io.header().orient.source_image_filename << std::endl;
    if(defined(&io.header().orient.source_creation_datetime[0],
        sizeof(io.header().orient.source_creation_datetime)))
        out << "- dpx:orient.source_creation_datetime: "
            << io.header().orient.source_creation_datetime << std::endl;
    if(defined(&io.header().orient.input_device_dev[0],
        sizeof(io.header().orient.input_device_dev)))
        out << "- dpx:orient.input_device_dev: "
            << io.header().orient.input_device_dev << std::endl;
    if(defined(&io.header().orient.input_device_serial[0],
        sizeof(io.header().orient.input_device_serial)))
        out << "- dpx:orient.input_device_serial: "
            << io.header().orient.input_device_serial << std::endl;
    if(defined(&io.header().orient.border_validity[0], sizeof(io.header().orient.border_validity))) {
        out << "- dpx:orient.border_validity: ";
        for(unsigned int i = 0; i < 4; ++i)
            out << "[" << io.header().orient.border_validity[i] << "]";
        out <<  std::endl;
    }
    if(defined(&io.header().orient.pixel_aspect[0], sizeof(io.header().orient.pixel_aspect))) {
        out << "- dpx:orient.pixel_aspect: ";
        for(unsigned int i = 0; i < 2; ++i)
            out << "[" << io.header().orient.pixel_aspect[i] << "]";
        out <<  std::endl;
    }
    
    // film
    if(defined(&io.header().film.mfg_id[0],
        sizeof(io.header().film.mfg_id)))
        out << "- dpx:film.mfg_id: "
            << io.header().film.mfg_id << std::endl;
    if(defined(&io.header().film.type[0],
        sizeof(io.header().film.type)))
        out << "- dpx:film.type: "
            << io.header().film.type << std::endl;
    if(defined(&io.header().film.perf_offset[0],
        sizeof(io.header().film.perf_offset)))
        out << "- dpx:film.perf_offset: "
            << io.header().film.perf_offset << std::endl;
    if(defined(&io.header().film.prefix[0],
        sizeof(io.header().film.prefix)))
        out << "- dpx:film.prefix: "
            << io.header().film.prefix << std::endl;
    if(defined(&io.header().film.count[0],
        sizeof(io.header().film.count)))
        out << "- dpx:film.count: "
            << io.header().film.count << std::endl;
    if(defined(&io.header().film.format[0],
        sizeof(io.header().film.format)))
        out << "- dpx:film.format: "
            << io.header().film.format << std::endl;
    if(defined(io.header().film.frame_position))
        out << "- dpx:film.frame_position: "
            << io.header().film.frame_position << std::endl;
    if(defined(io.header().film.sequence_length))
        out << "- dpx:film.sequence_length: "
            << io.header().film.sequence_length << std::endl;
    if(defined(io.header().film.held_count))
        out << "- dpx:film.held_count: "
            << io.header().film.held_count << std::endl;
    if(defined(io.header().film.frame_rate))
        out << "- dpx:film.frame_rate: "
            << io.header().film.frame_rate << std::endl;
    if(defined(io.header().film.shutter_angle))
        out << "- dpx:film.shutter_angle: "
            << io.header().film.shutter_angle << std::endl;
    if(defined(&io.header().film.frame_ident[0],
        sizeof(io.header().film.frame_ident)))
        out << "- dpx:film.frame_ident: "
            << io.header().film.frame_ident << std::endl;
    if(defined(&io.header().film.slate_info[0],
        sizeof(io.header().film.slate_info)))
        out << "- dpx:film.slate_info: "
            << io.header().film.slate_info  << std::endl;
    
    // tv
    if(defined(io.header().tv.time_code))
        out << "- dpx:tv.time_code: "
            << TimeCode(io.header().tv.time_code) << std::endl;
    if(defined(io.header().tv.user_bits))
        out << "- dpx:tv.user_bits: "
            << io.header().tv.user_bits << std::endl;
    if(defined(io.header().tv.interlace))
        out << "- dpx:tv.interlace: "
            << (Interlace::Code)io.header().tv.interlace << std::endl;
    if(defined(io.header().tv.field_number))
        out << "- dpx:tv.field_number: "
            << (unsigned int)io.header().tv.field_number << std::endl;
    if(defined(io.header().tv.video_signal))
        out << "- dpx:tv.video_signal: "
            << (VideoSignal::Code)io.header().tv.video_signal << std::endl;
    //out << "- zero: [" << (unsigned int)io.header().tv.zero << "]" << std::endl;
    if(defined(io.header().tv.horizontal_sampling))
        out << "- dpx:tv.horizontal_sampling: "
            << io.header().tv.horizontal_sampling << std::endl;
    if(defined(io.header().tv.vertical_sampling))
        out << "- dpx:tv.vertical_sampling: "
            << io.header().tv.vertical_sampling << std::endl;
    if(defined(io.header().tv.temporal_sampling))
        out << "- dpx:tv.temporal_sampling: "
            << io.header().tv.temporal_sampling << std::endl;
    if(defined(io.header().tv.time_offset))
        out << "- dpx:tv.time_offset: "
            << io.header().tv.time_offset << std::endl;
    if(defined(io.header().tv.gamma))
        out << "- dpx:tv.gamma: "
            << io.header().tv.gamma << std::endl;
    if(defined(io.header().tv.black_level))
        out << "- dpx:tv.black_level: "
            << io.header().tv.black_level << std::endl;
    if(defined(io.header().tv.black_gain))
        out << "- dpx:tv.black_gain: "
            << io.header().tv.black_gain << std::endl;
    if(defined(io.header().tv.breakpoint))
        out << "- dpx:tv.breakpoint: "
            << io.header().tv.breakpoint << std::endl;
    if(defined(io.header().tv.ref_white_level))
        out << "- dpx:tv.ref_white_level: "
            << io.header().tv.ref_white_level << std::endl;
    if(defined(io.header().tv.integration_times))
        out << "- dpx:tv.integration_times: "
            << io.header().tv.integration_times << std::endl;
    
    return out;
}
