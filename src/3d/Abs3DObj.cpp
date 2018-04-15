//
// Created by adam on 07.04.18.
//

#include "Abs3DObj.h"
#include "Point3D.h"

using namespace std;

gkom::Abs3DObj::Abs3DObj(Animation *anim) : anim(anim) {


}

gkom::Abs3DObj::~Abs3DObj() {

}

void gkom::Abs3DObj::insertObjToBuffers() {
	//cout << vertclesNum << endl;

	vboPointer = anim->insertIntoVBO(vertclesNum, vertices);

	cout << vboPointer << endl;

	for (int i = 0; i < indicesNum; i++)
		indices[0] += vboPointer;

	eboPointer = anim->insertIntoEBO(indicesNum, indices);
	cout << eboPointer << endl;
}

void gkom::Abs3DObj::draw() {

	glDrawRangeElements(GL_TRIANGLES,
						eboPointer,
						eboPointer + 3 * indicesNum,
						3 * indicesNum,
						GL_UNSIGNED_INT,
						nullptr);
}
