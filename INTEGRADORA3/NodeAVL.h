/*
 Created by Armando on 31/10/2022.
*/

#ifndef INTEGRADORA3_NODEAVL_H
#define INTEGRADORA3_NODEAVL_H
#include <iostream>
#include "Binnacle.h"
using namespace std;

class NodoAVL{
    Binnacle dato;
    NodoAVL *izq, *der;
    int fe;
public:
    NodoAVL(Binnacle dato);
    ~NodoAVL();
    // Getters
    NodoAVL*getIzq();
    NodoAVL*getDer();
    Binnacle getDato();
    int getFe();
    // Setters
    void setIzq(NodoAVL*);
    void setDer(NodoAVL*);
    void setFe(int);
    void setDato(Binnacle);
};

#endif //INTEGRADORA3_NODEAVL_H
