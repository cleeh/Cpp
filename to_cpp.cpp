#include <iostream>
#include <typeinfo>

void f(int a) { std::cout << "f(int)" << std::endl; }
void f(int* a) { std::cout << "f(int*)" << std::endl; }

int main(int argc, char* argv[]) {
	int x = 10, y = 20;
	std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

	int input = 0;
	std::cout << "Type Number: ";
	std::cin >> input;
	std::cout << "Typed Number: " << input << std::endl << std::endl;

	bool b = true;
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl << std::endl;

	std::cout.setf(std::ios::boolalpha); // marked with true/false
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl;
	std::cout.unsetf(std::ios::boolalpha); // marked with 1/0
	std::cout << "b = true: " << b << std::endl;
	std::cout << "!b = false: " << !b << std::endl << std::endl;

	int arr[] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	for(auto& i : arr)
		std::cout << i << " ";
	std::cout << std::endl << std::endl;
	
	int** arr1 = new int*[5];
	for(int i = 0; i < 5; i++)
		arr1[i] = new int[5];
	for(int i = 0; i < 5; i++)
		delete[] arr1[i];
	delete[] arr1;
	arr1 = nullptr;
	
	int* p1 = new int;
	delete p1; // just delete int type variable
	p1 = nullptr;
	int* p2 = new int[10];
	delete[] p2; // delete int array type variable so, use 'delete[]'
	p2 = nullptr;
	
	std::cout << "f(0): "; f(0);
	std::cout << "f(nullptr):"; f(nullptr);
	std::cout << sizeof(nullptr) << std::endl;
	std::cout << typeid(nullptr).name() << std::endl << std::endl;
	
	/*
	char* str = "Hello World!";
	int* pi1 = (int*)str; // Runtime Error
	char* pc1 = (char*)*pi1; // Runtime Error
	std::cout << pc1 << std::endl;
	
	int* pi2 = static_cast<int*>(str); // Compile Error: static_cast can't convert from 'char*' to 'int*'
	char* pc2 = static_cast<char*>(pi2); // Compile Error: static_cast can't convert from 'int*' to 'char*'
	std::cout << pc2 << std::endl;
	*/
	
	return 0;
}