#ifndef _CARD_H
#define _CARD_H

#include <cstdlib>
#include <string>

class Card
{
	private: 
		int data;
		bool isSkipBo;

	public:
		Card(int n);
		Card(int n, bool isSkipBo);
		//getter methods
		int getData() {return data;}
		bool getSkipBo() {return isSkipBo;}

		// mutators
		bool transform(Card prev); //changes skipBo into the next card
		bool transform(int prev);
		bool revert(); //changes skipbo back to their original value
		
		bool operator== (const Card &card);
		
		bool operator!= (const Card &card);
		
};

#endif
