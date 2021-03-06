#include <cstdlib>
#include <sys/types.h>
#include <iostream>
#include <string>
//#include "computer1.h"
//#include "computer2.h"
#include "map.h"
#include "game.h"


using namespace std;

Game::Game() {
    // Used by the who is next function to select player.
    playerSelect = 1;
    // Changes to 2 then three and then one every three player turns
    // therefore I am calling rounds
    rounds = 1;
    Map();
    car1();
    car2();
    car3();
}

/**
 *
 */
bool Game::gameEnded()
{
    return isGameEnded;
}

bool Game::endTheGame()
{
    isGameEnded = true;
}

/**
 *
 */
Map& Game::getMap()
{
    // Print top line with numeric index of columns
    return myMap;
}

/**
*   Figure out who is next
*/
int Game::whoIsNext()
{
    if (rounds == 1)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 1;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 2;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 2;
            return 3;
        }
    }
    else if (rounds == 2)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 2;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 3;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 3;
            return 1;
        }
    }
      else if (rounds == 3)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 3;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 1;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 1;
            return 2;
        }
    }

}

/**
 *
 */
bool Game::moveIsLegal (int column, int row) {
    //return (column >= 0) && ( row >= 0)
    //&& (row < getMap().getNumberOfRows(column))
    //&& (column < getCookie().getNumberOfColumns(row));
}


