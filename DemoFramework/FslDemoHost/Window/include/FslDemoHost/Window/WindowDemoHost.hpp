#ifndef FSLDEMOHOST_WINDOW_WINDOWDEMOHOST_HPP
#define FSLDEMOHOST_WINDOW_WINDOWDEMOHOST_HPP
/****************************************************************************************************************************************************
* Copyright (c) 2016 Freescale Semiconductor, Inc.
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

#include <deque>
#include <vector>
#include <FslDemoApp/Base/Host/ConfigControl.hpp>
#include <FslDemoHost/Base/ADemoHost.hpp>
#include <FslNativeWindow/Base/NativeWindowSetup.hpp>

namespace Fsl
{
  class DemoHostCustomWindowSystem;
  class INativeWindow;
  class INativeWindowSystem;
  class WindowDemoHostOptionParser;
  class WindowHostService;

  class WindowDemoHost
    : public ADemoHost
  {
    DemoHostConfig m_demoHostConfig;
    bool m_isActivated;
    DemoHostFeature m_activeApi;
    std::shared_ptr<WindowDemoHostOptionParser> m_options;
    std::shared_ptr<WindowHostService> m_windowHostService;
    std::unique_ptr<NativeWindowSetup> m_nativeWindowSetup;
    std::shared_ptr<DemoHostCustomWindowSystem> m_customWindowSystem;
    std::shared_ptr<INativeWindowSystem> m_windowSystem;
    std::shared_ptr<INativeWindow> m_window;

  public:
    WindowDemoHost(const DemoHostConfig& demoHostConfig);
    ~WindowDemoHost();

    virtual void OnActivate();
    virtual void OnDeactivate();
    virtual void OnSuspend();
    virtual void OnResume();
    virtual DemoHostFeature GetActiveAPI() const;
    virtual Point2 GetScreenResolution() const;
    virtual bool SwapBuffers();
    virtual bool ProcessNativeMessages(const bool allowBlock);
  private:
    void Init();
    void Shutdown();
  };
}

#endif