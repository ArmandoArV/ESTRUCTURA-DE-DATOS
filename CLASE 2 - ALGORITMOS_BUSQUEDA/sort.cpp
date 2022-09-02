#include <iostream>
#include <string>
#include <vector>
#include "Alumno.cpp"
#include <bits/stdc++.h>
using namespace std;
vector <Alumno> alumnos;

void quickSortName(vector <Alumno> &alumnos, int izq, int der) { //Funcion para ordenar por nombre
    int i = izq; //Variable para recorrer el vector
    int j = der; //Variable para recorrer el vector
    Alumno pivote = alumnos[(izq + der) / 2]; //Variable para guardar el pivote
    Alumno aux = alumnos[0]; //Variable auxiliar para hacer el intercambio
    while (i <= j) { //Mientras i sea menor o igual a j
        while (alumnos[i].getNombre() < pivote.getNombre()) { //Mientras el nombre del alumno en la posicion i sea menor al nombre del pivote
            i++; //Incremento i
        } //Fin del while
        while (alumnos[j].getNombre() > pivote.getNombre()) { //Mientras el nombre del alumno en la posicion j sea mayor al nombre del pivote
            j--; //Decremento j
        } //Fin del while
        if (i <= j) { //Si i es menor o igual a j
            aux = alumnos[i]; //Guardo el alumno en la posicion i en la variable auxiliar
            alumnos[i] = alumnos[j]; //Guardo el alumno en la posicion j en la posicion i
            alumnos[j] = aux; //Guardo el alumno en la variable auxiliar en la posicion j
            i++; //Incremento i
            j--; // Decremento j
        }
    }
    if (izq < j) { //Si la posicion izquierda es menor a j
        quickSortName(alumnos, izq, j); //Llamo a la funcion quickSortName con los parametros alumnos, izq y j
    }
    if (i < der) { //Si la posicion i es menor a la posicion derecha
        quickSortName(alumnos, i, der); //Llamo a la funcion quickSortName con los parametros alumnos, i y der
    } 
}

void bubbleSortName(vector <Alumno> &alumnos) { //Funcion para ordenar por nombre
    Alumno aux = alumnos[0]; //Variable auxiliar para hacer el intercambio
    for (int i = 0; i < alumnos.size(); i++) { //Recorro el vector
        for (int j = 0; j < alumnos.size() - 1; j++) { //Recorro el vector
            if (alumnos[j].getNombre() > alumnos[j + 1].getNombre()) { //Si el nombre del alumno en la posicion j es mayor al nombre del alumno en la posicion j + 1
                aux = alumnos[j]; //Guardo el alumno en la posicion j en la variable auxiliar
                alumnos[j] = alumnos[j + 1]; //Guardo el alumno en la posicion j + 1 en la posicion j
                alumnos[j + 1] = aux; //Guardo el alumno en la variable auxiliar en la posicion j + 1
            } //Fin del if
        } //Fin del for
    } //Fin del for
}

int main(){
    int dato;
    string option;
    alumnos.push_back(Alumno("Juan", "Perez", "Ingenieria", "1234", "a00000", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Aldo", "Cabrera", "Ingenieria", "1234", "a00001", "Mexico", "TIJ"));
    alumnos.push_back(Alumno("Pedro", "Gomez", "Ingenieria", "1234", "a00001", "Mexico", "SLP"));
    alumnos.push_back(Alumno("Maria", "Garcia", "Ingenieria", "1234", "a00002", "Mexico", "MOR"));
    alumnos.push_back(Alumno("Luis", "Hernandez", "Ingenieria", "1234", "a00003", "Mexico", "GUA"));
    alumnos.push_back(Alumno("Jose", "Martinez", "Ingenieria", "1234", "a00004", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Ana", "Lopez", "Ingenieria", "1234", "a00005", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Miguel", "Rodriguez", "Ingenieria", "1234", "a00006", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Carlos", "Diaz", "Ingenieria", "1234", "a00007", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Ricardo", "Perez", "Ingenieria", "1234", "a00008", "Mexico", "CDMX"));
    //cout << "QuickSort: " << "\n";
    //quickSortName(alumnos, 0, alumnos.size()-1);
    cout << "Bubble sort:" << "\n";
    cout << "----------------" << "\n";
    bubbleSortName(alumnos);
    for(int i = 0; i < alumnos.size(); i++){
        cout << alumnos[i].getNombre() << endl;
    }
    return 0;
}
