/*
 Created by Armando on 29/11/2022.
*/

#include "Product.h"
#include <cctype>
Product::Product() {
    name = "No name";
    price = 0;
}

Product::Product(string name_, float price_) {
    this->name = name_;
    this->price = price_;
}

Product::~Product() {}

bool Product::operator==(Product product) {
    string name1 = product.name;
    string compare1 = "";
    for (int i = 0; i<name1.size(); ++i) {
        compare1 += tolower(name1[i]);
    }

    string name2 = name;
    string compare2 = "";
    for (int i = 0; i<name2.size(); ++i) {
        compare2 += tolower(name2[i]);
    }
    return compare1 == compare2;
}

bool Product::operator!= (Product product){
    string name1 = product.name;
    string compare1 = "";
    for (int i = 0; i<name1.size(); ++i) {
        compare1 += tolower(name1[i]);
    }

    string name2 = name;
    string compare2 = "";
    for (int i = 0; i<name2.size(); ++i) {
        compare2 += tolower(name2[i]);
    }
    return compare1 != compare2;
}

bool Product::operator==(string name2) {
    string compare1 = "";
    for (int i = 0; i<name2.size(); ++i) {
        compare1 += tolower(name2[i]);
    }
    string compare2 = "";
    for (int i = 0; i<name.size(); ++i) {
        compare2 += tolower(name[i]);
    }
    return compare1 == compare2;
}

bool Product::operator!=(string name2) {
    string compare1 = "";
    for (int i = 0; i<name2.size(); ++i) {
        compare1 += tolower(name2[i]);
    }
    string compare2 = "";
    for (int i = 0; i<name.size(); ++i) {
        compare2 += tolower(name[i]);
    }
    return compare1 == compare2;
}