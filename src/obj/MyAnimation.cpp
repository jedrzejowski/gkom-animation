//
// Created by adam on 15.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <src/3d/Point3D.h>
#include <src/lib/glm_ext.hpp>
#include "MyAnimation.h"
#include "Screw.h"


gkom::anim::MyAnimation::MyAnimation() {
	klucz = new Wrench(this);
	nakrentka = new Nut(this);
	sruba = new Screw(this);
	podkladka = new Plate(this);

	nakrentkaM4 = nakrentka->modelMatrix;
	nakrentkaM4 = glm::scale(nakrentkaM4, glm::vec3(0.67f));
	nakrentkaM4 = glm::rotate(nakrentkaM4, 3.14f / 8, glm::vec3(0.0, 1.0, 0.0));
	nakrentkaM4 = glm::rotate(nakrentkaM4, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));

	sruba->modelMatrix = glm::scale(sruba->modelMatrix, glm::vec3(0.33f, 15.0f, 0.33f));
	sruba->modelMatrix = glm::rotate(sruba->modelMatrix, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));

	kluczM4 = glm::mat4(1.0f);
	kluczM4 = glm::rotate(kluczM4, 3.14f / 2, glm::vec3(1.0, 0.0, 0.0));
	kluczM4 = glm::scale(kluczM4, glm::vec3(1.67f, 1.67f, 1.33f));

	podkladka->modelMatrix = glm::translate(podkladka->modelMatrix, glm::vec3(-5.0f, -10.0f, -5.0f));
	podkladka->modelMatrix = glm::scale(podkladka->modelMatrix, glm::vec3(10.0f, 10.0f, 10.0f));
	podkladka->modelMatrix = glm::rotate(podkladka->modelMatrix, 3.14f / 25, glm::vec3(0.0f, 1.0f, 0.0f));
}

gkom::anim::MyAnimation::~MyAnimation() {
	delete nakrentka, klucz, sruba, podkladka;
}

void gkom::anim::MyAnimation::render(gkom::Window *window) {

	float angle = glfwGetTime() / 5;

	klucz->modelMatrix = glm::rotate(kluczM4, angle, glm::vec3(0.0, 0.0, 1.0));
	klucz->modelMatrix = glm::translate(klucz->modelMatrix, glm::vec3(0.0f, -0.8f, 0.0f));

	nakrentka->modelMatrix = glm::rotate(nakrentkaM4, angle, glm::vec3(0.0, 0.0, 1.0));

	podkladka->render(window);
//	nakrentka->render(window);
//	sruba->render(window);
//	klucz->render(window);

}

