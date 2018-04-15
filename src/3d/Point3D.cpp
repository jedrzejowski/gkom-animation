//
// Created by adam on 07.04.18.
//

#include "Point3D.h"

namespace gkom {

	unsigned int Point3D::SIZE = sizeof(Point3D);
	unsigned int Color::SIZE = sizeof(Color);
	unsigned int TexCoord::SIZE = sizeof(TexCoord);
	unsigned int Point3DeX::SIZE = sizeof(Point3DeX);
	unsigned int SimpleTriangle::SIZE = sizeof(SimpleTriangle);

	SimpleTriangle SimpleTriangle::operator+(const int &n) {
		return SimpleTriangle(this->first + n, this->second + n, this->third + n);
	}

	SimpleTriangle& SimpleTriangle::operator+=(const int &n) {
		this->first += n;
		this->second += n;
		this->third += n;
		return *this;
	}

	unsigned int Point3D::OFFSET = 0;
	unsigned int Color::OFFSET = Point3D::OFFSET + Point3D::SIZE;
	unsigned int TexCoord::OFFSET = Color::OFFSET + Color::SIZE;

	void Point3DeX::BindGlVAP() {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) Point3D::OFFSET);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) Color::OFFSET);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, Point3DeX::SIZE, (void *) TexCoord::OFFSET);
		glEnableVertexAttribArray(2);
	}


};
