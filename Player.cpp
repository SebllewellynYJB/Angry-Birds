#include <complex>

#include "Player.h"

Player::Player()
{

}

void Player::move(sf::RenderWindow& window, float dt,sf::Event event)
{
  // Updates player movement
  getSprite()->move(player_direction.x * getSpeed() * dt, player_direction.y * getSpeed() * dt);
  keyPressed(window,event,dt);
  mouseButtonPressed(window,event);
  init(window);
}

void Player::keyPressed(sf::RenderWindow& window, sf::Event event, float dt)
{
  // Key movement for the player
  // This includes shooting the player at the aliens
  if(event.key.code == sf::Keyboard::Space)
  {
    player_direction.x = 1;
    player_direction.y = 0.25;
    std::cos(angle) * speed;
    std::sin(angle) * speed;
  }
  if (event.key.code == sf::Keyboard::Q)
  {
    window.close();
  }
  if (event.key.code == sf::Keyboard::Enter)
  {
    player_direction.x = 0;
    player_direction.y = 0;
  }
}

// This is where any mouse pressed movement will happen
// This is used for moving the player in the x and y-axs and stopping the movement
void Player::mouseButtonPressed(sf::RenderWindow& window, sf::Event event)
{
  if (event.mouseButton.button == sf::Mouse::Left)
  {
    if (getSprite()->getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
    {
      player_direction.x = -0.25;
    }
  }
  if (event.mouseButton.button == sf::Mouse::Right)
  {
    if (getSprite()->getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
    {
      player_direction.y = -0.25;
    }
  }
  if (event.mouseButton.button == sf::Mouse::Middle)
  {
    if (getSprite()->getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
    {
      player_direction.y = 0.25;
    }
  }
}

bool Player::init(sf::RenderWindow& renderWindow)
{
  return false;
}

// Getter and Setter functions for the game
// Setters are used in the init to set different variables
// Getters are used in the update to get the speed from the init to be used
int Player::getSpeed() const
{
  return speed;
}

void Player::setSpeed(int speed)
{
  Player::speed = speed;
}

const Vector2& Player::getPlayerDirection() const
{
  return player_direction;
}

void Player::setPlayerDirection(const Vector2& playerDirection)
{
  player_direction = playerDirection;
}

