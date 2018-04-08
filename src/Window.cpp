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

#include "Window.h"
#include "exception.h"
#include "src/obj/Screw.h"

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

	glfwWin = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - OpenGL 01", nullptr, nullptr);

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

	Shader shader = Shader("basic", "basic");

	anim::Screw srubka = anim::Screw();


	while (!glfwWindowShouldClose(glfwWin)) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 model, view, projection;

		model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
		projection = glm::perspective(glm::radians(45.0f), (float) 800 / (float) 600, 0.1f, 100.0f);

		float radius = 10.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

		shader.setMat4("projection", projection);
		shader.setMat4("model", model);
		shader.setMat4("view", view);


		srubka.render(shader);

		glfwPollEvents();
		glfwSwapBuffers(glfwWin);
	}


	glfwTerminate();

	return *this;
}

void Window::windowLoop() {

}
