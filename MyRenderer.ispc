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

// included from ospray/ospray directory in source tree
#include "fb/FrameBuffer.ih"
#include "camera/PerspectiveCamera.ih"
#include "common/Model.ih"
#include "render/util.ih"
#include "render/Renderer.ih"

struct MyRenderer
{
  /*! the base "Renderer" we are derived from */
  uniform Renderer super;
};

// Renderers are responsible for providing a renderSample function (set in the
// create function below, basically a 'manual' virtual function). This just does
// simple raycasting w/ eyelight shading on any surfaces hit (no volumes here).
void MyRenderer_renderSample(uniform Renderer *uniform _self,
                             void *uniform perFrameData,
                             varying ScreenSample &sample)
{
  uniform MyRenderer *uniform self = (uniform MyRenderer *uniform)_self;

  traceRay(self->super.model, sample.ray);
  sample.z     = sample.ray.t;
  sample.alpha = 1.f;

  if (sample.ray.geomID < 0)
    sample.rgb = make_vec3f(1.f);
  else {
    const float c = dot(normalize(sample.ray.Ng), sample.ray.dir);
    sample.rgb = make_vec3f(.2f + .8f * abs(c));
  }
}

/* Creation function exported to C++ through "MyRenderer_ispc.h", called in
   MyRenderer::MyRenderer() on C++ side. */
export void *uniform MyRenderer_create(void *uniform cppE)
{
  uniform MyRenderer *uniform self = uniform new uniform MyRenderer;
  Renderer_Constructor(&self->super,cppE);
  self->super.renderSample = MyRenderer_renderSample;
  return self;
}
