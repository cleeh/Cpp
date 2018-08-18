#include <iostream>
#include <vector>

int main(){
	std::vector<int> vec;
	vec.push_back(50); // Add: vec.size() == 1
	vec.push_back(100); // Add: vec.size() == 2
	vec.pop_back(); // Delete: vec.size() == 1
	vec.resize(10, 0); // fill vector whose size is 10 with 0
	vec[3] = 10; // Random Access
	std::cout << "vec[3] = 10: " << vec[3] << std::endl;
	
	int nSum = 0;
	for(int i = 0; i < vec.size(); i++){
		nSum += vec[i];
	}
	std::cout << "nSum: " << nSum << std::endl;
	//auto = std::iterator<std::vector<int>>
	for(auto iter = vec.begin(); iter != vec.end(); iter++){
		nSum += (*iter);
	}
	std::cout << "nSum: " << nSum << std::endl;
	
	return 0;
}