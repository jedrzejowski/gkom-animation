//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_ANIMATION_H
#define GKOM_ANIMATION_ANIMATION_H

#include "src/Window.h"

namespace gengine {

	class Animation {

	protected:
		GLuint VAO;
		Light* light;
		Shader* shader;

	public:
		Animation();

		~Animation();

		virtual void render(gkom::Window *window) = 0;

		const GLuint getVAO() const {
			return VAO;
		}

		const Light& getLight() const{
			return *light;
		}

		const Shader& getShader() const{
			return *shader;
		}
	};
}


#endif //GKOM_ANIMATION_ANIMATION_H
