## ======================================================================== ##
## Copyright 2009-2017 Intel Corporation                                    ##
##                                                                          ##
## Licensed under the Apache License, Version 2.0 (the "License");          ##
## you may not use this file except in compliance with the License.         ##
## You may obtain a copy of the License at                                  ##
##                                                                          ##
##     http://www.apache.org/licenses/LICENSE-2.0                           ##
##                                                                          ##
## Unless required by applicable law or agreed to in writing, software      ##
## distributed under the License is distributed on an "AS IS" BASIS,        ##
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. ##
## See the License for the specific language governing permissions and      ##
## limitations under the License.                                           ##
## ======================================================================== ##

# This file shows the components of putting together an OSPRay module. An
# OSPRay module is a library which can be linked or loaded at runtime (via the
# ospLoadModule() API call) to allow OSPRay object creation functions to find
# additional objects to enable the API to use.

# It is important to note that OSPRay modules are indended to be self-contained
# directories that live in the ospray/modules directory, which reuse OSPRay's
# CMake macros such as ospray_create_library() and ospray_create_application().

# By convention, it's nice to have the ability to turn on/off a module in the
# build. Thus we have a option defined here, which can be toggled with passing
# "-DOSPRAY_MODULE_DEMO=ON:OFF", or through using ccmake/cmake-gui.
option(OSPRAY_MODULE_DEMO "Build Demonstration Module" ON)

# Only build the following code if the module is turned 'ON'.
if (OSPRAY_MODULE_DEMO)

# Step 1 --> (optional) find external dependencies for this module
#     - Here you may want to do a find_package() to grab an external library,
#       adding include files via include_directories(), and adding libs to
#       the 'LINK' section of an ospray_create_*() call.

# Step 2 --> build the module library
#     - This is where you build the library which defines the custom OSPRay
#       objects you intend to use.
#     - NOTE: All modules must follow the naming convention:
#            "ospray_module_${MODULE_NAME}" where the value of ${MODULE_NAME}
#            is the string handed to ospLoadModule() if the app will load the
#            module at runtime. Otherwise, linking the library at compile-time
#            removes the need for any naming convention.
#     - Apps would call ospLoadModule("mymodule") for the example below.

  ospray_create_library(ospray_module_mymodule
    MyRenderer.cpp
    MyRenderer.h
    MyRenderer.ispc
    mymodule_init.cpp
    LINK
    ospray
  )

# Step 3 --> (optional) build a sample application
#     - You may find it useful to build a sample app to show off features in
#       your module. Because the module is built in the OSPRay source tree, all
#       code in the apps/ directory is ok to use here (though it may change
#       without notice). Be sure to use the ospray_create_application() macro
#       if you create a custom app.

endif()
