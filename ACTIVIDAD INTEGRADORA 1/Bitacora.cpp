#include "bitacora.h"
#include  "fecha.h"
#include <string>
#include <vector>

using namespace std;

Bitacora::Bitacora(string IP, string reason, string puerto,Fecha fecha):Fecha(fecha){
    this->IP = IP;
    this->reason = reason;
    this->puerto = puerto;
    this->fecha = fecha;
}
Bitacora::Bitacora(){}
Bitacora::~Bitacora(){}
string Bitacora::getIP(){return this->IP;}
string Bitacora::getReason(){return this->reason;}
string Bitacora::getPuerto(){return this->puerto;}
void Bitacora::setIP(string IP){this->IP = IP;}
void Bitacora::setReason(string reason){this->reason = reason;}
void Bitacora::setPuerto(string puerto){this->puerto = puerto;}
