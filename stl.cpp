#include <iostream>
#include <vector>
#include <deque>
#include <list>

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
	std::cout << "nSum: " << nSum << std::endl << std::endl;
	
	std::deque<int> deq;
	deq.push_back(50);
	deq.push_back(100);
	deq.pop_back();
	deq.push_front(1000);
	deq.push_front(2000);
	deq.pop_front();
	deq.resize(10,0);
	deq[3] = 10;
	
	std::cout << "deq[3] = 10: " << deq[3] << std::endl;
	
	nSum = 0;
	for(int i = 0; i < deq.size(); i++){
		nSum += deq[i];
	}
	std::cout << "nSum: " << nSum << std::endl;
	//auto = std::iterator<std::deque<int>>
	for(auto iter = deq.begin(); iter != deq.end(); iter++){
		nSum += (*iter);
	}
	std::cout << "nSum: " << nSum << std::endl << std::endl;
	
	std::list<int> lst;
	lst.push_back(5); // 5
	lst.push_back(10); // 5 -> 10
	lst.push_front(100); // 100 -> 5 -> 10
	auto iter = lst.begin(); // iter -> 100 -> 5 -> 10
	iter++; // 100 -> iter -> 5 -> 10
	auto ater = lst.insert(iter, 200); // 100 -> ater -> 200 -> iter -> 5 -> 10
	lst.insert(ater, 300); // 100 -> 300 -> ater -> 200 -> iter -> 5 -> 10
	lst.insert(iter, 400); // 100 -> 300 -> ater -> 200 -> 400 -> iter -> 5 -> 10
	for(auto iterator = lst.begin(); iterator != lst.end(); iterator++){
		std::cout << (*iterator) << '\t';
	}
	std::cout << std::endl;
	
	std::list<int> lstB;
	lstB.push_back(20); // 20
	lstB.push_back(30); // 20 -> 30
	lst.insert(iter, lstB.begin(), lstB.end()); // 100 -> 300 -> ater -> 200 -> 400 -> 20 -> 30 -> iter -> 5 -> 10
	for(auto iterator = lst.begin(); iterator != lst.end(); iterator++){
		std::cout << (*iterator) << '\t';
	}
	std::cout << std::endl;
	
	return 0;
}