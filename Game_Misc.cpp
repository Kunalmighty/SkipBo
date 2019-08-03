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


FieldInfo Game::writeState()
{
	FieldInfo fi;
	fi.turn = turn;
	fi.trashPile = trashPile;
	fi.drawPile = drawPile;
	for(int i = 0 ; i < 4; ++i)
		fi.buildPiles[i] = buildPiles[i];
	for(Player* p : players)
		fi.players.push_back(*p);

	return fi;
}

void Game::step()
{
	Player& pl = *players[turn];
	//if it's the beginning of the player's turn, draw up to 5
	if(!pl.isActive || pl.hand.getSize() == 0)
	{
		while(pl.hand.getSize() < 5)
		{
			if(drawPile.getSize() == 0)
				trashToDeck();
			pl.hand += drawPile.draw();
		}
		pl.isActive = true;
	}

	term->notifyTurn(pl.name);
	
	FieldInfo cf = writeState(); //cf = current field
	history.push_back(cf);
	term->sendFieldInfo(cf);
	
	if(pl.isHuman)
		static_cast<HumanPlayer*>(&pl)->play();
	else
		static_cast<AIPlayer*>(&pl)->play();

	if(term->request == TERM_UNDO)
		undo();
	if(term->request == TERM_REDO)
		redo();
	if(term->request == TERM_SAVE)
		{
			save(term->getString("Please enter the name of the save file.\n"));
		}
	term->request = TERM_NONE;


	if(!pl.isActive) //if the player just finished their turn (discarded a card)
		turn = (turn+1) % players.size();

	for(int i = 0; i < NBUILD; ++i)
		buildToTrash(i); //This will trash it only if it's completely built

	if(pl.stock.getSize() == 0)
	{
		active = false;
		term->sendMessage(pl.getName() + " won!");
		message = ENDED;
	}
	if(!pl.isHuman)
	for(int i=0; i<10000000;i++)
	{
	
	}
}


string Game::getMessage()
{
	return message;
}



bool Game::trashToDeck()
{
	if (trashPile.getSize() == 0 || drawPile.getSize() != 0) //only executes if empty deck and nonempty discard
	{
		return false;
	}
	for (int i = 0; i < trashPile.getSize(); i++)
	{
		drawPile + trashPile.cardAt(i);
	}
	trashPile.empty(); //empties the trash pile
	drawPile.deckShuffle();
	return true;
}

bool Game::buildToTrash(int num)
{
	if (buildPiles[num].getSize() != 12) //only empty buildPile if 1-12 completed
	{
		return false;
	}

	for (int i = 0; i < 12; i++) //reverts each card to original number. then adds to trashPile
	{
		trashPile + buildPiles[num].cardAt(i).revert();
	}
	buildPiles[num].empty();
	return true;
}

void Game::undo()
{
	//TODO
}

void Game::redo()
{
	//TODO
}

