#include "Pile.h"
#include "Player.h"
#include <string>
using std::string;

class AIPlayer : public Player
{
public:
	AIPlayer(string name, Pile* builds[4], Pile& drawPile, int stockSize);
	void play();
};
