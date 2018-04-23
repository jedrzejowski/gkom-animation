//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_ANIMATION_H
#define GKOM_ANIMATION_ANIMATION_H

#include "gEngine.h"

namespace gengine {

	class Animation {

	protected:
		Light* light;
		Shader* shader;

	public:
		Animation();

		~Animation();

		virtual void render(Window *window) = 0;

		const Light& getLight() const{
			return *light;
		}

		const Shader& getShader() const{
			return *shader;
		}
	};
}


#endif //GKOM_ANIMATION_ANIMATION_H
