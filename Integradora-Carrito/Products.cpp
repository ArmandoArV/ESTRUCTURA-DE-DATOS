/*
 Created by Armando on 29/11/2022.
*/

#include "Products.h"
#include <bits/stdc++.h>

Products::Products() {}

Products::Products(string fileName) {
    ifstream file(fileName);
    string text;
    while (getline(file,text) && N > 0){
        Product* product = new Product(text.substr(0,text.find(" ")),stof(text.substr(text.find(" ")+1)));
        AvailableProducts.push_back(product);
    }
}

Products::~Products() {
    for (int i = 0; i < AvailableProducts.size(); ++i) {
        delete AvailableProducts[i];
    }
}

void Products::initializeProducts(string fileName) {
    AvailableProducts.clear();
    ifstream file(fileName);
    string text;
    while (getline(file,text) && N > 0){
        Product* product = new Product(text.substr(0,text.find(" ")),stof(text.substr(text.find(" ")+1)));
        AvailableProducts.push_back(product);
    }
}

int Products::size() {return AvailableProducts.size();}

int Products::findProduct(string name) {
    for (int i = 0; i < AvailableProducts.size(); ++i) {
        if (AvailableProducts[i]->getName() == name){
            return i;
        }
    }
    return -1;
}

Product* Products::operator[](int index) {
    if(index >= 0 && index < AvailableProducts.size()){
        return AvailableProducts[index];
    }else{
        cout << "Index out of range\n";
        return nullptr;
    }
}