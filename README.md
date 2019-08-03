This is the Skip-Bo game by Kunal Maiti.

The game features a smart AI and an undo/redo function. No GUI.

The game is broadly built on the following classes:

Card:
	We created a class called Card which stores an integer and a boolean value. 
    This object is used as the card in the game skip-bo. 
    The boolean allows us to mark cards which are skipBo cards. 

Pile:
	Pile is a class which contains a vector of cards. 
    We wrote a function to create a new deck and tested that all values were generated as expected. 

Player:
	Player is the superclass for HumanPlayer and AIPlayer. 
    It contains functions common to both.
	AIPlayer implements the smart AI.
	
Game:
	Game class contains information about the current session.
	 
	
FieldInfo (struct)
	This is used mainly to implement the undo/redo functionality.

The UI
In order to play the game, the player(s) make use of a detailed text based UI. 
- To enter the number for the pile, enter any number between 1 and 4
- To enter command, press the corresponding letter (lowercase)

	
