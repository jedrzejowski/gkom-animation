//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_ABS3DOBJ_H
#define GKOM_ANIMATION_ABS3DOBJ_H

#include <GL/glew.h>

#include "gEngine.h"

namespace gengine {
	class Abs3DObj {
	protected:

		GLuint VAO, VBO, EBO;
		Animation* anim;

		struct Point3DeX* vertices;
		struct SimpleTriangle* indices;
		uint verticesNum;
		uint indicesNum;

		void draw();
		void draw(uint from, uint count);
	public:
		glm::mat4 modelMatrix;

		Abs3DObj(Animation* anim);

		~Abs3DObj();
		virtual void render(Window *window) = 0;

		void insertObjToBuffers();

	};
}


#endif //GKOM_ANIMATION_ABS3DOBJ_H
