//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_WINDOW_H
#define GKOM_ANIMATION_WINDOW_H

#include <src/3d/Window.h>
#include <src/obj/MyAnimation.h>

namespace gkom {
	class MyWindow : public gengine::Window {
	protected:
		anim::MyAnimation *anim;

		void keyCallback(GLFWwindow *window);

		void windowLoop();

	public:
		MyWindow();
	};
}


#endif //GKOM_ANIMATION_WINDOW_H
