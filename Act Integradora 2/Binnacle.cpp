/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/

#include <iostream>
#include <string>
#include "binnacle.h"
#include "linkedListTwo.h"
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
string Binnacle::getIP(){return IP;}
string Binnacle::getPort(){return port;}
string Binnacle::getReason(){return reason;}
Date Binnacle::getDate(){return date;}

// Setters
void Binnacle::setDate(Date date){this->date = date;}
void Binnacle::setIP(string IP){this->IP = IP;}
void Binnacle::setPort(string port){this->port = port;}
void Binnacle::setReason(string reason){this->reason = reason;}

bool Binnacle::operator<=(Binnacle data) {
    if(getDate().getMonth() > data.getDate().getMonth()) {
        return false;
    } else if (getDate().getDay() > data.getDate().getDay()) {
        return false;
    } else if (getDate().getHour() > data.getDate().getHour()) {
        return false;
    } else {
        return true;
    }
}

ostream& operator<<(ostream& os, linkedListTwo doubleList){ // Complejidad O👎
    os << "|| Contenido de la bitácora || \n" <<
          "================================== \n";
    if (doubleList.isEmpty()){
        return os;
    } else {
        NodePtrTwo* aux = doubleList.getHead();
        while (aux != nullptr){
            os << "Fecha: " << aux->getData().getDate().getMonth() << " " << aux->getData().getDate().getDay() << " " << aux->getData().getDate().getHour() << ":" << aux->getData().getDate().getMinute() << ":" << aux->getData().getDate().getSecond() << endl;
            os << "IP: " << aux->getData().getIP() << endl;
            os << "Puerto: " << aux->getData().getPort() << endl;
            os << "Razón: " << aux->getData().getReason() << endl;
            os << "================================== \n";
            aux = aux->getNext();
        }
        return os;
    }
}