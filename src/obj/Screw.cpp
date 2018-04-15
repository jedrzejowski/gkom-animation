//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <src/3d/Point3D.h>

#include "Screw.h"

using namespace gkom;
using namespace std;

anim::Screw::Screw(Animation *anim) :
		Abs3DObj(anim),
		shader("basic", "basic") {


	texture = Texture("metal.jpeg");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Screw::~Screw() {
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

void anim::Screw::render(Window *window) {

	shader.setMat4("projection", window->getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window->getCameraMatrix());

	texture.use();
	shader.use();

	draw();
}


