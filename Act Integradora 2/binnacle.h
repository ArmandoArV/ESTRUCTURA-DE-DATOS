/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#pragma once
#include <iostream>
#include "date.h"
#include <string>
using namespace std;

class Binnacle{
    private:
        Date date;
        string IP, port, reason;
        char repeatedChar;
        int numRepeated;
    public:
        Binnacle();
        Binnacle(Date, string, string, string);
        ~Binnacle();
        // Getters
        Date getDate();
        string getIP();
        string getPort();
        string getReason();
        // Setters
        void setDate(Date date);
        void setIP(string IP);
        void setPort(string port);
        void setReason(string reason);
        void printBinnacle();
        bool operator<=(Binnacle);

        friend ostream& operator<=(ostream& os, const Binnacle& binnacle);
        friend ostream& operator<<(ostream& os, const Binnacle& binnacle);
};