#include <iostream>

//#include <src/MyWindow.h>
#include <src/exception.h>

using namespace std;

int main() {

	try {
//		gkom::MyWindow win = gkom::MyWindow();
//		win.open();
	} catch (std::exception &e) {
		std::cout << e.what();
	} catch (gkom::exception &e) {
		std::cout << e.what();
	}

	return 0;
}
