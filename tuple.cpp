#include <iostream>
#include <tuple>

int main(){
	std::tuple<int, double, bool> T1(10, 15.5, true);
	auto T2 = std::make_tuple<int, double, bool>(5, 12.7, false);
	
	std::cout << std::get<0>(T1) << ", " << std::get<1>(T1) << ", " << std::get<2>(T2) << std::endl;
}