#pragma once
#include"Date.h"
#include<string>;
#include<iostream>
using namespace std;
class Reservation {
public:
	//Reservation(int customer, Date dat, int tim, char nam[], char mobileNumbe[], char emai[], char passwor[], char reservationNumbe[]);
	Reservation(int, Date, int, string, string, string, string, string);
	int getCustomer();
	Date getDate();
	int getTime();
	char* getName();
	char* getMobileNum();
	char* getEmail();
	char* getPassword();
	char* getReservationNum();
private:
	int customers;
	Date date=Date();
	int time=0;
	char name[10] = "";
	char mobileNumber[12] = "";
	char email[40] = "";
	char password[12] = "";
	char reservationNumber[19] = "";
};