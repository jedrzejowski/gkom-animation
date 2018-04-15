//
// Created by adam on 15.04.18.
//

#ifndef GKOM_ANIMATION_MYANIMATION_H
#define GKOM_ANIMATION_MYANIMATION_H

#include <src/3d/Animation.h>
#include "Screw.h"
#include "Wrench.h"

namespace gkom::anim {
	class MyAnimation : public Animation {
	private:
		Screw *srubka1, *srubka2, *srubka3;
		Wrench *klucz;

	public:
		MyAnimation();
		~MyAnimation();
		void render(Window *window);
	};
}


#endif //GKOM_ANIMATION_MYANIMATION_H
