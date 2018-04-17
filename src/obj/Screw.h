//
// Created by adam on 16.04.18.
//

#ifndef GKOM_ANIMATION_SCREW_H
#define GKOM_ANIMATION_SCREW_H

#include "src/3d/Abs3DObj.h"
#include "src/3d/Texture.h"

namespace gkom::anim {
	class Screw : public Abs3DObj {
	protected:
		Texture texture;
		Shader shader;

		void initVertices();

	public:
		Screw(Animation *anim);

		~Screw();

		virtual void render(Window* window);
	};
}


#endif //GKOM_ANIMATION_SCREW_H
