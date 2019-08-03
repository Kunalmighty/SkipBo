#include "HumanPlayer.h"
HumanPlayer::HumanPlayer(string name, Pile* builds[4], Pile& drawPile, int stockSize, Terminal& t)
	: Player(name, builds, drawPile, stockSize),
	  term(t) {this->isHuman = true;}

void HumanPlayer::play()
{
	string act = term.getString(PROMPT_ACT);
	while(act == "man")
	{
		term.sendMessage(MAN_ACT);
		act = term.getString(PROMPT_ACT);
	}

	switch(act[0])
	{
	case 'u': //undo
		term.request = TERM_UNDO;
		break;
	case 'r': //redo
		term.request = TERM_REDO;
		break;
	case 's':
		term.request = TERM_SAVE;
		break;
	case 't':
		buildTo(term.getNum(PROMPT_BUILD_POS) - 1, stock.draw());
		break;
	case 'h':
		if(term.getBool("Would you like to build?"))
			buildFromHand(term.getNum(PROMPT_BUILD_POS) - 1);
		else
			discardCard(term.getNum(PROMPT_HAND_POS) - 1,
					term.getNum(PROMPT_DISCARD_POS) - 1);
		break;
	case 'd':
		buildFromDiscard(term.getNum(PROMPT_BUILD_POS) - 1,
						term.getNum(PROMPT_DISCARD_POS) - 1);
		break;
	default:
		term.sendMessage(TERM_INVALID);
		break;
	}
}
