/*
 Created by Armando on 29/11/2022.
*/

#include "Product.h"
Product::Product() {
    name = "No name";
    priceProduct = 0;
}

Product::Product(string name, float priceProduct) {
    this->name = name;
    this->priceProduct = priceProduct;
}

Product::~Product() {}

string Product::getName() {return name;}

float Product::getPrice() {return priceProduct;}

void Product::setName(string name) {this->name = name;}

void Product::setPriceProduct(float priceProduct) {this->priceProduct = priceProduct;}

bool Product::operator==(Product product) {
    string nameCompare = name;
    string namePCompare = product.getName();
    transform(nameCompare.begin(), nameCompare.end(),nameCompare.begin(), ::toupper);
    transform(namePCompare.begin(), namePCompare.end(),namePCompare.begin(), ::toupper);
    return nameCompare == namePCompare;
}

bool Product::operator!= (Product product){
    string nameCompare = name;
    string namePCompare = product.getName();
    transform(nameCompare.begin(), nameCompare.end(),nameCompare.begin(), ::toupper);
    transform(namePCompare.begin(), namePCompare.end(),namePCompare.begin(), ::toupper);
    return nameCompare != namePCompare;
}

bool Product::operator==(string name) {
    string nameCompare = this->name;
    transform(nameCompare.begin(), nameCompare.end(),nameCompare.begin(), ::toupper);
    transform(name.begin(), name.end(),name.begin(), ::toupper);
    return nameCompare == name;
}

bool Product::operator!=(string name) {
    string nameCompare = this->name;
    transform(nameCompare.begin(), nameCompare.end(),nameCompare.begin(), ::toupper);
    transform(name.begin(), name.end(),name.begin(), ::toupper);
    return nameCompare != name;
}