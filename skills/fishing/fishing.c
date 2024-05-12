#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fishing.h"
#include "../../combat/combat.h"
#include "../../playerdata/player.h"

extern Player player;

static RawFish create_raw_fish(const char *name, int exp, int level) {
    RawFish rawfish;
    strncpy(rawfish.name, name, sizeof(rawfish.name) - 1);
    rawfish.name[sizeof(rawfish.name) - 1] = '\0'; // Ensure null termination
    rawfish.exp = exp;
    rawfish.level = level;
    return rawfish;
}

// May remove this and just add in if and while loops to the functions below
static int fish_success(int player_level, int fish_level) {
    if (player_level < fish_level) {
        printf("Your fishing level is too low to catch this fish.\n");
        return 0;  // Not successful because level is too low
    }
    int chance = random_range(1, 100); // Random chance between 1 and 100
    int difficulty = (fish_level - player_level) * 5; // Increase difficulty if fish level is higher than player level
    return chance > difficulty;
}

RawFish fish_shrimp(int player_level) {
    if (fish_success(player_level, 1)) {
        printf("You caught a raw shrimp!\n");
        return create_raw_fish("Shrimp", 10, 1);
    } else {
        printf("You failed to catch anything.\n");
        return create_raw_fish("None", 0, 0); // No catch
    }
}

RawFish fish_trout(int player_level) {
    if (fish_success(player_level, 10)) {
        printf("You caught a raw trout!\n");
        return create_raw_fish("Trout", 50, 10);
    } else {
        printf("You failed to catch anything.\n");
        return create_raw_fish("None", 0, 0);
    }
}

RawFish fish_lobster(int player_level) {
    if (fish_success(player_level, 40)) {
        printf("You caught a raw lobster!\n");
        return create_raw_fish("Lobster", 75, 40);
    } else {
        printf("You failed to catch anything.\n");
        return create_raw_fish("None", 0, 0);
    }
}

RawFish fish_shark(int player_level) {
    if (fish_success(player_level, 70)) {
        printf("You caught a raw shark!\n");
        return create_raw_fish("Shark", 150, 70);
    } else {
        printf("You failed to catch anything.\n");
        return create_raw_fish("None", 0, 0);
    }
}

RawFish create_raw_shrimp() {
    return create_raw_fish("Shrimp", 10, 1);
}

RawFish create_raw_trout() {
    return create_raw_fish("Trout", 50, 10);
}

RawFish create_raw_lobster() {
    return create_raw_fish("Lobster", 75, 40);
}

RawFish create_raw_shark() {
    return create_raw_fish("Shark", 150, 70);
}
