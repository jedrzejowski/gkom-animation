//
// Created by adam on 07.04.18.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <src/obj/Wrench.h>

#include "Window.h"
#include "exception.h"
#include "src/obj/Screw.h"
#include "Animation.h"

using namespace gkom;

Window::Window() {
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	//cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

Window Window::init() {
	if (glfwInit() != GL_TRUE)
		throw gkom::exception("GLFW initialization failed");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DARWIN
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


	return *this;
}

Window Window::open() {

	glfwWin = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - Adam Jędrzejowski", nullptr, nullptr);

	if (glfwWin == nullptr)
		throw exception("Can't open GLFW window");

	glfwMakeContextCurrent(glfwWin);
	//glfwSetKeyCallback(glfwWin, keyCallback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw gkom::exception("GLEW initialization failed");

	glViewport(0, 0, WIDTH, HEIGHT);

	// configure global opengl state
	glEnable(GL_DEPTH_TEST);

	cameraMatrix = glm::lookAt(glm::vec3(0.0f, 3.0f, 3.0f),
							 glm::vec3(0.0f, 0.0f, 0.0f),
							 glm::vec3(0.0f, 1.0f, 0.0f));

	projectionMatrix = glm::perspective(glm::radians(45.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);

	Animation anim = Animation();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(glfwWin)) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		anim.render(*this);

		glfwPollEvents();
		glfwSwapBuffers(glfwWin);
	}


	glfwTerminate();

	return *this;
}

void Window::windowLoop() {

}
