#include"AvailTable.h"
#include<iostream>
#include"Date.h"
using namespace std;
AvailTable::AvailTable(Date day,int **avail) {
	date = day;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			numAvailTable[i][j] = avail[i][j];
		}
	}
}
Date AvailTable::getDay() {
	return date;
}
int AvailTable::getNum(int x, int y) {
	return numAvailTable[x][y];
}
void AvailTable::increaseCustomer(int x, int y) {
	numAvailTable[x][y] += 1;
}

void AvailTable::decreaseCustomer(int x, int y) {
	numAvailTable[x][y] -= 1;
}
