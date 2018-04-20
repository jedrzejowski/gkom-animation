//
// Created by adam on 17.04.18.
//

#ifndef GKOM_ANIMATION_PLATE_H
#define GKOM_ANIMATION_PLATE_H

#include <src/3d/Abs3DObj.h>
#include <src/3d/Texture.h>

using namespace gengine;

namespace gkom::anim {

	class Plate : public Abs3DObj {
	protected:
		Texture textureWood, textureBricks;

		void initVertices();
	public:
		Plate(Animation *anim);

		~Plate();

		virtual void render(Window* window);
	};

}

#endif //GKOM_ANIMATION_PLATE_H
