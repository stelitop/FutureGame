#ifndef COMMON_H
#define COMMON_H

#define TOTAL_WEAPONS 100
#define TOTAL_ARMOR 100
#define TOTAL_MATERIALS 100
#define TOTAL_SCROLLS 100

enum ItemType
{
    NOTYPE = 0,
    WEAPON = 1,
    ARMOR_HELMET = 2,
    ARMOR_CHESTPLATE = 3,
    ARMOR_LEGGINGS = 4,
    ARMOR_BOOTS = 5,
    ARMOR_GLOVES = 6,
    ARMOR_NECKLACE = 7,
    ARMOR_RING = 8,
    MATERIAL = 9,
    SPELL_SCROLL = 10
};

enum classes
{
    NONE = 0,
    MAGE = 1,
    WARRIOR = 2,
    ASSASSIN = 3,
    WARLOCK = 4
};

enum rarity
{
    NO_RARITY = -1,
    STARTING = 0,
    COMMON = 1,
    UNCOMMON = 2,
    RARE = 3,
    EPIC = 4,
    LEGENDARY = 5
};

enum menu
{
    MAIN = 0,
    CHARACTER_PROFILE = 1
};

#endif // COMMON_H
