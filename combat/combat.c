#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "combat.h"

// Function to generate a random number in a specific range [min, max]
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Test Function to add values from gear power pulled from string in the load player data function
// int random_range(int min, int max) {
//     return rand() % (player_power() - player_power() + random_range(1, 3) + player_power());
// }

// int player_power(p) {

// }

// int player_armor(a) {

// }

void goblin_encounter(Goblin *goblin, Player *player) {
    Goblin_Drop_Table goblin_drop_table = {.gold = 0};

    printf("\nA goblin jumps out at you! Prepare for battle!\n");
    printf("The goblin has %d health, %d power, and %d armor.\n", goblin->health, goblin->power, goblin->armor);

    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    while (goblin->health > 0) {
        int attack_damage = random_range(5, 10); // Player's attack
        int mitigated_damage = attack_damage - goblin->armor;
        if (mitigated_damage < 0) mitigated_damage = 0;
        goblin->health -= mitigated_damage;
        printf("You attack the Goblin and deal %d damage. The Goblin has %d health left.\n", mitigated_damage, goblin->health);
        Sleep(1500);

        if (goblin->health <= 0) {
            goblin->health = 0;
            printf("The goblin has been killed!\n");
            goblin_drop(&goblin_drop_table);
            player->gold += goblin_drop_table.gold;
            save_player_data();
            break;
        } else {

            // Goblin attacks the player
            int goblin_attack = random_range(goblin->power, random_range(1, 5));
            player->health -= goblin_attack;
            printf("The goblin attacks you and deals %d damage. You have %d health left.\n", goblin_attack, player->health);
            Sleep(1500);

            if (player->health <= 0) {
                printf("You have been defeated!\n");
                return;
            }
        }
    }
}

void orc_encounter(Orc *orc, Player *player) {
    Orc_Drop_Table orc_drop_table = {.gold = 0};

    printf("\nAn orc charges towards you! Brace for a tough fight!\n");
    printf("The orc has %d health, %d power, and %d armor.\n", orc->health, orc->power, orc->armor);

    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    while (orc->health > 0) {
        int attack_damage = random_range(5, 10); // Player's attack
        int mitigated_damage = attack_damage - orc->armor;
        if (mitigated_damage < 0) mitigated_damage = 0;
        orc->health -= mitigated_damage;
        printf("You attack the Orc and deal %d damage. The Orc has %d health left.\n", mitigated_damage, orc->health);

        if (orc->health <= 0) {
            orc->health = 0;
            printf("The orc has been defeated!\n");
            orc_drop(&orc_drop_table);
            player->gold += orc_drop_table.gold;
            save_player_data();
            break;
        } else {

            // Orc attacks the player
            int orc_attack = random_range(orc->power, random_range(1, 5));
            player->health -= orc_attack;
            printf("The orc attacks you and deals %d damage. You have %d health left.\n", orc_attack, player->health);
            Sleep(1500);

            if (player->health <= 0) {
                printf("You have been defeated!\n");
                return;
            }
        }
    }
}
