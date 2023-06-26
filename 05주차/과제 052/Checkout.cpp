#include <iostream>
#include <vector>

#include "Checkout.h"
#include "Item.h"

int calculateTotalPrice(std::vector<Item>::const_iterator begin,
                        std::vector<Item>::const_iterator end) {
    return 0;
}

void setShippingAddress(const std::string &shippingAddress){
    return;
}
void setDiscountCode(DiscountCode discountCode){
    if (discountCode == DISCOUNT_20) return;
    if (discountCode == DISCOUNT_50) return;
}