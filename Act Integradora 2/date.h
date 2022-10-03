/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#pragma once
using namespace std;
#include <iostream>

class Date{
    private:
        string month, day, hour;
    public:
        Date();
        Date(string month, string day, string hour);
        ~Date();
        string getMonth();
        string getDay();
        string getHour();
        string printDate();
        void setMonth(string month);
        void setDay(string day);
        void setHour(string hour);
};