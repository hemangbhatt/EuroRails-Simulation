/*****************************************
 ** File:    CommodityStore.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains CommodityStore class Implementation.
 **   See the CommodityStore.h for more details.
 **
 ***********************************************/

#include "CommodityStore.h"
#include <fstream>
// empty constructor
CommodityStore::CommodityStore() {/*empty body */}

// delete dynamically created map using iterator
CommodityStore::~CommodityStore() 
{
  // iterate through map and delete the object 
  for (std::map<std::string, Commodity*>::iterator i = m_store.begin(); i != m_store.end(); ++i)
    {
      delete i->second;
      i->second = NULL;
    }
}

//function takes file name as argument
void CommodityStore::loadCommodities(std::string filename)
{
    std::string color;
    std::string commo;
    // open the file
    std::ifstream commoFile(filename.c_str());
    if(commoFile.fail()) { std::cerr << "Cards file did not open." << std::endl; }
    
    // if file opens
    else
      {
	// go through file and create Commodity object
	// save pointer to the object in m_store with key
	while (commoFile >> commo)
	  {
	    commoFile >> color;

	    Commodity* temp = new Commodity;
	    temp->setColor(color);
	    temp->setName(commo);
        
	    // This maps keys to object
	    m_store[commo] = temp;
	  }
      }
}

// return the commodity pointer which points to key
Commodity* CommodityStore::getCommodity(std::string name)
{
    return m_store[name];
}
