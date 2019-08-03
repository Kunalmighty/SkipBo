#ifndef _PLAYER_H
#define _PLAYER_H
#define NBUILD 4
#define NDISC 4
#define ERR_CANT_BUILD_FROM_HAND "No possible builds on hand found.\n"
#include "Pile.h"
#include <string>
using std::string;

class Player{
public:
	string name;
	Pile stock;
	Pile hand;
	Pile discard[4];
	Pile* builds[4];
	Player(string name, Pile* builds[4], Pile& drawPile, int stockSize); //automatically draws into the stock
	void play();
	//accessors
	std::string getName() const {return name; };
	bool isActive;
	bool isHuman;

protected:
	void discardCard(int handPos, int pileNum);
	void buildFromHand(int nPile);
	void buildFromDiscard(int to, int from);
	Card getTopStock();
	Card drawTopStock(); //"draw" means remove AND return.
	Card getTopDisc(int i); //get the i-th discard pile's top card
	Card drawTopDisc(int i);
	void buildTo(int pile, Card c);
	static bool isBuildable(Card c, Pile p);
};

#endif
