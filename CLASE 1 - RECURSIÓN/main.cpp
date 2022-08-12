/*
    Armando Arredondo Valle
*/
#include <iostream>
#include <string>
using namespace std;

int recursiva(int arreglo[], int indice){
        if(indice<7){
            cout << arreglo[indice]<<"\n";
            indice ++;
            recursiva(arreglo,indice);
        }
    }




int main ()
{
    int nLimit = 6;
    int arreglo[nLimit];
    int indice = 0;
    for(int i =0; i < nLimit; i++){
        arreglo[i] = i+1;
    }
    recursiva(arreglo,indice);
    //sumElements(arreglo,nLimit);
}

