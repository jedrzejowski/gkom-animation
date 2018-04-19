//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <src/3d/Point3D.h>

#include "Wrench.h"
#include "createPoint3DeX.h"

using namespace gkom;

anim::Wrench::Wrench(Animation *anim) :
		Abs3DObj(anim) {

	texture = Texture("metal.jpeg");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Wrench::~Wrench() {
	delete vertices;
	delete indices;
}

void anim::Wrench::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);

	verticlesNum = (8 + 4) * 2;
	vertices = new Point3DeX[verticlesNum];

	unsigned int I = 0;

	auto b = 1.0f;
	auto a = (float) (b * sin(22.5 * M_PI / 180));
	float z = -0.25f;

	//Punkty
	for (int i = 0; i < 2; i++) {

		vertices[I++] = createPoint3DeX(a, b, z, color);
		vertices[I++] = createPoint3DeX(b, a, z, color);
		vertices[I++] = createPoint3DeX(b, -a, z, color);
		vertices[I++] = createPoint3DeX(a, -b, z, color);

		vertices[I++] = createPoint3DeX(a, -b * 5, z, color);
		vertices[I++] = createPoint3DeX(-a, -b * 5, z, color);

		vertices[I++] = createPoint3DeX(-a, -b, z, color);
		vertices[I++] = createPoint3DeX(-b, -a, z, color);
		vertices[I++] = createPoint3DeX(-b, a, z, color);
		vertices[I++] = createPoint3DeX(-a, b, z, color);

		vertices[I++] = createPoint3DeX(-a, -a, z, color);
		vertices[I++] = createPoint3DeX(a, -a, z, color);

		z += 0.5f;
	}

	//Ściany
	uint wallNum = 12;
	indicesNum = (wallNum + 9) * 2;
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


	Point3DeX::ClacNormals(vertices, verticlesNum, indices, indicesNum);
}

void anim::Wrench::render(gkom::Window *window) {
	texture.use();
	anim->getShader().setMat4("model", modelMatrix);

	draw();
}

