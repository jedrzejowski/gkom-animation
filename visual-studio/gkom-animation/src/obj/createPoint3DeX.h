//
// Created by adam on 18.04.18.
//

#ifndef GKOM_ANIMATION_CREATEPOINT3DEX_H
#define GKOM_ANIMATION_CREATEPOINT3DEX_H

#include "../3d/Point3D.h"

using namespace gkom;

inline Point3DeX createPoint3DeX(float x, float y, float z, Color color) {
	return Point3DeX(x, y, z, color, TexCoord((x + 1) / 2, (y + 1) / 2));
}

#endif //GKOM_ANIMATION_CREATEPOINT3DEX_H
