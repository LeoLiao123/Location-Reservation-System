#include<iostream>
#include"ReservationDatabase.h"
#include <fstream>
#include <cstdlib>
#include<string> 
#include"Date.h"
using namespace std;
bool CompareTwoCstringRN(char* left,char* right) {

	for (int i = 0; i < 19; i++) {
		if (left[i] != right[i]) {
			return false;
		}
	}
	return true;
}
bool CompareTwoCstringPS(char* left, char* right) {

	for (int i = 0; i < 12; i++) {
		if (left[i] != right[i]) {
			return false;
		}
	}
	return true;
}
ReservationDatabase::ReservationDatabase() {
	ifstream infile;
	infile.open("Reservation.dat");
	long long lines = 0;
	string temp;
	while (getline(infile, temp)) {
		lines++;
	}
	infile.close();
	if (lines != 0) {
		infile.open("Reservation.dat");
		string s;
		for (int i = 0; i < lines / 10; i++) {

			getline(infile, s);
			int customerNum = atoi(s.c_str());

			getline(infile, s);
			int Y = atoi(s.c_str());

			getline(infile, s);
			int M = atoi(s.c_str());

			getline(infile, s);
			int D = atoi(s.c_str());

			getline(infile, s);
			int Time = atoi(s.c_str());

			getline(infile, s);
			string Name = s;

			getline(infile, s);
			string mobileNum = s;

			getline(infile, s);
			string Email = s;

			getline(infile, s);
			string Password = s;

			getline(infile, s);
			string ReservationNum = s;

			Date TheDay(Y, M, D);
			Reservation TheReservation(customerNum, TheDay, Time, Name, mobileNum, Email, Password, ReservationNum);
			Reservations.push_back(TheReservation);
		}
		infile.close();
	}
}

void ReservationDatabase::Refreshinsert(Reservation newReservation) {
	Reservations.push_back(newReservation);
	/*int customer = newReservation.getCustomer();
	Date day = newReservation.getDate();
	int time = newReservation.getTime();
	char* name = newReservation.getName();
	char* mobileNumber = newReservation.getMobileNum();
	char* email = newReservation.getEmail();
	char* password = newReservation.getPassword();
	char* reservationNum = newReservation.getReservationNum();*/
	ofstream outfile;
	outfile.open("Reservation.dat");
	for (int g = 0; g < Reservations.size(); g++) {
		
		char space = ' ';
		outfile << Reservations[g].getCustomer() << endl;
		outfile << Reservations[g].getDate().GetYear() << endl; 
		outfile << Reservations[g].getDate().GetMonth() << endl; 
		outfile << Reservations[g].getDate().GetDay() << endl;
		outfile << Reservations[g].getTime() << endl;

		char* name = Reservations[g].getName();
		for (int i = 0; i < 10; i++) {
			outfile << name[i];
		}
		outfile << endl;

		char* mobileNumber = Reservations[g].getMobileNum();
		for (int i = 0; i < 12; i++) {
			outfile << mobileNumber[i];
		}
		outfile << endl;

		char* email = Reservations[g].getEmail();
		for (int i = 0; i < 40; i++) {
			outfile << email[i];
		}
		outfile << endl;

		char* password = Reservations[g].getPassword();
		for (int i = 0; i < 12; i++) {
			outfile << password[i];
		}
		outfile << endl;

		char* reservationNum = Reservations[g].getReservationNum();
		for (int i = 0; i < 19; i++) {
			outfile << reservationNum[i];
		}
		outfile << endl;
		
	}
	outfile.close();
}

bool ReservationDatabase::CheckReservation(char* reservationNum, char* password) {
	for (int i = 0; i < Reservations.size(); i++) {
		if (CompareTwoCstringRN(Reservations[i].getReservationNum(),reservationNum)) {
			if (CompareTwoCstringPS(Reservations[i].getPassword(),password)) {
				return true;
			}
		}
	}
	return false;
}

Reservation ReservationDatabase::TheChoosenReservation(char* reservationNum) {
	for (int i = 0; i < Reservations.size(); i++) {
		if (CompareTwoCstringRN(Reservations[i].getReservationNum(),reservationNum)) {
			return Reservations[i];
		}
	}
}

bool ReservationDatabase::SearchReservation(char* ReservationNum) {
	for (int i = 0; i < Reservations.size(); i++) {
		if (CompareTwoCstringRN(Reservations[i].getReservationNum(), ReservationNum)) {
			return true;
		}
	}
	return false;
}

Reservation ReservationDatabase::serchReservationAndReturn(char* ReservationNum) {
	for (int i = 0; i < Reservations.size(); i++) {
		if (CompareTwoCstringRN(Reservations[i].getReservationNum(), ReservationNum)) {
			return Reservations[i];
		}
	}
}

void ReservationDatabase::RefreshCancell(Reservation TheCancelledReservation) {
	for (int i = 0; i < Reservations.size(); i++) {
		if (CompareTwoCstringRN(Reservations[i].getReservationNum(), TheCancelledReservation.getReservationNum())) {
			Reservations.erase(Reservations.begin() + i);
		}
	}
	ofstream outfile;
	outfile.open("Reservation.dat");
	for (int g = 0; g < Reservations.size(); g++) {
		
		char space = ' ';
		outfile << Reservations[g].getCustomer() << endl;
		outfile << Reservations[g].getDate().GetYear() << endl;
		outfile << Reservations[g].getDate().GetMonth() << endl;
		outfile << Reservations[g].getDate().GetDay() << endl;
		outfile << Reservations[g].getTime() << endl;

		char* name = Reservations[g].getName();
		for (int i = 0; i < 10; i++) {
			outfile << name[i];
		}
		outfile << endl;

		char* mobileNumber = Reservations[g].getMobileNum();
		for (int i = 0; i < 12; i++) {
			outfile << mobileNumber[i];
		}
		outfile << endl;

		char* email = Reservations[g].getEmail();
		for (int i = 0; i < 40; i++) {
			outfile << email[i];
		}
		outfile << endl;

		char* password = Reservations[g].getPassword();
		for (int i = 0; i < 12; i++) {
			outfile << password[i];
		}
		outfile << endl;

		char* reservationNum = Reservations[g].getReservationNum();
		for (int i = 0; i < 19; i++) {
			outfile << reservationNum[i];
		}
		outfile << endl;
		
	}
	outfile.close();
}

void ReservationDatabase::RefreshDayByDay() {
	Date newDay(0);
	for (int i = 0; i < Reservations.size(); i++) {
		if (Reservations[i].getDate() < newDay) {
			Reservations.erase(Reservations.begin() + i);
			RefreshDayByDay();
		}
	}
	ofstream outfile;
	outfile.open("Reservation.dat");
	for (int g = 0; g < Reservations.size(); g++) {

		char space = ' ';
		outfile << Reservations[g].getCustomer() << endl;
		outfile << Reservations[g].getDate().GetYear() << endl;
		outfile << Reservations[g].getDate().GetMonth() << endl;
		outfile << Reservations[g].getDate().GetDay() << endl;
		outfile << Reservations[g].getTime() << endl;

		char* name = Reservations[g].getName();
		for (int i = 0; i < 10; i++) {
			outfile << name[i];
		}
		outfile << endl;

		char* mobileNumber = Reservations[g].getMobileNum();
		for (int i = 0; i < 12; i++) {
			outfile << mobileNumber[i];
		}
		outfile << endl;

		char* email = Reservations[g].getEmail();
		for (int i = 0; i < 40; i++) {
			outfile << email[i];
		}
		outfile << endl;

		char* password = Reservations[g].getPassword();
		for (int i = 0; i < 12; i++) {
			outfile << password[i];
		}
		outfile << endl;

		char* reservationNum = Reservations[g].getReservationNum();
		for (int i = 0; i < 19; i++) {
			outfile << reservationNum[i];
		}
		outfile << endl;

	}
	outfile.close();
}