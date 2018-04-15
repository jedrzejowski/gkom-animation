//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_ANIMATION_H
#define GKOM_ANIMATION_ANIMATION_H

#include "src/Window.h"

namespace gkom {
	class Animation {
	protected:
		GLuint VAO, VBO, EBO;
		uint vboCounter, eboCounter;

	public:
		Animation();

		~Animation();

		virtual void render(Window *window) = 0;

		const GLuint getVAO() const {
			return VAO;
		}

		uint insertIntoVBO(GLsizei size, const void *data);
		const GLuint getVBO() const {
			return VBO;
		}

		uint insertIntoEBO(GLsizei size, const void *data);
		const GLuint getEBO() const {
			return EBO;
		}
	};
}


#endif //GKOM_ANIMATION_ANIMATION_H
