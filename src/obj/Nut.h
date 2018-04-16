//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_NUT_H
#define GKOM_ANIMATION_NUT_H

#include <src/3d/Abs3DObj.h>
#include <src/3d/Shader.h>
#include <src/3d/Texture.h>

namespace gkom::anim {

	class Nut : public Abs3DObj {
	private:
		Texture texture;
		Shader shader;

		void initVertices();

	public:
		Nut(Animation *anim);

		~Nut();

		void render(Window *window) override;
	};
}


#endif //GKOM_ANIMATION_NUT_H