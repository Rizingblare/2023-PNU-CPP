#include <iostream>
#include <vector>
#include <algorithm>

#include "Cart.h"

void Cart::addItem(const Item& item) {
    this->items.push_back(item);
}

void Cart::deleteItem(int id) {
    this->items.erase(this->cbegin()+id);
}

int Cart::checkout() {
    int totalPrice = 0;

    for (auto i : this->items)
        totalPrice += i.getPrice() * i.getQuantity();

    return totalPrice;
}

void Cart::viewItemDetails(int id, std::ostream& out) const {
    auto target = std::find_if(this->cbegin(), this->cend(), [id](const Item a){return a.getId() == id;});

    if ( target != this->cend() ) {
        out << "Item "<< id <<": " << std::endl;
        out << "Name: " << target->getName() << std::endl;
        out << "Quantity: " << target->getQuantity() << std::endl;
        out << "Price: " << target->getPrice() << std::endl;
    }

    else out << "Item not found." << std::endl;
}

const_iterator Cart::cbegin() const { return this->items.begin(); }
const_iterator Cart::cend() const { return this->items.end(); }