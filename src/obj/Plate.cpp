//
// Created by adam on 17.04.18.
//

#include <src/3d/Point3D.h>
#include "Plate.h"

using namespace gkom;

anim::Plate::Plate(gkom::Animation *anim) :
		Abs3DObj(anim),
		shader("basic", "basic") {

	texture = Texture("wood.png");
	modelMatrix = glm::mat4(1.0f);

	initVertices();

	insertObjToBuffers();
}

anim::Plate::~Plate() {

}

void anim::Plate::initVertices() {

	uint I = 0;
	float r = 1.0f, x, y, z;

	verticlesNum = 4 * 6;
	vertices = new Point3DeX[verticlesNum]{
			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(1.0f, 1.0f)),

			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(1.0f, 1.0f)),

			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(1.0f, 1.0f)),

			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(1.0f, 1.0f)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),

			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(1.0f, 1.0f)),

			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(1.0f, 0.0f)),
			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, 1.0f)),
			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(1.0f, 1.0f)),
	};

	I = 0;
	indicesNum = 6 * 2;
	indices = new SimpleTriangle[indicesNum];

	for (uint i = 0; i < 6; i++) {
		indices[I++] = SimpleTriangle(0, 1, 3) + 4*i;
		indices[I++] = SimpleTriangle(0, 2, 3) + 4*i;
	}
}

void anim::Plate::render(Window *window) {
	texture.use();

	shader.use();

	shader.setMat4("projection", window->getProjectionMatrix());
	shader.setMat4("model", modelMatrix);
	shader.setMat4("camera", window->getCameraMatrix());

	draw();
}
