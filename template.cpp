#include <iostream>

template <typename T>
T Max(T a, T b){
	return a > b ? a : b;
}

int main(){
	int nA = 300, nB = 400, nC = Max(nA, nB);
	std::cout << "Max (300, 400) = " << nC << std::endl;
	
	float fD = 15.1f, fE = 15.3f, fF = Max(fD, fE);
	std::cout << "Max (15.1, 15.3) = " << fF << std::endl;
}