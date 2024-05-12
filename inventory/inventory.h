#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

class Item {
public:
    std::string name;
    int quantity;

    Item(const std::string& name, int quantity) : name(name), quantity(quantity) {}
};

class Inventory {
public:
    void addItem(const std::string& name, int quantity);
    void removeItem(const std::string& name, int quantity);
    void printInventory();

private:
    std::vector<Item> items;
};

#endif