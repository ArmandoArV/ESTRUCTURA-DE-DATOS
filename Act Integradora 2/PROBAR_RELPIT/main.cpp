/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/


#include <iostream>
#include <fstream>
#include <string>
#include "binnacle.h"
#include "date.h"
#include "linkedListTwo.h"
#include "node.cpp"
//#include "Queue.cpp"
//#include "Stack.cpp"
#include "nodePtrTwo.h"
using namespace std;

linkedListTwo binnacleList;


int main(){
    int counter = 0;
    string sentences;
    ifstream file("bitacora.txt");
    if (file.is_open()){
        do {
            getline(file,sentences);
            Date date;
            string IP;
            string port = "";
            string action;
            int spaces = 0;
            string word = "";
            for (int i = 0; i < sentences.size(); i++){
                if (sentences[i] == ' '){
                    spaces++;
                    if (counter == 0){
                        date.setMonth(word);
                        counter++;
                    }
                    else if (counter ==  1){
                        date.setDay(stoi(word));
                        counter++;
                    }
                    else if( counter == 2){
                        date.setHour(stoi(word));
                        date.setMinute(stoi(word.substr(3,2)));
                        date.setSecond(stoi(word.substr(6,2)));
                        counter++;
                    }
                    else if (counter == 3){
                        IP = word;
                        counter++;
                    }
                    word = "";
                    if (spaces == 4){
                        action = sentences.substr(i+1);
                        counter = 0;
                        break;
                    }
                }
                else{
                    word += sentences[i];
                }
            }
            port = IP.substr(IP.find(":")+1);
            IP = IP.substr(0,IP.find(":"));
            Binnacle bitacora(date, IP, port, action);
            // here will insert the binnacle in the linked list
            binnacleList.appendInOrder(bitacora);
    
        } while (!file.fail());
    }else {
        cout << "Error, file not found." << "\n";
}
    cout << "\n=============================================================================================================================================\n";
    cout << "||                                                      Binnacle List                                                                        ||" << "\n";
    cout << "=============================================================================================================================================\n";
    File << "\n=============================================================================================================================================\n";
    File << "||                                                      Binnacle List                                                                        ||" << "\n";
    File << "=============================================================================================================================================\n";
    
    binnacleList.recorrer();
    binnacleList.searchByData("246.92.643.20", "545.2.257.56");
    binnacleList.eraseByData("880.42.424.6");
    binnacleList.recorrer();
    binnacleList.viewLast();
    binnacleList.viewFirst();

    return 0;
}
