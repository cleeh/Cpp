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

class Parent{
	private:
	int priv;
	protected:
	int prot;
	public:
	int pub;
	void AccessAllMembers();
};
void Parent::AccessAllMembers(){
	priv = 100; // Success
	cout << "priv = 100: Success" << endl;
	prot = 100; // Success
	cout << "prot = 100: Success" << endl;
	pub = 100; // Success
	cout << "pub = 100: Success" << endl;
}
class Child : public Parent{
	public:
	void AccessParents(){
		int n;
		/*
		n = priv; // Compile Error: int Parent::priv is private
		cout << "n = Parent::priv: Success" << endl;
		*/
		n = prot;
		cout << "(n = Parent::prot): Success" << endl;
		n = pub;
		cout << "(n = Parent::priv): Success" << endl;
	}
};

int main(int argc, char* argv[]){
	Elephant e ={4, 4.96, 1.02};
	e.wash();
	e.pick();
	e.eat("nuts");
	cout << endl;
	
	Parent p;
	p.AccessAllMembers();
	Child c;
	c.AccessParents();
	cout << endl;
	
	return 0;
}