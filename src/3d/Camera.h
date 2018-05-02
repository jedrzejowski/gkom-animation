//
// Created by adam on 19.04.18.
//

#ifndef GKOM_ANIMATION_CAMERA_H
#define GKOM_ANIMATION_CAMERA_H

#include "../opengl.h"

namespace gengine {

	class Camera {
	public:
		glm::vec3 position;
		glm::vec3 front;
		glm::vec3 up;

		glm::mat4 getMatrix(){
			return glm::lookAt(position, position + front, up);
		}
	};
}


#endif //GKOM_ANIMATION_CAMERA_H
