#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H
#include "Terminal.h"
#include "Player.h"
#include <string>
using std::string;

class HumanPlayer : public Player
{
public:
	HumanPlayer(string name, Pile* builds[4], Pile& drawPile, int stockSize, Terminal& t);
	void play();
private:
	Terminal& term;
};
#endif
