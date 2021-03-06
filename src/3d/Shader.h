//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_SHADER_H
#define GKOM_ANIMATION_SHADER_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Light.h"

namespace gengine {

	struct Material {
		glm::vec3 specular;
		float shininess;
	};

	class Shader {
		GLuint shaderId;
	public:
		Shader(std::string vertexPath, std::string fragmentPath);

		Shader(const char *vertexPath, const char *fragmentPath) :
				Shader(std::string(vertexPath), std::string(fragmentPath)) {}

		void use() const {
			glUseProgram(getID());
		}

		// returns program ID
		GLuint getID() const {
			return shaderId;
		}

		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;;
		void setVec2(const std::string &name, const glm::vec2 &value) const;
		void setVec2(const std::string &name, float x, float y) const;
		void setVec3(const std::string &name, const glm::vec3 &value) const;
		void setVec3(const std::string &name, float x, float y, float z) const;
		void setVec4(const std::string &name, const glm::vec4 &value) const;
		void setVec4(const std::string &name, float x, float y, float z, float w) const;
		void setMat2(const std::string &name, const glm::mat2 &mat) const;
		void setMat3(const std::string &name, const glm::mat3 &mat) const;
		void setMat4(const std::string &name, const glm::mat4 &mat) const;

		void setLight(const std::string &name, const Light &light) const;
	};
}


#endif //GKOM_ANIMATION_SHADER_H
