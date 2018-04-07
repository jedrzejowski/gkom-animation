//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_POINT_H
#define GKOM_ANIMATION_POINT_H

#include <GL/glew.h>

struct Point3D {
	GLfloat X = 0.0f;
	GLfloat Y = 0.0f;
	GLfloat Z = 0.0f;

	Point3D(GLfloat X, GLfloat Y, GLfloat Z) : X(X), Y(Y), Z(Z) {}

	Point3D(GLfloat X, GLfloat Y) : Point3D(X, Y, 0.0f) {}

	Point3D() : Point3D(0.0f, 0.0f) {}
};

#endif //GKOM_ANIMATION_POINT_H
