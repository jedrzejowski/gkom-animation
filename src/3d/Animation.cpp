//
// Created by adam on 14.04.18.
//

#include <src/3d/Point3D.h>

#include "Animation.h"

using namespace gkom;

Animation::Animation(){

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}


Animation::~Animation() {
	glDeleteVertexArrays(1, &VAO);
}

