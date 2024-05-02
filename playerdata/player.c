#include "player.h"
#include "../gear/gear.h"
#include <stdio.h>
#include <string.h>

// Assuming 'player' is a global variable here, if not, pass it around as needed.
Player player = { .health = 100, .gold = 50 };  // Default starting values

void set_player_name(const char *name) {
    strncpy(player.playerName, name, sizeof(player.playerName) - 1);
    player.playerName[sizeof(player.playerName) - 1] = '\0';  // Ensure null termination
}

// Function to equip gear
void equip_gear(Player *player, Gear gear, GearType type) {
    player->equippedGear[type] = gear;
    // Depending on design, might want to update player stats here
}

// Initialize player with default gear
void initialize_player(void) {
    // Reset player gear to zero before initializing
    memset(player.equippedGear, 0, sizeof(player.equippedGear));

    // Equip the default bronze gear
    player.equippedGear[WEAPON] = create_bronze_sword();
    player.equippedGear[ARMOR] = create_bronze_armor();
    player.equippedGear[SHIELD] = create_bronze_shield();

    // Default player stats
    player.health = 100;
    player.gold = 50;
}

// Function to save player data to text file
void save_player_data(void) {
    FILE *file = fopen("playerdata.txt", "w");
    if (file != NULL) {
        fprintf(file, "Name: %s\nHealth: %d\nGold: %d\n", player.playerName, player.health, player.gold);
        fclose(file);
    } else {
        perror("Failed to save player data");
    }
}
