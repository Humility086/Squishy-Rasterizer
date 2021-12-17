#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <limits>

//==============================
//self contained project headers
//==============================
#include "Window/Window.h"

//================
//Vendor libraries
//================

//GLM - https://glm.g-truc.net/0.9.9/
//GLM is licenced under - The Happy Bunny License (Modified MIT License) - https://glm.g-truc.net/copying.txt
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/matrix_access.hpp>

//SDL2 (x64 used - please obtain dll from SDL (if required) https://www.libsdl.org/download-2.0.php - Runtime binary
//SDL 2.0 and newer are available under the zlib license - https://www.zlib.net/zlib_license.html
#include <SDL.h>

//Squishy simple obj
//Self developed by yours truly, MIT license - https://github.com/Humility086/Squishy-simple-obj
#include "..\Vendor\Humility\Squishy_obj.h"