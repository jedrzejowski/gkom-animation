//
// Created by adam on 15.04.18.
//

#ifndef GKOM_ANIMATION_MYANIMATION_H
#define GKOM_ANIMATION_MYANIMATION_H

#include <src/3d/Animation.h>
#include "Nut.h"
#include "Wrench.h"
#include "Screw.h"

namespace gkom::anim {
	class MyAnimation : public Animation {
	private:
		Nut *nakrentka;
		Screw *sruba;
		Wrench *klucz;

	public:
		MyAnimation();
		~MyAnimation();
		void render(Window *window);
	};
}


#endif //GKOM_ANIMATION_MYANIMATION_H
