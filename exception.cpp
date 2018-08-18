#include <iostream>
#include <new>

void f1() {
	std::cout << "f1() called" << std::endl;
	throw 0;
}
void f2() {
	std::cout << "f2() called" << std::endl;
	f1();
}
void f3() {
	std::cout << "f3() called" << std::endl;
	f2();
}
void f4() {
	std::cout << "f4() called" << std::endl;
	f3();
}

int main(){
	char* ptr;
	try
	{
		ptr = new char[-1];
		delete[] ptr;
	}
	catch(std::bad_alloc& ba)
	{
		std::cout << ba.what() << std::endl; // print std::bad_alloc
	}
	std::cout << std::endl;
	
	try
	{
		f4();
	}
	catch (int e)
	{
		std::cout << e << std::endl;
	}
	
	return 0;
}