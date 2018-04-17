//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_ABS3DOBJ_H
#define GKOM_ANIMATION_ABS3DOBJ_H

#include <GL/glew.h>
#include "src/Window.h"
#include "Animation.h"

namespace gkom {
	class Abs3DObj {
	protected:

		GLuint VAO, VBO, EBO;
		Animation* anim;

		struct Point3DeX* vertices;
		struct SimpleTriangle* indices;
		uint verticlesNum;
		uint indicesNum;

		void draw();
	public:
		glm::mat4 modelMatrix;

		Abs3DObj(Animation* anim);

		~Abs3DObj();
		virtual void render(Window *window) = 0;

		void insertObjToBuffers();

	};
}


#endif //GKOM_ANIMATION_ABS3DOBJ_H
