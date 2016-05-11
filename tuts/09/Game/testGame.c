#include "Game.h"
#include <stdlib.h>
#include <stdio.h>

void testThrowDice(void);
void testNewGame(void);
void testGetTurnNumber(void);


int main(int argc, char const *argv[])
{
	/* code */
	testThrowDice();
	testNewGame();
	testGetTurnNumber();

	return 0;
}

void testThrowDice(void) {

}

void testNewGame(void) {

}
void testGetTurnNumber(void) {
   
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;

   Game * myGame = newGame(disciplines, dice);
   assert(getTurnNumber(myGame) == -1);
   
   throwDice(myGame, 3);
   assert(getTurnNumber(myGame) == 0);

   
}

