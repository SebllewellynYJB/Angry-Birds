#ifndef ANGRYBIRDS_GAME_H
#define ANGRYBIRDS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"

class Game
{
 public:
  // Functions used in the game cpp
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt, sf::Event);
  void render();
  void keyPressed(sf::Event event, float dt);
  void keyReleased(sf::Event event);
  bool collision(const sf::Sprite& sprite1 , sf::Sprite sprite2);
  void mouseButtonPressed(sf::Event event);

  // Game States
  enum class GameStates
  {
    Menu,
    Play,
    Pause,
    GameOver,
    GameWon
  };
  GameStates currentState;

  // Game Objects
  sf::Texture player_texture;
  Player player;

  Enemy enemy[5];
  sf::Texture enemy_texture;
  int no_of_enemies = 5;

 private:
  sf::RenderWindow& window;

  // Menu Information- This includes font and textures
  sf::Font font;
  sf::Text menu_text;
  sf::Text escape_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;
  sf:: Text AngryBirds_text;
  sf::Text controls_text;
  sf::Text Draw_text;
  sf::Text Draw_text2;
  sf::Text Shoot_text;
  sf::Text bird_information;
  sf::Text alien_information;
  sf::Text rules;
  sf::Text return_menu;
  sf::Text pause;
  sf::Text game_won;
  sf::Text game_over;

  // Game Screen- Includes textures and score + lives
  sf::View view;
  sf::Sprite game_background;
  sf::Texture game_background_texture;
  int score = 0;
  sf::Text score_text;
  int number_of_lives = 0;
  sf::Text lives_text;

  sf::Music game_music;
  sf::SoundBuffer death_sound_buffer;
  sf::Sound death_sound;
};

#endif // ANGRYBIRDS_GAME_H
