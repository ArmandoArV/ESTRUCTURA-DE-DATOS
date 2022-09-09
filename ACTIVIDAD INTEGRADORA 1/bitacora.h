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

class Bitacora: public Fecha{
    private:
        string IP;
        string reason;
        string puerto;
        Fecha fecha;
        
    public:
        Bitacora(string IP, string reason, string puerto,Fecha fecha);
        Bitacora();
        ~Bitacora();
        string getIP();
        string getReason();
        string getPuerto();
        void setIP(string IP);
        void setReason(string reason);
        void setPuerto(string puerto);
        void quickSort(vector<Bitacora> &bitacora, int, int);
};