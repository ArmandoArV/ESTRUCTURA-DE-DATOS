/*
 Created by Armando on 30/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_ORDER_H
#define INTEGRADORA_CARRITO_ORDER_H
#include "Product.h"
using namespace std;
#include <iostream>

struct Order {
    Product* product;
    int quantity;
    Order(Product*, int);
    Order();
    ~Order();
    // Getters
    Product* getProduct();
    int getQuantity();
    // Setters
    void setProduct(Product*);
    void setQuantity(int);
    // Methods
    double cost();
    void changeQuantity(int);
    // Overload
    void operator +=(int);
    bool operator ==(Order);
    bool operator !=(Order);
    bool operator <=(Order);
    bool operator >=(Order);
    friend ostream& operator <<(ostream& output, Order orderPrint){
        output << "\n-Order-\n\tProduct: " << orderPrint.getProduct()->getName() << "\n\tQuantity: " << orderPrint.getQuantity() << "\n\tCost: $" << orderPrint.cost() << endl;
        return output;
    }
};


#endif //INTEGRADORA_CARRITO_ORDER_H
