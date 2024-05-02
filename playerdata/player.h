#ifndef PLAYER_H
#define PLAYER_H

#include "../gear/gear.h"  // Include gear definitions here

typedef struct {
    char playerName[20];
    int health;
    int gold;
    Gear equippedGear[3];  // Array to hold one of each type of gear
} Player;

void set_player_name(const char *name);
void save_player_data(void);
void equip_gear(Player *player, Gear gear, GearType type); 

#endif // PLAYER_H
