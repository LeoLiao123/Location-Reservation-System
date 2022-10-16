#pragma once
#include<string>;
#include<iostream>
using namespace std;
class Date {
public:
	Date(int i=0);
	Date(int, int, int);
	bool operator==(Date);
	bool operator<(Date);
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMin();
	int GetSec();

private:
	int Year;
	int Month;
	int day;
	int hour;
	int minute;
	int second;
	int total_time;
};