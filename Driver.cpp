/*****************************************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Hemang Bhatt
 ** Date:    19/10/16
 ** Section: 03
 ** E-mail:  hb6@umbc.edu 
 **
 **   This file contains the main driver program for Project 2.
 ** This program reads the file specified as the first command line
 ** argument, counts the number of words, spaces, and characters, and
 ** displays the results in the format specified in the project description.
 **
 **
 ***********************************************/

#include <iostream>
#include <string>
#include <fstream>

#include <cstdlib>
#include "Game.h"
#include "Player.h"

void printGreeting(std::ofstream& fileStream)
{
    fileStream << "Hemang Bhatt, Section 03" << std::endl;
}


int main(int argc, const char * argv[])
{

  // Store value from command Line Argument
  std::string cardFileName = argv[1];

  std::string commoFileName = argv[2];
  int numPlayers = atoi(argv[3]);
  int strategy = atoi(argv[4]);


  // Create Strategy and pass it into Run Simulation
  Player::STRATEGY temp;
  if (strategy == 0) { temp = Player::BEST_PAYOFF;}
  else if (strategy == 1) { temp = Player::FIRST_ALPHA_DESTINATION;}
  else if (strategy == 2) { temp = Player::COLOR_PURPLE;}
  else if (strategy == 3) { temp = Player::COLOR_RED;}
  else if (strategy == 4) { temp = Player::COLOR_ORANGE;}
  else if (strategy == 5) { temp = Player::COLOR_BLACK;}
  else if (strategy == 6) { temp = Player::COLOR_GREEN;}
  else if (strategy == 7) { temp = Player::COLOR_BROWN;}


    // Create Game, Print Greetings, Draw Pile
    // Create ofstream object to store result

  Game g;
  g.setupGame(commoFileName, cardFileName);
  std::ofstream fileStream("result.txt", std::ofstream::out);

  printGreeting(fileStream);
  g.printDrawPile(fileStream);

  g.runSimulation(numPlayers, temp);
  g.printResults(fileStream);
    
  fileStream.close();  
  return 0;
}
