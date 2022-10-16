#pragma once
#include"Date.h"
#include<string>;
#include<iostream>
using namespace std;
class AvailTable {
public:
	AvailTable(Date,int**);
	Date getDay();
	int getNum(int, int);
	void increaseCustomer(int, int);
	void decreaseCustomer(int, int);
private:
	Date date;
	int numAvailTable[4][6] = { 0 };
};