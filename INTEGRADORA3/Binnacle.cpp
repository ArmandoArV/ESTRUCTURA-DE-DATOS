//
// Created by Armando on 30/10/2022.
//

#include "Binnacle.h"
#include <iostream>
#include <string>

Binnacle::Binnacle(){}

Binnacle::Binnacle(string IP, string port){
    this->IP = IP;
    this->port = port;
}

Binnacle::~Binnacle(){}

// Getters
string Binnacle::getIP(){return IP;}
string Binnacle::getPort(){return port;}

// Setters
void Binnacle::setIP(string IP){this->IP = IP;}
void Binnacle::setPort(string port){this->port = port;}

bool Binnacle::operator>(Binnacle b) {
    if (this->IP > b.getIP()){
        return true;
    } else if (this->IP == b.getIP()){
        if (this->port > b.getPort()){
            return true;
        }
    }
    return false;
}

bool Binnacle::operator!=(Binnacle b) {
    if(b.getIP() != IP || b.getPort() != port){
        return true;
    } else {
        return false;
    }
}

bool Binnacle::operator==(Binnacle b) {
    if(b.getIP() == IP && b.getPort() == port){
        return true;
    } else {
        return false;
    }
}

bool Binnacle::operator<(Binnacle b) {
    if (this->IP < b.getIP()){
        return true;
    } else if (this->IP == b.getIP()){
        if (this->port < b.getPort()){
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Binnacle& b) {
    os << b.IP << ":" << b.port;
    return os;
}