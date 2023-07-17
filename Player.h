#ifndef ANGRYBIRDSSFML_PLAYER_H
#define ANGRYBIRDSSFML_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "GameObject.h"

class Player : public GameObject
{

 public:
  Player();
  const Vector2& getPlayerDirection() const;
  void setPlayerDirection(const Vector2& playerDirection);
  void move(sf::RenderWindow& window, float dt, sf::Event event);
  void handleInput(sf::RenderWindow&window, sf::Event event);
  int getSpeed() const;
  void setSpeed(int speed);

  // Player direction for key movement
  Vector2 player_direction = {0,0};
  bool isDragging = false;
  sf::Vector2f offset;

 private:
  void keyPressed(sf::RenderWindow& window, sf::Event event, float dt);
  bool init(sf::RenderWindow& renderWindow);

  int speed = 0;
  int angle = 0;


};

#endif // ANGRYBIRDSSFML_PLAYER_H
