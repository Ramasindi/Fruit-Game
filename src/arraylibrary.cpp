#include "arraylibrary.h"
namespace ArrayLibrary
{

    void initArray(int intArray[TOTAL_ROWS][TOTAL_COLS])
    {
        for(int r = 0;r < TOTAL_ROWS ;r++)
        {

            for(int c =0;c < TOTAL_COLS ;c++)
            {
                if(randomNumber(1,100) <= PER_FRUIT)
                    intArray[r][c] = FRUIT;
                else
                    intArray[r][c] = SPACE;
            }
        }
        int p_Row = randomNumber(0,TOTAL_ROWS - 1);
        int p_Col = randomNumber(0,TOTAL_COLS - 1);
        while(intArray[p_Row][p_Col] != SPACE)
        {
              p_Row = randomNumber(0,TOTAL_ROWS - 1);
              p_Col = randomNumber(0,TOTAL_COLS - 1);
        }
        intArray[p_Row][p_Col] = PLAYER;
    }
    void printArray(int intArray[TOTAL_ROWS][TOTAL_COLS])
    {
        system("cls");
        for(int r = 0; r < TOTAL_ROWS;r++)
        {
            for(int c =0;c < TOTAL_COLS;c++)
                {
                    switch(intArray[r][c])
                    {
                    case SPACE:
                        cout << ch_SPACE;
                        break;
                    case FRUIT:
                        cout << ch_FRUIT;
                        break;
                    case PLAYER:
                        cout << ch_PLAYER;
                        break;
                    default:
                        cerr << "Oops...An Error Occured";
                        exit(ARRAY_ERROR);
                    }

                }
        cout << endl;
        }
    }
    void captureInput(int intArray[TOTAL_ROWS][TOTAL_COLS])
    {
        for(int r =0;r < TOTAL_ROWS;r++)
        {
            for(int c =0;c <TOTAL_COLS;c++)
            {
           intArray[r][c] = randomNumber(1,9);
            }
        }
    }

    //generating random number given a range
    int randomNumber(int intLower,int intUpper)
    {
        int range = intUpper - intLower + 1;
        int random = rand() % range + intLower;
        return random;
    }
    void menu(int intArray[TOTAL_ROWS][TOTAL_COLS])
    {
        system("cls");
        printArray(intArray);
        cout << endl;
        cout << "w - Move Up" << endl
             << "s - Move Down" << endl
             << "a - Move Left" << endl
             << "d - Move Right" << endl
             << "x - Exit" << endl
             << "Please select the direction you wish to move to: " << endl;
    }
    char getUserInput()
    {
        bool blnValid = false;
        char chInput = '\0';
        while(!blnValid)
        {
        cin >> chInput;
        switch(chInput)
        {
    case 'w':
    case 'W':
    case 's':
    case 'S':
    case 'a':
    case 'A':
    case 'd':
    case 'D':
    case 'x':
    case 'X':
        blnValid = true;
        break;
    default:
        cerr << "Invalid Selection. Please retry: \n";
        blnValid = true;
        break;
        }
        }
        return chInput;

    }
      void movePlayer(int intArray[TOTAL_ROWS][TOTAL_COLS],char chInput)
      {
          int p_Row = -1;
          int p_Col = -1;
          findPlayer(intArray,p_Row,p_Col);
          int d_Row = p_Row;
          int d_Col = p_Col;

          switch(chInput)
          {
            case 'w':
            case 'W':
                d_Row--;
                break;
            case 's':
            case 'S':
                d_Row++;
                break;
            case 'a':
            case 'A':
                d_Col--;
                break;
            case 'd':
            case 'D':
                d_Col++;
                break;
          }
          if(isValid(d_Row,d_Col))
          {
              intArray[p_Row][p_Col] = SPACE;
              intArray[d_Row][d_Col] = PLAYER;
          }
      }
      void findPlayer(int intArray[TOTAL_ROWS][TOTAL_COLS],int& p_Row,int& p_Col)
      {
          for(int r = 0; r < TOTAL_ROWS; r++)
          {
              for(int c =0; c < TOTAL_COLS; c++)
              {
                  if(intArray[r][c] == PLAYER)
                  {
                      p_Row = r;
                      p_Col = c;
                      return;
                  }
              }
          }
      }
      bool isValid(int d_Row, int d_Col)
      {
          if(d_Row >=0 && d_Row < TOTAL_ROWS &&
             d_Col >=0 && d_Col < TOTAL_COLS)
          return true;
          return false;
      }
}
