/*****************************************
 ** File:    Game.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Game class Implementation.
 **   See the Game.h for more details
 ***********************************************/

#include "Game.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdio>


Game::~Game()
{
  // destory undealt card
  while(!m_drawPile.empty())
    {
      delete m_drawPile.top();
      m_drawPile.top() = NULL;
      m_drawPile.pop();
    }

  // players
  while(!m_players.empty())
    {
      for(unsigned int i = 0; i < m_players.size(); i++)
	{
	  delete m_players[i];
	  m_players[i] = NULL;
	}
      m_players.clear();
    }

}

// Do the game simulation
void Game::runSimulation(int players, Player::STRATEGY strategy)
{
  //sanity check 
    if (players > numCards)
    {
      std::cerr << "Num of players is greater then num of Cards " << std:: endl;
      exit(1);
    }

    // check number of players and cards
    else if (players <= numCards)
    {
      for (int i = 0; i < players; i++)
	{
	  
	  Player* temp = new Player;
	  std::string tempName;
	  char buffer[20];
	  sprintf(buffer, "Player %d", i+1);
	  tempName = buffer;
	  
          temp->setName(tempName);
          m_players.push_back(temp);
        }
        
      // deal card to player
        for(int dealCard = 0; dealCard < (numCards / players); dealCard++)
	  {
	    for (int player = 0; player < players; player++)
	      {
		m_players[player]->addCard(m_drawPile.top());
		m_drawPile.pop();
	      }
	  }
        
       
        
    }
    // calculate score for each player
    // this will add selected objective m_objectives in Player
    for (unsigned int player = 0; player < m_players.size(); player++)
      m_players[player]->calculateScore(strategy);

}

// print Card Pile
void Game::printDrawPile(std::ofstream& fileStream)
{
    fileStream << "------- Draw Pile---------" << std::endl;
    std::stack<Card*> temp = m_drawPile;
    while (!temp.empty())
    {
        temp.top()->printCard(fileStream);
        temp.pop();
    }
}



void Game::printResults(std::ofstream& fileStream)
{
  // check for highest score and store player pointer
  // and highest score
  int highest = 0;
  Player* temp;
  fileStream << "-------------RESULTS------------\n"; 
  for(unsigned int player = 0; player < m_players.size(); player++)
    {
      m_players[player]->printResult(fileStream);
      if (highest < m_players[player]->getScore())
	{
	  highest = m_players[player]->getScore();
	  temp = m_players[player];
	}
    }

  fileStream << "--------------------------" << std::endl;
  fileStream << "--------------------------" << std::endl;
  fileStream << "Winner: " << temp->getName() << " "
	     << "Score: " << highest << std::endl;

}




void Game::setupGame(std::string file, std::string cardsFile)
{
  // load cards and load commodities
    numCards = 0;
    m_bank.loadCommodities(file);
    loadCards(cardsFile);
    
}

void Game::loadCards(std::string file)
{
  std::ifstream cardsFile(file.c_str());
 
    std::string destination, commodity, value;

    // Create Objectives and add to Card
    while (cardsFile >> destination)
    {
        cardsFile>> commodity >> value;
        
	// Create Objective and store value
        Objective* temp = new Objective;
        temp->setDestination(destination);
        temp->setPayoff(value);
        temp->setCommodity(m_bank.getCommodity(commodity));
        
        
        
        Card* temp1 = new Card;
        temp1->addObjective(temp);
        
        cardsFile >> destination >> commodity >> value;
        temp = new Objective;
        temp->setDestination(destination);
        temp->setPayoff(value);
        // set Commodity pointer
        temp->setCommodity(m_bank.getCommodity(commodity));
        
        temp1->addObjective(temp);
        
     
        cardsFile >> destination >> commodity >> value;
        temp = new Objective;
        temp->setDestination(destination);
        temp->setPayoff(value);
        // set Commodity Pointer
        temp->setCommodity(m_bank.getCommodity(commodity));
        
        temp1->addObjective(temp);

        m_drawPile.push(temp1);
        numCards++;
        
    }
    
    
}
