#include <iostream>

#include "Game.h"


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

// This function is where the main features of the game are initialized.
// This includes font, text, textures, sprites, cameras and audio.
// The size, colour and position of text and objects can be set in this function
// The speed and direction of the player character are also set here
bool Game::init()
{
  in_menu = true;
  // Menu - this is where the text is set for the menu
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout <<"font did not load\n";
  }

  play_option.setString("Play");
  play_option.setFont(font);
  play_option.setCharacterSize(50);
  play_option.setFillColor(sf::Color(0,255,0,255));
  play_option.setPosition(875,150);

  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(50);
  quit_option.setFillColor(sf::Color(250,0,0,255));
  quit_option.setPosition(875,250);

  menu_text.setString("Menu navigation- Up, Down and Enter");
  menu_text.setFont(font);
  menu_text.setCharacterSize(25);
  menu_text.setFillColor(sf::Color(0,255,0,255));
  menu_text.setPosition(10,100);

  AngryBirds_text.setString("Angry Birds");
  AngryBirds_text.setFont(font);
  AngryBirds_text.setCharacterSize(50);
  AngryBirds_text.setFillColor(sf::Color(250,0,0,255));
  AngryBirds_text.setPosition(420,25);

  controls_text.setString("How to Play:");
  controls_text.setFont(font);
  controls_text.setCharacterSize(50);
  controls_text.setFillColor(sf::Color(250, 0, 0, 255));
  controls_text.setPosition(10,125);

  Shoot_text.setString("Shoot- Left mouse click on bird to draw back and release to shoot");
  Shoot_text.setFont(font);
  Shoot_text.setCharacterSize(25);
  Shoot_text.setFillColor(sf::Color(255, 0, 0, 128));
  Shoot_text.setPosition(10,250);

  escape_text.setString("Press Q to quit at any time and H to pause");
  escape_text.setFont(font);
  escape_text.setCharacterSize(25);
  escape_text.setFillColor(sf::Color(250,0,0,128));
  escape_text.setPosition(10,300);

  return_menu.setString("Press J to return to the menu");
  return_menu.setFont(font);
  return_menu.setCharacterSize(25);
  return_menu.setFillColor(sf::Color(250,0,0,128));
  return_menu.setPosition(10,325);

  rules.setString("Rules:");
  rules.setFont(font);
  rules.setCharacterSize(50);
  rules.setFillColor(sf::Color(250, 0, 0, 255));
  rules.setPosition(10,400);

  bird_information.setString("Birds- 3 attempts to kill all aliens");
  bird_information.setFont(font);
  bird_information.setCharacterSize(25);
  bird_information.setFillColor(sf::Color(255, 0, 0, 128));
  bird_information.setPosition(10,525);

  alien_information.setString("Aliens- total of 5 to kill");
  alien_information.setFont(font);
  alien_information.setCharacterSize(25);
  alien_information.setFillColor(sf::Color(250, 0, 0, 128));
  alien_information.setPosition(10,550);

  // Text for the game screen that includes score and number of lives
  score_text.setFont(font);
  score_text.setCharacterSize(50);
  score_text.setFillColor(sf::Color(255,0,0));
  score_text.setPosition(1000,10);

  lives_text.setFont(font);
  lives_text.setCharacterSize(50);
  lives_text.setFillColor(sf::Color(255,0,0));
  lives_text.setPosition(10,10);

  // Text for the pause screen
  pause.setString("Game Paused- Press P to play");
  pause.setFont(font);
  pause.setCharacterSize(50);
  pause.setFillColor(sf::Color(250, 0, 0, 255));
  pause.setPosition(100,275);

  // Text for the game over screen
  game_won.setString("Game Won- Press P to play and J to return to Menu");
  game_won.setFont(font);
  game_won.setCharacterSize(25);
  game_won.setFillColor(sf::Color(250, 0, 0, 255));
  game_won.setPosition(10,275);

  // Text for the game over screen
  game_over.setString("Game Over- Press P to play and J to return to Menu");
  game_over.setFont(font);
  game_over.setCharacterSize(25);
  game_over.setFillColor(sf::Color(250, 0, 0, 255));
  game_over.setPosition(100,275);

  // Game screen information- includes textures and game objects
  if (!game_background_texture.loadFromFile("Data/Images/menu.jpg"))
  {
    std::cout << "background did not load\n";
  }
  game_background.setTexture(game_background_texture);
  game_background.setScale(0.6,0.75);

  view.setCenter(window.getSize().x/2, window.getSize().y/2);
  view.setSize(window.getSize().x/1, window.getSize().y/1);
  view.setViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f));
  game_background_texture.setRepeated(true);
  game_background.setTextureRect(sf::IntRect(0,0,game_background.getGlobalBounds().width*2, game_background.getGlobalBounds().height*2));

  // // Player details. Sets the speed and direction for the player that is used in update
  player.initialiseSprite(player_texture,"Data/Images/kenney_animalpackredux/PNG/Round/gorilla.png");
  player.getSprite()->setPosition(200,680);
  player.getSprite()->setScale(0.2,0.2);
  player.setSpeed(250);
  player.setPlayerDirection(Vector2{0,0});

  // Enemy details-This is where the enemy array is set up. This includes the stands and actual enemies
  for (int i = 0; i < no_of_enemies; i++)
  {
    enemy[1].initialiseSprite(enemy_texture,"Data/Images/kenney_animalpackredux/PNG/Round/bear.png");
    enemy[2].initialiseSprite(enemy_texture,"Data/Images/kenney_animalpackredux/PNG/Round/cow.png");
    enemy[3].initialiseSprite(enemy_texture,"Data/Images/kenney_animalpackredux/PNG/Round/dog.png");
    enemy[1].getSprite()->setPosition(450,600);
    enemy[2].getSprite()->setPosition(600,620);
    enemy[3].getSprite()->setPosition(750,550);
    enemy[i].getSprite()->setScale(0.2,0.2);
  }

  for (int i = 0; i < no_of_enemies_stands; i++)
  {
    enemy_stand[1].initialiseSprite(enemy_stand__texture,"Data/Images/kenney_physicspack/PNG/wood elements/elementWood021.png");
    enemy_stand[2].initialiseSprite(enemy_stand__texture,"Data/Images/kenney_physicspack/PNG/wood elements/elementWood021.png");
    enemy_stand[3].initialiseSprite(enemy_stand__texture,"Data/Images/kenney_physicspack/PNG/wood elements/elementWood021.png");
    enemy_stand[1].getSprite()->setPosition(455,625);
    enemy_stand[2].getSprite()->setPosition(605,645);
    enemy_stand[3].getSprite()->setPosition(755,575);
    enemy_stand[i].getSprite()->setScale(0.2,0.2);
  }

  // Audio in the game. This includes the general game audio and the alien death sound effect
  if(!game_music.openFromFile("Data/577391__szegvari__desert-fly-orchestra-atmo (1).wav"))
  {
    std::cout << "Music did not load\n";
  }
  game_music.play();
  game_music.setVolume(10.0f);

  if (death_sound_buffer.loadFromFile("Data/555412__tonsil5__zombie-death-1.wav"))
  {
    std::cout << "sound did not load\n";
  }
  death_sound.setBuffer(death_sound_buffer);
  death_sound.setVolume(200);

  return true;
}

// This is where different events are updated every frame
// This includes collision and player movement win + lose states
void Game::update(float dt, sf::Event event)
{
  // Updates player movement
  player.move(window,dt,event);

  for (int i = 0; i < no_of_enemies; i++)
  {
    if (!collision(*player.getSprite(), *enemy[i].getSprite()))
      continue;
    enemy[i].setIsVisible(false);
    death_sound.play();
    return;
  }
  
  //or no_of_enemies > 0
  for (int i = 0; i < no_of_enemies; i++)
  {
    if (score >= 10)
    {
      currentState = GameStates::GameWon;
      player.player_direction.x = 0;
      player.player_direction.y = 0;
      score = 0;
      player.getSprite()->setPosition(200,680);
      enemy[i].setIsVisible(true);
      return;
    }
  }
  for (int i = 0; i < no_of_enemies; i++)
  {
    if (number_of_lives <= -3)
    {
      currentState = GameStates::GameOver;
      player.player_direction.x = 0;
      player.player_direction.y = 0;
      score = 0;
      enemy[i].setIsVisible(true);
      number_of_lives = 0;
    }
  }

  if ((player.getSprite()->getPosition().x > 1020) ||
      (player.getSprite()->getPosition().y > 720))
  {
    player.getSprite()->setPosition(100, 680);
    player.player_direction.y = -0;
    player.player_direction.x = -0;
    number_of_lives --;
  }
}

// This will render all the text and objects to the screen that was created in the init function
void Game::render()
{
  // Text and textures that are rendered for the menu screen
  if (in_menu)
  {
    window.draw(play_option);
    window.draw(quit_option);
    window.draw(menu_text);
    window.draw(AngryBirds_text);
    window.draw(escape_text);
    window.draw(controls_text);
    window.draw(Shoot_text);
    window.draw(rules);
    window.draw(bird_information);
    window.draw(alien_information);
    window.draw(return_menu);
  }
  // Game objects and Background rendered for the game screen
  else if (currentState == GameStates::Play)
  {
    window.setView(view);
    window.draw(game_background);
    window.draw(*player.getSprite());
    window.draw(score_text);
    score_text.setString(std::to_string(score));
    window.draw(lives_text);
    lives_text.setString(std::to_string(number_of_lives-0));
    for (int i = 0; i < no_of_enemies; i++)
    {
      if (enemy[i].isVisible())
      {
        window.draw(*enemy[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_enemies_stands; i++)
    {
      if (enemy_stand[i].isVisible())
      {
        window.draw(*enemy_stand[i].getSprite());
      }
    }
  }
  // Items rendered for the pause screen
  else if (currentState == GameStates::Pause)
  {
    window.draw(pause);
  }
  // Items rendered for game won screen
  else if (currentState == GameStates::GameWon)
  {
    window.draw(game_won);
  }
  // Items rendered for the game over screen
  else if (currentState == GameStates::GameOver)
  {
    window.draw(game_over);
  }
}

// This is where any key input will happen.
// This includes menu interaction
void Game::keyPressed(sf::Event event, float dt)
// When the key is pressed. An event will happen
{
  // menu keys for play and quit
  if ((event.key.code == sf::Keyboard::Up)||
      (event.key.code == sf::Keyboard::Down))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play_option.setString("> Play <");
      quit_option.setString("Quit");
    }
    else
    {
      play_option.setString("Play");
      quit_option.setString("> Quit <");
    }
  }
  // Menu keys for loading next screen
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      currentState = GameStates::Play;
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
  // Key input to control different game states
  // Key input to take player back to the menu
  if (event.key.code == sf::Keyboard::J)
  {
    in_menu = true;
  }
  // Key input to pause the game
  if (event.key.code == sf::Keyboard::H)
  {
    currentState = GameStates::Pause;
    player.player_direction.x = 0;
    player.player_direction.y = 0;
  }
  // Key input to resume play
  if (event.key.code == sf::Keyboard::P)
  {
    currentState = GameStates::Play;
  }
}

// This is where any key released events will happen.
void Game::keyReleased(sf::Event event)
// When the key is released. The event will stop happening
{

}

// This is where the main collision of the game is processed. The collision is set in this function then will be updated every frame in the update function
bool Game::collision(const sf::Sprite& sprite1, sf::Sprite sprite2)
{
  // Collision between player and enemies
  for (int i = 0; i < no_of_enemies; i++)
  {
    if (player.getSprite()->getGlobalBounds().intersects(enemy[i].getSprite()->getGlobalBounds()))
    {
      std::cout << "Coin collected\n";
      enemy[i].setIsVisible(false);
      score ++;
      return true;
    }
  }
}

// This is where any mouse pressed movement will happen
void Game::mouseButtonPressed(sf::Event event)
// When the mouse button is pressed. An event will happen
{

}

void Game::mouseButtonReleased(sf::Event event)
// When the mouse button is released. An event will happen
{

}

void Game::mouseMoved(sf::Event event)
// When the mouse button is moved. An event will happen
{

}
