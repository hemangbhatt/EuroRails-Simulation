/*****************************************
 ** File:    Game.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Game class Declaration and Function Prototypes
 **
 ***********************************************/

#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Card.h"
#include <stack>
#include <ostream>

class Game
{
public:
  // delete dynamic memory
  ~Game();

  // pass number of players and strategy 
  // simulate game calculate score
  void runSimulation(int players, Player::STRATEGY strategy);

  // print result to fileStream
  // print drawPile Stack
  void printDrawPile(std::ofstream& fileStream);

  // print results to fileStream
  // of each player
  // print winner and score
  void printResults(std::ofstream& fileStream);

  // load cards and load commodities
  void setupGame(std::string file, std::string cardsFile);

  // load cards from Cards file
  void loadCards(std::string file);
    

private:
    std::stack<Card*> m_drawPile;
    std::vector<Player*> m_players;
    CommodityStore m_bank;
    int numCards;
};

#endif /* Game_h */
