//
// Created by adam on 15.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "MyAnimation.h"
#include "Screw.h"

using namespace gkom;

anim::MyAnimation::MyAnimation() {
	shader = new Shader("basic", "basic");
	shader->use();
	shader->setInt("material.diffuse", 0);

	light = new Light();
	light->position = glm::vec3(5.0f, 4.0f, -3.0f);
	light->ambient = glm::vec3(0.2f);
	light->diffuse = glm::vec3(0.5f);
	light->specular = glm::vec3(1.0f);

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

	podkladka->modelMatrix = glm::scale(podkladka->modelMatrix, glm::vec3(50.0f));
	podkladka->modelMatrix = glm::rotate(podkladka->modelMatrix, 3.14f / 25, glm::vec3(0.0f, 1.0f, 0.0f));

	add2Angle(0.0f);
}

anim::MyAnimation::~MyAnimation() {
	delete nakrentka, klucz, sruba, podkladka;
	delete shader;
}

void anim::MyAnimation::render(Window *window) {

	shader->setMat4("projection", window->getProjectionMatrix());
	shader->setMat4("camera", window->getCamera().getMatrix());
	shader->setVec3("cameraPos", window->getCamera().position);

	shader->setLight("light", *light);

	shader->setVec3("material.specular", 0.5f, 0.5f, 0.5f);
	shader->setFloat("material.shininess", 64.0f);

	klucz->render(window);
	podkladka->render(window);
	nakrentka->render(window);
	sruba->render(window);
}

void anim::MyAnimation::add2Angle(float delta) {
	angle += delta;

	klucz->modelMatrix = glm::rotate(kluczM4, angle, glm::vec3(0.0, 0.0, 1.0));
	klucz->modelMatrix = glm::translate(klucz->modelMatrix, glm::vec3(0.0f, -0.8f, angle / 3 / 1.33));
	nakrentka->modelMatrix = glm::rotate(nakrentkaM4, angle, glm::vec3(0.0, 0.0, 1.0));
	nakrentka->modelMatrix = glm::translate(nakrentka->modelMatrix, glm::vec3(0.0f, 0.0f, angle / 3 / 0.67f));
}

