/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#include <iostream>
#include "date.h"
#include <string>
using namespace std;

Date::Date(){}

Date::Date(string month, int day, int hour, int minute, int second,int monthInt){
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->monthInt = monthInt;
}

Date::~Date(){}

// Getters
string Date::getMonth(){return month;}
int Date::getDay(){return day;}
int Date::getHour(){return hour;}
int Date::getMinute(){return minute;}
int Date::getSecond(){return second;}
int Date::getMonthInt(){return monthInt;}

// Setters
void Date::setDay(int day){this->day = day;}
void Date::setHour(int hour){this->hour = hour;}
void Date::setMinute(int minute){this->minute = minute;}
void Date::setSecond(int second){this->second = second;}
void Date::setMonthInt(int monthInt){this->monthInt = monthInt;}
void Date::setMonth(string month){this->monthInt = monthToString(month);}

int Date::monthToString(string month){
    if(month == "Jan"){
        return 1;
    } else if(month == "Feb"){
        return 2;
    } else if(month == "Mar"){
        return 3;
    } else if(month == "Apr"){
        return 4;
    } else if(month == "May"){
        return 5;
    } else if(month == "Jun"){
        return 6;
    } else if(month == "Jul"){
        return 7;
    } else if(month == "Aug"){
        return 8;
    } else if(month == "Sep"){
        return 9;
    } else if(month == "Oct"){
        return 10;
    } else if(month == "Nov"){
        return 11;
    } else {
        return 12;
    }
}

