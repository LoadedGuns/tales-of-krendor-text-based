#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include "playerdata\player.h"
#include "npcs\goblin\goblin.h"
#include "npcs\orc\orc.h"
#include "combat\combat.h"
#include "functions\functions.h"
#include "skills/fishing/fishing.h"

int main(void) {
    // Initialize random number generator
    srand(time(NULL));

    printf("Welcome to Tales Of Krendor, a text-based adventure game created by James Sweetsir!\n");
    Sleep(2000);

    char save_load;
    printf("Would you like to load a saved game, or start over? (L/N): ");
    save_load = getchar();

if (tolower(save_load == 'l')) {
    // Block to load player data and display for testing
    load_player_data();
    printf("Name: %s\n", player.playerName);
    printf("Health: %d\n", player.health);
    printf("Gold: %d\n", player.gold);
    printf("Weapon: %s\n", player.equippedGear[WEAPON].name);
    printf("Armor: %s\n", player.equippedGear[ARMOR].name);
    printf("Shield: %s\n", player.equippedGear[SHIELD].name);
    flush_input();
} else if (tolower(save_load == 'n')) {
    char playerName[50];
    printf("Please enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0;
    flush_input();
    set_player_name(playerName);
    initialize_player();  // Ensure player is properly initialized with default gear
    save_player_data();   // Save initial player data
    printf("Welcome to The Kingdom of Krendor, %s!\n", playerName);
    flush_input();
} else {
    printf("Invalid answer, please type L or N!\n");
    exit(1);
}
    Sleep(1500);

    // While condition to allow the player to play the game until they wish to stop and save, preventing the program from ending prematurely 
    bool playing_game = true;
    while (playing_game) {

        // Potentially print out equipped gear for debugging
        printf("You are equipped with: \nWeapon: %s\nArmor: %s\nShield: %s\n",
            player.equippedGear[WEAPON].name,
            player.equippedGear[ARMOR].name,
            player.equippedGear[SHIELD].name);

        char testAnswer; // Setting up variable to accept y or n for question
        printf("You are walking down the road, and find an old chest, as you open it you find some armor and weapons, would you like to equip them? Y or N: ");
        testAnswer = getchar();
        if (tolower(testAnswer == 'y')) {
            printf("You grab and put on the gear, made of iron, it is stronger then what you currently have on! \n");
            Gear ironsword = create_iron_sword();
            Gear ironarmor = create_iron_armor();
            Gear ironshield = create_iron_shield();

            equip_gear(&player, ironsword, WEAPON);
            equip_gear(&player, ironarmor, ARMOR);
            equip_gear(&player, ironshield, SHIELD);
            flush_input();
        } else if (tolower(testAnswer == 'n')) {
            printf("You leave the gear inside the chest and move on! \n");
            flush_input();
        } else {
            printf("Invalid answer, please enter Y or N: ");
        }

        save_player_data();
        printf("Player %s is equipped with:\n", player.playerName);
        printf("Weapon: %s\n", player.equippedGear[WEAPON].name);
        printf("Armor: %s\n", player.equippedGear[ARMOR].name);
        printf("Shield: %s\n", player.equippedGear[SHIELD].name);
        //FUNCTIONS CORRECT (Test later switch cases for equipping gear from loot table or bought in shops)

    // Fishing Test
    char catch_shrimp;
    printf("Would you like to catch some shrimp? (Y or N): ");
    catch_shrimp = getchar();
    flush_input(); 

    if (tolower(catch_shrimp) == 'y') {
        do {
            fish_shrimp(player.fishingLevel); 

            printf("Would you like to continue fishing? (Y or N): ");
            catch_shrimp = getchar();
            flush_input();

        } while (tolower(catch_shrimp) == 'y');
    }

        char engage_goblin;
        printf("You spot a goblin, do you engage in combat? (Y or N): ");
        engage_goblin = getchar();
        if (tolower(engage_goblin == 'y')) {

        // Goblin encounter test
        Goblin goblin = {.health = 15, .power = 5, .armor = 3};
        goblin_encounter(&goblin, &player);
        flush_input();
        } else {
            printf("You avoid the goblin and move on!\n");
            flush_input();
        }
        // Orc counter test
        // Orc orc = {.health = 35, .power = 10, .armor = 5};
        // orc_encounter(&orc, &player);

        // Prompt the player whether they want to continue playing
        char continue_playing;
        printf("Do you want to continue playing? (Y or N): ");
        continue_playing = getchar();
        flush_input(); // Consume the newline character left in the input buffer

        if (tolower(continue_playing) != 'y') { // If player doesn't want to continue, end the game
            save_player_data();
            printf("PLayer Data Saved!\n");
            Sleep(1000);
            printf("Thank you for playing!\n");
            flush_input();
            playing_game = false;
            return 0;
        }
    }
}
