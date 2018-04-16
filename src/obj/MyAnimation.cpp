//
// Created by adam on 15.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <src/3d/Point3D.h>
#include "MyAnimation.h"
#include "Screw.h"


gkom::anim::MyAnimation::MyAnimation() {
	klucz = new Wrench(this);
	nakrentka = new Nut(this);
	sruba = new Screw(this);

	nakrentka->modelMatrix = glm::scale(nakrentka->modelMatrix, glm::vec3(0.67f));
	nakrentka->modelMatrix = glm::rotate(nakrentka->modelMatrix, 3.14f / 8, glm::vec3(0.0, 1.0, 0.0));
	nakrentka->modelMatrix = glm::rotate(nakrentka->modelMatrix, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));

	sruba->modelMatrix = glm::scale(sruba->modelMatrix, glm::vec3(0.33f, 15.0f, 0.33f));
	sruba->modelMatrix = glm::rotate(sruba->modelMatrix, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));

	klucz->modelMatrix = glm::translate(klucz->modelMatrix, glm::vec3(0.0f, 0.0f, -0.8f));
	klucz->modelMatrix = glm::rotate(klucz->modelMatrix, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));
	klucz->modelMatrix = glm::scale(klucz->modelMatrix, glm::vec3(1.67f, 1.67f, 1.33f));
}

gkom::anim::MyAnimation::~MyAnimation() {
	delete (nakrentka);
	delete (klucz);
}

void gkom::anim::MyAnimation::render(gkom::Window *window) {

	auto time = glfwGetTime();
	float angle = time / 360;

	//klucz->modelMatrix = glm::rotate(klucz->modelMatrix, angle, glm::vec3(0.0, 0.0, 1.0));
	//nakrentka->modelMatrix = glm::rotate(nakrentka->modelMatrix, angle, glm::vec3(0.0, 0.0, 1.0));

	nakrentka->render(window);
	sruba->render(window);
	klucz->render(window);
}

