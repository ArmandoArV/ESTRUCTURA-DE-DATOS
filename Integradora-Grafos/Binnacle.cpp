/*
 Created by Armando on 14/11/2022.
*/

#include "Binnacle.h"
#include <iostream>
#include "Date.h"
#include <string>
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

bool Binnacle::operator<=(Binnacle b2) {  // Time Complexity O(1)
    if(getDate().getMonthInt() < b2.getDate().getMonthInt()) {
        return true;
    }
    if (getDate().getMonthInt() > b2.getDate().getMonthInt()){
        return false;
    }
    if (getDate().getMonthInt() == b2.getDate().getMonthInt()){
        if (getDate().getDay() < b2.getDate().getDay()) {
            return true;
        }
        if (getDate().getDay() > b2.getDate().getDay()){
            return false;
        }
        if (getDate().getDay() == b2.getDate().getDay()) {
            if (getDate().getHour() < b2.getDate().getHour()) {
                return true;
            }
            if (getDate().getHour() > b2.getDate().getHour()){
                return false;
            }
            if (getDate().getHour() == b2.getDate().getHour()){
                if (getDate().getMinute() < b2.getDate().getMinute()) {
                    return true;
                }
                if (getDate().getMinute() > b2.getDate().getMinute()){
                    return false;
                }
                if (getDate().getMinute() == b2.getDate().getMinute()){
                    if (getDate().getSecond() <= b2.getDate().getSecond()) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}
