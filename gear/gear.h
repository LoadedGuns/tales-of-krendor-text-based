#ifndef GEAR_H
#define GEAR_H


typedef enum {
    WEAPON,
    ARMOR,
    SHIELD
} GearType;

typedef struct {
    GearType type;
    char name[50];
    int power; // Power can mean different things based on type (damage, or defense, can add more later if needed)
} Gear;

//Declaring Functions to create gear types

//Bronze Items
Gear create_bronze_sword();
Gear create_bronze_armor();
Gear create_bronze_shield();

//Iron Items
Gear create_iron_sword();
Gear create_iron_armor();
Gear create_iron_shield();

//Steel Items
Gear create_steel_sword();
Gear create_steel_armor();
Gear create_steel_shield();

//Black Items
Gear create_black_sword();
Gear create_black_armor();
Gear create_black_shield();

//Mithril Items
Gear create_mithril_sword();
Gear create_mithril_armor();
Gear create_mithril_shield();

//Adamant Items
Gear create_adamant_sword();
Gear create_adamant_armor();
Gear create_adamant_shield();

//Runite Items
Gear create_runite_sword();
Gear create_runite_armor();
Gear create_runite_shield();

//Dragon Items
Gear create_dragon_sword();
Gear create_dragon_armor();
Gear create_dragon_shield();

//Obsidian Items
Gear create_obsidian_sword();
Gear create_obsidian_armor();
Gear create_obsidian_shield();

//God Items

//Rings/Amulets (Add In Later)

//Magic Gear (Add In Later)

//Runes (Add In Later)

//Range Gear (Add In Later) Include Bows/Crossbows and Arrows/Bolts

//Skilling Items (Consider Fishing, Cooking, Mining, Smithing, Woodcutting, Fletching)



#endif // !GEAR_H