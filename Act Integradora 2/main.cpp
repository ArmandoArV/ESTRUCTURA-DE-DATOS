/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/


#include <iostream>
#include <fstream>
#include <string>
#include "Binnacle.cpp"
#include "Date.cpp"
#include "LinkedListTwo.cpp"
#include "Node.cpp"
//#include "Queue.cpp"
//#include "Stack.cpp"
#include "NodePtrTwo.cpp"
using namespace std;

linkedListTwo binnacleList;


int main(){
    int counter = 0;
    string sentences;
    ifstream file("bita.txt");
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
    cout << "The binnacle has been loaded." << "\n";
    binnacleList.printThrough();
}