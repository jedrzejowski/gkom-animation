//
// Created by adam on 15.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <src/3d/Point3D.h>
#include "MyAnimation.h"



gkom::anim::MyAnimation::MyAnimation() {
	srubka1 = new Screw(this);
	klucz  = new Wrench(this);

	Point3DeX::BindGlVAP();

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//klucz.modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
//	srubka2->modelMatrix = glm::translate(srubka2->modelMatrix, glm::vec3( 1.0f,  1.0f, -1.0f));
//	klucz->modelMatrix = glm::translate(klucz->modelMatrix, glm::vec3( -1.0f,  -1.0f, -1.0f));
}

gkom::anim::MyAnimation::~MyAnimation() {
//	delete(srubka1);
//	delete(srubka2);
//	delete(klucz);
}

void gkom::anim::MyAnimation::render(gkom::Window *window) {
	glBindVertexArray(VAO);

	srubka1->render(window);

	//klucz->render(window);
}

