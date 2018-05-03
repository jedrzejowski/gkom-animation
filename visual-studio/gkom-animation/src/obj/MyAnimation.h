//
// Created by adam on 15.04.18.
//

#ifndef GKOM_ANIMATION_MYANIMATION_H
#define GKOM_ANIMATION_MYANIMATION_H

#include "../3d/gEngine.h"

#include "Nut.h"
#include "Wrench.h"
#include "Screw.h"
#include "Plate.h"

namespace gkom {
	namespace anim {

		class MyAnimation : public Animation {
		private:
			Nut * nakrentka;
			Screw *sruba;
			Wrench *klucz;
			Plate *podkladka;

			glm::mat4 nakrentkaM4, kluczM4;

			float angle;

		public:
			MyAnimation();

			~MyAnimation();

			void render(Window *window);

			void add2Angle(float delta);
		};
	}
}


#endif //GKOM_ANIMATION_MYANIMATION_H
