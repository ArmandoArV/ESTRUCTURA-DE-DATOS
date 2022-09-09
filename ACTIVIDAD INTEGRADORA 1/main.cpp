#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "Fecha.cpp"
#include "Bitacora.cpp"
using namespace std;

vector<Bitacora> bitacoras;
vector<Bitacora> bitacoras2;
vector<Bitacora> repetidas;



void quicksort(vector<Bitacora> &bitacoras, int left, int right){
    int i = left, j = right;
    Bitacora tmp;
    Bitacora pivot = bitacoras[(left + right) / 2];
    while (i <= j) {
        while (bitacoras[i].getIP() < pivot.getIP()) {
            i++;
        }
        while (bitacoras[j].getIP() > pivot.getIP()) {
            j--;
        }
        if (i <= j) {
            tmp = bitacoras[i];
            bitacoras[i] = bitacoras[j];
            bitacoras[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(bitacoras, left, j);
    if (i < right)
        quicksort(bitacoras, i, right);
}



int main(){
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
            //string IP = line.substr(line.find(" ") + 13, line.find(":")+4);
            string IP = line.substr(line.find(" ")+13);
            if(IP.find(":") != string::npos){
                IP = IP.substr(0, IP.find(":"));
            }
            string reason = line.substr(line.find(" ") + 31, line.find(" ")+35);
            string puerto = line.substr(line.find(":") + 20);
            if(puerto.find(" ") != string::npos){
                puerto = puerto.substr(0, puerto.find(" "));
            }
            if(puerto.find(":") == string::npos){
                puerto = ":" + puerto;
            }
            Bitacora bitacora(IP, reason, puerto, Fecha(month, day, hour, minute, second));
            bitacoras.push_back(bitacora);
        }
    }
    const int total = bitacoras.size();
    quicksort(bitacoras, 0, bitacoras.size()-1);
    for(int i = 0; i < bitacoras.size(); i++){
        cout << "-----------------------------------------" << "\n";
        cout << " Number: " << i << "\n";
        cout << " IP: " << bitacoras[i].getIP() <<
        "\n" << 
        " Reason: " << bitacoras[i].getReason() <<
        "\n" <<  
        " Port: " << bitacoras[i].getPuerto() <<
        "\n" << 
        " Month: " << bitacoras[i].getMonth() <<
        "\n" <<
        " Day: " << bitacoras[i].getDay() <<
        "\n" <<
        " Hour: " << bitacoras[i].getHour() << 
        "\n" <<
        " Minutes: " << bitacoras[i].getMinute() << 
        "\n" <<
        " Seconds: " << bitacoras[i].getSecond() << 
        "\n";
        // verify if the IP is repeated
        if ((i+1) < bitacoras.size()){
            if(bitacoras[i].getIP() == bitacoras[i+1].getIP() && bitacoras[i].getPuerto() == bitacoras[i+1].getPuerto() && bitacoras[i].getReason() == bitacoras[i+1].getReason()){
                cout << " Repeated." << "\n";
                // remove the repeated IP
                repetidas.push_back(bitacoras[i-1]);
            }
            else 
            {
                cout << " Non repeated." << "\n";
                // push the non repeated IP to the vector bitacoras2
                bitacoras2.push_back(bitacoras[i]);
            }
        }
    }
    const int total_repeated = repetidas.size();   
    cout << "-----------------------------------------" << "\n";
    cout << "Number of registries: " << total << "\n";
    cout << "Repeated registries: " << total_repeated << "\n";
    cout << "-----------------------------------------" << "\n";
    cout << "New number of registries: " << bitacoras2.size() << "\n";
    cout << "-----------------------------------------" << "\n";
    cout << "Ordered repeated registries: " "\n";
    for(int i = 0; i < repetidas.size(); i++){
        // remove duplicated registries
        if(repetidas[i].getIP() == repetidas[i+1].getIP() && repetidas[i].getPuerto() == repetidas[i+1].getPuerto() && repetidas[i].getReason() == repetidas[i+1].getReason()){
            // leave only leave the first repeated registries
            repetidas.erase(repetidas.begin() + i);
        }
        cout << "-----------------------------------------" << "\n";
        cout << " Number: " << i << "\n";
        cout << " IP: " << repetidas[i].getIP() <<
        "\n" << 
        " Reason: " << repetidas[i].getReason() <<
        "\n" <<  
        " Port: " << repetidas[i].getPuerto() <<
        "\n" << 
        " Month: " << repetidas[i].getMonth() <<
        "\n" <<
        " Day: " << repetidas[i].getDay() <<
        "\n" <<
        " Hour: " << repetidas[i].getHour() << 
        "\n" <<
        " Minutes: " << repetidas[i].getMinute() << 
        "\n" <<
        " Seconds: " << repetidas[i].getSecond() << 
        "\n";
    }
    cout << "-----------------------------------------" << "\n";
    


    return 0;
}