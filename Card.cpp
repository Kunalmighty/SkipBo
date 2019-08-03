#include "Card.h"

#include <cstdlib>
#include <string>

Card::Card(int n)
{
	isSkipBo = (n == 0);
	data = n;
}

Card::Card(int n, bool b)
{
	data = n;
	isSkipBo = b;
}

bool Card::transform(int prev)
{
	return transform(Card(prev));
}

bool Card::transform(Card prev) //changes skipBo into the next card
{
	if (isSkipBo)
	{
		data = prev.getData() + 1;
		return true;
	} 
	return false;
}

bool Card::revert() //changes skipBo back to original value
{
	if (isSkipBo)
	{
		data = 0;
		return true;
	}
	return false;
}

	
bool Card::operator== (const Card &card) {

    if (this->data == card.data && this->isSkipBo == card.isSkipBo)

        return true;

    else

        return false;

}



bool Card::operator!= (const Card &card) {

    if (this->data != card.data) 

        return true;
	
	else 
        
        return false;

    }
   


