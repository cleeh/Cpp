#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int> V{10, 20, 40, 30, 50};
	
	auto iter30 = std::find(V.rbegin(), V.rend(), 30);
	auto iter25 = std::find(V.begin(), V.end(), 25);
	
	if(iter30 != V.rend())
		std::cout << "Found 30 !" << std::endl;
	if(iter25 != V.end())
		std::cout << "Found 25 !" << std::endl;
	std::cout << std::endl;
	
	auto GT25 = [](int n) {return n > 25;};
	auto itFI = std::find_if(V.begin(), V.end(), GT25);
	if(itFI != V.end())
		std::cout << (*itFI) << std::endl;
	auto ifFI = std::find_if(V.rbegin(), V.rend(), GT25);
	std::cout << std::endl;
	
	std::cout << "V.size(): " << V.size() << std::endl;
	auto iterR = std::remove(V.begin(), V.end(), 40);
	if(iterR != V.end()){
		std::cout << "V.size(): " << V.size() << std::endl;
		V.erase(iterR, V.end());
		std::cout << "V.size(): " << V.size() << std::endl;
	}
	
	return 0;
}