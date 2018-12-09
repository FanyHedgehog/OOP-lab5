#include <fstream>
#include <cstring>
#include"Admin.h"
#include"Tour.h"

Admin::Admin(string name, string surname, string english_level, string sex, int age, int salary) : Man(name, surname, english_level, sex, age){
	this->salary = salary;
}

void Admin::AddTour(string country, int lenght, int rate, string hotel, string room_type, string transport, int price, int departure_date){
	Tour tour(country, lenght, rate, hotel, room_type, transport, price, departure_date);
	WriteTourToFile(tour);
}
void Admin::WriteTourToFile(Tour tour){
	ofstream file("Tours.data", ios::app);
	file.write((char *)&tour, sizeof(Tour));
	file.close();
}
void Admin::ReadTourFromFile(Tour *tour, int n){
	try{
		
		ifstream file("Tours.data");
		file.exceptions(ifstream::badbit | ifstream::failbit);


		for (int i = 0; i < n; i++){
			file.read((char *)&tour[i], sizeof(Tour));
		}
		file.close();
	}
	catch (const std::exception &ex){
		cout << "Error" << endl;
	}
}
void Admin::charge(){
	if (english_level == "B"){
		setSalary(getSalary() + 100);
	}
	cout << "Virtual metod of Admin" << endl;
}