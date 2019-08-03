#include "Game.h"
#include "Card.h"

#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using std::cout;
using std::endl;

using namespace std;

class SkipBoTest {

public:

    static void CardTest() {

    	// build a few cards with constructor

    	// and test for contents

        Card c1(1);
        assert(c1.getData() == 1);


        Card c2(2);
        assert(c2.getData() == 2);



        Card c3(0);
        assert(c3.getSkipBo());


        // test mutators

        assert(!(c2.transform(c1)));
        assert(c3.transform(c2));

        assert(!(c1.revert()));
        assert(c3.revert());

    }



    static void PileTest() {

    	// build a few piles with constructor
    	// and test for type and contents

    	Pile p1(true);
    	assert(p1.getSize()==162);

    	Card c4 = p1.cardAt(36);
	Card c5 = p1.cardAt(37);
        Card c6 = p1.cardAt(80);
	assert(c4==c5);
	assert(c4!=c6);
	for (int i=0; i<144; i++)
		assert(p1.cardAt(i).getData() == i/12 + 1);
    	for (int i=144; i<162; i++)
		assert(p1.cardAt(i).getSkipBo());
	p1.deckShuffle(); 
	//Makes sure that deck is shuffled
        while (p1.cardAt(36)==c4 || p1.cardAt(37)==c5 || p1.cardAt(80)==c6) {
        p1.deckShuffle();
        }

        assert(p1.cardAt(36)!=c4);
	p1 + c4;
	cout << p1.getSize();
	assert(p1.cardAt(162).getData() == 4);
	p1 + c5;
	assert(p1.cardAt(163).getData() == 4);
	
	p1.empty();
	assert(p1.getSize() == 0); 
    }



    static void PlayerTest() {

    	//Player pl1("Kunal");
    	//assert(pl1.getName() == "Kunal");

    }



    static void GameTest() {


    }

};

int main(void) {

    cout << "Testing SkipBo. *Fingers crossed*" << endl;

    SkipBoTest::CardTest();

    SkipBoTest::PileTest();

    //SkipBoTest::PlayerTest();

    //SkipBoTest::GameTest();

    cout << "All Skipbo tests passed! I know.. we're surprised too!" << endl;

}







