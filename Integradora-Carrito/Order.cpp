/*
 Created by Armando on 30/11/2022.
*/

#include "Order.h"
#include <iostream>
using namespace std;
Order::Order(){
    product = nullptr;
    quantity = 0;
}

Order::Order(Product* product, int quantity){
    this->product = product;
    this->quantity = quantity;
}

Order::~Order() {delete product;}

// Getters
Product* Order::getProduct() {return product;}

int Order::getQuantity() {return quantity;}

// Setters
void Order::setProduct(Product* product) {this->product = product;}

void Order::setQuantity(int quantity) {this->quantity = quantity;}

// Methods
double Order::cost() {return product->getPrice()*quantity;}

void Order::changeQuantity(int i) {this->quantity += i;}

bool Order::operator==(Order order) {return product->getName() == order.getProduct()->getName();}
bool Order::operator!=(Order order) {return product->getName() != order.getProduct()->getName();}
bool Order::operator<=(Order order) {return product->getName() <= order.getProduct()->getName();}
bool Order::operator>=(Order order) {return product->getName() >= order.getProduct()->getName();}
void Order::operator+=(int i) {this->quantity += i;}

