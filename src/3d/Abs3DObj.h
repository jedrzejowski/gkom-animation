//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_ABS3DOBJ_H
#define GKOM_ANIMATION_ABS3DOBJ_H

#include <GL/glew.h>
#include "Shader.h"

namespace gkom {
	class Abs3DObj {
	protected:
		int stride;
		GLuint VBO, EBO, VAO;
	public:
		virtual void render(Shader &shader) = 0;
	};
}


#endif //GKOM_ANIMATION_ABS3DOBJ_H
