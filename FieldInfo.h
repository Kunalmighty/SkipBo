#ifndef _FIELDINFO_H
#define _FIELDINFO_H

#include <vector>
#include <string>
#include "Pile.h"
#include "Player.h"
using std::vector;
using std::string;

class FieldInfo
{
public:
	int turn;
	Pile drawPile;
	Pile trashPile;
	Pile buildPiles[4];
	vector<Player> players;
	string toString();
	operator string();
};

#endif
