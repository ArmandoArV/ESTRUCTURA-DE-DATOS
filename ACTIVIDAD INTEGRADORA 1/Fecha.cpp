#include "fecha.h"
#include <string>
#include <vector>
using namespace std;
Fecha::Fecha(string month, string day, string hour, string minute, string second){
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Fecha::Fecha(){}

Fecha::~Fecha(){

}

void Fecha::setDay(string day){this->day = day;}
void Fecha::setHour(string hour){this->hour = hour;}
void Fecha::setMinute(string minute){this->minute = minute;}
void Fecha::setSecond(string second){this->second = second;}
void Fecha::setMonth(string month){this->month = month;}
string Fecha::getDay(){return this->day;}
string Fecha::getHour(){return this->hour;}
string Fecha::getMinute(){return this->minute;}
string Fecha::getSecond(){return this->second;}
string Fecha::getMonth(){return this->month;}
