/*
 Created by Armando on 31/10/2022.
*/

#include "AVL.h"
#include <iostream>
#include <vector>
using namespace std;

AVL::AVL() {
    this->raiz = nullptr;
    repeated = 0;
}

AVL::~AVL() {}

// Getters
NodoAVL* AVL::getRaiz() {return this->raiz;}
int AVL::getRepeated(void) {return this->repeated;}

// Setters
void AVL::setRaiz(NodoAVL*r) {this->raiz = r;}
void AVL::setRepeated(int r) {this->repeated = r;}

// Methods
void AVL::alturarraTodo(NodoAVL *aux)	{
    if(aux!= nullptr){
        alturarraTodo(aux->getIzq());
        alturarraTodo(aux->getDer());
        delete aux;
    }
}
NodoAVL* AVL::insertaAVL(NodoAVL*nodo, Binnacle dato, bool& altura){
    NodoAVL*nodo1, *nodo2;
    if(nodo == nullptr){
        nodo = new NodoAVL(dato);
        altura = true;
        return nodo; // nuevo nodo a insertar al encontrar un nulo
    }
    else if(dato < nodo->getDato()){// el dato que se inserta va a la izq
        nodo->setIzq(insertaAVL(nodo->getIzq(), dato, altura));
        if(altura){ // el arbol crecio
            switch (nodo->getFe()){
                case 1:	nodo->setFe(0);
                    altura = false;
                    break;
                case 0:	nodo->setFe(-1);
                    break;
                case -1:	nodo1=nodo->getIzq();
                    if(nodo1->getFe() <= -1){
                        nodo->setIzq(nodo1->getDer());
                        nodo1->setDer(nodo);
                        nodo->setFe(0);
                        nodo = nodo1;
                    }
                    else					{
                        nodo2 = nodo1->getDer();
                        nodo->setIzq(nodo2->getDer());
                        nodo2->setDer(nodo);
                        nodo1->setDer(nodo2->getIzq());
                        nodo2->setIzq(nodo1);
                        if(nodo2->getFe() == -1)
                            nodo->setFe(1);
                        else
                            nodo->setFe(0);
                        if(nodo2->getFe() == 1)
                            nodo1->setFe(-1);
                        else
                            nodo1->setFe(0);
                        nodo = nodo2;
                    }
                    nodo->setFe(0);
                    altura = false;
                    break;
            }
        }
    }
    else if(dato > nodo->getDato())	{
        nodo->setDer(insertaAVL(nodo->getDer(), dato, altura));
        if(altura){
            switch (nodo->getFe()){
                case -1:nodo->setFe(0); // -1 + 1 = 0
                    altura = false;
                    break;
                case 0:	nodo->setFe(1);
                    break;
                case 1:
                    nodo1 = nodo->getDer();
                    if(nodo1->getFe() >= 0){
                        nodo->setDer(nodo1->getIzq());
                        nodo1->setIzq(nodo);
                        nodo->setFe(0);
                        nodo = nodo1;
                    }
                    else{
                        nodo2 = nodo1->getIzq();
                        nodo->setDer(nodo2->getIzq());
                        nodo2->setIzq(nodo);
                        nodo1->setIzq(nodo2->getDer());
                        nodo2->setDer(nodo1);
                        if(nodo2->getFe() == 1)
                            nodo->setFe(-1);
                        else
                            nodo->setFe(0);
                        if(nodo2->getFe() == -1)
                            nodo1->setFe(1);
                        else
                            nodo1->setFe(0);
                        nodo=nodo2;
                    }
                    nodo->setFe(0);
                    altura = false;
                    break;
            }
        }
    }
    else{
        repeated++;
        cout << "======================\n";
        cout << "AVL | Repeated node: " << dato << " times: " << repeated << endl;
        cout << "======================\n";
        cout << " \n";
        altura = false;
    }
    return nodo;
}


void AVL::preorden(NodoAVL*aux)
{
    if(aux!= nullptr){
        Binnacle i = aux->getDato();
        cout << i << endl;
        preorden(aux->getIzq());
        preorden(aux->getDer());
    }
}


void AVL::inorden(NodoAVL*aux){
    if(aux!= nullptr){
        Binnacle i = aux->getDato();
        inorden(aux->getIzq());
        cout << i << endl;
        inorden(aux->getDer());
    }
}

