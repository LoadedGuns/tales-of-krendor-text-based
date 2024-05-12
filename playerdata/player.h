#ifndef PLAYER_H
#define PLAYER_H

// #define WEAPON 0
// #define ARMOR 1
// #define SHIELD 2

#include "../gear/gear.h"  // Include gear definitions here

typedef struct {
    char playerName[20];
    int health;
    int gold;
    int fishingLevel;
    Gear equippedGear[3];  // Array to hold one of each type of gear
} Player;

extern Player player; //Declares player across all files

void set_player_name(const char *name);
void equip_gear(Player *player, Gear gear, GearType type);
void initialize_player(void);
void save_player_data(void);
void load_player_data(void);

#endif // PLAYER_H
