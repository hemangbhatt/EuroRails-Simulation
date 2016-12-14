/*****************************************
 ** File:    Commodity.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    10/19/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Commodity Class Declaration and functions Prototypes.
 **
 ***********************************************/

#ifndef Commodity_h
#define Commodity_h

#include <iostream>
#include <string>

class Commodity
{
public:

  enum COLOR
  {
    PURPLE = 0,
    RED = 1,
    ORANGE = 2,
    BLACK = 3,
    GREEN = 4,
    BROWN = 5,
    COLORLESS = 6
  };
    
  // Name: getName()
  // precondition:set m_sName before using this function
  std::string getName() const;

  // Name: getColor()
  // precondition:set m_eColor before using this function
  COLOR getColor();
    
  // Name: setName()
  // precondition: Create Object without Constructor
  void setName(std::string name);

  // Name: setColor()
  // precondition: Create Object without Constructor
  void setColor(std::string color);
    
private:
  std::string m_sName;
  COLOR m_eColor;
    
};

#endif /* Commodity_h */
