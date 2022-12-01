/*
 Created by Armando on 29/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_PRODUCT_H
#define INTEGRADORA_CARRITO_PRODUCT_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef float price_t;

struct Product {
private:
    string name;
    price_t price;
public:
    Product();
    Product(string name, price_t price);
    ~Product();
    bool operator== (Product);
    bool operator!= (Product);
    bool operator== (string);
    bool operator!= (string);
    friend ostream& operator<< (ostream& output, Product product2){
        output << "\n-Product-\n\tName: "<< product2.name << "\n\tPrice: $" << product2.price << endl;
        return output;
    }
};


#endif //INTEGRADORA_CARRITO_PRODUCT_H
