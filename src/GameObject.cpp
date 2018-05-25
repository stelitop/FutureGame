#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameObject.h"

using namespace std;
using namespace sf;

GameObject::GameObject()
{
    this->corner = Vector2f(0,0);
    this->objectSize = Vector2f(0,0);
}
GameObject::GameObject(Vector2f corner, Vector2f sz)
{
    this->corner = corner;
    this->objectSize = sz;
}
GameObject::GameObject(int x, int y, int szx, int szy)
{
    this->corner = Vector2f(x,y);
    this->objectSize = Vector2f(szx, szy);
}

bool GameObject::checkForHover(RenderWindow * window)
{
    Vector2i mousePos = Mouse::getPosition(*window);
    if (mousePos.x > this->corner.x && mousePos.x < this->corner.x + this->objectSize.x &&
        mousePos.y > this->corner.y && mousePos.y < this->corner.y + this->objectSize.y)
    {
        return true;
    }
    return false;
}

bool GameObject::loadFromFile(string s)
{
    if (this->texture.loadFromFile(s))
        return true;
    return false;
}

void GameObject::drawFrame(RenderWindow * window, Color col)
{
    VertexArray v(LineStrip, 5);
    v[0] = this->corner;
    v[1] = Vector2f(this->corner.x + this->objectSize.x, this->corner.y);
    v[2] = Vector2f(this->corner.x + this->objectSize.x, this->corner.y + this->objectSize.y);
    v[3] = Vector2f(this->corner.x, this->corner.y + this->objectSize.y);
    v[4] = this->corner;
    for (int i=0;i<5;i++)
    {
        v[i].color = col;
    }
    window->draw(v);
}
void GameObject::draw(RenderWindow * window)
{
    Sprite s;
    s.setTexture(this->texture);
    s.setPosition(this->corner);
    s.setScale(double(this->objectSize.x) / double(this->texture.getSize().x) , double(this->objectSize.y) / double(this->texture.getSize().y));
    window->draw(s);
}
