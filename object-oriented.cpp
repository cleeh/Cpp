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

class Person{
	private:
	const string SSN;
	double height;
	double weight;
	int* grade;
	public:
	Person(const Person& src): SSN(src.SSN), height(src.height), weight(src.weight), grade(nullptr) {}
	Person(const string _SSN, double _height, double _weight):SSN(_SSN), height(_height), weight(_weight), grade(nullptr){
		cout << "<Personal Information is made>" << endl;
		cout << "SSN: " << SSN << endl;
		cout << "height: " << height << endl;
		cout << "weight: " << weight << endl;
	}
	~Person(){
		delete[] grade;
		grade = nullptr;
		cout << "~Person() is called!" << endl;
	}
	void SetGrade(int _number){
		grade = new int[_number];
		for(int i = 0; i < _number; i++){
			grade[i] = i;
			cout << "grade[" << i << "]: " << grade[i] << endl;
		}
	}
	string GetSSN(){
		return SSN;
	}
	void SetHeight(double height){
		this->height = height;
	}
	double GetHeight(){
		return height;
	}
	void SetWeight(double weight){
		this->weight = weight;
	}
	double GetWeight(){
		return weight;
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
	
	Person person("103487-478263", 178.2, 73.8);
	person.SetGrade(5);
	person.SetHeight(170.2);
	cout << "Result of SetHeight(170.2): " << person.GetHeight() << endl << endl;
	
	Person p1("127001-987002", 181.8, 82.1);
	Person p2(p1);
	cout << "p2.SSN, p2.height, p2.weight: " << p2.GetSSN() << ", " << p2.GetHeight() << ", " << p2.GetWeight() << endl << endl;
	
	return 0;
}