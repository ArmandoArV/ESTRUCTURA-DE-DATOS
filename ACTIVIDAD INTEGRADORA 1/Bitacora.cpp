#include "bitacora.h"
#include <string>
#include <vector>
using namespace std;

Bitacora::Bitacora(string IP, string reason){
    this->IP = IP;
    this->reason = reason;
}

Bitacora::~Bitacora(){

}
string Bitacora::getIP(){return this->IP;}
string Bitacora::getReason(){return this->reason;}
void Bitacora::setIP(string IP){this->IP = IP;}
void Bitacora::setReason(string reason){this->reason = reason;}