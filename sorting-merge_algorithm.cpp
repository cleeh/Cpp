#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>
#include <numeric>

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
	
	std::vector<int> VA{1,2,3,4};
	int nSum = std::accumulate(VA.begin(), VA.end(), 0); // Sum of vector
	int nSum10 = std::accumulate(VA.begin(), VA.end(), 10); // Sum of (vector + 10)
	std::cout << "(nSum, nSum10): (" << nSum << ", " << nSum10 << ")" << std::endl;
	
	auto multi = [](int a, int b) { return a * b; };
	int nMulti = std::accumulate(VA.begin(), VA.end(), 1, multi); // Product of arguments
	std::cout << "nMulti: " << nMulti << std::endl;
	
	auto nSquare = [](int a, int b) { return a + b * b; };
	int nSumSquare = std::accumulate(VA.begin(), VA.end(), 0, nSquare); // Sum of Square
	std::cout << "nSumSquare: " << nSumSquare << std::endl;
	
	return 0;
}