/*****************************************
 ** File:    Objective.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Objective Class Declaration and function Prototypes.
 **
 ***********************************************/

#ifndef Objective_h
#define Objective_h

#include "CommodityStore.h"

class Objective
{
public:

  //Name: getDestination()
  //precondition: SetDestination() Should be called before this one
  std::string getDestination() const;

  //Name: getCommodity()
  //precondition: SetCommodity() should be called before this one
  Commodity* getCommodity() const;
 
  //Name: getPayoff()
  //preconditon: setPayoff() should be called before this one
  int getPayoff() const;

  //Name: printObjective()
  //precondition: fileStream should be valid ostream object
  //postconditon: print Objective to fileStream
  void printObjective(std::ofstream& fileStream);
    
  //Name: setDestination()
  //precondtion: Objective should be created before
  //postconditon: set value
  void setDestination(std::string name);
  
  //Name:setCommodity()
  //precondition: pass Commodity ptr to this function
  void setCommodity(Commodity* ptr);

  //Name: setPayoff()
  //precondition:Objective should be created before
  void setPayoff(std::string value);
    
private:
    std::string m_sDestination;
    Commodity* m_pCommodity;
    int m_iPayoff;
    
};

#endif /* Objective_h */
