#include "InfoPanels.h"
#include "GameObject.h"
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

string filter(string s, int maxWidth, Font font, int charSz)
{
    string ret;
    Text text;
    text.setFont(font);
    text.setCharacterSize(charSz);
    string curr="";
    for (int i=0;i<s.size();i++)
    {
        curr+=s[i];
        text.setString(curr);
        if (text.getGlobalBounds().width > maxWidth)
        {
            while (s[i] != ' ')
            {
                i--;
                curr.resize(curr.size()-1);
            }
            curr.resize(curr.size()-1);
            ret+=curr+'\n';
            curr="";
        }
    }
    ret+=curr;
    return ret;
}

void displayPanel(RenderWindow * window, string s, Vector2f corner, int maxWidth, int charSz)
{
    Font font;
    font.loadFromFile("Calibri.ttf");
    Text text;

    text.setString(filter(s, maxWidth, font, charSz));
    text.setCharacterSize(charSz);
    text.setPosition(corner);
    text.setFont(font);

    FloatRect r = text.getGlobalBounds();

    window->draw(text);
    GameObject panel(r.left-10, r.top-10, r.width+20, r.height+20);
    panel.drawFrame(window, Color::White);
}


void displayPanel(RenderWindow * window, Items item, Vector2f corner, int minWidth, int charSz)
{
    Font font;
    font.loadFromFile("Calibri.ttf");

    Text text;
    text.setCharacterSize(charSz);
    text.setPosition(corner);
    text.setFont(font);

    string name = " - " + item.name + " - ";
    string description;

    text.setString(name);
    FloatRect r = text.getGlobalBounds();

    if (r.width < minWidth)
    {
        while (r.width < minWidth)
        {
            name = " "+name+" ";
            text.setString(name);
            r = text.getGlobalBounds();
        }
        name = name.substr(1,name.size()-2);
    }
    else minWidth = r.width;

    description=filter(item.description, minWidth, font, charSz);

    text.setString(name+"\n\n"+description);
    r = text.getGlobalBounds();

    GameObject panel(r.left-10, r.top-10, r.width+20, r.height+20);
    if (item.name == "None") panel.objectSize.y = 15+charSz;
    panel.loadFromFile("textures/Background.png");
    panel.draw(window);
    panel.drawFrame(window, Color::White);

    switch (item.rarity)
    {
    case UNCOMMON:
        text.setColor(Color::Green);
        break;
    case RARE:
        text.setColor(Color::Cyan);
        break;
    case EPIC:
        text.setColor(Color::Magenta);
        break;
    case LEGENDARY:
        text.setColor(Color(255,100,0));
        break;
    default:
        text.setColor(Color(150,150,150));
    }
    if (item.name == "None")
    {
        text.setString(name);
        font.loadFromFile("CalibriB.ttf");
        text.setFont(font);
        window->draw(text);
    }
    else
    {
        text.setString(name);
        font.loadFromFile("CalibriB.ttf");
        text.setFont(font);
        window->draw(text);

        text.setString("\n\n"+description);
        font.loadFromFile("CalibriI.ttf");
        text.setFont(font);
        window->draw(text);
    }
}
