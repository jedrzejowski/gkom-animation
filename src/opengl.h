#pragma once

#define WINDOWS


#ifdef LINUX

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>


#endif // LINUX

#ifdef WINDOWS

#include "windows/GL/glew.h"

#include "windows/GLFW/glfw3.h"

#include "windows/glm/glm.hpp"
#include "windows/glm/vec3.hpp"
#include "windows/glm/mat4x4.hpp"
#include "windows/glm/detail/type_mat.hpp"

#include "windowsglm/gtc/matrix_transform.hpp"

#endif //WINDOWS


