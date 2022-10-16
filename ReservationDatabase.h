#pragma once
#include"Reservation.h"
#include<vector>
#include<iostream>
#include"Date.h";
using namespace std;
class ReservationDatabase {
public:
	ReservationDatabase();
	void Refreshinsert(Reservation);
	void RefreshCancell(Reservation);
	void RefreshDayByDay();
	Reservation serchReservationAndReturn(char*);
	bool SearchReservation(char*);
	bool CheckReservation(char*, char*);
	Reservation TheChoosenReservation(char*);
private:
	vector<Reservation>Reservations;
};