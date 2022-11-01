/*
 Created by Armando on 31/10/2022.
*/
#include "Binnacle.h"
#include "NodeAVL.h"
#include <iostream>

using namespace std;

NodoAVL::NodoAVL(Binnacle dato){
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
    this->fe = 0;
}

NodoAVL::~NodoAVL() {}

// Getters
NodoAVL* NodoAVL::getIzq() {return this->izq;}
NodoAVL* NodoAVL::getDer() {return this->der;}
Binnacle NodoAVL::getDato() {return this->dato;}
int NodoAVL::getFe() {return this->fe;}

// Setters
void NodoAVL::setIzq(NodoAVL*izq) {this->izq = izq;}
void NodoAVL::setDer(NodoAVL*der) {this->der = der;}
void NodoAVL::setFe(int fe) {this->fe = fe;}
void NodoAVL::setDato(Binnacle dato) {this->dato = dato;}

