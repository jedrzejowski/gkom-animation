//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_FILE_H
#define GKOM_ANIMATION_FILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace gkom {

	class FileSystem {
	public:
		static std::string loadTextFile(std::string& relativePath);
		static std::string loadTextFile(const char* relativePath);
	};

}

#endif //GKOM_ANIMATION_PATH_H
