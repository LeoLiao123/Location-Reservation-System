#include"AvailTableDatabase.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include<string> 
#include"AvailTable.h"
#include"Reservation.h"
#include"ReservationDatabase.h"
using namespace std;
AvailTableDatabase::AvailTableDatabase() {
	ifstream infile;
	infile.open("AvailTables.dat");
	int y = 0, m = 0, d = 0;
	int data[4][6] = { 0 };
	int* data2[4];
	for (int g = 1; g < 31; g++) {
		infile >> y;
		infile >> m;
		infile >> d;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				infile >> data[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			data2[i] = data[i];
		}
		Date day(y, m, d);
		
		AvailTable table(day, data2);
		AvailTables.push_back(table);
	}
	infile.close();
}

int AvailTableDatabase::TableType(int customer) {
	int type = 0;
	if (customer < 3) {
		type = 1;
	}
	else if (customer < 5) {
		type = 2;
	}
	else if (customer < 6) {
		type = 3;
	}
	else if (customer < 8) {
		type = 4;
	}
	else if (customer > 9 && customer < 13) {
		type = 5;
	}
	return type;
}

bool AvailTableDatabase::CheckAvailDay(Date date2,int type) {
	for (int i = 0; i < 30; i++) {
		if (AvailTables[i].getDay() == date2) {
			int counts = 0;
			for (int j = 1; j < 4; j++) {
				if (AvailTables[i].getNum(j, type) > 1) {
					counts++;
				}
			}
			//cout << counts;
			if (counts == 3) {
				return false;
			}
			break;
		}
	}
	return true;
}

bool AvailTableDatabase::CheckAvailTime(int day, int time,int type) {
	if (AvailTables[day].getNum(time, type) > 1) {
		return false;
	}
	return true;
}
void AvailTableDatabase::RefreshNewAvailTable(Date day,int time,int type){
	char space = ' ';
	ofstream outfile;
	outfile.open("AvailTables.dat");
	for (int i = 0; i < 30; i++) {
		if (AvailTables[i].getDay() == day) {
			AvailTables[i].increaseCustomer(time, type);
			outfile << AvailTables[i].getDay().GetYear() << space << AvailTables[i].getDay().GetMonth() << space << AvailTables[i].getDay().GetDay() << endl;
			for (int j = 0; j < 4; j++) {
				for (int g = 0; g < 6; g++) {
					outfile << AvailTables[i].getNum(j, g) << space;
				}
				outfile << endl;
			}
		}
		else {
			outfile << AvailTables[i].getDay().GetYear() << space << AvailTables[i].getDay().GetMonth() << space << AvailTables[i].getDay().GetDay() << endl;
			for (int j = 0; j < 4; j++) {
				for (int g = 0; g < 6; g++) {
					outfile << AvailTables[i].getNum(j, g) << space;
				}
				outfile << endl;
			}
		}
	}
	
	outfile.close();
	
}

void AvailTableDatabase::TheCancellReservationRecover(Reservation cancellCase) {
	int type = TableType(cancellCase.getCustomer());
	Date day = cancellCase.getDate();
	int time = cancellCase.getTime();
	char space = ' ';
	ofstream outfile;
	outfile.open("AvailTables.dat");
	for (int i = 0; i < 30; i++) {
		if (AvailTables[i].getDay() == day) {
			AvailTables[i].decreaseCustomer(time, type);
			outfile << AvailTables[i].getDay().GetYear() << space << AvailTables[i].getDay().GetMonth() << space << AvailTables[i].getDay().GetDay() << endl;
			for (int j = 0; j < 4; j++) {
				for (int g = 0; g < 6; g++) {
					outfile << AvailTables[i].getNum(j, g) << space;
				}
				outfile << endl;
			}
		}
		else {
			outfile << AvailTables[i].getDay().GetYear() << space << AvailTables[i].getDay().GetMonth() << space << AvailTables[i].getDay().GetDay() << endl;
			for (int j = 0; j < 4; j++) {
				for (int g = 0; g < 6; g++) {
					outfile << AvailTables[i].getNum(j, g) << space;
				}
				outfile << endl;
			}
		}
	}

	outfile.close();
}

void AvailTableDatabase::RefreshEveryDay() {
	Date newDay(0);
	int start=30;

	int data[4][6] = { 0 };
	int* data2[4];
	for (int i = 0; i < 4; i++) {
		data2[i] = data[i];
	}

	for (int i = 0; i < 30; i++) {
		if (AvailTables[i].getDay() == newDay) {
			start = i;
		}
	}
	for (int i = 0; i < start; i++) {
		AvailTables.erase(AvailTables.begin());
	}
	int start2 = 30 - start;
	for (int i = 0; i < start; i++) {
		Date TheDay(start2 + i);
		AvailTable availTable(TheDay, data2);
		AvailTables.push_back(availTable);
	}


	char space = ' ';
	ofstream outfile;
	outfile.open("AvailTables.dat");
	for (int i = 0; i < 30; i++) {
		outfile << AvailTables[i].getDay().GetYear() << space << AvailTables[i].getDay().GetMonth() << space << AvailTables[i].getDay().GetDay() << endl;
		for (int j = 0; j < 4; j++) {
			for (int g = 0; g < 6; g++) {
				outfile << AvailTables[i].getNum(j, g) << space;
			}
			outfile << endl;
		}

	}

	outfile.close();
}