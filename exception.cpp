#include <iostream>
#include <new>

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
	
	return 0;
}