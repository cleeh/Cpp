#include <iostream>

int main(){
	std::pair<int, double> P(10, 15.5);
	auto P2 = std::make_pair<int, double>(5, 55.3);
	P2.second = 12.7;
	std::cout << P.first << ", " << P.second << std::endl;
	std::cout << P2.first << ", " << P2.second << std::endl << std::endl;
}