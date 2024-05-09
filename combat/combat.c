#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "combat.h"

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
        int attack_damage = rand() % 8 + 3;  // Player's attack (3 to 10)
        int mitigated_damage = attack_damage - goblin->armor;
        if (mitigated_damage < 0) mitigated_damage = 0;
        printf("You attack the goblin and deal %d damage.\n", mitigated_damage);
        goblin->health -= mitigated_damage;
        Sleep(1500);

        if (goblin->health <= 0) {
            goblin->health = 0;
            printf("The goblin has been killed!\n");
            goblin_drop(&goblin_drop_table);
            player->gold += goblin_drop_table.gold;
            save_player_data();
            break;
        } else {
            printf("The goblin has %d health left.\n", goblin->health);

            // Goblin attacks the player
            int goblin_attack = rand() % goblin->power + 1;
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
        int attack_damage = rand() % 10 + 5;  // Player's attack (5 to 14)
        int mitigated_damage = attack_damage - orc->armor;
        if (mitigated_damage < 0) mitigated_damage = 0;
        printf("You attack the orc and deal %d damage.\n", mitigated_damage);
        orc->health -= mitigated_damage;
        Sleep(1500);

        if (orc->health <= 0) {
            orc->health = 0;
            printf("The orc has been defeated!\n");
            orc_drop(&orc_drop_table);
            player->gold += orc_drop_table.gold;
            save_player_data();
            break;
        } else {
            printf("The orc has %d health left.\n", orc->health);

            // Orc attacks the player
            int orc_attack = rand() % orc->power + 1;
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
