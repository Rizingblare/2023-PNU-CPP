#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item {
public:
    Item(std::string name, int quantity, int price)
            : name(name), quantity(quantity), price(price) {
        static int IdCounter=0;
        id = IdCounter++;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    int getPrice() const { return price; }

private:
    int id;
    std::string name;
    int quantity;
    int price;
};

#endif