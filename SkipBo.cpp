#include "Game.h"
#include <iostream>

int main(){

	Game g = Game(false); //let's just create debug games for now
	while(g.active)
		g.step();
	std::cout << g.getMessage();

	return 0;
}
