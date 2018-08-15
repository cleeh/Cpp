#include <iostream>
#include <typeinfo>
#include <string>

void f(int a) { std::cout << "f(int)" << std::endl; }
void f(int* a) { std::cout << "f(int*)" << std::endl; }

int computeRectArea(int x1, int y1, int x2, int y2){
	int width = x1 - x2;
	int height = y1 = y2;
	int area = width * height;
	if(area < 0) area = -area;
	return area;
}
int computeRectArea(int width, int height){
	return width * height;
}

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
	
	enum class TrafficLight {Red, Yellow, Green};
	enum class Job {Warrior, Ranger, Wizard, Green};
	enum class Coffee : unsigned char {Latte=10, Mocha=25};
	Job jobnum = Job::Warrior;
	int i = static_cast<int>(TrafficLight::Green) + static_cast<int>(Coffee::Latte);
	std::cout << i << std::endl << std::endl;
	/*
	if(TrafficLight::Yellow == Job::Ranger) // Compile Error: No Match Enum Type
		std::cout << "Same!" << std::endl;
	else
		std::cout << "Different!" << std::endl;
	*/
	
	int decimal = 52;
	int octal = 064;
	int hexadecimal = 0x34;
	int binary = 0b110100; // C++14
	int maxInt_Cpp98 = 2147483647;
	// int maxInt_Cpp14 = 21'4748'3647; // C++14
	
	std::string str1 = "Hello, World";
	std::string str2 = "Hello, Word";
	if(str1 == str2) std::cout << "Same!" << std::endl;
	else std::cout << "Different!" << std::endl;
	str1 = str1 + str2;
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str2.length() << std::endl << std::endl;
	
	int refT = 10;
	int& ref = refT;
	ref += 10;
	std::cout << "refT = " << refT << std::endl;
	std::cout << "ref = " << ref << std::endl << std::endl;
	
	std::cout << computeRectArea(5, 0, 10, 5) << std::endl;
	std::cout << computeRectArea(5, 5) << std::endl << std::endl;
	
	return 0;
}