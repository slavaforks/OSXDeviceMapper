/*

 Copyright (c) 2014, Michal Parusinski
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef _OSX_DEVICE_MAPPER_
#define _OSX_DEVICE_MAPPER_

#include <sys/fcntl.h>
#include <sys/vnode.h>

#include <IOKit/IOService.h>

#include "VNodeDiskDevice.h"

class com_parusinskimichal_OSXDeviceMapper : public IOService
{
    OSDeclareDefaultStructors(com_parusinskimichal_OSXDeviceMapper)

public:
    virtual bool init(OSDictionary *dictionary = 0);

    virtual void free(void);

    virtual IOService *probe(IOService *provider, SInt32 *score);

    virtual bool start(IOService *provider);

    virtual void stop(IOService *provider);

private:
    com_parusinskimichal_VNodeDiskDevice * m_vnodedisk;

};

#endif  // _OSX_DEVICE_MAPPER_
