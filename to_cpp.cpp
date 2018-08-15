#include <iostream>

int main(int argc, char* argv[]) {
	int x = 10, y = 20;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	int input = 0;
	std::cout << "Type Number: ";
	std::cin >> input;
	std::cout << "Typed Number: " << input << std::endl;
}