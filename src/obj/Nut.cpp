//
// Created by adam on 14.04.18.
//

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Nut.h"
#include "createPoint3DeX.h"

using namespace gkom;
using namespace std;
using namespace gengine;

anim::Nut::Nut(Animation *anim) :
		Abs3DObj(anim) {


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
	uint accuracy = 8;

	verticesNum = accuracy * 2 * 2 + accuracy * 4 * 2;
	vertices = new Point3DeX[verticesNum];
	indicesNum = accuracy * 2 * 2 + accuracy * 2 * 2;
	indices = new SimpleTriangle[indicesNum];

	uint I = 0, N = 0;

	float ro = 1.0f, ri = 0.6f;
	float z = -0.25f;
	float deg2Rad = M_PI / 180, angle;

	//góra i dół
	for (int i = 0; i < 2; i++) {

		uint start = I;

		for (uint a = 0; a < accuracy; a++) {
			angle = a * 45 * deg2Rad;
			vertices[I++] = createPoint3DeX(ro * sinf(angle), ro * cosf(angle), z, color);

			angle += 0.3926875; //22.5 stopni
			vertices[I++] = createPoint3DeX(ri * sinf(angle), ri * cosf(angle), z, color);
		}

		for (uint a = 0; a < accuracy; a++) {
			uint t1 = start + a * 2,
					t2 = t1 + 1,
					t3 = t2 + 1 == I ? start : t2 + 1,
					t4 = t3 + 1;

//			cout << t1 << ":" << t2 << ":" << t3 << ":" << t4 << endl;

			indices[N++] = SimpleTriangle(t1, t2, t3);
			indices[N++] = SimpleTriangle(t4, t3, t2);
		}

		z += 0.5f;
	}

	//boki
	uint zJump = accuracy * 2;
	float d1, d2;
	for (uint a = 0; a < accuracy; a++) {
		uint out1 = a * 2, in1 = out1 + 1;
		uint out2 = a * 2 + 2;
		if (out2 == accuracy * 2) out2 = 0;
		uint in2 = out2 + 1;

		//outer

		indices[N++] = SimpleTriangle(I, I + 1, I + 2);
		indices[N++] = SimpleTriangle(I + 3, I + 2, I + 1);

		d2 = Point3D::DistanceBetween(vertices[out1].point, vertices[out2].point) / 2;
		d1 = Point3D::DistanceBetween(vertices[out1 + zJump].point, vertices[out2].point) / 2;

		vertices[I++] = Point3DeX(vertices[out1].point, TexCoord(0.0f, 0.0f));
		vertices[I++] = Point3DeX(vertices[out2].point, TexCoord(d1, 0.0f));
		vertices[I++] = Point3DeX(vertices[out1 + zJump].point, TexCoord(0.0f, d2));
		vertices[I++] = Point3DeX(vertices[out2 + zJump].point, TexCoord(d1, d2));

		//inner

		indices[N++] = SimpleTriangle(I + 2, I + 1, I);
		indices[N++] = SimpleTriangle(I + 1, I + 2, I + 3);

		d2 = Point3D::DistanceBetween(vertices[in1].point, vertices[in2].point) / 2;
		d1 = Point3D::DistanceBetween(vertices[in1 + zJump].point, vertices[in2].point) / 2;

		vertices[I++] = Point3DeX(vertices[in1].point, TexCoord(0.0f, 0.0f));
		vertices[I++] = Point3DeX(vertices[in2].point, TexCoord(d1, 0.0f));
		vertices[I++] = Point3DeX(vertices[in1 + zJump].point, TexCoord(0.0f, d2));
		vertices[I++] = Point3DeX(vertices[in2 + zJump].point, TexCoord(d1, d2));
	}

	//boki

//	//Ściany
//	indicesNum = 8 * 2 * 2 + 8 * 2 * 2;
//	indices = new SimpleTriangle[indicesNum];
//	I = 0;
//
//	for (uint n = 0, i; n < 7; n++) {
//		i = n * 2;
//
//		//Top
//		indices[I++] = SimpleTriangle(i, i + 1, i + 2);
//		indices[I++] = SimpleTriangle(i + 1, i + 2, i + 3);
//
//		//WallOut
//		indices[I++] = SimpleTriangle(i + 0, i + 2, i + 2 + 16);
//		indices[I++] = SimpleTriangle(i + 0, i + 0 + 16, i + 2 + 16);
//
//		//Bot
//		indices[I++] = SimpleTriangle(i, i + 1, i + 2) + 16;
//		indices[I++] = SimpleTriangle(i + 1, i + 2, i + 3) + 16;
//
//		//WallIn
//		indices[I++] = SimpleTriangle(i + 1, i + 3, i + 3 + 16);
//		indices[I++] = SimpleTriangle(i + 1, i + 1 + 16, i + 3 + 16);
//	}
//
//	//Ostatni segment
//
//	//Top
//	indices[I++] = SimpleTriangle(14, 15, 0);
//	indices[I++] = SimpleTriangle(15, 0, 1);
	//WallOut
//	indices[I++] = SimpleTriangle(14, 0, 16);
//	indices[I++] = SimpleTriangle(14, 30, 16);

	//Bot
//	indices[I++] = SimpleTriangle(14, 15, 0) + 16;
//	indices[I++] = SimpleTriangle(15, 0, 1) + 16;

	//WallIn
//	indices[I++] = SimpleTriangle(15, 1, 17);
//	indices[I++] = SimpleTriangle(15, 31, 17);

	verticesNum = I;
	indicesNum = N;

	Point3DeX::CalcNormals(vertices, verticesNum, indices, indicesNum);
}

void anim::Nut::render(Window *window) {
	anim->getShader().setMat4("model", modelMatrix);
	texture.use();

	draw();
}


