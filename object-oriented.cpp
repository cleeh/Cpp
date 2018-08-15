#include <iostream>
#include <string>

using namespace std;

class Elephant{
	public:
	int FootNumber;
	double noseLength;
	double weight;
	
	void wash(){cout << "Wash!\n";} // Acts like inline function
	void pick(){cout << "Pick!\n";} // Acts like inline function
	void eat(string food); // Acts like general function
};
void Elephant::eat(string food){
	cout<< "This elephant eats " << food << "!" << endl;
}

int main(int argc, char* argv[]){
	Elephant e ={4, 4.96, 1.02};
	e.wash();
	e.pick();
	e.eat("nuts");
	
	return 0;
}