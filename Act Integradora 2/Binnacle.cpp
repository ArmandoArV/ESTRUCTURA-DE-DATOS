/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#include <iostream>
#include <string>
#include "binnacle.h"
#include "date.h"
using namespace std;

Binnacle::Binnacle(){}

Binnacle::Binnacle(Date date, string IP, string port, string reason){
    this->date = date;
    this->IP = IP;
    this->port = port;
    this->reason = reason;
    this->repeatedChar = repeatedChar;
    this->numRepeated = numRepeated;
}

Binnacle::~Binnacle(){}

// Getters
Date Binnacle::getDate(){return date;}
string Binnacle::getIP(){return IP;}
string Binnacle::getPort(){return port;}
string Binnacle::getReason(){return reason;}

// Setters
void Binnacle::setDate(Date date){this->date = date;}
void Binnacle::setIP(string IP){this->IP = IP;}
void Binnacle::setPort(string port){this->port = port;}
void Binnacle::setReason(string reason){this->reason = reason;}

// Methods
void Binnacle::printBinnacle(){
    cout << date.printDate() << " " << IP << " " << port << " " << reason << endl;
}
