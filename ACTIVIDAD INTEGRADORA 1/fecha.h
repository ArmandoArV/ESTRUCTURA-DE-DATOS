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
        string day;
        string hour;
        string minute;
        string second;
    public:
        Fecha(string month, string day, string hour, string minute, string second);
        Fecha();
        ~Fecha();
        string getMonth();
        string getDay();
        string getHour();
        string getMinute();
        string getSecond();
        void setMonth(string month);
        void setDay(string day);
        void setHour(string hour);
        void setMinute(string minute);
        void setSecond(string second);
};
