//
// Created by adam on 16.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <src/3d/Point3D.h>

#include "Screw.h"

using namespace gkom;

anim::Screw::Screw(gkom::Animation *anim) :
		Abs3DObj(anim),
		shader("basic", "basic") {

	texture = Texture("iron.png");
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	initVertices();

	insertObjToBuffers();
}

anim::Screw::~Screw() {
	delete vertices;
	delete indices;
}

void anim::Screw::initVertices() {
	Color color = Color(1.0f, 0.0f, 0.0f);
	uint accuracy = 16;

	verticlesNum = accuracy * 2 + 2;
	vertices = new Point3DeX[verticlesNum];

	uint I = 0;

	float ro = 1.0f, ri = 0.6f;
	float z = -0.25f;
	float deg2Rad = M_PI / 180, angle;

	//Punkty
	for (int i = 0; i < 2; i++) {

		vertices[I++] = Point3DeX(0, 0, z, color);

		for (uint a = 0; a < accuracy; a++) {
			angle = a * 360 / accuracy * deg2Rad;
			vertices[I++] = Point3DeX(ro * sinf(angle), ro * cosf(angle), z, color);
		}

		z += 0.5f;
	}


	//Ściany
	indicesNum = accuracy * 4;
	indices = new SimpleTriangle[indicesNum];
	I = 0;

	for (uint i = 1; i <= accuracy; i++) {
		uint ct = 0, cb = accuracy + 1;
		uint p1t = i, p2t = (i == accuracy ? 1 : i + 1);
		uint p1b = p1t + cb, p2b = p2t + cb;

		indices[I++] = SimpleTriangle(p1t, p2t, ct);
		indices[I++] = SimpleTriangle(p1b, p2b, cb);

		indices[I++] = SimpleTriangle(p1t, p2t, p2b);
		indices[I++] = SimpleTriangle(p1t, p1b, p2b);

	}
}

void anim::Screw::render(gkom::Window *window) {
	texture.use();

	shader.use();

	shader.setMat4("projection", window->getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window->getCameraMatrix());

	draw();

}
