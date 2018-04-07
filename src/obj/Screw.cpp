//
// Created by adam on 07.04.18.
//

#include <cstdlib>
#include <src/3d/Point3D.h>
#include <iostream>
#include <math.h>

#include "Screw.h"

using namespace gkom;

anim::Screw::Screw() {

	initVertices();

	stride = sizeof(Point3D);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, stride * 16, vertices, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 3 * 6, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point3D), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

anim::Screw::~Screw() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	delete[] vertices;
}

void anim::Screw::initVertices() {
	vertices = new Point3D[16];

	int I = 0;

	auto b = 1.0f;
	auto a = (float) (b * sin(22.5 * M_PI / 180));
	float z = -0.5f;

	//Punkty
	for (int i = 0, m; i < 2; i++) {

		vertices[I++] = Point3D(a, b, z);
		vertices[I++] = Point3D(b, a, z);

		vertices[I++] = Point3D(b, -a, z);
		vertices[I++] = Point3D(a, -b, z);

		vertices[I++] = Point3D(-a, -b, z);
		vertices[I++] = Point3D(-b, -a, z);

		vertices[I++] = Point3D(-b, a, z);
		vertices[I++] = Point3D(-a, b, z);

		z += 0.5f;
	}

	//Ściany
	indices = new unsigned int[(6 + 6 + 8 * 2) * 3];
	I = 0;

	//Dół i góra
	for (unsigned int i = 1; i <= 6; i++) {
		indices[I++] = 0;
		indices[I++] = i;
		indices[I++] = i + 1;

//		indices[I++] = 0 + 8;
//		indices[I++] = i + 8;
//		indices[I++] = i + 1 + 8;
	}

	for (unsigned int i = 0; i < 8; i++) {
		indices[I++] = i + 0;
		indices[I++] = i + 1;
		indices[I++] = i + 8;

		indices[I++] = i + 1;
		indices[I++] = i + 8;
		indices[I++] = i + 9;
	}

}

void anim::Screw::render() {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, (6 + 6 + 8 * 2) * 3, GL_UNSIGNED_INT, 0);
}


