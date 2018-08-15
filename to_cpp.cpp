#include <iostream>

int main(int argc, char* argv[]) {
	int x = 10, y = 20;
	std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

	int input = 0;
	std::cout << "Type Number: ";
	std::cin >> input;
	std::cout << "Typed Number: " << input << std::endl << std::endl;

	bool b = true;
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl << std::endl;

	std::cout.setf(std::ios::boolalpha); // marked with true/false
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl;
	std::cout.unsetf(std::ios::boolalpha); // marked with 1/0
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl << std::endl;
}