/*****************************************
 ** File:    Card.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Card Class Declaration and  function Prototypes.
 **
 ***********************************************/

#ifndef Card_h
#define Card_h

#include "Objective.h"
#include <vector>

class Card
{
public:
  // destructor to destroy dynamically allocated vector
  ~Card();

  //add pointer to the objective to vector
  void addObjective(Objective* objective);

  //return pointer to the best payoff objective
  Objective* getBestPayoff();

  //return pointer to the first destination objective
  Objective* getFirstAlphaDestination();

  // return pointer to color objective
  Objective* getByColor(Commodity::COLOR color);

  // print Card to fileStream
  void printCard(std::ofstream& fileStream);

private:
  std::vector<Objective*> m_objectives;
};

#endif /* Card_h */
