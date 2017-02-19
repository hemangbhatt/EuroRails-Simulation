/*****************************************
 ** File:    Player.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains the Player Class Implementation
 **   and function prototypes.
 ***********************************************/


#include "Player.h"

// destructor to deallocate dynamic memory
Player::~Player()
{
  m_sName = "NONE";
  // delete m_cards
  while(!m_cards.empty())
    {
      delete m_cards.front();
      m_cards.front() = NULL;
      m_cards.pop();
    }
}

std::string Player::getName() const { return m_sName; }

int Player::getScore() const { return m_score; }

void Player::addCard(Card* card)
{
    m_cards.push(card); 
}


// calculate score and push selected objectives to m_objectives
int Player::calculateScore(Player::STRATEGY strategy)
{
  m_score = 0;
  std::queue<Card*> temp = m_cards;
    
  if(strategy == BEST_PAYOFF)
    {
      for(unsigned int i = 0; i < m_cards.size(); i++)
	{
	  m_score += temp.front()->getBestPayoff()->getPayoff();
	  m_objectives.push(temp.front()->getBestPayoff());
	
	  temp.pop();
	}
    }
  else if (strategy == FIRST_ALPHA_DESTINATION)
    {
      for(unsigned int i = 0; i < m_cards.size(); i++)
	{
	  m_score += temp.front()->getFirstAlphaDestination()->getPayoff();
	  m_objectives.push(temp.front()->getFirstAlphaDestination());
          temp.pop();
        }
    }
    
  else
    {
      for(unsigned int i = 0; i < m_cards.size(); i++)
	{
	  if(strategy == COLOR_PURPLE)
	    {
	      m_score += temp.front()->getByColor(Commodity::PURPLE)->getPayoff();
	      m_objectives.push(temp.front()->getByColor(Commodity::PURPLE));
	    }

	  else if (strategy == COLOR_RED)
	    {
	      m_score += temp.front()->getByColor(Commodity::RED)->getPayoff();
	      m_objectives.push(temp.front()->getByColor(Commodity::RED));
	    }
            
	  else if(strategy == COLOR_ORANGE)
	    {
              m_score += temp.front()->getByColor(Commodity::ORANGE)->getPayoff();
	      m_objectives.push(temp.front()->getByColor(Commodity::ORANGE));
	    }

           else if (strategy == COLOR_BLACK)
	     {
	       m_score += temp.front()->getByColor(Commodity::BLACK)->getPayoff();
               m_objectives.push(temp.front()->getByColor(Commodity::BLACK));
	     }
	   else if (strategy == COLOR_GREEN)
	     {
	       m_score += temp.front()->getByColor(Commodity::GREEN)->getPayoff();
	       m_objectives.push(temp.front()->getByColor(Commodity::GREEN));
	     }

           else if (strategy == COLOR_BROWN)
	     {
	       m_score += temp.front()->getByColor(Commodity::BROWN)->getPayoff();
               m_objectives.push(temp.front()->getByColor(Commodity::BROWN));
	     }
          temp.pop();
        }
    }
    return m_score;
}


// print result to fileStream
void Player::printResult(std::ofstream& fileStream)
{
    fileStream << "---------" << m_sName << "-----------" << std::endl;
    //loop through m_objectives
    // print objectives
    std::queue<Objective*> temp = m_objectives;
    for (unsigned int i = 0; i < m_objectives.size(); i++)
      {
	temp.front()->printObjective(fileStream);
	temp.pop();
      }
    fileStream << "Score: " << this->getScore() << std::endl;
}


void Player::setName(std::string name) { m_sName = name; }
