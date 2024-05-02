#include "gear.h"
#include <string.h>

// Function to create a generic gear item (not used directly, only by specific gear creation functions)
static Gear create_gear(GearType type, const char *name, int power) {
    Gear gear;
    gear.type = type;
    strncpy(gear.name, name, sizeof(gear.name) - 1);
    gear.power = power;
    return gear;
}

//Functions to create gear items

//Bronze Items
Gear create_bronze_sword() {
    return create_gear(WEAPON, "Bronze Sword", 2);
}

Gear create_bronze_armor() {
    return create_gear(ARMOR, "Bronze Armor", 2);
}

Gear create_bronze_shield() {
    return create_gear(SHIELD, "Bronze Shield", 1);
}

//Iron Items
Gear create_iron_sword() {
    return create_gear(WEAPON, "Iron Sword", 3);
}

Gear create_iron_armor() {
    return create_gear(ARMOR, "Iron Armor", 3);
}

Gear create_iron_shield() {
    return create_gear(SHIELD, "Iron Shield", 2);
}

//Steel Items
Gear create_steel_sword() {
    return create_gear(WEAPON, "Steel Sword", 4);
}

Gear create_steel_armor() {
    return create_gear(ARMOR, "Steel Armor", 5);
}

Gear create_steel_shield() {
    return create_gear(SHIELD, "Steel Shield", 3);
}

//Black Items
Gear create_black_sword() {
    return create_gear(WEAPON, "Black Sword", 5);
}

Gear create_black_armor() {
    return create_gear(ARMOR, "Black Armor", 6);
}

Gear create_black_shield() {
    return create_gear(SHIELD, "Black Shield", 4);
}

//Mithril Items
Gear create_mithril_sword() {
    return create_gear(WEAPON, "Mithril Sword", 6);
}

Gear create_mithril_armor() {
    return create_gear(ARMOR, "Mithril Armor", 7);
}

Gear create_mithril_shield() {
    return create_gear(SHIELD, "Mithril Shield", 5);
}

//Adamant Items
Gear create_adamant_sword() {
    return create_gear(WEAPON, "Adamant Sword", 7);
}

Gear create_adamant_armor() {
    return create_gear(ARMOR, "Adamant Armor", 8);
}

Gear create_adamant_shield() {
    return create_gear(SHIELD, "Adamant Shield", 6);
}

//Runite Items
Gear create_runite_sword() {
    return create_gear(WEAPON, "Runite Sword", 9);
}

Gear create_runite_armor() {
    return create_gear(ARMOR, "Runite Armor", 10);
}

Gear create_runite_shield() {
    return create_gear(SHIELD, "Runite Shield", 8);
}

//Dragon Items
Gear create_dragon_sword() {
    return create_gear(WEAPON, "Dragon Sword", 12);
}

Gear create_dragon_armor() {
    return create_gear(ARMOR, "Dragon Armor", 14);
}

Gear create_dragon_shield() {
    return create_gear(SHIELD, "Dragon Shield", 10);
}

//Obsidian Items
Gear create_obsidian_sword() {
    return create_gear(WEAPON, "Obsidian Sword", 14);
}

Gear create_obsidian_armor() {
    return create_gear(ARMOR, "Obsidian Armor", 16);
}

Gear create_obsidian_shield() {
    return create_gear(SHIELD, "Obsidian Shield", 12);
}

//God Items

//Rings/Amulets (Add In Later)

//Magic Gear (Add In Later)

//Runes (Add In Later)

//Range Gear (Add In Later) Include Bows/Crossbows and Arrows/Bolts

//Skilling Items (Consider Fishing, Cooking, Mining, Smithing, Woodcutting, Fletching)