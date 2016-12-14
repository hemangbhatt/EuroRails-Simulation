/*****************************************
 ** File:    Commodity.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains Commodity class Implementation.
 **   See the Commodity.h for more details
 **
 ***********************************************/

#include "Commodity.h"

void Commodity::setName(std::string name)
{
    m_sName = name;
}

// compare the string and save as correcr enum type
void Commodity::setColor(std::string color)
{
    if (color == "Purple") { m_eColor = PURPLE; }
    
    else if (color == "Red") { m_eColor = RED; }
    
    else if (color == "Orange") { m_eColor = ORANGE; }
    
    else if (color == "Black") { m_eColor = BLACK; }
    
    else if (color == "Green") { m_eColor = GREEN; }
    
    else if (color == "Brown") { m_eColor = BROWN; }
    
    else { m_eColor = COLORLESS; }
}


std::string Commodity::getName() const
{
    return m_sName;
}


Commodity::COLOR Commodity::getColor()
{
    return m_eColor;
}
