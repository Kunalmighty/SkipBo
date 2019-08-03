#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <fstream>
using std::ostringstream;

void Game::restore(std::string filename)
{
	std::ifstream myfile(filename);
	if (myfile.is_open())
 	{

 		Pile* bp[NBUILD];
		for(int i = 0; i < NBUILD; i ++)
		bp[i] = &buildPiles[i];

 		myfile >> turn;
 		myfile >> isGui;
 		
 		int drawsize;
 		myfile >> drawsize;
 		for (int i = 0; i < drawsize; i++)  //reads in the size of the draw pile, and makes a card for each int and adds
 		{
 			int temp;
 			myfile >> temp;
 			Card *c = new Card(temp);
 			drawPile + *c;
 		}
 		int trashsize;
 		myfile >> trashsize;
 		for (int i = 0; i < trashsize; i++)  //does same but with trashpile
 		{
 			int temp;
 			myfile >> temp;
 			Card *c = new Card(temp);
 			trashPile + *c;
 		}
 
 		for (int i = 0; i < 4; i++)
 		{
 			int buildsize;  //takes the size of each pile and creates cards to add them to the buildpiles
 			myfile >> buildsize;
 			for (int j = 0; j < buildsize; j++ )
 			{
 				int temp;
 				myfile >> temp;
 				bool b;
 				myfile >> b;
 				Card *c = new Card(temp, b);
 				buildPiles[i] + *c;
 			}
 		}

 		int numplayers;
 		myfile >> numplayers;
 		for (int i = 0; i < numplayers; i++) //loads in players
 		{
 			std::string name;
 			bool isHuman;
 			bool isAct;
 			int stocksize;
 			myfile >> name;
			myfile >> isHuman;	
			myfile >> isAct;
			myfile >> stocksize;
			Player* person;
			if (isHuman)
			{
				person = new HumanPlayer(name, bp, drawPile, 0, *term);
			}
			else
			{
				person = new AIPlayer (name, bp, drawPile, 0);
			}
			person->isActive = isAct;
			for (int j = 0; j < stocksize; j++) //loads stock pile
			{
				int data;
				myfile >> data;
				Card *c = new Card(data);
				person->stock + *c;
			}

			for (int j = 0; j < 5; j++) //loads player hand
			{
				int data;
				myfile >> data;
				Card *c = new Card(data);
				person->hand + *c;
			}	
			
			for (int j = 0; j < 4; j++) //writes each discard pile
			{
				int discardsize;
				myfile >> discardsize;
				for (int k = 0; k < discardsize; k++)
				{
					int data;
					myfile >> data;
					Card *c = new Card(data);
					person->discard[j] + *c;
				}
			}
			players.push_back(person);			
 		}	
 	}
 	myfile.close();
}

void Game::save(std::string name)
{
	std::ofstream myfile;
	myfile.open(name);
	myfile << "turn:" << turn << std::endl;
	myfile << "gui" << isGui << std::endl;
	myfile << "drawPIleSize" << drawPile.getSize() << std::endl;
	for (int i = 0; i < drawPile.getSize(); i++)
	{
		myfile << "card data" << std::endl;
		myfile << drawPile.cardAt(i).getData() << std::endl;
	}
	myfile << "trashpile" << std::endl;
	myfile << trashPile.getSize() << std::endl;
	for (int i = 0; i < trashPile.getSize(); i++)
	{
		myfile << "trashpile cards" << std::endl;
		myfile << trashPile.cardAt(i).getData() << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < buildPiles[i].getSize(); j++ )
		{	
			myfile << "buildpile size" << std::endl;
			myfile << buildPiles[i].getSize() << std::endl;
			myfile << "card data" << std::endl;
			myfile << buildPiles[i].cardAt(j).getData() << " " << buildPiles[i].cardAt(j).getSkipBo() << std::endl;
		}
	}
	myfile << "number of players" << std::endl;
	myfile << players.size() << std::endl;
	for (int i = 0; i < (int)players.size(); i++) //write each player's data
	{
		myfile << "player name" << std::endl;
		myfile << players[i]->getName() << std::endl;
		myfile << "ishuman" << std::endl;
		myfile << players[i]->isHuman << std::endl;
		myfile << "isactive" << std::endl;	
		myfile << players[i]->isActive << std::endl;
		myfile << "stockpile size" << std::endl;
		myfile << players[i]->stock.getSize() << std::endl;
		for (int j = 0; j < players[i]->stock.getSize(); j++)
		{	
myfile << "stockkpile cards" << std::endl;
		myfile << players[i]->stock.cardAt(j).getData() << std::endl; //writes the cards in the stock pile

		}
		for (int j = 0; j < 5; j++)
		{
	myfile << "hand cards" << std::endl;	
		myfile << players[i]->hand.cardAt(j).getData() << std::endl; //writes the cards in the hand
		}
		for (int k = 0; k < 4; k++) //writes each discard pile
		{
myfile << "discard pile  size" << std::endl;
			int size = players[i]->discard[k].getSize();
			myfile << size << std::endl;
			for (int n = 0; n < size; n++)
			{
myfile << "discard pile cards" << std::endl;
				myfile << players[i]->discard[k].cardAt(n).getData() << std::endl;
			}
			
		}


	}

	myfile.close();
}

