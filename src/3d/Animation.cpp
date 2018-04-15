//
// Created by adam on 14.04.18.
//

#include <src/3d/Point3D.h>

#include "Animation.h"

using namespace gkom;

Animation::Animation() :
		vboCounter(0),
		eboCounter(0){

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

}

uint Animation::insertIntoVBO(GLsizei size, const void *data) {

	glBufferData(GL_ARRAY_BUFFER, Point3DeX::SIZE * size, data, GL_STATIC_DRAW);

	auto temp = vboCounter;
	vboCounter += size;
	return temp;
}

uint Animation::insertIntoEBO(GLsizei size, const void *data) {

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, SimpleTriangle::SIZE * size, data, GL_STATIC_DRAW);

	auto temp = eboCounter;
	eboCounter += SimpleTriangle::SIZE * size;
	return temp;
}


Animation::~Animation() {
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}

