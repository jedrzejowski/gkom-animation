//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_POINT_H
#define GKOM_ANIMATION_POINT_H

#include <GL/glew.h>
#include <zconf.h>

namespace gkom {

	struct Point3D {
		static uint SIZE;
		static uint OFFSET;

		GLfloat X = 0.0f;
		GLfloat Y = 0.0f;
		GLfloat Z = 0.0f;

		Point3D() : Point3D(0.0f, 0.0f) {}

		Point3D(GLfloat X, GLfloat Y) : Point3D(X, Y, 0.0f) {}

		Point3D(GLfloat X, GLfloat Y, GLfloat Z) : X(X), Y(Y), Z(Z) {}
	};


	struct Color {
		static uint SIZE;
		static uint OFFSET;

		GLfloat R = 0.0f;
		GLfloat G = 0.0f;
		GLfloat B = 0.0f;

		Color() : Color(0.0f, 0.0f, 0.0f) {}

		Color(GLfloat gray) : R(gray), G(gray), B(gray) {}

		Color(GLfloat R, GLfloat G, GLfloat B) : R(R), G(G), B(B) {}
	};

	struct TexCoord {
		static uint SIZE;
		static uint OFFSET;

		GLfloat X = 0.0f;
		GLfloat Y = 0.0f;

		TexCoord() : TexCoord(0.0f, 0.0f) {}

		TexCoord(GLfloat X, GLfloat Y) : X(X), Y(Y) {}
	};

	struct Point3DeX {
		static uint SIZE;

		static void BindGlVAP();

		Point3D point;
		Color color;
		TexCoord texture;


		Point3DeX() {}

		Point3DeX(Point3D p) : point(p) {}

		Point3DeX(Point3D p, Color c) : point(p), color(c) {}

		Point3DeX(Point3D p, Color c, TexCoord t) : point(p), color(c), texture(t) {}

		Point3DeX(GLfloat X, GLfloat Y, GLfloat Z) : point(X, Y, Z), color() {}

		Point3DeX(GLfloat X, GLfloat Y, GLfloat Z, Color c) : point(X, Y, Z), color(c) {}

		Point3DeX(GLfloat X, GLfloat Y, GLfloat Z, Color c, TexCoord t) : point(X, Y, Z), color(c), texture(t) {}

		Point3DeX(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B) : point(X, Y, Z),
																					  color(R, G, B) {}
	};

	struct SimpleTriangle {
		uint first;
		uint second;
		uint third;

		static uint SIZE;

		SimpleTriangle() {}

		SimpleTriangle(const uint first, const uint second, const uint third) : first(first), second(second),
																					  third(third) {}
		SimpleTriangle operator+(const int& n);
	};
}
#endif //GKOM_ANIMATION_POINT_H
