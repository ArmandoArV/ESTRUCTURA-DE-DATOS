//
// Created by Armando on 30/10/2022.
//

#ifndef INTEGRADORA3_BINNACLE_H
#define INTEGRADORA3_BINNACLE_H
#include <iostream>
#include <string>
using namespace std;
class Binnacle : public error_code {
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
    bool operator>(Binnacle);
    bool operator<(Binnacle);
    bool operator != (Binnacle);
    bool operator == (Binnacle);
    friend ostream& operator<<(ostream& os, const Binnacle& b);
};


#endif //INTEGRADORA3_BINNACLE_H
