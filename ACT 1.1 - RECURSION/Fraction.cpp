/*
    Made by:
        - Armando Arredondo Valle
        - Antonio Noguerón Bárcenas     

*/

#include "fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::~Fraction() {
//
}


int Fraction::getNumerator(){return numerator;}
int Fraction::getDenominator(){return denominator;}
void Fraction::setNumerator(int n){numerator = n;}
void Fraction::setDenominator(int d){denominator = d;}
// Reduce without iteration
void Fraction::reduce(int numerador, int denominador){
    for (int i = 2; i <= numerador; i++) {
        if(numerador%i==0 && denominador%i==0){
            numerador = numerador / i;
            denominador = denominador / i;
        }
    }
    cout << numerador << "/" << denominador << "\n";
}

void Fraction::recursive_reduce(int numerador, int denominador){
    if(numerador%denominador==0){
        cout << numerador << "/" << denominador << "\n";
    }
    else{
        recursive_reduce(denominador,numerador%denominador);
    }
}