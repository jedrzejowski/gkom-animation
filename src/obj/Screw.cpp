//
// Created by adam on 16.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Screw.h"

using namespace gkom;
using namespace gengine;

anim::Screw::Screw(Animation *anim) :
		Abs3DObj(anim) {

	texture = Texture("iron.png");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Screw::~Screw() {
	delete vertices, indices;
}

void anim::Screw::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);
	uint accuracy = 32;

	verticesNum = accuracy * 4;
	vertices = new Point3DeX[verticesNum];

	indicesNum = accuracy * 2;
	indices = new SimpleTriangle[indicesNum];

	uint I = 0, N = 0;

	float ro = 1.0f, ri = 0.6f;
	float z = -0.25f;
	float deg2Rad = M_PI / 180, angle1, angle2;

	//Punkty

	for (uint a = 0; a < accuracy; a++) {
		angle1 = a * 360 / accuracy * deg2Rad;
		angle2 = (a + 1) * 360 / accuracy * deg2Rad;

		indices[N++] = SimpleTriangle(I, I + 1, I + 2);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I + 1);

		vertices[I++] = Point3DeX(ro * sinf(angle1), ro * cosf(angle1), 1.0f, TexCoord(1.0f / accuracy * a, z * 20));
		vertices[I++] = Point3DeX(ro * sinf(angle1), ro * cosf(angle1), -1.0f, TexCoord(1.0f / accuracy * a, -z * 20));
		vertices[I++] = Point3DeX(ro * sinf(angle2), ro * cosf(angle2), 1.0f,
								  TexCoord(1.0f / accuracy * (a + 1), z * 20));
		vertices[I++] = Point3DeX(ro * sinf(angle2), ro * cosf(angle2), -1.0f,
								  TexCoord(1.0f / accuracy * (a + 1), -z * 20));
	}

	Point3DeX::CalcNormals(vertices, verticesNum, indices, indicesNum);
}

void anim::Screw::render(Window *window) {

	anim->getShader().setMat4("model", modelMatrix);
	texture.use();

	draw();
}
