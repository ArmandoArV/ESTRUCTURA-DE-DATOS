#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Fecha.cpp"
#include "Bitacora.cpp"
using namespace std;

vector<Bitacora> bitacoras;

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

    quicksort(bitacoras, 0, bitacoras.size()-1);
    int repeated = 0;
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
            if(bitacoras[i].getIP() == bitacoras[i+1].getIP() && bitacoras[i].getPuerto() == bitacoras[i+1].getPuerto()){
                cout << " Repeated." << "\n";
                repeated++;
                // remove the repeated IP
                bitacoras.erase(bitacoras.begin()+i);
            }
            else 
            {
                cout << " Non repeated." << "\n";
            }
        }
    }   
    cout << "-----------------------------------------" << "\n";
    cout << "Number of registries: " << bitacoras.size() << "\n";
    cout << "Repeated registries: " << repeated << "\n";
    cout << "-----------------------------------------" << "\n";


    return 0;
}