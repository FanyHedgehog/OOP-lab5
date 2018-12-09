#pragma once
#include<iostream>
#include "string"
#include "Man.h"
using namespace std;
class Admin;
class CEO :public Man
{
public:
	using Man::age;
	string position;
	string education;
	CEO(string, string, string, int, string, string, string, int, int, int, int);
	CEO(string, string, string, int, string, string, string, int);
	CEO() :adr(salary){}
	CEO(string position, int salary) :position(position), salary(salary), adr(salary){} //5 список ініціалізації
	int getWorkExperience();
	int getSalary();
	void setSalary(int);
	void ChangePosition(Admin &);
	void English();
	~CEO(){
		cout << "CEO destructor" <<endl;
	}
protected:
	int business_trip;
	int work_experience;
	int number_of_subordinates;
private:
	int salary;
	int& adr;
};
