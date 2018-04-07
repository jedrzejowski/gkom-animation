#include <iostream>

#include <src/Window.h>
#include <src/exception.h>

using namespace std;

int main() {

	try {

		gkom::Window win = gkom::Window();
		win.init().open();
	} catch (std::exception &e) {
		std::cout << e.what();
	} catch (gkom::exception &e) {
		std::cout << e.what();
	}

	return 0;
}
