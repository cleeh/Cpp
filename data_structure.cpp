#include <iostream>
#include <stack>
#include <queue>

int main(){
	std::stack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	int count = S.size();
	for(int i = 0; i < count; i++){
		std::cout << S.top() << std::endl;
		S.pop();
	}
	std::cout << std::endl;
	
	std::queue<int> Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	count = Q.size();
	for(int i = 0; i < count; i++){
		std::cout << Q.front() << std::endl;
		Q.pop();
	}
	
	return 0;
}