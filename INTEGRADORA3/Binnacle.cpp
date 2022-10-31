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
