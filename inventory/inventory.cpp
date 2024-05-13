#include "inventory.h"
#include <iostream>
#include <string>

// Existing C++ class methods
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
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            if (quantity >= it->quantity) {
                items.erase(it); // Erase the item if quantity to remove is equal or greater than the item's quantity
                return;
            } else {
                it->quantity -= quantity;
                return;
            }
        }
    }
}

void Inventory::printInventory() {
    for (const auto& item : items) {
        std::cout << "Item: " << item.name << ", Quantity: " << item.quantity << std::endl;
    }
}

// C-compatible function implementations
extern "C" Inventory* create_inventory() {
    return new Inventory();
}

extern "C" void destroy_inventory(Inventory* inventory) {
    delete inventory;
}

extern "C" void inventory_add_item(Inventory* inventory, const char* name, int quantity) {
    inventory->addItem(std::string(name), quantity);
}

extern "C" void inventory_remove_item(Inventory* inventory, const char* name, int quantity) {
    inventory->removeItem(std::string(name), quantity);
}

extern "C" void inventory_print(Inventory* inventory) {
    inventory->printInventory();
}
