#include "Player.h"
#include "FieldInfo.h"
#include "TUITerminal.h"
#include <cstdlib>
#include <string>
#include <vector>

using std::vector;

class Game {

private:
	bool isGui;
	static Terminal* term;
	
public: 
    //constructor
	Game(bool graphic = false);
	Game(bool graphic, bool useDefault);

	bool active = true; //if the game is in an ongoing, healthy state.
	void step(); //makes the game move forward a step
	string getMessage(); //see if the game has anything to report.

private:
	vector<FieldInfo> history;
	vector<Player*> players;
	Pile drawPile;
	Pile trashPile;
	Pile buildPiles[4];
	int turn;
	string message;
	const string HEALTHY = "The game is running in a healthy state!";
	const string ABNORMAL = "The game is not in a normal state.";
	const string ENDED = "The game has ended!";


	//saves current state of the game into a FieldInfo
	FieldInfo writeState();

	//take trash pile and put it into deck
	bool trashToDeck();

	//take completed build pile and put it into trash pile
	bool buildToTrash(int num); //specifies which build pile to empty

	void undo();
	void redo();

	//Save
	void save(std::string name);

	//Restore
	void restore(std::string filename);
};

