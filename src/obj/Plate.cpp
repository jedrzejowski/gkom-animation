//
// Created by adam on 17.04.18.
//

#include <src/3d/Point3D.h>
#include "Plate.h"

using namespace gkom;
using namespace gengine;

anim::Plate::Plate(Animation *anim) :
		Abs3DObj(anim) {

	textureWood = Texture("wood.png");
	textureBricks = Texture("brick.png");
	modelMatrix = glm::mat4(1.0f);

	initVertices();

	insertObjToBuffers();
}

anim::Plate::~Plate() {
	delete vertices, indices;
}

void anim::Plate::initVertices() {

	float texScale = 10.0f;

	uint I = 0;
	float r = 1.0f, x, y, z;

	verticesNum = 4 * 6;
	vertices = new Point3DeX[verticesNum]{
			//Prawa
			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(texScale, texScale)),

			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(texScale, texScale)),

			//Lewa
			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(texScale, texScale)),

			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(texScale, texScale)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),

			//Dolna
			Point3DeX(-0.5f, -0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, -0.5f, -0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(-0.5f, -0.5f, 0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(0.5f, -0.5f, 0.5f, TexCoord(texScale, texScale)),

			Point3DeX(-0.5f, 0.5f, -0.5f, TexCoord(0.0f, 0.0f)),
			Point3DeX(0.5f, 0.5f, -0.5f, TexCoord(texScale, 0.0f)),
			Point3DeX(-0.5f, 0.5f, 0.5f, TexCoord(0.0f, texScale)),
			Point3DeX(0.5f, 0.5f, 0.5f, TexCoord(texScale, texScale)),
	};

	I = 0;
	indicesNum = 6 * 2;
	indices = new SimpleTriangle[indicesNum];

	for (uint i = 0; i < 6; i++) {
		indices[I++] = SimpleTriangle(0, 1, 3) + 4 * i;
		indices[I++] = SimpleTriangle(0, 3, 2) + 4 * i;
	}

	Point3DeX::CalcNormals(vertices, verticesNum, indices, indicesNum);
}

void anim::Plate::render(Window *window) {

	anim->getShader().setMat4("model", modelMatrix);

	textureWood.use();
	draw(0, 1);
	draw(5, 6);
	textureBricks.use();
	draw(9, 10);
}
