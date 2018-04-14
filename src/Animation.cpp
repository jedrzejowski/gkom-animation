//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Animation.h"

gkom::Animation::Animation(){

	//klucz.modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
	//klucz.modelMatrix = glm::translate(klucz.modelMatrix, glm::vec3( 2.0f,  2.0f, -2.0f));
}

void gkom::Animation::render(gkom::Window &window) {
	srubka1.render(window);
	srubka2.render(window);
	srubka3.render(window);
	//klucz.render(window);
}
