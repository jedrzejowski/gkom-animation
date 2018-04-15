//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_WRENCH_H
#define GKOM_ANIMATION_WRENCH_H

#include "src/3d/Abs3DObj.h"
#include "src/3d/Texture.h"

namespace gkom::anim {

	class Wrench : public Abs3DObj {
	private:
		Shader shader;
		Texture texture;

		void initVertices();

	public:
		Wrench(Animation *anim);

		~Wrench();

		void render(Window *window) override;
	};
}


#endif //GKOM_ANIMATION_WRENCH_H
