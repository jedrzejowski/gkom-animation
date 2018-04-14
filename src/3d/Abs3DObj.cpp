//
// Created by adam on 07.04.18.
//

#include "Abs3DObj.h"

gkom::Abs3DObj::Abs3DObj() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

}

gkom::Abs3DObj::~Abs3DObj() {

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}
