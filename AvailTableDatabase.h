#pragma once
#include"AvailTable.h"
#include"Date.h"
#include<vector>
#include<iostream>
#include"Reservation.h"
#include"ReservationDatabase.h"
using namespace std;
class AvailTableDatabase {
public:
	AvailTableDatabase();
	int TableType(int);
	void TheCancellReservationRecover(Reservation);
	void RefreshNewAvailTable(Date, int, int);
	void RefreshEveryDay();
	bool CheckAvailDay(Date,int);
	bool CheckAvailTime(int,int,int);
private:
	vector<AvailTable>AvailTables;
};