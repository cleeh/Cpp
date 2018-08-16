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
		cout << "weight: " << weight << endl << endl;
	}
	~Person(){
		delete[] grade;
		grade = nullptr;
		cout << "~Person() is called!" << endl;
	}
	Person& operator=(const Person& rhs){
		if(this == &rhs) return *this;
		height = rhs.height;
		weight = rhs.weight;
		
		return *this;
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

class Copy{
	private:
	int* room;
	int roomNum;
	double height;
	double weight;
	public:
	Copy(const Copy& src): roomNum(src.roomNum), height(src.height), weight(src.weight){
		room = new int[roomNum];
		for(int i = 0; i < roomNum; i++)
			room[i] = src.room[i];
	}
	Copy(int _roomNum, double _height, double _weight): roomNum(_roomNum), height(_height), weight(_weight){
		room = new int[roomNum];
	}
	~Copy(){
		delete[] room;
		cout << "~Copy() is called" << endl;
	}
	Copy& operator=(const Copy& rhs){
		if(this == &rhs)
			return *this;
		delete[] room;
		room = nullptr;
		
		height = rhs.height;
		weight = rhs.weight;
		roomNum = rhs.roomNum;
		
		room = new int[roomNum];
		for(int i = 0; i < roomNum; i++)
			room[i] = rhs.room[i];
		
		return *this;
	}
};

class Vault{
	private:
	int money;
	public:
	Vault(int _money): money(_money){
		
	}
};

class Bank{
	private:
	static double interestRate;
	const Vault& vault;
	int width, height;
	
	public:
	static const int kMaxWidth = 300;
	static const int kMaxHeight = 300;
	
	Bank(const Vault& _vault, int _width, int _height): vault(_vault), width(_width), height(_height){}
	Bank(const Bank& src): vault(src.vault), width(src.width), height(src.height){}
};
double Bank::interestRate = 3.5;

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
	
	Person p3("123456-789012", 160, 60);
	Person p4("987654-321098", 170, 70);
	p3 = p4;
	cout << "p3.SSN: " << p3.GetSSN() << endl << "p3.height: " << p3.GetHeight() << endl << "p3.weight: " << p3.GetWeight() << endl << endl;
	
	Copy c1(3, 183.4, 78.5);
	Copy c2(5, 175.6, 68.3);
	c1 = c2;
	
	Vault daeguVault(200000000);
	Bank daeguBank(daeguVault, 50, 50);
	
	return 0;
}