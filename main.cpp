#include<iostream>
#include <fstream>
#include"AvailTable.h"
#include"AvailTableDatabase.h"
#include"Date.h"
#include"MakeReservation.h"
#include"Reservation.h"
#include"ReservationDatabase.h"
#include"ReservationInquiry.h"
using namespace std;
int main() {


	char space = ' ';
	fstream file;
	int ch;
	file.open("AvailTables.dat", ios::in);
	ch = file.get();
	if (ch == EOF) {
		file.close();
		ofstream outfile;
		outfile.open("AvailTables.dat");
		for (int i = 1; i < 31; i++) {
			Date day(i-1);
			outfile << day.GetYear() << space << day.GetMonth() << space << day.GetDay() << endl;
			for (int j = 0; j < 4; j++) {
				for (int g = 0; g < 6; g++) {
					outfile << 0;
					if (g != 5) {
						outfile << space;
					}
				}
				outfile << endl;
			}
		}
	}
	file.close();

	AvailTableDatabase refresh;
	refresh.RefreshEveryDay();
	ReservationDatabase rerefresh;
	rerefresh.RefreshDayByDay();

	while (true) {
		cout << "Welcome to Hi-Lai Harbour Taoyuan Location!" << endl;
		cout << endl;
		cout << "1 - Book a Table" << endl;
		cout << "2 - My Bookings" << endl;
		cout << "3 - End" << endl;
		cout << endl;
		cout << "Enter your choice: (1~3): ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			MakeReservation make;
		}
		else if (choice == 2) {
			ReservationInquiry inquiry;
		}
		else if (choice == 3) {
			break;
		}
	}
	
}