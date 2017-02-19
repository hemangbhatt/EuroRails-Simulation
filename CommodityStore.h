/*****************************************
 ** File:    CommodityStore.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains CommodityStore Class Declaration 
 **   and functions prototypes.
 **
 ***********************************************/

#ifndef CommodityStore_h
#define CommodityStore_h

#include "Commodity.h"
#include <map>
#include <fstream>

class CommodityStore
{
public:
  // empty constructor  
  CommodityStore();
  // constructor deletes map using iterator
  ~CommodityStore();
    
  //pass file name as a string
  //Creates Commodity objects while reading from file
  void loadCommodities(std::string filename);

  //returns commodity pointer using map
  Commodity* getCommodity(std::string name);
    
private:
    std::map<std::string, Commodity*> m_store;
    std::map<std::string, Commodity*>::iterator it;
    
};

#endif /* CommodityStore_h */
