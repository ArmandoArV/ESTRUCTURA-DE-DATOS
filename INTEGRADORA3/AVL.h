/*
 Created by Armando on 31/10/2022.
*/

#ifndef INTEGRADORA3_AVL_H
#define INTEGRADORA3_AVL_H
#include "NodeAVL.h"

class AVL{
    NodoAVL* raiz;
    int repeated;
public:
    AVL();
    ~AVL();

    //GETTERS
    NodoAVL*getRaiz();
    int getRepeated(void);


    //SETTERS
    void setRaiz(NodoAVL*r);
    void setRepeated(int);

    //METHODS
    NodoAVL* insertaAVL(NodoAVL*,Binnacle, bool&);
    void inorden(NodoAVL*);
    void preorden(NodoAVL*);
    void posorden(NodoAVL*);
    void alturarraTodo(NodoAVL *);
};


#endif //INTEGRADORA3_AVL_H
