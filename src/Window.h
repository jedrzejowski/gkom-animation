//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_WINDOW_H
#define GKOM_ANIMATION_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "src/3d/Shader.h"

namespace gkom {
	class Window {
	private:
		const GLuint WIDTH = 800, HEIGHT = 600;
		GLFWwindow *glfwWin;
		void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);

		void windowLoop();
	public:
		Window();

		Window init();
		Window open();
	};
}


#endif //GKOM_ANIMATION_WINDOW_H
