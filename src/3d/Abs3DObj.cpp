//
// Created by adam on 07.04.18.
//

#include "Abs3DObj.h"
#include "Point3D.h"

using namespace std;

gkom::Abs3DObj::Abs3DObj(Animation *anim) : anim(anim) {
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	cout<<"VBO:"<<VBO<<endl;
	cout<<"EBO:"<<EBO<<endl;
}

gkom::Abs3DObj::~Abs3DObj() {
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void gkom::Abs3DObj::insertObjToBuffers() {
	cout << "insertObjToBuffers" << vertclesNum << endl;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Point3DeX::SIZE * vertclesNum, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, SimpleTriangle::SIZE * indicesNum, indices, GL_STATIC_DRAW);

}

void gkom::Abs3DObj::draw() {

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(GL_TRIANGLES, 3*indicesNum, GL_UNSIGNED_INT, nullptr);

}
