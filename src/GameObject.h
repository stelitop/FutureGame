#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameObject
{
public:
    Vector2f corner;
    Vector2f objectSize;
    Texture texture;

    bool checkForHover(RenderWindow * window);
    void drawFrame(RenderWindow * window, Color col);
    bool loadFromFile(string s);
    void draw(RenderWindow * window);

    GameObject();
    GameObject(Vector2f corner, Vector2f sz);
    GameObject(int x, int y, int szx, int szy);
};

#endif // GAMEOBJECT_H
