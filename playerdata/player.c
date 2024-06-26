#include "player.h"
#include "../gear/gear.h"
#include <stdio.h>
#include <string.h>
#include "../skills/fishing/fishing.h"

// Assuming 'player' is a global variable here, if not, pass it around as needed.
Player player = { .health = 100, .gold = 50, .fishingLevel = 1 };  // Default starting values

void set_player_name(const char *name) {
    strncpy(player.playerName, name, sizeof(player.playerName) - 1);
    player.playerName[sizeof(player.playerName) - 1] = '\0';  // Ensure null termination
}

// Function to equip gear
void equip_gear(Player *player, Gear gear, GearType type) {
    player->equippedGear[type] = gear;
    printf("New gear equipped in slot %d: %s\n", type, gear.name);
    save_player_data();
}

// Initialize player with default gear
void initialize_player(void) {
    // Reset player gear to zero before initializing
    memset(player.equippedGear, 0, sizeof(player.equippedGear));

    // Equip the default bronze gear
    player.equippedGear[WEAPON] = create_bronze_sword();
    printf("Equipped Weapon: %s\n", player.equippedGear[WEAPON].name);
    player.equippedGear[ARMOR] = create_bronze_armor();
    printf("Equipped Armor: %s\n", player.equippedGear[ARMOR].name);
    player.equippedGear[SHIELD] = create_bronze_shield();
    printf("Equipped Shield: %s\n", player.equippedGear[SHIELD].name);

    // Default player stats
    player.health = 100;
    player.gold = 50;
}

// Function to save player data to text file
void save_player_data(void) {
    FILE *file = fopen("playerdata.txt", "w");
    if (file != NULL) {
        // Saves player details
        fprintf(file, "Name: %s\nHealth: %d\nGold: %d\nFishing Level: %d\n", player.playerName, player.health, player.gold, player.fishingLevel);
        
        // Saves player gear
        fprintf(file, "Weapon: %s\n", player.equippedGear[WEAPON].name);
        fprintf(file, "Armor: %s\n", player.equippedGear[ARMOR].name);
        fprintf(file, "Shield: %s\n", player.equippedGear[SHIELD].name);
        
        fclose(file);
    } else {
        perror("Failed to save player data");
        // Consider what should happen here - maybe return an error code or set a status flag
    }
}

void load_player_data(void) {
    FILE *file = fopen("playerdata.txt", "r");
    if (file != NULL) {
        // Loads player details
        fscanf(file, "Name: %49[^\n]\nHealth: %d\nGold: %d\nFishing Level: %d\n", player.playerName, &player.health, &player.gold, &player.fishingLevel);

        // Loads player gear
        fscanf(file, "Weapon: %49[^\n]\n", player.equippedGear[WEAPON].name);
        fscanf(file, "Armor: %49[^\n]\n", player.equippedGear[ARMOR].name);
        fscanf(file, "Shield: %49[^\n]\n", player.equippedGear[SHIELD].name);
        
        fclose(file);
    } else {
        perror("Failed to load player data");
        // Consider what should happen here - maybe return an error code or set a status flag
    }
}

