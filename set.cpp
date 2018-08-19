#include <iostream>
#include <set>

int main(){
	std::set<int> S{9, 7, 5, 1, 3}; // 1,3,5,7,9
	S.insert(4); // 1,3,4,5,7,9

	for(auto iter = S.begin(); iter != S.end(); iter++)
		std::cout << (*iter) << '\t';
	std::cout << std::endl;
	
	auto f = S.find(5);
	if(f != S.end())
		std::cout << "found !" << std::endl;
	
	return 0;
}