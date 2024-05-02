#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "playerdata/player.h"

int main(void) {
    printf("Welcome to Tales Of Krendor, a text-based adventure game created by James Sweetsir!\n");
    Sleep(2000);

    char playerName[50];
    printf("Please enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0;

    set_player_name(playerName);
    initialize_player();  // Ensure player is properly initialized with default gear
    save_player_data();   // Save initial player data
    Sleep(1500);
    printf("Welcome to The Kingdom of Krendor, %s!\n", playerName);

    // Potentially print out equipped gear for debugging
    printf("You are equipped with: \nWeapon: %s\nArmor: %s\nShield: %s\n",
           player.equippedGear[WEAPON].name,
           player.equippedGear[ARMOR].name,
           player.equippedGear[SHIELD].name);

    return 0;
}
