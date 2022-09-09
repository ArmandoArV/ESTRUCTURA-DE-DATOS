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
Fecha fecha;

ofstream File("Casos_De_Prueba.txt");

void smarter_search(vector<Bitacora> &bitacoras, Fecha patron){
    int a = bitacoras.size();
    bool repetida = false;
    for(int i(0); i < a; i++){
        for(int j = 0; j < a; j++){
            if(bitacoras[i].getMonth() == bitacoras[i].getMonth() && bitacoras[i].getDay() == bitacoras[i].getDay() && bitacoras[i].getHour() == bitacoras[i].getHour() && bitacoras[i].getMinute() == bitacoras[i].getMinute()){
                cout << "-----------------------------------------" << "\n";
                cout << "Number: " << i << "\n";
                cout << "IP: " << bitacoras[i].getIP() << "\n";
                cout << "Reason: " << bitacoras[i].getReason() << "\n";
                cout << "Port: " << bitacoras[i].getPuerto() << "\n";
                cout << "Month: " << bitacoras[i].getMonth() << "\n";
                cout << "Day: " << bitacoras[i].getDay() << "\n";
                cout << "Hour: " << bitacoras[i].getHour() << "\n";
                cout << "Minutes: " << bitacoras[i].getMinute() << "\n";
                cout << "Seconds: " << bitacoras2[i].getSecond() << "\n";
                // Sobreescribir el archivo
                File << "-----------------------------------------" << "\n";
                File << "Number: " << i << "\n";
                File << "IP: " << bitacoras[i].getIP() << "\n";
                File << "Reason: " << bitacoras[i].getReason() << "\n";
                File << "Port: " << bitacoras[i].getPuerto() << "\n";
                File << "Month: " << bitacoras[i].getMonth() << "\n";
                File << "Day: " << bitacoras[i].getDay() << "\n";
                File << "Hour: " << bitacoras[i].getHour() << "\n";
                File << "Minutes: " << bitacoras[i].getMinute() << "\n";
                File << "Seconds: " << bitacoras2[i].getSecond() << "\n";
                repetida = true;
                break;
            }
        }
        if(!repetida){
            cout << "Not found" << "\n";
        }
    }

}

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
} // N log N

int main(){
    // Read file bitacora.txt
    //ifstream file("bitacora.txt");
    ifstream file("bitacora.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){ // Complexity: O(N)
            string month = line.substr(0, line.find(" "));
            string day = line.substr(line.find(" ") + 1, line.find(" "));
            if (day.find(" ") != string::npos){
                // remove space before day
                day = day.substr(0,day.find(" ") + 1);
            }
            
            string hour = line.substr(line.find(" ") + 3, line.find(" "));
            if(hour.find(":") != string::npos){
                // remove : after hour
                hour = hour.substr(0,hour.find(":"));
            }
            string minute = line.substr(line.find(" ") + 6, line.find(" "));

            string second = line.substr(line.find(" ") + 9, line.find(" "));
            if(second.find(":") != string::npos){
                // remove : before second
                second = second.substr(second.find(":") + 1);
            }
            //string IP = line.substr(line.find(" ") + 13, line.find(":")+4);
            string IP = line.substr(line.find(" ")+13);
            if(IP.find(":") != string::npos){ // Complexity: O(1)
                IP = IP.substr(0, IP.find(":"));
            }
            string reason = line.substr(line.find(" ") + 30, line.find(" ")+35);
            string puerto = line.substr(line.find(":") + 20);

            if(puerto.find(" ") != string::npos){ // Complexity: O(1)
                puerto = puerto.substr(0, puerto.find(" "));
            }
            if(puerto.find(":") == string::npos){ // Complexity: O(1)
                puerto = ":" + puerto;
            }
            string date = month + " "  + day + " " + hour + " : " +  minute + " : "  +second;
            Bitacora bitacora(IP, reason, puerto, Fecha(month, day, hour, minute, second));
            bitacoras.push_back(bitacora);
        }
    }
    for(int i = 0; i < bitacoras.size(); i++){
        cout << i << "Month" << bitacoras[i].getMonth() << " " << bitacoras[i].getDay() << "Hour" << bitacoras[i].getHour() << " " << bitacoras[i].getMinute() << " " << bitacoras[i].getSecond() << " " << bitacoras[i].getIP() << " " << bitacoras[i].getReason() << " " << bitacoras[i].getPuerto() << "\n";
        File << i << "Month" << bitacoras[i].getMonth() << " " << bitacoras[i].getDay() << "Hour" << bitacoras[i].getHour() << " " << bitacoras[i].getMinute() << " " << bitacoras[i].getSecond() << ""  << bitacoras[i].getIP() << " " << bitacoras[i].getReason() << " " << bitacoras[i].getPuerto() << "\n";
    }
    const int total = bitacoras.size(); // Complexity: O(N)

    cout << "-----------------------------------------" << "\n";
    cout << "QUIK SORT" << "\n";
    cout << "-----------------------------------------" << "\n";
    File << "-----------------------------------------" << "\n";
    File << "QUIK SORT" << "\n";
    File << "-----------------------------------------" << "\n";

    quicksort(bitacoras, 0, bitacoras.size()-1); // Complexity:O(N)
    for(int i = 0; i < bitacoras.size(); i++){ // Complexity: O(N)
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
        File << "-----------------------------------------" << "\n";
        File << " Number: " << i << "\n";
        File << " IP: " << bitacoras[i].getIP() <<
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
        if ((i+1) < bitacoras.size()){ // Complexity: O(N)
            if(bitacoras[i].getIP() == bitacoras[i+1].getIP() && bitacoras[i].getPuerto() == bitacoras[i+1].getPuerto() && bitacoras[i].getReason() == bitacoras[i+1].getReason()){
                // complexiry: O(N)
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
    File << "-----------------------------------------" << "\n";
    File << "Number of registries: " << total << "\n";
    File << "Repeated registries: " << total_repeated << "\n";
    File << "-----------------------------------------" << "\n";
    File << "New number of registries: " << bitacoras2.size() << "\n";
    File << "-----------------------------------------" << "\n";
    File << "Ordered repeated registries: " "\n";
    int c2 = 1;
    for(int i = 0; i < repetidas.size(); i++){
        // remove duplicated registries
        if ((i+1) < bitacoras.size()){ // Complexity: O(N)
            if(repetidas[i].getIP() == repetidas[i+1].getIP() && repetidas[i].getPuerto() == repetidas[i+1].getPuerto() && repetidas[i].getReason() == repetidas[i+1].getReason()){
            // leave only leave the first repeated registries
                repetidas.erase(repetidas.begin() + i);
            }
            if (repetidas[i].getIP() != repetidas[i+1].getIP() || repetidas[i].getPuerto() != repetidas[i+1].getPuerto() || repetidas[i].getReason() != repetidas[i+1].getReason()){
                c2++;
            }

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
        File << "-----------------------------------------" << "\n";
        File << " Number: " << i << "\n";
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
        " Seconds: " << repetidas[i].getSecond();
    }
    cout << "-----------------------------------------" << "\n";
    cout << "Searcg information by date: "<< "\n";
    cout << "-----------------------------------------" << "\n";
    cout << "\n";
    File << "-----------------------------------------" << "\n";
    File << "Searcg information by date: "<< "\n";
    File << "-----------------------------------------" << "\n";
    File << "\n";
    string month;
    string day;
    string hour;
    string minute;
    string second;
    cout << "Enter the month: ";
    File << "Enter the month: ";
    cin >> month;
    File << month;
    cout << "Enter the day: ";
    File << "Enter the day: ";
    cin >> day;
    File << day;
    cout << "Enter the hour: ";
    File << "Enter the hour: ";
    cin >> hour;
    File << hour;
    cout << "Enter the minute: ";
    File << "Enter the minute: ";
    cin >> minute;
    File << minute;
    cout << "Enter the second: ";
    File << "Enter the second: ";
    cin >> second;
    File << second;
    Fecha dato(month,day,hour,minute,second);
    smarter_search(bitacoras,dato);
    
    return 0;
}
