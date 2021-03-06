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

#ifndef _V_NODE_DISK_CONTROLLER_
#define _V_NODE_DISK_CONTROLLER_

#include <IOKit/IOService.h>
 #include "VNodeDiskDevice.h"

#define VNodeDiskControllerClass com_parusinskimichal_VNodeDiskController

class VNodeDiskControllerClass : public IOService
{
  OSDeclareDefaultStructors(VNodeDiskControllerClass)

public:
  virtual bool init(OSDictionary *dictionary = 0);

  virtual void free(void);

  virtual IOService * probe(IOService *provider, SInt32 *score);

  virtual bool start(IOService *provider);

  virtual void stop(IOService *provider);

  // Returns name of the device
  bool createVNodeWithFilePathAndBlockSizeAndBlockNum(
  	const char * filePath, UInt64 blockSize, UInt64 blockNum);

  bool deleteVNodeWithFilePath(const char * filePath);

  bool deleteAllVNodes();

private:
	bool deregisterVNode(VNodeDiskDeviceClass * vnodeDisk);

	OSDictionary * m_VNodeLibraryByPath;

};

#endif // _V_NODE_DISK_CONTROLLER_
