/*****************************************
 ** File:    Card.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Card class implementation.
 **
 ******************************************/

#include "Card.h"

// destructor to delete dynamically allocated memory    
Card::~Card()
{
  // empty the m_objectives
  while(!m_objectives.empty())
    {
      for(unsigned int i = 0; i < m_objectives.size(); i++)
	{
	  delete m_objectives[i];
	  m_objectives[i] = NULL;
	}
      m_objectives.clear();
    }
}

// push objective pointer to vector
void Card::addObjective(Objective* objective) 
{ 
  m_objectives.push_back(objective); 
}

// return the bestPayoff
Objective* Card::getBestPayoff()
{
  int highest = 0;
  Objective* temp = NULL;
  for (size_t i = 0; i < m_objectives.size(); i++ )
    {
      if (highest < m_objectives[i]->getPayoff())
	{
	  highest = m_objectives[i]->getPayoff();
          temp = m_objectives[i];
        }
    }  
  return temp;
}


Objective* Card::getFirstAlphaDestination()
{
  std::string dest1 = m_objectives[0]->getDestination();
  std::string dest2 = m_objectives[1]->getDestination();
  std::string dest3 = m_objectives[2]->getDestination();
    
  // select the card by destination
  if((dest1 <= dest2) && (dest1 <= dest3)) { return m_objectives[0]; }
  else if ((dest2 < dest1) && (dest2 <= dest3)) { return m_objectives[1]; }
  else return m_objectives[2];
}


// Return pointer objective by Color
Objective* Card::getByColor(Commodity::COLOR color)
{
    int colorCheck = 0;
    std::vector<int> v;
    // count number of colors
    for (unsigned int i = 0; i < m_objectives.size(); i++)
    {
        if (m_objectives[i]->getCommodity()->getColor() == color)
        {
            v.push_back(i);
            colorCheck++;
        }
    }

    if (colorCheck == 1)
    {
        return m_objectives[v[0]];
    }
    
    else if (colorCheck == 2)
    {
        if ((m_objectives[(v[0])])->getPayoff() < m_objectives[(v[1])]->getPayoff())
            return m_objectives[v[1]];
        else
            return m_objectives[v[0]];
    }
    
    else { return getBestPayoff(); }
    
}


// print result to fileStream
void Card::printCard(std::ofstream& fileStream)
{
    fileStream << "---------CARD-----------" << std::endl;
    for (unsigned int i = 0; i < m_objectives.size(); i++)
    {
        m_objectives[i]->printObjective(fileStream);
    }
    fileStream << "------------------------" << std::endl;
}
