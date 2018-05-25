#ifndef INFOPANELS_H
#define INFOPANELS_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Items.h"
#include"Common.h"

using namespace std;
using namespace sf;

void displayPanel(RenderWindow * window, Items item, Vector2f corner, int minWidth, int charSz);
void displayPanel(RenderWindow * window, string s, Vector2f corner, int charSz);

#endif // INFOPANELS_H
