//
//  Character.cpp
//  Rpg
//
//  Created by Soufiane on 23/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Character.h"
#include <iostream>
Character::Character(std::string m_name)
{
    //Setting the character display
    m_texture.loadFromFile("/Users/mrhade/Desktop/Rpg/Character_Hero_Archor.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,100,100));// Character is 100x100
    m_sprite.setScale(0.32, 0.32);//Now the character has the same size as the tiles 32x32
    m_sprite.setPosition(32*5, 32*3);
    //Setting variables for collision manager
    m_canMoveRight=true;
    m_canMoveLeft=true;
    m_canMoveUp=true;
    m_canMoveDown=true;
    }
sf::Sprite Character::getSprite()
{
    return m_sprite;
}
void Character::moveRight()
{
   
    m_sprite.setTextureRect(sf::IntRect(100,0,-100,100));//Flips the character
    if(m_canMoveRight)
    {
    m_sprite.move(32,0);
    }
}
void Character::moveLeft()
{
    m_sprite.setTextureRect(sf::IntRect(0,0,100,100));//Puts the correct TextureRect from the char file

    if(m_canMoveLeft)
    {
    m_sprite.move(-32, 0);
    }
}
void Character::moveUp()
{
    m_sprite.setTextureRect(sf::IntRect(0,100,100,100));//Character looks up
    if(m_canMoveUp)
    {
    m_sprite.move(0, -32);
    }
}
void Character::moveDown()
{
    m_sprite.setTextureRect(sf::IntRect(0,200,100,100));//Character looks down

    if(m_canMoveDown)
    {
    m_sprite.move(0, 32);
    }
}
//********************************
void Character::canMoveRight()
{
    m_canMoveRight=true;
}
void Character::canMoveLeft()
{
    m_canMoveLeft=true;
}
void Character::canMoveUp()
{
    m_canMoveUp=true;
}
void Character::canMoveDown()
{
    m_canMoveDown=true;
}
//********************************
void Character::collisionManager(TileMap map)
{
        std::vector<std::vector<int> > vmap = map.getVmap();
    
        //If you want to add tiles that provoke collision, put " || numberOfYourTile " after the 54
        //54=Trees
        //Don't use else if because the char could be in the middle of 4 tiles so we have to check every collision
    
        //Collision with tiles on the right of character
        if(vmap[(m_sprite.getPosition().y)/32][((m_sprite.getPosition().x)+32)/32]==54 /*add tiles here*/)
        {
            m_canMoveRight=false;
        }
        //Collision with tiles on the left of character
        if (vmap[(m_sprite.getPosition().y)/32][((m_sprite.getPosition().x)-32)/32]==54 /*add tiles here*/)
        {
            m_canMoveLeft=false;
        }
        //Collision with tiles above the character
        if(vmap[((m_sprite.getPosition().y)-32)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
        {
            m_canMoveUp=false;
        }
        //Collision with tiles under the character
        if (vmap[((m_sprite.getPosition().y)+32)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
        {
            m_canMoveDown=false;
        }
        //If the character is on a tile where he's not suppose to be, we block him
        if (vmap[(m_sprite.getPosition().y)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
        {
            m_canMoveRight=false;
            m_canMoveLeft=false;
            m_canMoveUp=false;
            m_canMoveDown=false;
        }
    
}








