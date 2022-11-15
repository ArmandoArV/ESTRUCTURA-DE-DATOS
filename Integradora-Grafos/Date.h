/*
 Created by Armando on 14/11/2022.
*/

#ifndef INTEGRADORA_GRAFOS_DATE_H
#define INTEGRADORA_GRAFOS_DATE_H

#include <string>
#include <iostream>
using namespace std;

class Date {
private:
    string month;
    int day, hour, minute, second, monthInt;
public:
    Date();
    Date(string month, int day, int hour, int minute, int second,int monthInt);
    ~Date();
    string getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();
    int monthToString(string);
    int getMonthInt();
    string printDate();
    void setMonth(string month);
    void setDay(int day);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void setMonthInt(int monthInt);

};


#endif //INTEGRADORA_GRAFOS_DATE_H
