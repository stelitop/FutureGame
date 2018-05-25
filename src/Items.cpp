#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include"Items.h"

using namespace std;
using namespace sf;

Items allWeapons[TOTAL_WEAPONS], allArmor[TOTAL_ARMOR], allMaterials[TOTAL_MATERIALS], allScrolls[TOTAL_SCROLLS];

Items getWeapon(int index)
{
    return allWeapons[index];
}
Items getArmor(int index)
{
    return allArmor[index];
}

Items::Items()
{
    this->name = "";
    this->statsAD = 0;
    this->statsArmor = 0;
    this->statsHP = 0;
    this->statsMana = 0;
    this->statsIntellect = 0;
    this->statsStrength = 0;
    this->type = NOTYPE;
    this->classSpecific = NONE;
    this->description = "";
    this->texture.loadFromFile("textures/Unavailable.png");
}

void Player::calculateStats()
{
    if (this->upToDate == false)
    {
        this->calculatedAD = this->baseAD;
        this->calculatedMana = this->baseMana;
        this->calculatedHP = this->baseHP;
        this->calculatedArmor = this->baseArmor;
        this->calculatedIntellect = this->baseIntellect;
        this->calculatedStrength = this->baseStrength;


        int * cWeapon = &this->currentWeapon;
        int * cHelmet = &this->currentHelmet;
        int * cChestplate = &this->currentChestplate;
        int * cLeggings = &this->currentLeggings;
        int * cBoots = &this->currentBoots;
        int * cGloves = &this->currentGloves;
        int * cNecklace = &this->currentNecklace;
        int * cRing = &this->currentRing;

        int * addresses[] = {cWeapon, cHelmet, cChestplate, cLeggings, cBoots, cGloves, cNecklace, cRing};
        int const sizeOf = 8;

        for (int i=0; i<sizeOf; i++)
        {
            if (i == 0)
            {
                this->calculatedAD += allWeapons[*addresses[i]].statsAD;
                this->calculatedHP += allWeapons[*addresses[i]].statsHP;
                this->calculatedMana += allWeapons[*addresses[i]].statsMana;
                this->calculatedArmor += allWeapons[*addresses[i]].statsArmor;
                this->calculatedIntellect += allWeapons[*addresses[i]].statsIntellect;
                this->calculatedStrength += allWeapons[*addresses[i]].statsStrength;
            }
            else
            {
                this->calculatedAD += allArmor[*addresses[i]].statsAD;
                this->calculatedHP += allArmor[*addresses[i]].statsHP;
                this->calculatedMana += allArmor[*addresses[i]].statsMana;
                this->calculatedArmor += allArmor[*addresses[i]].statsArmor;
                this->calculatedIntellect += allArmor[*addresses[i]].statsIntellect;
                this->calculatedStrength += allArmor[*addresses[i]].statsStrength;
            }
        }
        this->upToDate = true;
    }
}

void Player::displayInfo()
{
    this->calculateStats();
    cout<<"Name: "<<this->nickname<<endl;
    cout<<"Level: "<<this->level<<endl;
    cout<<"Class: "<<this->playerClass<<endl;
    cout<<"Base AD: "<<this->calculatedAD<<endl;
    cout<<"Base HP: "<<this->calculatedHP<<endl;
    cout<<"Base Mana: "<<this->calculatedMana<<endl;
    cout<<"Base Armor: "<<this->calculatedArmor<<endl;
    cout<<"Base Strength: "<<this->calculatedStrength<<endl;
    cout<<"Base Intellect: "<<this->calculatedIntellect<<endl;
    cout<<"HP Growth: "<<this->healthPerLvl<<endl;
    cout<<"Mana Growth: "<<this->manaPerLvl<<endl;
    cout<<"AD Growth: "<<this->ADPerLvl<<endl;
    cout<<"Weapon: "<<allWeapons[this->currentWeapon].name<<endl;
    cout<<"Helmet: "<<allArmor[this->currentHelmet].name<<endl;
    cout<<"Chestplate: "<<allArmor[this->currentChestplate].name<<endl;
    cout<<"Leggings: "<<allArmor[currentLeggings].name<<endl;
    cout<<"Boots: "<<allArmor[currentBoots].name<<endl;
    cout<<"Gloves: "<<allArmor[this->currentGloves].name<<endl;
    cout<<"Necklace: "<<allArmor[this->currentNecklace].name<<endl;
    cout<<"Ring: "<<allArmor[this->currentRing].name<<endl;
}

void loadWeapons()
{
    for (int i=0;i<TOTAL_WEAPONS;i++)
    {
        allWeapons[i].type = WEAPON;
    }

    allWeapons[0].name = "None";
    allWeapons[0].classSpecific = NONE;

    allWeapons[1].name = "Starting Sword";
    allWeapons[1].statsAD = 10;
    allWeapons[1].classSpecific = WARRIOR;
    allWeapons[1].rarity = STARTING;
    allWeapons[1].description = "Every warrior's starting sword.";

    allWeapons[2].name = "Starting Wand";
    allWeapons[2].statsAD = 10;
    allWeapons[2].classSpecific = MAGE;
    allWeapons[2].rarity = STARTING;
    allWeapons[2].description = "Every mage's starting wand.";

    allWeapons[3].name = "Starting Staff";
    allWeapons[3].statsAD = 10;
    allWeapons[3].classSpecific = WARLOCK;
    allWeapons[3].rarity = STARTING;
    allWeapons[3].description = "Every warlock's starting staff.";

    allWeapons[4].name = "Starting Dagger";
    allWeapons[4].statsAD = 10;
    allWeapons[4].classSpecific = ASSASSIN;
    allWeapons[4].rarity = STARTING;
    allWeapons[4].description = "Every assassin's starting dagger.";

    allWeapons[5].name = "Common Item";
    allWeapons[5].rarity = COMMON;

    allWeapons[6].name = "Uncommon Item";
    allWeapons[6].rarity = UNCOMMON;

    allWeapons[7].name = "Rare Item";
    allWeapons[7].rarity = RARE;

    allWeapons[8].name = "Epic Item";
    allWeapons[8].rarity = EPIC;

    allWeapons[9].name = "Legendary Item";
    allWeapons[9].rarity = LEGENDARY;
    allWeapons[9].description = "That's pretty good.";
}
void loadArmor()
{
    allArmor[0].name = "None";
    allArmor[0].classSpecific = NONE;

    allArmor[1].name = "Starting Robe";
    allArmor[1].classSpecific = MAGE;
    allArmor[1].type = ARMOR_CHESTPLATE;
    allArmor[1].statsArmor = 5;
    allArmor[1].description = "Every mage's starting robe.";

    allArmor[2].name = "Starting Boots";
    allArmor[2].classSpecific = MAGE;
    allArmor[2].type = ARMOR_BOOTS;
    allArmor[2].statsArmor = 3;
    allArmor[2].description = "Every mage's starting boots.";

    allArmor[3].name = "Starting Chestplate";
    allArmor[3].classSpecific = WARRIOR;
    allArmor[3].type = ARMOR_CHESTPLATE;
    allArmor[3].statsHP = 60;
    allArmor[3].description = "Every warrior's starting chestplate.";

    allArmor[4].name = "Starting Leggings";
    allArmor[4].classSpecific = WARRIOR;
    allArmor[4].type = ARMOR_LEGGINGS;
    allArmor[4].statsHP = 40;
    allArmor[4].description = "Every warrior's starting leggings.";

    allArmor[5].name = "Starting Gloves";
    allArmor[5].classSpecific = ASSASSIN;
    allArmor[5].type = ARMOR_GLOVES;
    allArmor[5].statsAD = 2;
    allArmor[5].statsArmor = 2;
    allArmor[5].description = "Every assassin's starting gloves.";

    allArmor[6].name = "Starting Mask";
    allArmor[6].classSpecific = ASSASSIN;
    allArmor[6].type = ARMOR_HELMET;
    allArmor[6].statsArmor = 4;
    allArmor[6].description = "Every assassin's starting mask.";

    allArmor[7].name = "Starting Robe";
    allArmor[7].classSpecific = WARLOCK;
    allArmor[7].type = ARMOR_CHESTPLATE;
    allArmor[7].statsArmor = 5;
    allArmor[7].description = "Every warlock's starting robe.";

    allArmor[8].name = "Starting Ring";
    allArmor[8].classSpecific = MAGE;
    allArmor[8].type = ARMOR_CHESTPLATE;
    allArmor[8].statsIntellect = 2;
    allArmor[8].description = "Every warlock's starting ring.";
}
void loadMaterials()
{

}
void loadScrolls()
{

}

bool Player::equipWeapon(int index)
{
    if ((this->itemsWeapons[index] > 0 && (allWeapons[index].classSpecific == NONE || allWeapons[index].classSpecific == this->playerClass)) || index == 0)
    {
        if (this->currentWeapon != 0) this->itemsWeapons[this->currentWeapon]++;
        this->currentWeapon = index;
        this->itemsWeapons[index]--;
        this->upToDate = false;
        return true;
    }
    return false;
}
/// \brief for (index > 0) the new item will be set according to the item's type. If the index is negative, it means that an armour piece is being unequipped
bool Player::equipArmor(int index)
{
    if (index < 0)
    {
        switch (index)
        {
        case -ARMOR_HELMET:
            this->itemsArmor[this->currentHelmet]++;
            this->currentHelmet = 0;
            break;
        case -ARMOR_CHESTPLATE:
            this->itemsArmor[this->currentChestplate]++;
            this->currentChestplate = 0;
            break;
        case -ARMOR_LEGGINGS:
            this->itemsArmor[this->currentLeggings]++;
            this->currentLeggings= 0;
            break;
        case -ARMOR_BOOTS:
            this->itemsArmor[this->currentBoots]++;
            this->currentBoots = 0;
            break;
        case -ARMOR_GLOVES:
            this->itemsArmor[this->currentGloves]++;
            this->currentGloves = 0;
            break;
        case -ARMOR_NECKLACE:
            this->itemsArmor[this->currentNecklace]++;
            this->currentNecklace= 0;
            break;
        case -ARMOR_RING:
            this->itemsArmor[this->currentRing]++;
            this->currentRing = 0;
            break;
        }
        this->upToDate = false;
        return true;
    }
    if (this->itemsArmor[index] > 0 && (allArmor[index].classSpecific == NONE || allArmor[index].classSpecific == this->playerClass))
    {
        int * curArmor;
        switch (allArmor[index].type)
        {
        case ARMOR_HELMET:
            curArmor = &this->currentHelmet;
            break;
        case ARMOR_CHESTPLATE:
            curArmor = &this->currentChestplate;
            break;
        case ARMOR_LEGGINGS:
            curArmor = &this->currentLeggings;
            break;
        case ARMOR_BOOTS:
            curArmor = &this->currentBoots;
            break;
        case ARMOR_GLOVES:
            curArmor = &this->currentGloves;
            break;
        case ARMOR_NECKLACE:
            curArmor = &this->currentNecklace;
            break;
        case ARMOR_RING:
            curArmor = &this->currentRing;
            break;
        default:
            curArmor = 0;
        }

        if (*curArmor != 0) this->itemsArmor[*curArmor]++;
        *curArmor = index;
        this->itemsArmor[index]--;
        this->upToDate = false;
        return true;
    }
    return false;
}
