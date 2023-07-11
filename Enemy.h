#ifndef ANGRYBIRDSSFML_ENEMY_H
#define ANGRYBIRDSSFML_ENEMY_H


#include "GameObject.h"

class Enemy : public GameObject
{
 private:
  bool is_visible = true;

 public:
  bool isVisible() const;
  void setIsVisible(bool isVisible);

};

#endif // ANGRYBIRDSSFML_ENEMY_H
