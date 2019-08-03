#include "AIPlayer.h"
#include <algorithm>
#include <vector>
AIPlayer::AIPlayer(string name, Pile* builds[4], Pile& drawPile, int stockSize)
	: Player(name, builds, drawPile, stockSize){}

void AIPlayer::play()
{
	//If anything is buildable from stock, build it
	for(int i = 0; i < 4; i++)
	{
		if(isBuildable(stock.getTop(), (*builds)[i]))
		{
			buildTo(i, stock.draw());
			return;
		}
	}

	//If anything is buildable from hand, build it.
	for(int i = 0; i < hand.getSize(); i++)
	for(int j = 0; j < 4; j++)
	if(isBuildable(hand[i], (*builds)[j]))
	{
		buildTo(j, hand.drawAt(i));
		return;
	}

	//TODO:pro "pathing" from discard to hand/stock goes here.

	//nothing is buildable. Let's discard.
	//TODO: discard card choice algorithm goes here.
	int discPos = 0; //right now always discarding first card.

	std::vector<int> discTops;
	for(int i = 0; i < 4; i++)
	{
		if(discard[i].getSize() == 0 ||
		std::find(discTops.begin(), discTops.end(), hand[discPos].getData()) != discTops.end())
		{discardCard(discPos, i);return;}
		else
			discTops.push_back(discard[i].getTop().getData());
	}

	discardCard(discPos, 0);
	return;

}
