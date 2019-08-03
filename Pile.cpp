#include "Pile.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


Pile::Pile(bool isDrawPile) 
{
	for(int k = 0; k < 3; ++k)
	if (isDrawPile) //constructs the drawPile
	{
		for (int i = 1; i <= 12; i++) //iterates through cards with numbers 1-12
		{
			for (int j = 1; j <= 12; j++) //adds 12 of each card
			{
				Card *temp = new Card(i);
				cards.push_back(*temp);
			}
		}
		for (int i = 1; i <= 18; i++) //adds 18 skipbo cards
		{
			Card *temp = new Card(0);
			cards.push_back(*temp);
		}
	}
}

void Pile::deckShuffle() //shuffles the pile
{
	std::srand ( unsigned ( std::time(0) ) );
  	std::random_shuffle ( cards.begin(), cards.end() );
}

Card Pile::cardAt(int num)
{
	return cards.at(num);
}

void Pile::empty()
{
	cards.clear();
}

void Pile::removeTop()
{
	cards.pop_back();
}

void Pile::operator+ (const Card &c)
{
	cards.push_back(c);
}

void Pile::operator+= (const Card &c)
{
	*this + c;
}

Card Pile::operator[](int i)
{
	return cardAt(i);
}

Card Pile::draw()
{
	Card c = (*this)[getSize() - 1];
	removeTop();
	return c;
}

Card Pile::getTop()
{
	return (*this)[getSize() - 1];
}

Card Pile::drawAt(int i)
{
	std::swap(cards[i], cards[cards.size()-1]);
	return draw();
}
