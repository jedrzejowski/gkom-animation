cmake_minimum_required(VERSION 3.10)
project(gkom_animation)
find_package(PkgConfig)

set(CMAKE_CXX_STANDARD 11)
set(APP_TARGET gkom_animation)


include_directories(${PROJECT_SOURCE_DIR})
add_executable(${APP_TARGET}
		main.cpp
		src/lib/stb_image.h
		src/FileSystem.cpp
		src/FileSystem.h
		src/3d/Shader.cpp
		src/3d/Shader.h
		src/exception.cpp
		src/exception.h
		src/Window.cpp
		src/Window.h
		src/3d/Abs3DObj.cpp
		src/3d/Abs3DObj.h
		src/obj/Screw.cpp
		src/obj/Screw.h
		src/3d/Point3D.h src/3d/Texture.cpp src/3d/Texture.h)

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

# glm
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_libraries(${GLM_LIBRARY_DIRS})


target_link_libraries(
		${APP_TARGET}
		glfw
		${OPENGL_LIBRARIES}
		${GLEW_LIBRARIES}
		${GLM_LIBRARIES}
		${EXTRA_LIBS}
)