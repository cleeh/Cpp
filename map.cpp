#include <iostream>
#include <map>
#include <vector>
#include <string>

int main(){
	std::multimap<int, double> M{{8, 32.5}, {8, 1.1}};
	M.insert(std::make_pair<int, int>(5, 105.5));
	M.insert(std::pair<int, int>(5, 14.9));
	M.insert({5, 50}); // using initializer_list
	
	for(auto iter = M.begin(); iter != M.end(); iter++){
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	
	std::string key = "sss";
	std::map<std::string, std::vector<int>> MSV;
	auto iter = MSV.find(key);
	if(iter -> second.empty()){
		
	}
	iter->second.push_back(10);
	std::vector<int> &V = iter->second;
	for(auto IT = V.begin(); IT != V.end(); IT++){
		
	}
	
	return 0;
}
