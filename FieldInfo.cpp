#include "FieldInfo.h"
#include <ostream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using std::ostream;
using std::ostringstream;
using std::setw;
using std::endl;

string FieldInfo::toString()
{
	ostringstream os;
	os<<"Buildpiles: ";
	for(int i = 0 ; i < NBUILD; ++i)
	{
		Pile myP = buildPiles[i];
		if(myP.getSize() != 0)
			os << std::left << myP.getTop().getData() << ",";
		else
			os << "empty, ";
	}
	os  << endl;


	for(Player pl : players){
		os << std::left << "Player: " << pl.name;
		os << std::left <<"     Stock Card: ";
		if(pl.stock.getTop().getData() != 0)
			os <<  setw(5)  << pl.stock.getTop().getData();
		else
			os << setw(5) << "SB";
		os << "Stock remaining: " << setw(5) << pl.stock.getSize();
		os << std::left <<"Hand: ";
	       	for(int i = 0; i < pl.hand.getSize(); i++)
		{
			if(pl.hand[i].getData() !=0)
	               		os << setw(3) << pl.hand[i].getData();
			else
				os << setw(3) << "SB";
		}
		os << "      " << endl;
		os  << "Discard Piles: ";
		for (int i = 0; i<4; i++)
	  	{
	               	if (pl.discard[i].getSize() != 0)
	                    os << pl.discard[i].getTop().getData() << ", ";
	               	else
	                    os << "Empty, ";
	  	}
	    os   << endl;

		}
		os << endl;

		return os.str();
}

FieldInfo::operator string()
{
	return toString();
}
