// Employee.h
#include <string>

using namespace std;

namespace Records{
	const int kDefaultStartingSalary = 30000;
	
	class Employee{
		public:
		Employee();
		void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire();
		void fire();
		void display() const;
		
		void setFirstName(string inFirstName);
		string getFirstName() const;
		void setLastName(string inLastName);
		string getLastName() const;
		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber() const;
		void setSalary(int inNewSalary);
		int getSalary() const;
		bool getIsHired() const;
		
		protected:
		string mFirstName;
		string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool bHired;
	};
}