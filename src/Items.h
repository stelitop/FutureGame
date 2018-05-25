#ifndef ITEMS_H
#define ITEMS_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Common.h"
#include"Player.h"

using namespace std;
using namespace sf;

class Items
{
public:
    string name;
    ItemType type;
    int statsHP, statsMana, statsArmor, statsAD, statsIntellect, statsStrength;
    classes classSpecific;
    rarity rarity;
    string description;
    Texture texture;

    Items();
};

void loadWeapons();
void loadArmor();
void loadMaterials();
void loadScrolls();

Items getWeapon(int index);
Items getArmor(int index);

#endif // ITEMS_H
