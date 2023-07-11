#ifndef ANGRYBIRDSSFML_GAMEOBJECT_H
#define ANGRYBIRDSSFML_GAMEOBJECT_H

#include<SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Vector.h"

class GameObject
{
 public:

  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();


 private:

  sf::Sprite* sprite = nullptr;

};


#endif // ANGRYBIRDSSFML_GAMEOBJECT_H
