/*****************************************
 ** File:    Objective.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains the Objective class Implementaion.
 **   See the Objective.h for more details
 **
 ***********************************************/

#include "Objective.h"
#include <stdlib.h>
#include <cstring>

//return destination
std::string Objective::getDestination() const 
{ 
  return m_sDestination; 
}

//return commodity pointer
Commodity* Objective::getCommodity() const 
{ 
  return m_pCommodity; 
}

//return m_iPayoff
int Objective::getPayoff() const 
{ 
  return m_iPayoff; 
}

//PrintObjective to filestream
void Objective::printObjective(std::ofstream& fileStream)
{
  fileStream << m_pCommodity->getName() << " to " << m_sDestination << " for " << m_iPayoff
             << std:: endl;
}

void Objective::setDestination(std::string name)
{
  m_sDestination = name;
}

void Objective::setCommodity(Commodity* ptr)
{
  m_pCommodity = ptr;
}

void Objective::setPayoff(std::string value) 
{ 
  m_iPayoff = atoi(value.c_str()); 
}
