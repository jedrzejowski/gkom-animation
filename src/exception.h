//
// Created by adam on 07.04.18.
//

#ifndef GKOM_ANIMATION_EXCEPTION_H
#define GKOM_ANIMATION_EXCEPTION_H

#include <string>
#include <iostream>

namespace gkom {

	class exception : std::exception {
	private:
		std::string msg;

		explicit exception() : msg("") {}

	public:

		explicit exception(std::string msg1) : msg(msg1) {};

		explicit exception(const char *msg1) : msg(msg1) {};

		const char *what() const throw() override {
			return msg.c_str();
		};
	};
}


#endif //GKOM_ANIMATION_EXCEPTION_H
