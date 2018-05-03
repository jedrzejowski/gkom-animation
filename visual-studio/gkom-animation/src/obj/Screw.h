//
// Created by adam on 16.04.18.
//

#ifndef GKOM_ANIMATION_SCREW_H
#define GKOM_ANIMATION_SCREW_H

#include "../3d/gEngine.h"

using namespace gengine;

namespace gkom {
	namespace anim {
		class Screw : public Abs3DObj {
		protected:
			Texture texture;

			void initVertices();

		public:
			Screw(Animation *anim);

			~Screw();

			virtual void render(Window* window);
		};
	}
}

#endif //GKOM_ANIMATION_SCREW_H
