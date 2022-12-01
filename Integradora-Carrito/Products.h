/*
 Created by Armando on 29/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_PRODUCTS_H
#define INTEGRADORA_CARRITO_PRODUCTS_H
#include "Product.h"
#include <iostream>
#include <vector>

class Products {
    private:
        vector <Product*> AvailableProducts;
        int N = 20;
    public:
    Products();
    Products(string);
    ~Products();
    void initializeProducts(string);
    int size();
    int findProduct(string);
    Product* operator[] (int);
};


#endif //INTEGRADORA_CARRITO_PRODUCTS_H
