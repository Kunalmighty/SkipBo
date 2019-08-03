

CC = g++

CFLAGS = -std=c++11 -Wall -Wextra -pedantic -O0 #normal compile
#CXXFLAGA = -std=c++11 -Wall -Wextra -pedantic -O0 -g #for debugging

bin: SkipBo

test: SkipBoTest
	./SkipBoTest



Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) -c Card.cpp

Pile.o: Pile.cpp Pile.h
	$(CC) $(CFLAGS) -c Pile.cpp

Game.o: Game_Constructors.cpp Game_Misc.cpp Game_SaveAndRestore.cpp Game.h
	$(CC) $(CFLAGS) -c Game_Constructors.cpp Game_Misc.cpp Game_SaveAndRestore.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp

AIPlayer.o: AIPlayer.cpp AIPlayer.h
	$(CC) $(CFLAGS) -c AIPlayer.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) -c HumanPlayer.cpp

FieldInfo.o: FieldInfo.cpp FieldInfo.h
	$(CC) $(CFLAGS) -c FieldInfo.cpp

Terminal.o: Terminal.cpp Terminal.h
	$(CC) $(CFLAGS) -c Terminal.cpp

TUITerminal.o: TUITerminal.cpp TUITerminal.h
	$(CC) $(CFLAGS) -c TUITerminal.cpp

SkipBoTest: SkipBoTest.cpp Card.o Pile.o
	$(CC) $(CFLAGS) -O -o SkipBoTest SkipBoTest.cpp Card.o Pile.o

SkipBo: SkipBo.cpp Card.o Pile.o Player.o AIPlayer.o HumanPlayer.o FieldInfo.o Terminal.o TUITerminal.o Game.o
	$(CC) $(CFLAGS) -O -o SkipBo SkipBo.cpp Card.o Pile.o Player.o AIPlayer.o HumanPlayer.o FieldInfo.o Terminal.o TUITerminal.o Game_Constructors.o Game_SaveAndRestore.o Game_Misc.o


clean:
	rm -f *.o SkipBo SkipBoTest




