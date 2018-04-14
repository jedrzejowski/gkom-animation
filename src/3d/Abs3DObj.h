//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_ABS3DOBJ_H
#define GKOM_ANIMATION_ABS3DOBJ_H

#include <GL/glew.h>
#include <src/Window.h>
#include "Shader.h"

namespace gkom {
	class Abs3DObj {
	protected:
		GLuint VBO, EBO, VAO;

		struct Point3DeX* vertices;
		struct SimpleTriangle* indices;
		unsigned int vertclesNum;
		unsigned int indicesNum;
	public:
		glm::mat4 modelMatrix;

		Abs3DObj();
		~Abs3DObj();
		virtual void render(Window &window) = 0;


	};
}


#endif //GKOM_ANIMATION_ABS3DOBJ_H
