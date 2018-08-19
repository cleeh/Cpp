#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int> V{10, 20, 30, 40, 50};
	
	auto iter30 = std::find(V.rbegin(), V.rend(), 30);
	auto iter25 = std::find(V.begin(), V.end(), 25);
	
	if(iter30 != V.rend())
		std::cout << "Found 30 !" << std::endl;
	if(iter25 != V.end())
		std::cout << "Found 25 !" << std::endl;
	
	return 0;
}