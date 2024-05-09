#ifndef COMBAT_H
#define COMBAT_H

#include "../npcs/goblin/goblin.h"
#include "../npcs/orc/orc.h"
#include "../playerdata/player.h"

void goblin_encounter(Goblin *goblin, Player *player);
void orc_encounter(Orc *orc, Player *player);

#endif // COMBAT_H
