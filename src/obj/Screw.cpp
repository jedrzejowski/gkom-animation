//
// Created by adam on 07.04.18.
//

#include <cstdlib>
#include <src/3d/Point3D.h>
#include <iostream>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Screw.h"

using namespace gkom;
using namespace std;


anim::Screw::Screw() {

	texture = Texture("metal.jpeg");
	initVertices();

	stride = sizeof(Point3DeX);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, stride * vertclesNum, vertices, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicesNum, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *) Point3D::OFFSET);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void *) Color::OFFSET);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void *) TexCoord::OFFSET);
	glEnableVertexAttribArray(2);

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
	Color color = Color(1.0f, 0.0f, 0.0f);

	vertclesNum = 16;
	vertices = new Point3DeX[vertclesNum];

	unsigned int I = 0;

	auto b = 1.0f;
	auto a = (float) (b * sin(22.5 * M_PI / 180));
	float z = -0.25f;


	//Punkty
	for (int i = 0; i < 2; i++) {

		vertices[I++] = Point3DeX(a, b, z, color, TexCoord((a+1)/2, (b+1)/2));
		vertices[I++] = Point3DeX(b, a, z, color, TexCoord((b+1)/2, (a+1)/2));

		vertices[I++] = Point3DeX(b, -a, z, color, TexCoord((b+1)/2, (-a+1)/2));
		vertices[I++] = Point3DeX(a, -b, z, color, TexCoord((a+1)/2, (-b+1)/2));

		vertices[I++] = Point3DeX(-a, -b, z, color, TexCoord((-a+1)/2, (-b+1)/2));
		vertices[I++] = Point3DeX(-b, -a, z, color, TexCoord((-b+1)/2, (-a+1)/2));

		vertices[I++] = Point3DeX(-b, a, z, color, TexCoord((-b+1)/2, (a+1)/2));
		vertices[I++] = Point3DeX(-a, b, z, color, TexCoord((-a+1)/2, (b+1)/2));

		z += 0.5f;
	}

	//Ściany
	indicesNum = (6 + 6 + 8 * 2) * 3;
	indices = new unsigned int[indicesNum];
	I = 0;

	for (unsigned int i = 1; i <= 6; i++) {
		//Dół
		indices[I++] = 0;
		indices[I++] = i + 1;
		indices[I++] = i;
	}

	for (unsigned int i = 1; i <= 6; i++) {
		//Góra
		indices[I++] = 0 + 8;
		indices[I++] = i + 8 + 1;
		indices[I++] = i + 8;
	}

	for (unsigned int i = 0; i < 7; i++) {
		indices[I++] = i + 0;
		indices[I++] = i + 1;
		indices[I++] = i + 8;

		indices[I++] = i + 1;
		indices[I++] = i + 8;
		indices[I++] = i + 9;
	}


	indices[I++] = 7;
	indices[I++] = 0;
	indices[I++] = 15;

	indices[I++] = 8;
	indices[I++] = 0;
	indices[I++] = 15;

	indicesNum = I;
}

void anim::Screw::render(Window& window) {


	texture.use();
	window.defaultShader.use();

	glBindVertexArray(VAO);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 3 * indicesNum, GL_UNSIGNED_INT, nullptr);
}


