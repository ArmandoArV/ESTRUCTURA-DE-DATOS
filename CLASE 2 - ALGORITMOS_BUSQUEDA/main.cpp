#include <iostream>
#include <string>
#include <vector>
#include "Alumno.cpp"
using namespace std;
vector <Alumno> alumnos;




int main(){
    int dato;
    string option;
    alumnos.push_back(Alumno("Juan", "Perez", "Ingenieria", "1234", "a00000", "Mexico", "CDMX"));
    alumnos.push_back(Alumno("Juan", "Cabrera", "Ingenieria", "1234", "a00001", "Mexico", "CDMX"));
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
    // Using linear search to find the student by name 
    switch (dato)
    {
        case 1:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same name
                cout << "Input the name of the student: ";
                cin >> option;
                if (alumnos[i].getNombre() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 2:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same last name
                cout << "Input the last name of the student: ";
                cin >> option;
                if (alumnos[i].getApellido() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 3:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same career
                cout << "Input the career of the student: ";
                cin >> option;
                if (alumnos[i].getCarrera() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 4:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same postal code
                cout << "Input the postal code of the student: ";
                cin >> option;
                if (alumnos[i].getCP() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 5:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same student ID
                cout << "Input the student ID of the student: ";
                cin >> option;
                if (alumnos[i].getMatricula() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 6: 
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same country
                cout << "Input the country of the student: ";
                cin >> option;
                if (alumnos[i].getPais() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        case 7:
            for (int i=0; i<alumnos.size(); i++){
                // sort if there are more than one student with the same state
                cout << "Input the state of the student: ";
                cin >> option;
                if (alumnos[i].getEstado() == option){
                    cout << "Student found: " << alumnos[i].getNombre() << " " << alumnos[i].getApellido() << "\n";
                }
            }
            break;
        default:
            cout << "Invalid option" << "\n";
            break;
    }
    return 0;
}

            
    