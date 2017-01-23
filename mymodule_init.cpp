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

#include <iostream>

// All ospLoadModule() compatible modules are required to define an
// initialization function which is of the following name/signature:
//     ospray_init_module_[module_name]()
// where [module_name] must match the name of the library. In this case, the
// module library is named "ospray_module_mymodule", where "mymodule" matches
// the end of the below function name.
extern "C" void ospray_init_module_mymodule()
{
  // Do nothing special here, just report we loaded the module successfully on
  // the command line.
  std::cout << "'mymodule' initialized!" << std::endl;
}
