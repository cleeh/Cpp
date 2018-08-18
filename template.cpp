#include <iostream>

template <typename T>
T Max(T a, T b){
	return a > b ? a : b;
}

template <typename T>
class Data{
	T data;
	public:
	Data(T d): data(d){}
	void SetData(T d){data = d;}
	T GetData() const {return data;}
};

int main(){
	int nA = 300, nB = 400, nC = Max(nA, nB);
	std::cout << "Max (300, 400) = " << nC << std::endl;
	
	float fD = 15.1f, fE = 15.3f, fF = Max(fD, fE);
	std::cout << "Max (15.1, 15.3) = " << fF << std::endl << std::endl;
	
	Data<float> data1(10.3);
	Data<int> data2(-50.7);
	std::cout << "Data<float> data1(10.3): " << data1.GetData() << std::endl;
	std::cout << "Data<int> data2(-50.7): " << data2.GetData() << std::endl << std::endl;
	
}