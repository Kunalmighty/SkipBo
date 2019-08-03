#include "TUITerminal.h"
#include <iomanip>
using std::setw;
using std::endl;

TUITerminal::TUITerminal(istream& is, ostream& os) : is(is), os(os){}

void TUITerminal::sendMessage(string message)
{
	os << message;
}

void TUITerminal::sendFieldInfo(FieldInfo fi)
{
	os << (string)fi;
}

string TUITerminal::getString(string message)
{
	os << message;
	string str;
	is >> str;
	return str;
}
int TUITerminal::getNum(string message)
{
	os << message;
	int i;
	is >> i;
	return i;
}

bool TUITerminal::getBool(string message)
{
	while(true)
	{
		os << message << " y/n";
		char c;
		is >> c;
		if(c == 'y')
			return true;
		else if (c == 'n')
			return false;
		else
			os << "Input invalid." << endl;
	}
	return false;
}

void TUITerminal::refreshStatus(Pile hand, Pile stock, Pile discard[4])
{
	if(hand.getSize() != 5)
		return; //In TUI, only do this if the person has a full hand, to reduce spam.
	os << "Hand: ";
	for(int i = 0; i < hand.getSize(); ++i)
		os << hand[i].getData() << ", ";
	os << "\b\b";
	os << endl << "top stock: " << stock[stock.getSize() - 1].getData() << endl;

	os << "Discard Pile: ";
	for (int i = 0; i<4; i++)
	{
		if (discard[i].getSize() != 0)
			os << discard[i].getTop().getData() << ", ";
		else
			os << "Empty, ";
	}
	os  << endl;
}

void TUITerminal::notifyTurn(string name)
{
	sendMessage("==============================\nIt's " + name + "'s move.\n");
}

void TUITerminal::printAllPlayerInfo(std::vector<Player*> players)
{
	for(Player *p : players){
		Player& pl = *p;
		os << std::left << "Player: " << setw(18) << pl.name;
		os << std::left <<"Stock Card: "<< setw(5)  << pl.stock[pl.stock.getSize() - 1].getData();
		os << "Stock remaining: " << setw(5) << pl.stock.getSize();
		os << std::left <<"Hand: ";
        	for(int i = 0; i < pl.hand.getSize(); i++)
                	os << std::left << setw(3) << pl.hand[i].getData();
		os << "      ";
		os  << "  Discard Piles:";
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
}
