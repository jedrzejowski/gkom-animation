//
// Created by adam on 17.04.18.
//

#ifndef GKOM_ANIMATION_GLM_EXT_HPP
#define GKOM_ANIMATION_GLM_EXT_HPP

#include <glm/detail/type_mat.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/detail/type_mat4x4.hpp>

namespace glm {
	mat4 rotateFromPoint(mat4 matrix, float angle, vec3 origin, vec3 rotVec = glm::vec3(1.0f, 0.0f, 0.0f)) {
		//matrix = glm::translate(matrix, glm::vec3(-origin.x, -origin.y, -origin.z)); //subtract origin position
		matrix = glm::rotate(matrix, angle, rotVec); //rotate
		//matrix = glm::translate(matrix, glm::vec3(origin.x, origin.y, origin.z)); //return object on it's place
		return matrix;
	}
}

#endif //GKOM_ANIMATION_GLM_EXT_HPP
