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
Terminal* Game::term = 0;

Game::Game(bool graphic, bool useDefault)
{
	bool wat = useDefault;
	useDefault = wat;
	//TODO if graphics
	term = new TUITerminal(std::cin, std::cout);
	bool temp = graphic;
	graphic = temp;
	//initializing field
	drawPile = Pile(true);
	drawPile.deckShuffle();
	trashPile = Pile();
	turn = 0;
	for (int i = 0; i < NBUILD; i++)
		buildPiles[i] = Pile();
	int stockSize = 3;
	//initializing the list of players
	Pile* bp[NBUILD];
	for(int i = 0; i < NBUILD; i ++)
		bp[i] = &buildPiles[i];
	Player* p1 = new HumanPlayer("Manyu", bp, drawPile, stockSize, *term);
	Player* p2 = new HumanPlayer("Kunal", bp, drawPile, stockSize, *term);
	Player* p3 = new HumanPlayer("Ethan", bp, drawPile, stockSize, *term);
	Player* p4 = new HumanPlayer("Tony", bp, drawPile, stockSize, *term);
	players.push_back(p1);
	players.push_back(p2);
	players.push_back(p3);
	players.push_back(p4);

	term->sendMessage(GAME_CREATED);
	history.push_back(writeState());
	message = HEALTHY;
}


Game::Game(bool graphic)
{
	isGui = graphic;

	//	if(!isGui)
	term = new TUITerminal(std::cin, std::cout);

	bool load = term->getBool("Loading any games?");
	if(load)
	{
		string fileName = term->getString("file name?");
		//To-be-implemented
		//if(fileName == "default")
		return;
	}

	//initializing field
	drawPile = Pile(true);
	drawPile.deckShuffle();
	trashPile = Pile(false);
	turn = 0;
	for (int i = 0; i < NBUILD; i++)
		buildPiles[i] = Pile(false);

	int stockSize = term->getNum(PROMPT_CNUM);

	//initializing the list of players
	int nPrs = term->getNum(PROMPT_PNUM); //TODO: 2-6
	for(int i = 0; i < nPrs; ++i)
	{
		bool isHuman = term->getBool("Is player #"
					+ static_cast<ostringstream*>( &(ostringstream() << (1+i)) )->str()
					+ " a human player?");
		string name = term->getString(PROMPT_NAME);
		Player* p;
		Pile* bp[4];
		for(int i = 0; i < NBUILD; i ++)
			bp[i] = &buildPiles[i];

		if(isHuman)
			p = new HumanPlayer(name, bp, drawPile, stockSize, *term);
			//The terminal passed in will take care of whether we want a human TUI or GUI
		else
			p = new AIPlayer(name, bp, drawPile, stockSize);
		players.push_back(p);
	}

	term->sendMessage(GAME_CREATED);

	//make it so that the history starts with this starting state
	history.push_back(writeState());

	//message
	message = HEALTHY;
}

