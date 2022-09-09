#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Fecha.cpp"
#include "Bitacora.cpp"
using namespace std;
int main(){
    vector<Fecha> fechas;
    vector<Bitacora> bitacoras;
    // Read file bitacora.txt
    ifstream file("bitacora.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            string month = line.substr(0, line.find(" "));
            string day = line.substr(line.find(" ") + 1, line.find(" "));
            string hour = line.substr(line.find(" ") + 4, line.find(" "));
            string minute = line.substr(line.find(" ") + 7, line.find(" "));
            string second = line.substr(line.find(" ") + 10, line.find(" "));
            fechas.push_back(Fecha(month, stoi(day), stoi(hour), stoi(minute), stoi(second)));
            //string IP = line.substr(line.find(" ") + 1, line.find(" "));
            string IP = line.substr(line.find(" ") + 13, line.find(" ")+14); // YA FUNCIONA
            string reason = line.substr(line.find(" ") + 31, line.find(" ")+35); // YA FUNCIONA
            bitacoras.push_back(Bitacora(IP, reason));
        }
    }
    /* YA FUNCIONA NO TOCAR
    cout << "Fechas: " << endl;
    for(int i = 0; i < fechas.size(); i++){
        cout << fechas[i].getMonth() << " " << fechas[i].getDay() << " " << fechas[i].getHour() << "h " << fechas[i].getMinute() << "m "  << fechas[i].getSecond() << "s " << "\n";
    }
    */
    /* YA FUNCIONA NO TOCAR
    cout << "Bitacoras: " << endl;
    for (int i = 0; i < bitacoras.size(); i++){
        cout << "IP: " << bitacoras[i].getIP() << " Reason: " << bitacoras[i].getReason() << "\n";
    }
    */
   
    return 0;
}