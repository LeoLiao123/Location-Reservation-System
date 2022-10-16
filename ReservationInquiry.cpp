#include<iostream>
#include"Date.h"
#include"ReservationInquiry.h"
#include"Reservation.h"
#include"ReservationDatabase.h"
#include <iomanip>
#include<string>
#include <fstream>
#include"AvailTableDatabase.h"
#include"AvailTable.h"
using namespace std;
ReservationInquiry::ReservationInquiry() {
	AvailTableDatabase base;
	ifstream infile;
	infile.open("Reservation.dat");
	long long lines = 0;
	string temp;
	while (getline(infile, temp)) {
		lines++;
	}
	infile.close();

	if (lines != 0) {
		string TimeType[3] = { "11:30","14:30","17:30" };
		ReservationDatabase DataBase;
		long long reserevationNum, reservationPassword;
		cout << endl;
		cout << "Enter reservation number: ";
		cin >> reserevationNum;
		cout << endl;
		char ReservationNumber[19] = "";
		for (int i = 18; i >= 0; i--) {
			if (reserevationNum > 0) {
				ReservationNumber[i] = reserevationNum % 10 + 48;
				reserevationNum /= 10;
			}
			else {
				ReservationNumber[i] = ' ';
			}
		}
		if (DataBase.SearchReservation(ReservationNumber)) {
			cout << "Enter reservation password: ";
			cin >> reservationPassword;
			cout << endl;
			char password[12] = "";

			for (int i = 11; i >= 0; i--) {
				if (reservationPassword > 0) {
					password[i] = reservationPassword % 10 + 48;
					reservationPassword /= 10;
				}
				else {
					password[i] = ' ';
				}
			}

			if (DataBase.CheckReservation(ReservationNumber, password)) {
				cout << "  Mobile No.      Name          Date     Time                                   Email    No of Customers    Password    Reservation No." << endl;
				Reservation TheChoosenReservation = DataBase.TheChoosenReservation(ReservationNumber);
				char* MobileNo = TheChoosenReservation.getMobileNum();
				for (int i = 0; i < 12; i++) {
					cout << MobileNo[i];
				}
				char* Name = TheChoosenReservation.getName();
				for (int i = 0; i < 10; i++) {
					cout << Name[i];
				}
				cout << "    " << TheChoosenReservation.getDate().GetYear() << "/";
				if (TheChoosenReservation.getDate().GetMonth() < 10) {
					cout << 0;
				}
				cout << TheChoosenReservation.getDate().GetMonth() << "/";
				if (TheChoosenReservation.getDate().GetDay() < 10) {
					cout << 0;
				}
				cout << TheChoosenReservation.getDate().GetDay() << setw(9) << TimeType[TheChoosenReservation.getTime()-1];
				char* ema = TheChoosenReservation.getEmail();
				for (int i = 0; i < 40; i++) {
					cout << ema[i];
				}
				cout << setw(19) << TheChoosenReservation.getCustomer();
				char* password = TheChoosenReservation.getPassword();
				for (int i = 0; i < 12; i++) {
					cout << password[i];
				}
				for (int i = 0; i < 19; i++) {
					cout << ReservationNumber[i];
				}
				cout << endl;
				cout << "Cancel this reservation? ( y/n ) ";
				char choice;
				cin >> choice;
				cout << endl;
				if (choice == 'y') {
					Reservation TheCancelledReservation = DataBase.serchReservationAndReturn(ReservationNumber);
					DataBase.RefreshCancell(TheCancelledReservation);
					base.TheCancellReservationRecover(TheCancelledReservation);
					cout << "This reservation has been cancelled." << endl;
				}
				cout << endl;
			}
		}
		else {
			cout << "No reservations with this reservation number!" << endl;
			cout << endl;
		}
	}
	else {
		cout << endl;
		cout << "No reservations!" << endl;
		cout << endl;
	}
}
