//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_SCREW_H
#define GKOM_ANIMATION_SCREW_H

#include <src/3d/Abs3DObj.h>
#include <src/3d/Shader.h>
#include <src/3d/Texture.h>

namespace gkom::anim {

	class Screw : Abs3DObj {
	private:
		Texture texture;
		struct Point3DeX* vertices;
		unsigned int vertclesNum;
		unsigned int* indices;
		unsigned int indicesNum;

		void initVertices();

	public:
		Screw();

		~Screw();

		void render(Window& window) override;
	};
}


#endif //GKOM_ANIMATION_SCREW_H
