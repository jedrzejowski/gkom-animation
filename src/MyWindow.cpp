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

#include <src/obj/MyAnimation.h>
#include "MyWindow.h"


using namespace gkom;

MyWindow::MyWindow() {

	projectionMatrix = glm::perspective(glm::radians(45.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);

	camera.position = glm::vec3(4.0f);
	camera.front = glm::vec3(-4.0f);
	camera.up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void MyWindow::initObjects() {
	anim = new anim::MyAnimation();
}

MyWindow::~MyWindow() {
	delete anim;
}

void MyWindow::keyCallback(GLFWwindow *window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 2.5f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.position += cameraSpeed * camera.front;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.position -= cameraSpeed * camera.front;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed * 2.0f;
		camera.front = -camera.position;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed * 2.0f;
		camera.front = -camera.position;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		anim->add2Angle(cameraSpeed);

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		anim->add2Angle(-cameraSpeed);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void MyWindow::windowLoop() {
	anim->render(this);
}
