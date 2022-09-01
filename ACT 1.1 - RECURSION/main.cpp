/*
    Made by:
        - Armando Arredondo Valle
        - Antonio Noguerón Bárcenas     

*/
#include <iostream>
#include <string>
#include "Fraction.cpp"
using namespace std;

// iterative sum

Fraction fraction1;

void sumaIterativa(int n) {
    // here will calculate the sum from 1 to an n range number
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    cout << "The sum of 1 to " << n << " is: " << sum << "\n";
    
}

void sumaRecursiva(int n,int contador, int suma){
    if(contador<=n)
    {
        suma += contador;
        contador++;
        sumaRecursiva(n,contador,suma);
    }
    else
    {
        cout << "The sum of 1 to " << n << " is: " << suma << "\n";
    }
}

void sumaDirecta(int n,int suma){
    suma = n*(n+1)/2;
    cout << "The sum of 1 to " << n << " is: " << suma << "\n";
}   

void euclidesIterative(int n,int n2){ // minumum common divisor
    int resudus = 1;
    while(resudus > 0){
        resudus = n%n2;
        n = n2;
        n2 = resudus;
    }
    cout << "The minimum common divisor is " << n << "\n";
}

void euclidesRecursive(int n,int n2,int resudus){
    if(n2==0)
    {
        cout << "The minimum common divisor is " << n << "\n";
    }
    else
    {
        resudus = n%n2;
        n = n2;
        n2 = resudus;
        euclidesRecursive(n,n2,resudus);
    }
}

int main(){
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    // Sumas
    sumaIterativa(n); // Iterativa
    sumaRecursiva(n,1,0); // Recursiva
    sumaDirecta(n,1); // Directa
    // Euclides
    int n2;
    cout << "Ingrese un numero: ";
    cin >> n2;
    euclidesIterative(n,n2);
    euclidesRecursive(n,n2,1);
    fraction1 =  Fraction(n,n2);
    fraction1.reduce(n,n2);
    fraction1.recursive_reduce(n,n2);
    return 0;
}