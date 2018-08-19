#include <iostream>
#include <map>

int main(){
	std::map<int, double> M{{8, 32.5}, {35, 1.1}};
	M.insert(std::make_pair<int, int>(5, 105.5));
	M.insert(std::pair<int, int>(7, 14.9));
	M.insert({3, 50}); // using initializer_list
	
	double d = M[5];
	std::cout << "M[5] = " << d << std::endl;
	
	for(auto iter = M.begin(); iter != M.end(); iter++){
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	
	return 0;
}