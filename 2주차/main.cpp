#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    int price;
};

void addItem(int*,  vector<unique_ptr<Item>>*);
void deleteItem(int*,  vector<unique_ptr<Item>>*);
void detailItem(int*, vector<unique_ptr<Item>>*);
void total(vector<unique_ptr<Item>>*);


int main(){

    int item_count = 0;

    vector<unique_ptr<Item>> cart;

    while (true) {

        cout << "1. Add item" << endl;

        cout << "2. Delete item" << endl;

        cout << "3. View item details" << endl;

        cout << "4. View total cost" << endl;

        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";

        int opt = 0;

        cin >> opt;

        switch(opt){
            case 1:
                addItem(&item_count, &cart);
                break;
            case 2:
                deleteItem(&item_count,&cart);
                break;
            case 3:
                detailItem(&item_count,&cart);
                break;
            case 4:
                total(&cart);
                break;
            case 5:
                return 0;
        }
    }
}

void addItem(int* item_count,  vector<unique_ptr<Item>>* cart){
    cout << "Enter item name: " << endl;
    cout << "Enter item quantity: " << endl;
    cout << "Enter item price: " << endl;

    unique_ptr <Item> newItem {new Item};

    cin >> newItem->name >> newItem->quantity >> newItem->price;

    cart->push_back(move(newItem));

    cout << "Item " << *item_count << " added successfully." << endl;
    *item_count += 1;
}

void deleteItem(int* item_count,  vector<unique_ptr<Item>>* cart) {
    cout << "Enter item id: ";

    int itemNum;
    cin >> itemNum;
    cart->erase(cart->begin()+itemNum);
    cout << "Item deleted successfully." << endl;
    *item_count -= 1;
}

void detailItem(int* item_count,vector<unique_ptr<Item>>* cart){
    cout << "Enter the item number: ";

    int itemNum;
    cin >> itemNum;

    if (itemNum < *item_count){
        cout << "Item "<< itemNum <<": " << endl;
        cout << "Name: " << (cart[0])[itemNum]->name << endl;
        cout << "Quantity: " << (cart[0])[itemNum]->quantity << endl;
        cout << "Price: " << (cart[0])[itemNum]->price << endl;
    }

    else {
        cout << "Item not found" << endl;
    }
}

void total(vector<unique_ptr<Item>>* cart) {
    cout << "Total cost: ";

    int sum = 0;
    for (auto &i: *cart){
        sum += (i->price) * (i->quantity);
    }

    cout << sum << endl;
}