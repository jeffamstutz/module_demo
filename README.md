
This module shows the CMake build system components to building a module, as
well as defining a very simple renderer. A module is free to add any type of
OSPRay object (cameras, renderers, volumes, geometries, etc.). The
CMakeLists.txt file contains comments to walk you though the expected CMake
structure, and comments in MyRenderer.h/.cpp/.ispc show basic structure
expected in OSPRay itself.

This particular module defines a simple raycast renderer "MyRenderer". In order
to use it, you can run the GLUT viewer as follows:

    % ospGlutViewer [dataset] --module mymodule --renderer my_renderer

