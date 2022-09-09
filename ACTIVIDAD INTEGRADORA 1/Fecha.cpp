#include "fecha.h"
#include <string>
#include <vector>
using namespace std;
Fecha::Fecha(string month, int day, int hour, int minute, int second){
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Fecha::~Fecha(){

}

void Fecha::setDay(int day){this->day = day;}
void Fecha::setHour(int hour){this->hour = hour;}
void Fecha::setMinute(int minute){this->minute = minute;}
void Fecha::setSecond(int second){this->second = second;}
void Fecha::setMonth(string month){this->month = month;}
int Fecha::getDay(){return this->day;}
int Fecha::getHour(){return this->hour;}
int Fecha::getMinute(){return this->minute;}
int Fecha::getSecond(){return this->second;}
string Fecha::getMonth(){return this->month;}
