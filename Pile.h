#ifndef _PILE_H
#define _PILE_H
#include "Card.h"

#include <cstdlib>
#include <string>
#include <vector>

class Pile
{ 
	private:
		std::vector<Card> cards;


	public: //constructors
		
		Pile(bool isDrawPile = false); //creates an empty pile is false, otherwise constructs an ordered drawPIle

		//void display(); //prints contents of the pile
		void deckShuffle(); 
		void empty(); 
		Card cardAt(int num); //returns the card at a particular position in the pile
		int getSize() {return cards.size();}
		Card getTop();
		void operator+ (const Card &c);
		void operator+= (const Card &c);
		Card operator[](int i);
		void removeTop();
		Card drawAt(int); //NOT ORDER-PRESERVING
		Card draw(); //removes the top card and returns it.
};
#endif
