#include <iostream>

#include "GameObject.h"

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  delete sprite;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout<<"texture did not load";
  }
  sprite->setTexture(texture);
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

