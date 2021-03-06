//
// Created by adam on 07.04.18.
//

#include <math.h>
#include <glm/gtx/normal.hpp>

#include "Point3D.h"

using namespace gengine;

unsigned int Point3D::SIZE = sizeof(Point3D);
unsigned int Normal::SIZE = sizeof(Normal);
unsigned int Color::SIZE = sizeof(Color);
unsigned int TexCoord::SIZE = sizeof(TexCoord);
unsigned int Point3DeX::SIZE = sizeof(Point3DeX);
unsigned int SimpleTriangle::SIZE = sizeof(SimpleTriangle);

SimpleTriangle SimpleTriangle::operator+(const int &n) {
	return SimpleTriangle(this->first + n, this->second + n, this->third + n);
}

SimpleTriangle &SimpleTriangle::operator+=(const int &n) {
	this->first += n;
	this->second += n;
	this->third += n;
	return *this;
}

unsigned int Point3D::OFFSET = 0;
unsigned int Normal::OFFSET = Point3D::OFFSET + Point3D::SIZE;
unsigned int Color::OFFSET = Normal::OFFSET + Normal::SIZE;
unsigned int TexCoord::OFFSET = Color::OFFSET + Color::SIZE;

void Point3DeX::BindGlVAP() {

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) Point3D::OFFSET);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) Normal::OFFSET);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) Color::OFFSET);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) TexCoord::OFFSET);
	glEnableVertexAttribArray(3);
}

void Point3DeX::CalcNormals(Point3DeX *points, size_t pSize, SimpleTriangle *triangles, size_t tSize) {
	glm::vec3 temp1, temp2, temp3, temp4;

	for (unsigned int i = 0; i < tSize; i++) {
		temp1 = glm::vec3(points[triangles[i].first].point.x,
						  points[triangles[i].first].point.y,
						  points[triangles[i].first].point.z);

		temp2 = glm::vec3(points[triangles[i].second].point.x,
						  points[triangles[i].second].point.y,
						  points[triangles[i].second].point.z);

		temp3 = glm::vec3(points[triangles[i].third].point.x,
						  points[triangles[i].third].point.y,
						  points[triangles[i].third].point.z);

		temp4 = glm::triangleNormal(temp2, temp1, temp3);

		points[triangles[i].first].normal.x = temp4.x;
		points[triangles[i].first].normal.y = temp4.y;
		points[triangles[i].first].normal.z = temp4.z;

		points[triangles[i].second].normal.x = temp4.x;
		points[triangles[i].second].normal.y = temp4.y;
		points[triangles[i].second].normal.z = temp4.z;

		points[triangles[i].second].normal.x = temp4.x;
		points[triangles[i].second].normal.y = temp4.y;
		points[triangles[i].second].normal.z = temp4.z;
	}
}

float Point3D::DistanceBetween(const Point3D &point1, const Point3D &point2) {
	return (float) sqrt(
			pow(point1.x - point2.x, 2) +
			pow(point1.y - point2.y, 2) +
			pow(point1.z - point2.z, 2)
	);
}