#include <iostream>
#include <stack>

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
	
	return 0;
}