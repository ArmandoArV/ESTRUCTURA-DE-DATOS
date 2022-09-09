/*
    Made by: Armando Arredondo Valle
    Date: 08/09/2022
*/

#pragma once
#include <string>
#include <vector>
using namespace std;

class Fecha{
    private:
        string month;
        int day;
        int hour;
        int minute;
        int second;
    public:
        Fecha(string month, int day, int hour, int minute, int second);
        ~Fecha();
        string getMonth();
        int getDay();
        int getHour();
        int getMinute();
        int getSecond();
        void setMonth(string month);
        void setDay(int day);
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
};
