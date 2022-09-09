/*
    Made by: Armando Arredondo Valle
    Date: 08/09/2022
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "fecha.h"
using namespace std;

class Bitacora{
    private:
        string IP;
        string reason;

    public:
        Bitacora(string IP, string reason);
        ~Bitacora();
        string getIP();
        string getReason();
        void setIP(string IP);
        void setReason(string reason);
};