#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T>
void print_vector(std::vector<T> vec){
	for(auto iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << (*iter) << '\t';
	std::cout << std::endl;
}

int main(){
	std::vector<int> V{100, 25, 40, 35, 5};
	
	print_vector<int>(V);
	std::sort(V.begin(), V.end(), std::less<int>());
	print_vector<int>(V);
	
	return 0;
}