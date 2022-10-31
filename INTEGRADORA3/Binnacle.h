//
// Created by Armando on 30/10/2022.
//

#ifndef INTEGRADORA3_BINNACLE_H
#define INTEGRADORA3_BINNACLE_H
#include <iostream>
#include <string>
using namespace std;
class Binnacle {
private:
    string IP,port;
public:
    Binnacle();
    Binnacle(string IP, string port);
    ~Binnacle();
    // Getters
    string getIP();
    string getPort();
    // Setters
    void setIP(string IP);
    void setPort(string port);
    void printBinnacle();
    friend ostream& operator<<(ostream& out, Binnacle&printOutput){
        out << printOutput.getIP() << " " << printOutput.getPort() << "\n";
        return out;
    }
};


#endif //INTEGRADORA3_BINNACLE_H
