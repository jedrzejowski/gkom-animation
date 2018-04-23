cmake_minimum_required(VERSION 3.10)
project(gkom_animation)
find_package(PkgConfig)

#set(CMAKE_CXX_COMPILER "clang")

set(CMAKE_CXX_STANDARD 11)
set(APP_TARGET gkom_animation)

include_directories(${PROJECT_SOURCE_DIR})


add_executable(${APP_TARGET} main.cpp)

#gEngine
target_sources(${APP_TARGET} PUBLIC
		src/3d/Point3D.h
		src/3d/Point3D.cpp

		src/3d/Texture.h
		src/3d/Texture.cpp
		src/3d/Light.h
		src/3d/Light.cpp
		src/3d/Shader.h
		src/3d/Shader.cpp
		src/3d/Camera.h
		src/3d/Camera.cpp

		src/3d/Window.h
		src/3d/Window.cpp
		src/3d/Animation.h
		src/3d/Animation.cpp
		src/3d/Abs3DObj.cpp
		src/3d/Abs3DObj.h

		src/3d/gEngine.h)

target_sources(${APP_TARGET} PUBLIC
		src/lib/stb_image.h
		src/FileSystem.cpp
		src/FileSystem.h
		src/exception.cpp
		src/exception.h
		src/MyWindow.cpp
		src/MyWindow.h
		src/obj/Nut.cpp
		src/obj/Nut.h
		src/obj/Wrench.cpp
		src/obj/Wrench.h
		src/obj/MyAnimation.cpp
		src/obj/MyAnimation.h
		src/obj/Screw.cpp
		src/obj/Screw.h
		src/obj/Plate.cpp
		src/obj/Plate.h
		src/obj/createPoint3DeX.h)

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