#include <string>
#include "Player.h"
#include <iostream>
#include <stdexcept>
#include <exception>
using std::string;

Player::Player(string s, Pile* buildPiles[4], Pile& drawPile, int stockSize)
	: name(s), isActive(false), isHuman(false)
{

	for(int i = 0; i < 4; ++i)
		builds[i] = buildPiles[i];
	for(int j = 0; j < stockSize; ++j)
		stock += drawPile.draw();
}

void Player::discardCard(int handPos, int pileNum)
{
	discard[pileNum] += hand.drawAt(handPos);
	isActive = false;
}

void Player::buildTo(int pile, Card c)
{
	Pile& b = *builds[pile];
	if(b.getSize() != 0)
		c.transform(builds[pile]->getTop());
	else
		c.transform(0);

	*builds[pile] += c;
}
	
Card Player::getTopStock()
{	
	return stock.getTop();
}

//"draw" means remove AND return.
Card Player::drawTopStock() 
{
	return stock.draw();
}

//get the i-th discard pile's top card
Card Player::getTopDisc(int i)
{
	return discard[i].getTop();
}

Card Player::drawTopDisc(int i) 
{
	return discard[i].draw();
}

void Player::buildFromHand(int nPile)
{
	//non-skip-bos take priority on building
	for(int i = 0; i < hand.getSize(); ++i)
		if(!hand[i].getSkipBo() && isBuildable(hand[i], *builds[nPile]))
		{
			buildTo(nPile, hand.drawAt(i));
			return;
		}
	//if no non-skip-bos are found, build with a skip-bo
	for(int i = 0; i < hand.getSize(); ++i)
		if(isBuildable(hand[i], *builds[nPile]))
		{
			buildTo(nPile, hand.drawAt(i));
			return;
		}
	//if none, throw an exception
	throw std::invalid_argument(ERR_CANT_BUILD_FROM_HAND);
}

void Player::buildFromDiscard(int to, int from)
{
	if(isBuildable(discard[from].getTop(), *builds[to]))
	{
		buildTo(to, discard[from].draw());
		return;
	}

	//if not buildable, throw an exception
	throw std::invalid_argument(ERR_CANT_BUILD_FROM_HAND);
}

bool Player::isBuildable(Card c, Pile p)
{
	return ((p.getSize() == 0 && c.getData() == 1)
		|| c.getSkipBo() == true
		|| (p.getSize() != 0 &&
			p.getTop().getData() - c.getData() == -1));
}

