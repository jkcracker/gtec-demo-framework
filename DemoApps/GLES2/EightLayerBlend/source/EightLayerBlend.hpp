#ifndef GLES2_EIGHTLAYERBLEND_EIGHTLAYERBLEND_HPP
#define GLES2_EIGHTLAYERBLEND_EIGHTLAYERBLEND_HPP
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

#include <FslDemoAppGLES2/DemoAppGLES2.hpp>
#include <FslGraphicsGLES2/GLProgram.hpp>
#include <FslGraphicsGLES2/GLTexture.hpp>
#include <FslGraphicsGLES2/GLVertexBuffer.hpp>
#include <FslGraphicsGLES2/GLValues.hpp>
#include <FslBase/Math/Point2.hpp>
#include <FslBase/Math/Matrix.hpp>

namespace Fsl
{
  class EightLayerBlend : public DemoAppGLES2
  {
    GLES2::GLProgram m_program;
    GLES2::GLVertexBuffer m_vertexBuffer;
    GLint m_locMatModelViewProj;
    Point2 m_layerSize;

    struct LayerRecord
    {
      GLES2::GLTexture Texture;
      float Position;
      LayerRecord()
        : Texture()
        , Position(0)
      {
      }
    };
    static const int32_t LAYER_COUNT = 8;
    LayerRecord m_layers[LAYER_COUNT];
    float m_angle;
    Matrix m_matViewProj;
  public:
    EightLayerBlend(const DemoAppConfig& config);
    ~EightLayerBlend();
  protected:
    virtual void Update(const DemoTime& demoTime) override;
    virtual void Draw(const DemoTime& demoTime) override;
  };
}

#endif