//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <src/3d/Point3D.h>

#include "Nut.h"
#include "createPoint3DeX.h"

using namespace gkom;
using namespace std;
using namespace gengine;

anim::Nut::Nut(Animation *anim) :
		Abs3DObj(anim){


	texture = Texture("iron.png");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Nut::~Nut() {
	delete vertices, indices;
}


void anim::Nut::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);

	verticlesNum = 8 * 2 * 2;
	vertices = new Point3DeX[verticlesNum];

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
	anim->getShader().setMat4("model", modelMatrix);
	texture.use();

	draw();
}


