/*****************************************
 ** File:    Player.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Player Class Declaration and function prototypes.
 **
 ***********************************************/
#ifndef Player_h
#define Player_h

#include "Card.h"
#include <queue>

class Player
{
public:

  enum STRATEGY
  {
    BEST_PAYOFF = 0,
    FIRST_ALPHA_DESTINATION = 1,
    COLOR_PURPLE = 2,
    COLOR_RED = 3,
    COLOR_ORANGE = 4,
    COLOR_BLACK = 5,
    COLOR_GREEN = 6,
    COLOR_BROWN = 7
  };

  // Destructor to deallocate dynamic memory
  ~Player();
  
   
  std::string getName() const;
  int getScore() const;
  void addCard(Card* card);
 
  // Calculate score using specific strategy defined in enum
  int calculateScore(Player::STRATEGY strategy);

  // Print Result to fileStream
  void printResult(std::ofstream& fileStream);
    
  void setName(std::string name);
    
private:
    std::string m_sName;
    std::queue<Card*> m_cards;
    std::queue<Objective*> m_objectives;
    int m_score;
};

#endif /* Player_h */
