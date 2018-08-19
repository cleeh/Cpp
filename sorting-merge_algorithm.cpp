#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>

template<typename T>
void print_vector(std::vector<T> vec){
	for(auto iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << (*iter) << '\t';
	std::cout << std::endl;
}

int main(){
	std::vector<int> V{100, 25, 40, 35, 5};
	std::sort(V.begin(), V.end(), std::less<int>());
	
	std::deque<int> D{13, 78, 57, 24, 69};
	std::sort(D.begin(), D.end(), std::less<int>());
	
	std::vector<int> VR;
	VR.resize(V.size() + D.size());
	
	auto isLess = [](int a, int b){ return a < b; };
	std::merge(V.begin(), V.end(), D.begin(), D.end(), VR.begin(), isLess);
	print_vector<int>(VR);
	
	return 0;
}