#include <iostream>
#include <string>
#include <vector>
#include "Alumno.cpp"
using namespace std;
vector <Alumno> alumnos;

// function for sorting by alphabetical order the vector
void sortVector(vector <Alumno> &alumnos){
    
}

int main(){
    int dato;
    string option;
    alumnos.push_back(Alumno("Juan", "Perez", "Ingenieria", "1234", "a00000", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Juan", "Cabrera", "Ingenieria", "1234", "a00001", "Mexico", "TIJ"));
    alumnos.push_back(Alumno("Pedro", "Gomez", "Ingenieria", "1234", "a00001", "Mexico", "SLP"));
    alumnos.push_back(Alumno("Maria", "Garcia", "Ingenieria", "1234", "a00002", "Mexico", "MOR"));
    cout << "--------------------------------" << "\n";
    cout << "-------Student information------" << "\n";
    cout << "--------------------------------" << "\n";
    cout << "[1] Search by name: " << "\n";
    cout << "[2] Search by last name: " << "\n";
    cout << "[3] Search by career: " << "\n";
    cout << "[4] Search by postal code: " << "\n";
    cout << "[5] Search by student ID: " << "\n";
    cout << "[6] Search by country: " << "\n";
    cout << "[7] Search by state: " << "\n";
    cout << "Input the search type: " << "\n";
    cin >> dato;
    // print the vector

}