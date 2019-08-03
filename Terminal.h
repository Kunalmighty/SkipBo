#ifndef _TERMINAL_H
#define _TERMINAL_H

#define TERM_UNDO 'u'
#define TERM_REDO 'r'
#define TERM_SAVE 's'
#define TERM_STOCK 't'
#define TERM_HAND 'h'
#define TERM_DISC 'd'
#define TERM_NONE '\0'
#define TERM_INVALID "Invalid input.\n"
#define GAME_CREATED "The game has been created successfully!\n"
#define PROMPT_NAME "What's the name of this player?\n"
#define PROMPT_PNUM "How many players are there in the game?\n"
#define PROMPT_CNUM "How many cards are there per player?\n"
#define PROMPT_ACT "What would you like to do? man for manual\n"
#define PROMPT_CARD_POS "Which card? Enter the position\n"
#define PROMPT_HAND_POS "Which card from your hand?\n"
#define PROMPT_BUILD_POS "Which pile would you like to build to?\n"
#define PROMPT_DISCARD_CARD "Which card to discard?\n"
#define PROMPT_DISCARD_POS "Which discard pile?\n"
#define MAN_ACT "Undo: u, redo: r, Save: s Load: l pick card from hand: h, pick card from stock: s, pick card from discard: d\n"
#define ERR_CANT_BUILD_FROM_HAND "No possible builds on hand found.\n"
#include <string>
#include "FieldInfo.h"
using std::string;

class Terminal
{
public:
	char request;
	Terminal();

	virtual ~Terminal() {};
	virtual void sendMessage(string message) =0;
	virtual void sendFieldInfo(FieldInfo f) =0;
	virtual string getString(string message) =0;
	virtual bool getBool(string message) =0;
	virtual int getNum(string message) =0;
	virtual void notifyTurn(string name) =0;
	virtual void printAllPlayerInfo(std::vector<Player*>) =0;
	virtual void refreshStatus(Pile hand, Pile stock, Pile discard[4]) =0;

};
#endif
