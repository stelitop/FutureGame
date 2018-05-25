#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include"Common.h"

using namespace std;

class Player
{
public:
    int level;
    int baseHP, baseMana, baseArmor, baseAD, baseStrength, baseIntellect;
    int healthPerLvl, manaPerLvl, ADPerLvl;
    classes playerClass;
    string nickname;
    int itemsWeapons[TOTAL_WEAPONS];
    int itemsArmor[TOTAL_ARMOR];
    int itemsMaterials[TOTAL_MATERIALS];
    int itemsScrolls[TOTAL_SCROLLS];

    int currentWeapon, currentHelmet, currentChestplate, currentLeggings, currentBoots, currentGloves, currentNecklace, currentRing;
    bool upToDate;

    int calculatedHP, calculatedMana, calculatedArmor, calculatedAD, calculatedStrength, calculatedIntellect;

    Player();
    Player(classes c);

    void calculateStats();
    void displayInfo();
    bool equipWeapon(int index);
    bool equipArmor(int index);

};

#endif // PLAYER_H
