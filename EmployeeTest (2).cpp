#include <iostream>

using namespace std;

namespace MET
{
	class Employee
	{
		private: 
			int eid;
			int hours;
			double rate;
			static int count;
		public:
			Employee()
			{
				eid = ++count;
				hours = 180;
				rate = 100;
				cout <<"Employee Instance Activated through Default CTor" << endl;
			}

			Employee(int hh, float rr)
			{	eid = ++count;
				hours = hh;
				rate = rr;
				cout <<"Employee Instance Activated through Parameterised CTor" << endl;
			}
                        //double AnnualIncome(const Employee* this)
			virtual double AnnualIncome() const 
			{
				return hours * rate * 12 * 1.12;
			}

			virtual void DisplayDetails()
			{
				cout << "Printing Employee Details" << endl;
				cout << "=========================" << endl;
				cout << "Id : " << eid << endl;
				cout << "Hours worked : " << hours << endl;
				cout << "Rate : " << rate << endl;
				cout << "Total Annual income : " << AnnualIncome() << endl;

			}
			~Employee()
			{	
				--count;
				cout << "Employee Instance DeActivated" << endl;
			}

	};

	class SalesPerson : public Employee
	{
		private:
			double sales;
		public:
			SalesPerson() : Employee()
			{
				sales = 25000;
			}
	   
			SalesPerson(int hh, float rr, double ss) : Employee(hh, rr)
			{
				sales = ss;
			}
 
			double AnnualIncome() const
			{
				double basicannualincome = Employee::AnnualIncome();
				return basicannualincome + 0.25 * sales;
			}

			void DisplayDetails()
			{
				Employee::DisplayDetails();
				cout << "SalesPerson Total Sales : " << sales << endl;

			}

	};


}

using namespace MET;

int Employee :: count = 0;

double Tax(const Employee* emp)
{	//               Employee::AnnualIncome(emp)   Static Binding  // Dynamic binding
	double aincome = emp->AnnualIncome();
	if (aincome > 500000) 
		return 0.1 * (aincome - 500000);
	return 0.0;
}
/*
double Tax(const SalesPerson* emp)
{	//               SalesPerson::AnnualIncome(emp)
	double aincome = emp->AnnualIncome();
	if (aincome > 500000) 
		return 0.1 * (aincome - 500000);
	return 0.0;
}
*/
int main()
{
  Employee e;
  Employee e1(200, 200);
  Employee* emp;
  emp = new Employee(250, 250);
  SalesPerson sp(200, 200, 50000);
 // e.DisplayDetails();
  cout << "First Employee A Income : " << e.AnnualIncome() << endl;
  cout << "Appliclable Tax: " << Tax(&e) << endl;

  //e1.DisplayDetails();
  
  cout << "Second Employee A Income : " << e1.AnnualIncome() << endl;
  cout << "Appliclable Tax: " << Tax(&e1) << endl;

  //emp->DisplayDetails();
  cout << "Third Employee A Income : " << emp->AnnualIncome() << endl;
  cout << "Appliclable Tax: " << Tax(emp) << endl << endl;

  cout << "Displaying SalesPersons Data" << endl <<endl;
  cout << "SalesPerson A Income : " << sp.AnnualIncome() << endl;
  //sp.DisplayDetails();

  //cout << "Displaying Annual Income of SalesPerson " << sp.AnnualIncome() << endl;
  cout << "Appliclable Tax: " << Tax(&sp) << endl;
  
  return 0;

}


