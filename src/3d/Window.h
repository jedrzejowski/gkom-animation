//
// Created by adam on 23.04.18.
//

#ifndef GKOM_ANIMATION_WINDOW_H
#define GKOM_ANIMATION_WINDOW_H

#include "../opengl.h"
#include "Camera.h"

namespace gengine {
	class Window {
	protected:
		const GLuint WIDTH = 800, HEIGHT = 600;
		GLFWwindow *glfwWin;
		glm::mat4 projectionMatrix;
		Camera camera;

		float currentFrame = 0.0f, deltaTime = 0.0f, lastFrame = 0.0f;

		virtual void keyCallback(GLFWwindow *window) = 0;
		virtual void windowLoop() = 0;

	public:

		virtual void initObjects() = 0;

		void open();

		Camera getCamera() {
			return camera;
		}

		glm::mat4 getProjectionMatrix() {
			return projectionMatrix;
		}

		virtual std::string getTitle() = 0;
	};
}


#endif //GKOM_ANIMATION_WINDOW_H
