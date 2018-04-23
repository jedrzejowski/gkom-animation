#include <iostream>

#include "src/MyWindow.h"

using namespace std;

int main() {

	try {
		gkom::MyWindow win = gkom::MyWindow();
		win.open();
	} catch (std::exception &e) {
		std::cout << e.what();
	} catch (gkom::exception &e) {
		std::cout << e.what();
	}

	return 0;
}
