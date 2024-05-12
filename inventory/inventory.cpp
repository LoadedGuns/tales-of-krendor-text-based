#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const std::string& name, int quantity) {
    for (auto& item : items) {
        if (item.name == name) {
            item.quantity += quantity;
            return;
        }
    }
    items.push_back(Item(name, quantity));
}

void Inventory::removeItem(const std::string& name, int quantity) {
    for (auto& item : items) {
        if (item.name == name) {
            if (quantity >= item.quantity)
                item.quantity = 0;  // Or you might prefer to erase the item from the vector.
            else
                item.quantity -= quantity;
            return;
        }
    }
}

void Inventory::printInventory() {
    for (const auto& item : items) {
        std::cout << "Item: " << item.name << ", Quantity: " << item.quantity << std::endl;
    }
}
