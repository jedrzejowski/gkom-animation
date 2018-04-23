//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
	uint wallNum = 12;

	verticesNum = wallNum * 2 + wallNum * 4;
	vertices = new Point3DeX[verticesNum];

	indicesNum = (wallNum + 9) * 2;
	indices = new SimpleTriangle[indicesNum];

	uint I = 0, N = 0;

	auto b = 1.0f;
	auto a = (float) (b * sin(22.5 * M_PI / 180));
	float z = -0.25f;

	//góra i dół
	for (int i = 0; i < 2; i++) {

		//Prawa strona klucza
		indices[N++] = SimpleTriangle(I + 2, I + 1, I);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I);
		vertices[I++] = createPoint3DeX(a, b, z, color);
		vertices[I++] = createPoint3DeX(b, a, z, color);
		vertices[I++] = createPoint3DeX(b, -a, z, color);
		vertices[I++] = createPoint3DeX(a, -b, z, color);

		//Lewa strona klucza
		indices[N++] = SimpleTriangle(I + 3, I + 1, I);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I + 1);
		vertices[I++] = createPoint3DeX(-a, -b, z, color);
		vertices[I++] = createPoint3DeX(-b, -a, z, color);
		vertices[I++] = createPoint3DeX(-b, a, z, color);
		vertices[I++] = createPoint3DeX(-a, b, z, color);

		//Rączka
		indices[N++] = SimpleTriangle(I + 2, I + 1, I);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I);
		vertices[I++] = createPoint3DeX(a, -b * 5, z, color);
		vertices[I++] = createPoint3DeX(-a, -b * 5, z, color);
		vertices[I++] = createPoint3DeX(-a, -a, z, color);
		vertices[I++] = createPoint3DeX(a, -a, z, color);

		z += 0.5f;
	}

	//Boki
	uint wallOrder[] = {
			0, 1, 2, 3,
			8, 9,
			4, 5, 6, 7,
			10, 11,
			0
	};
	for (uint i = 0; i < wallNum; i++) {
		uint t1 = wallOrder[i],
				t2 = wallOrder[i + 1],
				b1 = t1 + wallNum,
				b2 = t2 + wallNum;

//		cout << t1 << ":" << t2 << ":" << b1 << ":" << b2 << endl;

		indices[N++] = SimpleTriangle(I, I + 1, I + 2);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I + 1);

		float d1 = Point3D::DistanceBetween(vertices[t1].point, vertices[t2].point) / 2;
		float d2 = Point3D::DistanceBetween(vertices[t1].point, vertices[b1].point) / 2;

		vertices[I++] = Point3DeX(vertices[t1].point, TexCoord(0.0f, 0.0f));
		vertices[I++] = Point3DeX(vertices[t2].point, TexCoord(d1, 0.0f));
		vertices[I++] = Point3DeX(vertices[b1].point, TexCoord(0.0f, d2));
		vertices[I++] = Point3DeX(vertices[b2].point, TexCoord(d1, d2));

	}

	verticesNum = I;
	indicesNum = N;

	Point3DeX::CalcNormals(vertices, verticesNum, indices, indicesNum);
}

void anim::Wrench::render(Window *window) {

	anim->getShader().setMat4("model", modelMatrix);
	texture.use();

	draw();
}

