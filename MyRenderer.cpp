// ======================================================================== //
// Copyright 2009-2017 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

// ospray
#include "MyRenderer.h"
#include "camera/PerspectiveCamera.h"
// ispc exports
#include "MyRenderer_ispc.h"

namespace ospray {

  MyRenderer::MyRenderer()
  {
    ispcEquivalent = ispc::MyRenderer_create(this);
  }

  std::string MyRenderer::toString() const
  {
    return "ospray::MyRenderer";
  }

  // This 'registers' MyRenderer as a valid renderer for OSPRay to create using
  // ospNewRenderer(). In this case, "my_renderer" is the string which will
  // create an instance of MyRenderer --> thus clients would call:
  //     auto renderer = ospNewRenderer("my_renderer");
  // in the client app to create one. This will only work if the module was
  // linked at compile time in the app, or the app calls:
  //     ospLoadModule("mymodule");
  // before trying to create the renderer!
  OSP_REGISTER_RENDERER(MyRenderer, my_renderer);

} // ::ospray
