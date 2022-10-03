/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#include <iostream>
#include "date.h"
#include <string>
using namespace std;

Date::Date(){}

Date::Date(string month, int day, int hour, int minute, int second){
    this->month = month;
    this->day = day;
    this->hour = hour;
}

Date::~Date(){}

// Getters
string Date::getMonth(){return month;}
int Date::getDay(){return day;}
int Date::getHour(){return hour;}
int Date::getMinute(){return minute;}
int Date::getSecond(){return second;}

// Setters
void Date::setMonth(string month){this->month = month;}
void Date::setDay(int day){this->day = day;}
void Date::setHour(int hour){this->hour = hour;}
void Date::setMinute(int minute){this->minute = minute;}
void Date::setSecond(int second){this->second = second;}



