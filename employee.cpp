/**
Lab Program 5
Employee Class
Author ujwalp15
*/

#include<iostream>
using namespace std;

class EMPLOYEE
{
	int emp_no,basic_sal,all_allow,it,net_sal;
	char emp_name[30];
	
	public:
	void read();
	void calculate();
	void display();
};

void EMPLOYEE::read()
{
	cout<<"\n Employee No:  ";
	cin>>emp_no;
	cout<<"\n Employee Name:  ";
	cin>>emp_name;
	cout<<"\n Employee Salary: ";
	cin>>basic_sal;
}

void EMPLOYEE::calculate()
{
	all_allow=1.23*basic_sal;
	it=0.3*(all_allow+basic_sal);
	net_sal=basic_sal+all_allow-it;
}

void EMPLOYEE::display()
{
	cout<<"\n Employee No. :  "<<emp_no;
	cout<<"\n Employee Name. :  "<<emp_name;
	cout<<"\n Basic Salary :  "<<basic_sal;
	cout<<"\n All Allowance :  "<<all_allow;
	cout<<"\n IT :  "<<it;
	cout<<"\n Net Salary :  "<<net_sal;
	cout<<"\n";
}

int main()
{
	int i,n=0;
	cout<<"\n Enter the no. of Employees:  ";
	cin>>n;
	EMPLOYEE E[n];
	cout<<"\n Enter Employee Details";
	for(i=0;i<n;i++)
	{
		cout<<"\n Employee "<<i+1;
		E[i].read();
	}
	cout<<"\n\n Details:  ";
	for(i=0;i<n;i++)
	{
		E[i].calculate();
		cout<<"\n Employee "<<i+1;
		E[i].display();
	}
	return 0;
}
	
