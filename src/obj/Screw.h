//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_SCREW_H
#define GKOM_ANIMATION_SCREW_H

#include <src/3d/Abs3DObj.h>
#include <src/3d/Shader.h>

namespace gkom::anim {

	class Screw : Abs3DObj {
	private:
		struct Point3D* vertices;
		unsigned int* indices;

		void initVertices();

	public:
		Screw();

		~Screw();

		void render() override;
	};
}


#endif //GKOM_ANIMATION_SCREW_H
