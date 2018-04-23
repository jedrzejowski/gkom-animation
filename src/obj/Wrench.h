//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_WRENCH_H
#define GKOM_ANIMATION_WRENCH_H

#include "src/3d/gEngine.h"

using namespace gengine;

namespace gkom::anim {

	class Wrench : public Abs3DObj {
	private:
		Texture texture;

		void initVertices();

	public:
		Wrench(Animation *anim);

		~Wrench();

		void render(Window *window) override;
	};
}


#endif //GKOM_ANIMATION_WRENCH_H
