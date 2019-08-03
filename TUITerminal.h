#include "Terminal.h"
#include "Player.h"
#include <vector>
#include <iostream>

using std::istream;
using std::ostream;

class TUITerminal : public Terminal
{
public:
	TUITerminal(istream& is, ostream& os);
	void sendMessage(string message);
	void sendFieldInfo(FieldInfo fi);
	string getString(string message);
	int getNum(string message);
	bool getBool(string message);
	void notifyTurn(string name);
	void printAllPlayerInfo(std::vector<Player*>);
	void refreshStatus(Pile hand, Pile stock, Pile discard[4]);
private:
	istream& is;
	ostream& os;
};

