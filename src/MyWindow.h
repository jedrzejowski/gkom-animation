//
// Created by adam on 07.04.18.
//

#ifndef GKOM_MYANIMATION_WINDOW_H
#define GKOM_MYANIMATION_WINDOW_H

#include "exception.h"
#include "src/3d/Window.h"
#include "src/obj/MyAnimation.h"

namespace gkom {
	class MyWindow : public gengine::Window {
	protected:
		anim::MyAnimation *anim;

		void keyCallback(GLFWwindow *window);

		void initObjects();
		void windowLoop();

	public:
		MyWindow();
		~MyWindow();

		virtual std::string getTitle(){
			return "GKOM - Adam Jedrzejowski";
		}
	};
}


#endif //GKOM_ANIMATION_WINDOW_H
