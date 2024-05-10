#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "playerdata\player.h"
#include "npcs\goblin\goblin.h"
#include "npcs\orc\orc.h"
#include "combat\combat.h"

int main(void) {
    // Initialize random number generator
    srand(time(NULL));

    printf("Welcome to Tales Of Krendor, a text-based adventure game created by James Sweetsir!\n");
    Sleep(2000);

    // Block to load player data and display for testing
    load_player_data();
    printf("Name: %s\n", player.playerName);
    printf("Health: %d\n", player.health);
    printf("Gold: %d\n", player.gold);
    printf("Weapon: %s\n", player.equippedGear[WEAPON].name);
    printf("Armor: %s\n", player.equippedGear[ARMOR].name);
    printf("Shield: %s\n", player.equippedGear[SHIELD].name);

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

    char testAnswer; // Setting up variable to accept y or n for question
    printf("You are walking down the road, and find an old chest, as you open it you find some armor and weapons, would you like to equip them? Y or N: ");
    testAnswer = getchar();
    testAnswer = tolower(testAnswer);
    if (testAnswer = 'y') {
        printf("You grab and put on the gear, made of iron, it is stronger then what you currently have on! \n");
        Gear ironsword = create_iron_sword();
        Gear ironarmor = create_iron_armor();
        Gear ironshield = create_iron_shield();

        equip_gear(&player, ironsword, WEAPON);
        equip_gear(&player, ironarmor, ARMOR);
        equip_gear(&player, ironshield, SHIELD);
    } else if (testAnswer = 'n') {
        printf("You leave the gear inside the chest and move on! \n");
    } else {
        printf("Invalid answer, please enter Y or N: ");
    }

    //TESTING EQUIP GEAR FUNCTIONS (Remove after all testing done)
    // Gear ironsword = create_iron_sword();
    // Gear ironarmor = create_iron_armor();
    // Gear ironshield = create_iron_shield();

    // equip_gear(&player, ironsword, WEAPON);
    // equip_gear(&player, ironarmor, ARMOR);
    // equip_gear(&player, ironshield, SHIELD);

    save_player_data();
    printf("Player %s is equipped with:\n", player.playerName);
    printf("Weapon: %s\n", player.equippedGear[WEAPON].name);
    printf("Armor: %s\n", player.equippedGear[ARMOR].name);
    printf("Shield: %s\n", player.equippedGear[SHIELD].name);
    //FUNCTIONS CORRECT (Test later switch cases for equipping gear from loot table or bought in shops)

    // Goblin encounter test
    Goblin goblin = {.health = 15, .power = 5, .armor = 3};
    goblin_encounter(&goblin, &player);

    // Orc counter test
    // Orc orc = {.health = 35, .power = 10, .armor = 5};
    // orc_encounter(&orc, &player);

    return 0;
}
