//
// Created by adam on 07.04.18.
//

#include "FileSystem.h"

std::string gkom::FileSystem::loadTextFile(std::string& relativePath) {
	return gkom::FileSystem::loadTextFile(relativePath.c_str());
}

std::string gkom::FileSystem::loadTextFile(const char* relativePath) {
	std::ifstream shader_file;
	shader_file.exceptions(std::ifstream::badbit);

	shader_file.open(relativePath);
	std::stringstream shader_stream;
	shader_stream << shader_file.rdbuf();
	shader_file.close();
	return shader_stream.str();
}