#include <iostream>
#include <string>
#include "Tour.h"
#include "Tourist.h"
#include "Admin.h"
#include "Man.h"
#include "CEO.h"
#include "Agency.h"


using namespace std;
int Admin::salary;
int Tour::object_count;
class AdminAdding{};
class TouristAdding{};
class TourAdding{};
void main(){
	
	Man *ptr = new Man;
	ptr->charge();
	delete ptr;
	ptr = new Admin;
	ptr->charge();
	delete ptr;
	Admin admin1("Vova", "Petrov", "C", "man", 25, 1000);

	Man *ptr;
	CEO ceo;
	ptr = &admin1;
	ptr->charge();
	ptr = &ceo;
	ptr->charge();
	delete ptr;

	Tourist tourist1("Kolya", "Ivanov", "A", "man", 25, 2010, 65442, 63592565, 63474, 46737);


	Admin *ptr = &admin1;
	ptr->charge();
	ptr = (Tourist *)&tourist1;// ���������� ����
	ptr->charge();
	delete ptr;
	
	Man*ptr;
	ptr = new Admin;
	ptr->charge();//���� ����������
	delete ptr;
	Man*func;
	func = new Admin;
	func -> getAge();//����� ����������
	delete func;
	try{
		Man *a = new Admin;//3
		if (a == NULL){
			throw(AdminAdding());
		}
		delete a;
		Admin *admin = new Admin("Petro", "Petrov", "B", "man",24, 1000);
		if (admin == NULL){
			throw(AdminAdding());
		}
		admin->AddTour("Ukraine", 10, 4, "HUkraine", "a", "bus", 11, 200);
		admin->AddTour("France", 11, 5, "HFrance", "b", "plane", 15, 1000);
		cout << "Hello! The rules of the program. If you want to say yes, press 1, if no - press 0" << endl;
		Tourist *tourist = new Tourist("Ivan", "Ivanov", "C", "man", 25, 2010, 65442, 63592565, 63474, 10000);
		if (tourist == NULL){
			throw(TouristAdding());
		}
		admin->setTourist(tourist);
		cout << "Count of added tours " << Tour::ObjectCount() << endl;//8
		cout << "Enter price?" << endl;
		Tour *tour_mass = new Tour[4];//�� �� ������ ��� Tour(){},�������� ���'���,����� ��'����
		if (tour_mass == NULL){
			throw(TourAdding());
		}
		admin->Man::charge();//11 ����� ��������� �-��
		Agency agency(admin, tourist, tour_mass, "Around the world", "Email", 123456, "Owner", 2, 2, 1, 2);
		admin->ReadTourFromFile(tour_mass, 4);
		int count_orders = 0;
		string country_tour;
		int price;
		cin >> price;
		count_orders++;
		tourist->ChooseTourForMoney(tour_mass, price, 4, *admin);
		bool yes_no = 0;
		cout << "Do you need other or one more tour?" << endl;
		cin >> yes_no;
		if (yes_no == 1){
			cout << "Enter country:" << endl;
			cin >> country_tour;
		}
		if (yes_no == 1){
			count_orders++;
			tourist->ChooseTour(tour_mass, country_tour, 2, *admin);
		}
		cout << "Do you want pay for order(s)" << endl;
		cin >> yes_no;

		if (yes_no == 1){
			cout << "Last price your orders is " << tourist->GetOrdersPrice(count_orders) << ". Do you want pay by card: " << tourist->getCardNumber() << " ?" << endl;
		}
		cin >> yes_no;
		if (yes_no == 1){
			tourist->PayForTour(tourist->GetOrdersPrice(count_orders));
		}
		else{

			cout << "Please, enter new cardnumber" << endl;
			int cardnumber;
			cin >> cardnumber;
			tourist->setCardNumber(cardnumber);
			if (tourist->getCardNumber() % 2 == 0){
				tourist->PayForTour();
			}
			else{
				tourist->PayForTour(tourist->GetOrdersPrice(count_orders));
			}

		}
		
	}
	catch (AdminAdding()){
		cout << "Object Admin was not created" << endl;
	}
	catch (TouristAdding()){
		cout << "Object Tourist was not created" << endl;
	}
	catch (TourAdding()){
		cout << "Objects Tour was not created" << endl;
	}

	cin.get();
	cin.get();
}