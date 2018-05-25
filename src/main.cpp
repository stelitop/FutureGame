#include<iostream>
#include<SFML/Graphics.hpp>
#include"IncludeAll.h"

using namespace std;
using namespace sf;

void loadEverything()
{
    loadWeapons();
    loadArmor();
    loadMaterials();
    loadScrolls();
}

menu currentMenu = CHARACTER_PROFILE;

int main()
{

    loadEverything();
    Player x(WARRIOR);
    x.displayInfo();
    x.equipArmor(3);
    x.equipArmor(4);

    RenderWindow window(VideoMode(1500,800), "", Style::Close);

    GameObject obj(300,300,500,350);
    obj.loadFromFile("textures/Background.png");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        if (currentMenu == CHARACTER_PROFILE)
        {
            renderPlayerProfile(&window, &x);
        }

        window.display();
    }

    return 0;
}
