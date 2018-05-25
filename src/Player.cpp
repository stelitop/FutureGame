#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
    this->nickname = "Player";
    this->baseAD = 0;
    this->baseArmor = 0;
    this->baseHP = 0;
    this->baseIntellect = 0;
    this->baseMana = 0;
    this->baseStrength = 0;
    this->healthPerLvl = 0;
    this->level = 0;
    this->manaPerLvl = 0;
    this->ADPerLvl = 0;
    this->playerClass = NONE;
    for (int i=0; i<TOTAL_WEAPONS; i++) this->itemsWeapons[i] = 0;
    for (int i=0; i<TOTAL_ARMOR; i++) this->itemsArmor[i] = 0;
    for (int i=0; i<TOTAL_MATERIALS; i++) this->itemsMaterials[i] = 0;
    for (int i=0; i<TOTAL_SCROLLS; i++) this->itemsScrolls[i] = 0;
    this->currentBoots = 0;
    this->currentChestplate = 0;
    this->currentGloves = 0;
    this->currentHelmet = 0;
    this->currentLeggings = 0;
    this->currentNecklace = 0;
    this->currentWeapon = 0;
    this->currentRing = 0;
    this->upToDate = false;
}
Player::Player(classes c)
{
    *this = Player();
    this->playerClass = c;
    if (c == MAGE)
    {
        this->currentWeapon = 2;
        this->currentChestplate = 1;
        this->currentBoots = 2;
    }
    else if (c == WARRIOR)
    {
        this->currentWeapon = 1;
        this->currentChestplate = 3;
        this->currentLeggings = 4;
    }
    else if (c == ASSASSIN)
    {
        this->currentWeapon = 4;
        this->currentGloves = 5;
        this->currentHelmet = 6;
    }
    else if (c == WARLOCK)
    {
        this->currentWeapon = 3;
        this->currentChestplate = 7;
        this->currentRing = 8;
    }
}
