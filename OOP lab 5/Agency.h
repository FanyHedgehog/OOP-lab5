#pragma once
#include <string>
#include "Admin.h"
#include "Tour.h"
#include "Tourist.h"
#include <vector>
using namespace std;

class Agency{
public:
	string agency_name;
	string e_mail;
	int phone;
	Agency(Admin *admins, Tourist *tourists, Tour *tours, string agency_name, string e_mail, int phone, string owner, int numbers_of_jobs, int numbers_of_customers, int level, int years_of_works){
		this->admins = admins;
		this->tourists = tourists;
		this->tours = tours;
		this->agency_name = agency_name;
		this->e_mail = e_mail;
		this->phone = phone;
		this->owner = owner;
		this->numbers_of_jobs = numbers_of_jobs;
		this->numbers_of_customers = numbers_of_customers;
		this->level = level;
		this->years_of_works = years_of_works;
	};
	~Agency(){
	};
private:
	string owner;
	int numbers_of_jobs;
	int numbers_of_customers;
	int level;
	int years_of_works;
	Admin *admins;
	Tourist *tourists;
	Tour *tours;
};