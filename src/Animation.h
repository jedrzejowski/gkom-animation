//
// Created by adam on 14.04.18.
//

#ifndef GKOM_ANIMATION_ANIMATION_H
#define GKOM_ANIMATION_ANIMATION_H

#include <src/obj/Screw.h>
#include <src/obj/Wrench.h>
#include "Window.h"

namespace gkom {
	class Animation {
	private:
		anim::Screw srubka1, srubka2, srubka3;
		//anim::Wrench klucz;
	public:
		Animation();
		virtual void render(Window &window);
	};
}


#endif //GKOM_ANIMATION_ANIMATION_H
