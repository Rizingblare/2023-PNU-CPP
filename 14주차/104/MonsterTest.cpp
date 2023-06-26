#include <iostream>
#include <iomanip>
#include <map>

class Monster {
public:
    Monster() = default;
    virtual std::unique_ptr<Monster> clone() const = 0;
    virtual void roar() = 0;
};

class Dragon : public Monster {
public:
    std::unique_ptr<Monster> clone() const override {
        return std::make_unique<Dragon>(*this);
    }

    void roar() {
        std::cout << "Dragon roars!" << std::endl;
    }
};
class Goblin : public Monster {
public:
    std::unique_ptr<Monster> clone() const override {
        return std::make_unique<Goblin>(*this);
    }

    void roar() {
        std::cout << "Goblin roars!" << std::endl;
    }
};

std::map<std::string, std::unique_ptr<Monster>> monsterRegistry;

void loadMonsters() {
    // Read monster information from file (this is the costly operation)
    // Here, we just pretend to do it and create a Dragon and a Goblin

    monsterRegistry["Dragon"] = std::make_unique<Dragon>();
    monsterRegistry["Goblin"] = std::make_unique<Goblin>();
}

std::unique_ptr<Monster> spawnMonster(const std::string& type) {
    return monsterRegistry[type]->clone();
}

int main() {
    //std::cout << "-1-" << std::endl;
    loadMonsters(); // load monster prototypes

    //std::cout << "-2-" << std::endl;
    std::unique_ptr<Monster> dragon1 = spawnMonster("Dragon"); // clone from prototype
    dragon1->roar();

    //std::cout << "-3-" << std::endl;
    std::unique_ptr<Monster> goblin1 = spawnMonster("Goblin"); // clone from prototype
    goblin1->roar();

    return 0;
}