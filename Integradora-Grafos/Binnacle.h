/*
 Created by Armando on 14/11/2022.
*/

#ifndef INTEGRADORA_GRAFOS_BINNACLE_H
#define INTEGRADORA_GRAFOS_BINNACLE_H
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

class Binnacle: public Date{
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
    bool operator<(Binnacle);
    bool operator>(Binnacle);
    bool operator>=(Binnacle);
    bool operator<=(Binnacle);
    friend ostream& operator<<(ostream& out, Binnacle&printOutput){
        out << printOutput.getMonth() << " " << printOutput.getDay() << " " << printOutput.getHour() << " " << printOutput.getIP() << " " << printOutput.getPort() << " " << printOutput.getReason() << "\n";
        return out;
    }

};


#endif //INTEGRADORA_GRAFOS_BINNACLE_H
