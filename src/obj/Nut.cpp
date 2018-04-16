//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <src/3d/Point3D.h>

#include "Nut.h"

using namespace gkom;
using namespace std;

anim::Nut::Nut(Animation *anim) :
		Abs3DObj(anim),
		shader("basic", "basic") {


	texture = Texture("metal.jpeg");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Nut::~Nut() {
	delete vertices;
	delete indices;
}

Point3DeX createPoint3DeX(float x, float y, float z, Color color) {
	return Point3DeX(x, y, z, color, TexCoord((x + 1) / 2, (y + 1) / 2));
}


void anim::Nut::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);

	vertclesNum = 8 * 2 * 2;
	vertices = new Point3DeX[vertclesNum];

	unsigned int I = 0;

	float ro = 1.0f, ri = 0.6f;
	float z = -0.25f;
	float deg2Rad = M_PI / 180, angle;

	//Punkty
	for (int i = 0; i < 2; i++) {

		for (uint a = 0; a < 8; a++) {
			angle = a * 45 * deg2Rad;
			vertices[I++] = createPoint3DeX(ro * sinf(angle), ro * cosf(angle), z, color);

			angle += 0.3926875; //22.5 stopni
			vertices[I++] = createPoint3DeX(ri * sinf(angle), ri * cosf(angle), z, color);
		}

		z += 0.5f;
	}

	//Ściany
	indicesNum = 8 * 2 * 2 + 8 * 2 * 2;
	indices = new SimpleTriangle[indicesNum];
	I = 0;

	for (uint n = 0, i; n < 7; n++) {
		i = n * 2;

		//Top
		indices[I++] = SimpleTriangle(i, i + 1, i + 2);
		indices[I++] = SimpleTriangle(i + 1, i + 2, i + 3);

		//WallOut
		indices[I++] = SimpleTriangle(i + 0, i + 2, i + 2 + 16);
		indices[I++] = SimpleTriangle(i + 0, i + 0 + 16, i + 2 + 16);

		//Bot
		indices[I++] = SimpleTriangle(i, i + 1, i + 2) + 16;
		indices[I++] = SimpleTriangle(i + 1, i + 2, i + 3) + 16;

		//WallIn
		indices[I++] = SimpleTriangle(i + 1, i + 3, i + 3 + 16);
		indices[I++] = SimpleTriangle(i + 1, i + 1 + 16, i + 3 + 16);
	}

	//Ostatni segment

	//Top
	indices[I++] = SimpleTriangle(14, 15, 0);
	indices[I++] = SimpleTriangle(15, 0, 1);
	//WallOut
	indices[I++] = SimpleTriangle(14, 0, 16);
	indices[I++] = SimpleTriangle(14, 30, 16);

	//Bot
	indices[I++] = SimpleTriangle(14, 15, 0) + 16;
	indices[I++] = SimpleTriangle(15, 0, 1) + 16;

	//WallIn
	indices[I++] = SimpleTriangle(15, 1, 17);
	indices[I++] = SimpleTriangle(15, 31, 17);

	indicesNum = I;


}

void anim::Nut::render(Window *window) {
	texture.use();

	shader.use();

	shader.setMat4("projection", window->getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window->getCameraMatrix());

	draw();
}


