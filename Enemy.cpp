#include "Enemy.h"

bool Enemy::isVisible() const
{
  return is_visible;
}

void Enemy::setIsVisible(bool isVisible)
{
  is_visible= isVisible;
}
