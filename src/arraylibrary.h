#ifndef ARRAYLIBRARY_H_INCLUDED
#define ARRAYLIBRARY_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int TOTAL_ROWS = 10;
const int TOTAL_COLS = 30;

const int SPACE = 0;
const int FRUIT = 1;
const int PLAYER = 2;

const char ch_PLAYER = 'p';
const char ch_FRUIT = '@';
const char ch_SPACE = '.';
//error flag
const int ARRAY_ERROR = -1;
//chances
const int PER_FRUIT = 20;

namespace ArrayLibrary
{

    void initArray(int intArray[TOTAL_ROWS][TOTAL_COLS]);
    void printArray(int intArray[TOTAL_ROWS][TOTAL_COLS]);
    void captureInput(int intArray[TOTAL_ROWS][TOTAL_COLS]);
    int randomNumber(int intLower,int intUpper);
    void menu(int intArray[TOTAL_ROWS][TOTAL_COLS]);
    char getUserInput();
    void movePlayer(int intArray[TOTAL_ROWS][TOTAL_COLS],char chInput);
    void findPlayer(int intArray[TOTAL_ROWS][TOTAL_COLS],int& p_Row,int& p_Col);
    bool isValid(int d_Row,int d_Col);


}


#endif // ARRAYLIBRARY_H_INCLUDED
