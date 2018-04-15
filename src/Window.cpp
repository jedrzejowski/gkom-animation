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
#include <src/obj/MyAnimation.h>

#include "Window.h"
#include "exception.h"
#include "src/obj/Screw.h"
#include "src/3d/Animation.h"

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

	projectionMatrix = glm::perspective(glm::radians(45.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);

	anim::MyAnimation anim = anim::MyAnimation();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(glfwWin)) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float radius = 10.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		glm::mat4 view;
		cameraMatrix = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

//		cameraMatrix = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f),
//								   glm::vec3(0.0f, 0.0f, 0.0f),
//								   glm::vec3(0.0f, 1.0f, 0.0f));

		anim.render(this);

		glfwPollEvents();
		glfwSwapBuffers(glfwWin);
	}


	glfwTerminate();

	return *this;
}

void Window::windowLoop() {

}
