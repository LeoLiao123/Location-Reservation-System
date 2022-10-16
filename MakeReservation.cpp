#include"MakeReservation.h"
#include<iostream>
#include"Date.h"
#include<string>
#include <iomanip>
#include"Reservation.h"
#include"ReservationDatabase.h"
using namespace std;
MakeReservation::MakeReservation() {
	AvailTableDatabase check;
	cout << endl;
	cout << "Enter the number of customers (1 - 7, 10 - 12): ";
	int customers;
	cin >> customers;
	int type = check.TableType(customers);
	cout << endl;
	cout << "Choose a date" << endl;
	int counts = 0;
	for (int i = 1; i < 31; i++) {
		Date day(i - 1);
		if (check.CheckAvailDay(day,type)) {
			if (i < 10) {
				cout << " ";
			}
			cout << i << ". " << day.GetYear() << "/";
			if (day.GetMonth() < 10) {
				cout << "0";
			}
			cout << day.GetMonth() << "/";
			if (day.GetDay() < 10) {
				cout << "0";
			}
			cout << day.GetDay() << "  ";
			counts++;
		}
		if (counts % 4 == 0) {
			cout << endl;
		}
	}
	cout << endl;
	cout << "?";
	int ChooseD;
	cin >> ChooseD;
	cout << endl;
	string TimeType[3] = {"11:30","14:30","17:30"};
	for (int i = 1; i < 4; i++) {
		if (check.CheckAvailTime(ChooseD-1, i, type)) {
			if (i == 1) {
				cout << "1. 11:30" << endl;
			}
			else if (i == 2) {
				cout << "2. 14:30" << endl;
			}
			else if (i == 3) {
				cout << "3. 17:30" << endl;
			}
		}
	}
	cout << "?";
	int chooseT;
	cin >> chooseT;
	cout << endl;
	Date TheChoosenDay(ChooseD-1);
	check.RefreshNewAvailTable(TheChoosenDay, chooseT, type);
	string name, EmailAddress,MobileNumber, password;
	cout << "Enter name: ";
	cin >> name;
	cout << endl;
	cout << "Enter mobile number: ";
	cin >> MobileNumber;
	cout << endl;
	cout << "Enter email address: ";
	cin >> EmailAddress;
	cout << endl;
	cout << "Enter reservation password: ";
	cin >> password;
	cout << endl;
	cout << "  Mobile No.    Name          Date     Time                                   Email    No of Customers    Password    Reservation No." << endl;
	cout << setw(12) << MobileNumber << setw(8) << name << "    ";
	
	cout << TheChoosenDay.GetYear() << "/";
	if (TheChoosenDay.GetMonth() < 10) {
		cout << 0;
	}
	cout << TheChoosenDay.GetMonth() << "/";
	if (TheChoosenDay.GetDay() < 10) {
		cout << 0;
	}
	long long int ReservationNum = (rand() % 100000000) + 10000000; 
	cout << TheChoosenDay.GetDay() << setw(9) << TimeType[chooseT - 1] << setw(40) << EmailAddress << setw(19) << customers << setw(12) << password << setw(19) << ReservationNum << endl;
	cout << endl;
	cout << "Reservation Completed." << endl;
	cout << endl;
	string ReservationS = (to_string(ReservationNum));
	Reservation newReservation(customers, TheChoosenDay, chooseT, name, MobileNumber, EmailAddress, password, ReservationS);
	ReservationDatabase database;
	database.Refreshinsert(newReservation);
}