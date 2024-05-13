#ifndef INVENTORY_H
#define INVENTORY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Inventory Inventory; // Forward declaration of an opaque type

// C-compatible function declarations
Inventory* create_inventory();
void destroy_inventory(Inventory* inventory);
void inventory_add_item(Inventory* inventory, const char* name, int quantity);
void inventory_remove_item(Inventory* inventory, const char* name, int quantity);
void inventory_print(Inventory* inventory);

#ifdef __cplusplus
}
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    int quantity;
    Item(const std::string& name, int quantity) : name(name), quantity(quantity) {}
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const std::string& name, int quantity);
    void removeItem(const std::string& name, int quantity);
    void printInventory();
};
#endif

#endif
