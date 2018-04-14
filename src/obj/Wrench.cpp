//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <src/3d/Point3D.h>

#include "Wrench.h"

using namespace gkom;

anim::Wrench::Wrench() :
		shader("basic", "basic") {

	texture = Texture("metal.jpeg");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER,
				 Point3DeX::SIZE * vertclesNum, vertices,
				 GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				 SimpleTriangle::SIZE * indicesNum, indices,
				 GL_STATIC_DRAW);

	Point3DeX::BindGlVAP();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

anim::Wrench::~Wrench() {
	delete[] vertices;
}

void anim::Wrench::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);

	vertclesNum = (8 + 4) * 2;
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

		vertices[I++] = Point3DeX(a, -b * 5, z, color);
		vertices[I++] = Point3DeX(-a, -b * 5, z, color);

		vertices[I++] = Point3DeX(-a, -b, z, color, TexCoord((-a + 1) / 2, (-b + 1) / 2));
		vertices[I++] = Point3DeX(-b, -a, z, color, TexCoord((-b + 1) / 2, (-a + 1) / 2));
		vertices[I++] = Point3DeX(-b, a, z, color, TexCoord((-b + 1) / 2, (a + 1) / 2));
		vertices[I++] = Point3DeX(-a, b, z, color, TexCoord((-a + 1) / 2, (b + 1) / 2));

		vertices[I++] = Point3DeX(-a, -a, z, color);
		vertices[I++] = Point3DeX(a, -a, z, color);

		z += 0.5f;
	}

	//Ściany
	uint wallNum = 12;
	indicesNum = wallNum + 9;
	indices = new SimpleTriangle[indicesNum];
	I = 0;

	//Góra i dół
	for (int n = 0; n <= 12; n += 12) {

		indices[I++] = SimpleTriangle(11, 0, 1) + n;
		indices[I++] = SimpleTriangle(11, 1, 2) + n;
		indices[I++] = SimpleTriangle(11, 2, 3) + n;

		indices[I++] = SimpleTriangle(10, 9, 8) + n;
		indices[I++] = SimpleTriangle(10, 8, 7) + n;
		indices[I++] = SimpleTriangle(10, 7, 6) + n;

		indices[I++] = SimpleTriangle(10, 11, 4) + n;
		indices[I++] = SimpleTriangle(10, 5, 4) + n;

	}

	//Boki
	for (unsigned int i = 0; i < wallNum - 1; i++) {
		indices[I++] = SimpleTriangle(i + 0, i + 1, i + wallNum + 1);
		indices[I++] = SimpleTriangle(i + 0, i + wallNum, i + wallNum + 1);
	}

	indices[I++] = SimpleTriangle(wallNum - 1, 0, wallNum * 2 - 1);
	indices[I++] = SimpleTriangle(wallNum, 0, wallNum * 2 - 1);

	indicesNum = I;
}

void anim::Wrench::render(gkom::Window &window) {

	shader.setMat4("projection", window.getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window.getCameraMatrix());

	texture.use();
	shader.use();

	glBindVertexArray(VAO);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 3 * indicesNum, GL_UNSIGNED_INT, nullptr);
}
