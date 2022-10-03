/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#include <iostream>
#include "date.h"
#include <string>
using namespace std;

Date::Date(){
    month = "00";
    day = "00";
    hour = "00:00:00";
}

Date::Date(string month, string day, string hour){
    this->month = month;
    this->day = day;
    this->hour = hour;
}

Date::~Date(){}

string Date::getMonth(){return month;}

string Date::getDay(){return day;}


string Date::getHour(){return hour;}

void Date::setMonth(string month){this->month = month;}

void Date::setDay(string day){this->day = day;}

void Date::setHour(string hour){this->hour = hour;}

string Date::printDate(){
    return month + " " + day + " " + hour;
}


