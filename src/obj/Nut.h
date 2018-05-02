//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_NUT_H
#define GKOM_ANIMATION_NUT_H

#include "src/3d/gEngine.h"

using namespace gengine;

namespace gkom::anim {

	class Nut : public Abs3DObj {
	private:
		Texture texture;

		void initVertices();

	public:
		Nut(Animation *anim);

		~Nut();

		void render(Window *window) override;
	};
}


#endif //GKOM_ANIMATION_NUT_H
