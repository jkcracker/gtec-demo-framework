#ifdef __ANDROID__
/****************************************************************************************************************************************************
* Copyright (c) 2014 Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*
*    * Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*
*    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
*      its contributors may be used to endorse or promote products derived from
*      this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************************************************************************************/

#include "VulkanNativeWindowSystemAndroid.hpp"
#include "VulkanNativeWindowAndroid.hpp"
#include <FslNativeWindow/Vulkan/NativeVulkanSetup.hpp>
#include <FslNativeWindow/Platform/Android/PlatformNativeWindowSystemAndroidTag.hpp>
#include <FslBase/Log/Log.hpp>
#include <FslGraphics/Exceptions.hpp>
#include <RapidVulkan/Check.hpp>


#if 1
#define LOCAL_LOG(X) FSLLOG("VulkanNativeWindowSystemAndroid: " << X)
#else
#define LOCAL_LOG(X) {}
#endif

namespace Fsl
{
  namespace
  {
    const auto PLATFORM_KHR_SURFACE_EXTENSION_NAME = VK_KHR_ANDROID_SURFACE_EXTENSION_NAME;

    std::shared_ptr<INativeWindow> AllocateWindow(const NativeWindowSetup& nativeWindowSetup, const PlatformNativeWindowParams& windowParams, const PlatformNativeWindowAllocationParams*const pPlatformCustomWindowAllocationParams)
    {
      const auto pNativeVulkanSetup = dynamic_cast<const NativeVulkanSetup*>(pPlatformCustomWindowAllocationParams);
      if (!pNativeVulkanSetup)
        throw NotSupportedException("NativeVulkanSetup pointer expected");

      return std::make_shared<VulkanNativeWindowAndroid>(nativeWindowSetup, windowParams, pPlatformCustomWindowAllocationParams);
    }

    NativeVulkanSetup ToNativeVulkanSetup(const PlatformNativeWindowAllocationParams*const pPlatformCustomWindowAllocationParams)
    {
      const auto pNativeSetup = dynamic_cast<const NativeVulkanSetup*>(pPlatformCustomWindowAllocationParams);
      if (!pNativeSetup)
        throw NotSupportedException("NativeVulkanSetup pointer expected");
      return *pNativeSetup;
    }
  }


  VulkanNativeWindowSystemAndroid::VulkanNativeWindowSystemAndroid(const NativeWindowSystemSetup& setup)
    : VulkanNativeWindowSystemTemplate<PlatformNativeWindowSystemAndroid>(setup, PLATFORM_KHR_SURFACE_EXTENSION_NAME, AllocateWindow)
  {
  }


  VulkanNativeWindowAndroid::VulkanNativeWindowAndroid(const NativeWindowSetup& nativeWindowSetup, const PlatformNativeWindowParams& windowParams, const PlatformNativeWindowAllocationParams*const pPlatformCustomWindowAllocationParams)
    : AVulkanNativeWindow(ToNativeVulkanSetup(pPlatformCustomWindowAllocationParams))
    , PlatformNativeWindowAndroid(nativeWindowSetup, windowParams, pPlatformCustomWindowAllocationParams)
  {

    VkAndroidSurfaceCreateInfoKHR surfaceCreateInfoKHR{};
    surfaceCreateInfoKHR.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfoKHR.window = GetPlatformWindow();

    RAPIDVULKAN_CHECK(vkCreateAndroidSurfaceKHR(m_instance, &surfaceCreateInfoKHR, nullptr, &m_surface));
  }


  VulkanNativeWindowAndroid::~VulkanNativeWindowAndroid()
  {
  }


  PlatformNativeWindowType VulkanNativeWindowAndroid::GetWindowType() const
  {
    return GetPlatformWindow();
  }

}
#endif