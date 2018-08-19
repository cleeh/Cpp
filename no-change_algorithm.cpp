#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print_vector(std::vector<T> vec){
	for(auto iter = vec.begin(); iter != vec.end(); iter++){
		std::cout << (*iter) << '\t';
	}
	std::cout << std::endl;
}

int main(){
	std::vector<int> V{10, 20, 40, 30, 50, 55, 60, 75, 100};
	
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
	print_vector<int>(V); // 10 20 40 30 50 55 60 75 100
	auto iterR = std::remove(V.begin(), V.end(), 40);
	if(iterR != V.end()){
		std::cout << "V.size(): " << V.size() << std::endl;
		print_vector<int>(V); // 10 20 30 50 55 60 75 100 100
		V.erase(iterR, V.end());
		std::cout << "V.size(): " << V.size() << std::endl;
		print_vector<int>(V); // 10 20 30 50 55 60 75 100
	}
	std::cout << std::endl;
	
	auto isOdd = [](int n) {return n % 2 == 1;};
	auto iterRI = std::remove_if(V.begin(), V.end(), isOdd);
	if(iterRI != V.end()){
		std::cout << "After remove_if(): " << V.size() << std::endl;
		print_vector<int>(V); // 10 20 30 50 60 100 75 100
		V.erase(iterRI, V.end());
		std::cout << "After erase(): " << V.size() << std::endl;
		print_vector<int>(V); // 10 20 30 50 60 100
	}
	
	return 0;
}