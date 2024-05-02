#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "playerdata/player.h"

int main(void) {
    printf("Welcome to Tales Of Krendor, a text based adventure game created by James Sweetsir!\n");
    Sleep(2000);
    char playerName[20];
    printf("Please enter your name: ");
    scanf("%s", playerName);
    set_player_name(playerName);
    save_player_data();  // Now handled within player.c
    Sleep(1500);
    printf("Welcome to The Kingdom of Krendor %s", playerName);

    return 0;
}