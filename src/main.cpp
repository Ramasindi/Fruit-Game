#include <iostream>
#include "arraylibrary.h"
#include <ctime>
using namespace std;
using namespace ArrayLibrary;

int main()
{
    srand(time(0));
    int fruitGrid[TOTAL_ROWS][TOTAL_COLS];
    initArray(fruitGrid);

    bool blnContinue = true;
    char chInput = '\0';

    do
    {
        menu(fruitGrid);
        chInput = getUserInput();
        movePlayer(fruitGrid,chInput);
      if(chInput == 'x' || chInput == 'X')
        blnContinue = false;

    }while(blnContinue);
    printArray(fruitGrid);

    return 0;
}
