/*
 Created by Armando on 29/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_PRODUCT_H
#define INTEGRADORA_CARRITO_PRODUCT_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Product {
private:
    string name;
    float priceProduct;
public:
    Product();
    Product(string name, float priceProduct);
    ~Product();
    string getName();
    float getPrice();
    void setName(string);
    void setPriceProduct(float);
    bool operator== (Product);
    bool operator!= (Product);
    bool operator== (string);
    bool operator!= (string);
    friend ostream& operator<< (ostream& output, Product productPrint){
        output << "\n-Product-\n\tName: "<< productPrint.getName() << "\n\tPrice: $" << productPrint.getPrice() << endl;
        return output;
    }
};


#endif //INTEGRADORA_CARRITO_PRODUCT_H
