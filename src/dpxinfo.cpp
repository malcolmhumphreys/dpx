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
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "dpx.h"

int main(int argc, char * const argv[]) {
    
    if(argc < 2) {
        std::cout << "dpxInfo: you need to pass in a dpx file (dpxInfo myframe.dpx)" << std::endl;
        return 1;
    }
    
    for(int x = 1; x < argc; x++) {
        
        std::string file(argv[1]);
        DpxReader in;
        
        if(!in.is_dpx(file)) {
            std::cout << "dpxInfo: " << file << " is not a dpx file" << std::endl;
            continue;
        }
        
        std::cout << "- dpx: " << file << std::endl;
        in.open(file);
        std::cout << in;
        
        if(in.is_complete())
            std::cout << "- dpx:is_complete: true" << std::endl;
        else
            std::cout << "- dpx:is_complete: false" << std::endl;
        
        std::cout << std::endl;
    }
    
}

