#include<iostream>
#include<SFML/Graphics.hpp>
#include"RenderScreen.h"
#include"GameObject.h"
#include"Items.h"

using namespace std;
using namespace sf;

void renderPlayerProfile (RenderWindow * window, Player * player)
{
    double sz = window->getSize().y*2.0/11.0;
    GameObject helmet(window->getSize().x/4-sz/2 ,sz/10, sz, sz);
    helmet.texture = getArmor(player->currentHelmet).texture;
    helmet.draw(window);
    helmet.drawFrame(window, Color::White);

    GameObject chestplate(window->getSize().x/4-sz*3/4, sz*6/5, sz*3/2, sz*3/2);
    chestplate.texture = getArmor(player->currentChestplate).texture;
    chestplate.draw(window);
    chestplate.drawFrame(window, Color::White);

    GameObject leggings(window->getSize().x/4-sz*3/4, sz*14/5, sz*3/2, sz*3/2);
    leggings.texture = getArmor(player->currentLeggings).texture;
    leggings.draw(window);
    leggings.drawFrame(window, Color::White);

    GameObject boots(window->getSize().x/4-sz/2, sz*22/5, sz, sz);
    if (player->currentBoots != 0) boots.texture = getArmor(player->currentBoots).texture;
    else boots.texture.loadFromFile("textures/NoBoots(Pirated).png");
    boots.draw(window);
    boots.drawFrame(window, Color::White);
}
