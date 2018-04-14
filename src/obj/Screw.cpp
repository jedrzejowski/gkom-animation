//
// Created by adam on 07.04.18.
//

#include <cstdlib>
#include <src/3d/Point3D.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Screw.h"

using namespace gkom;
using namespace std;

anim::Screw::Screw() :
		shader("basic", "basic") {


	texture = Texture("metal.jpeg");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, Point3DeX::SIZE * vertclesNum, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, SimpleTriangle::SIZE * indicesNum, indices, GL_STATIC_DRAW);

	Point3DeX::BindGlVAP();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

anim::Screw::~Screw() {

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

		vertices[I++] = Point3DeX(a, b, z, color, TexCoord((a + 1) / 2, (b + 1) / 2));
		vertices[I++] = Point3DeX(b, a, z, color, TexCoord((b + 1) / 2, (a + 1) / 2));

		vertices[I++] = Point3DeX(b, -a, z, color, TexCoord((b + 1) / 2, (-a + 1) / 2));
		vertices[I++] = Point3DeX(a, -b, z, color, TexCoord((a + 1) / 2, (-b + 1) / 2));

		vertices[I++] = Point3DeX(-a, -b, z, color, TexCoord((-a + 1) / 2, (-b + 1) / 2));
		vertices[I++] = Point3DeX(-b, -a, z, color, TexCoord((-b + 1) / 2, (-a + 1) / 2));

		vertices[I++] = Point3DeX(-b, a, z, color, TexCoord((-b + 1) / 2, (a + 1) / 2));
		vertices[I++] = Point3DeX(-a, b, z, color, TexCoord((-a + 1) / 2, (b + 1) / 2));

		z += 0.5f;
	}

	//Ściany
	indicesNum = 6 + 6 + 8 * 2;
	indices = new SimpleTriangle[indicesNum];
	I = 0;

	//Dół
	for (unsigned int i = 1; i <= 6; i++)
		indices[I++] = SimpleTriangle(0, i + 1, i);

	//Góra
	for (unsigned int i = 1; i <= 6; i++)
		indices[I++] = SimpleTriangle(0, i + 1, i) + 8;

	//Boki
	for (unsigned int i = 0; i < 7; i++) {
		indices[I++] = SimpleTriangle(i + 0, i + 1, i + 8);
		indices[I++] = SimpleTriangle(i + 1, i + 8, i + 9);
	}

	indices[I++] = SimpleTriangle(7, 0, 15);
	indices[I++] = SimpleTriangle(8, 0, 15);

	indicesNum = I;


}

void anim::Screw::render(Window &window) {

	shader.setMat4("projection", window.getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window.getCameraMatrix());

	texture.use();
	shader.use();

	glBindVertexArray(VAO);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 3 * indicesNum, GL_UNSIGNED_INT, nullptr);
}


