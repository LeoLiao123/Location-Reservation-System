#include"Date.h"
#include<ctime>
#include<iostream>
using namespace std;
bool leapYear(int year){
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{

			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}
bool Date::operator==(Date day2) {
	if (Year != day2.Year) {
		return false;
	}
	if (Month != day2.Month) {
		return false;
	}
	if (day != day2.day) {
		return false;
	}
	return true;
}
bool Date::operator<(Date day2) {
	if (Year > day2.Year) {
		return false;
	}
	else if (Year < day2.Year) {
		return true;
	}

	if (Month > day2.Month) {
		return false;
	}
	else if (Month < day2.Month) {
		return true;
	}

	if (day > day2.day) {
		return false;
	}
	else if(day<day2.day){
		return true;
	}

	return false;
}
Date::Date(int y, int m, int d) {
	Year = y; 
	Month = m;
	day = d;
	hour = 0;
	minute = 0;
	second = 0;
}
Date::Date(int Num) {
	second = static_cast<int>(time(0));
	second += 60 * 60 * 8;
	Num *= 24 * 60 * 60;
	second += Num;
	int year = 1970;

	int secondsPerYear = 365 * 24 * 60 * 60;
	if (leapYear(year))
		secondsPerYear += 24 * 60 * 60;

	while (second >= secondsPerYear)
	{
		second -= secondsPerYear;
		year++;

		secondsPerYear = 365 * 24 * 60 * 60;
		if (leapYear(year))
			secondsPerYear += 24 * 60 * 60;
	}
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (leapYear(year))
		days[2] = 29;

	int month = 1;
	while (second >= days[month] * 24 * 60 * 60)
	{
		second -= days[month] * 24 * 60 * 60;
		month++;
	}
	Year = year;
	Month = month;

	day = second / (24 * 60 * 60) + 1;
	second %= 24 * 60 * 60;

	hour = second / (60 * 60);
	second %= 60 * 60;

	minute = second / 60;
	second %= 60;
	/*tm structuredTime;
	time_t rawTime = time(0);
	localtime_s(&structuredTime, &rawTime);
	year = structuredTime.tm_year + 1900;
	month = structuredTime.tm_mon + 1;
	day = structuredTime.tm_mday;
	hour = structuredTime.tm_hour;
	minute = structuredTime.tm_min;
	seconds = structuredTime.tm_sec;*/
}


int Date::GetYear() {
	return Year;
}

int Date::GetMonth() {
	return Month;
}

int Date::GetDay() {
	return day;
}

int Date::GetHour() {
	return hour;
}

int Date::GetMin() {
	return minute;
}

int Date::GetSec() {
	return second;
}