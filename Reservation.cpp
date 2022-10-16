#include<iostream>
#include"Reservation.h"
#include"Date.h"
using namespace std;
//Reservation::Reservation(int customer, Date dat, int tim, char nam[], char mobileNumbe[], char emai[], char passwor[], char reservationNumbe[]) {
//	customers = customer;
//	date = dat;
//	time = tim;
//	for (int i = 0; i < strlen(nam); i++) {
//		name[i] = nam[i];
//	}
//	for (int i = 0; i < strlen(mobileNumbe); i++) {
//		mobileNumber[i] = mobileNumbe[i];
//	}
//	for (int i = 0; i < strlen(emai); i++) {
//		email[i] = emai[i];
//	}
//	for (int i = 0; i < strlen(passwor); i++) {
//		password[i] = passwor[i];
//	}
//	for (int i = 0; i < strlen(reservationNumbe); i++) {
//		reservationNumber[i] = reservationNumbe[i];
//	}
//}
Reservation::Reservation(int customer, Date dat, int tim, string nam, string mobileNumbe, string emai, string passwor, string reservationNumbe) {
	customers = customer;
	date = dat;
	time = tim;
	
	for (int i = 0; i < 10 - nam.size(); i++) {
		name[i] = ' ';
	}
	for (int i = 0; i < nam.size(); i++) {
		name[i+10-nam.size()] = nam[i];
	}

	for (int i = 0; i < 12 - mobileNumbe.size(); i++) {
		mobileNumber[i] = ' ';
	}
	for (int i = 0; i < mobileNumbe.size(); i++) {
		mobileNumber[i+12-mobileNumbe.size()] = mobileNumbe[i];
	}

	for (int i = 0; i < 40 - emai.size(); i++) {
		email[i] = ' ';
	}
	for (int i = 0; i < emai.size(); i++) {
		email[i + 40 - emai.size()] = emai[i];
	}

	for (int i = 0; i < 12 - passwor.size(); i++) {
		password[i] = ' ';
	}
	for (int i = 0; i < passwor.size(); i++) {
		password[i + 12 - passwor.size()] = passwor[i];
	}

	for (int i = 0; i < 19 - reservationNumbe.size(); i++) {
		reservationNumber[i] = ' ';
	}
	for (int i = 0; i < reservationNumbe.size(); i++) {
		reservationNumber[i + 19 - reservationNumbe.size()] = reservationNumbe[i];
	}
}

int Reservation::getCustomer() {
	return customers;
}
int Reservation::getTime() {
	return time;
}
Date Reservation::getDate() {
	return date;
}
char* Reservation::getEmail() {
	return email;
}
char* Reservation::getMobileNum() {
	return mobileNumber;
}
char* Reservation::getName() {
	return name;
}
char* Reservation::getPassword() {
	return password;
}
char* Reservation::getReservationNum() {
	return reservationNumber;
}
