#include "Knight.h"

int Knight::move(string dest)
{
    // Calculate source coordinates
    int srcRow = place[0] - 'a';  // Convert 'a'-'h' to 0-7
    int srcCol = place[1] - '1';  // Convert '1'-'8' to 0-7

    int dstRow = place[0] - 'a';  // Convert 'a'-'h' to 0-7
    int dstCol = place[1] - '1';  // Convert '1'-'8' to 0-7

    if(srcRow <= 8 && srcRow >= 0 && dstRow <= 8 && dstCol >= 0)
    {
        if (dest != this->place)
        {
           if (this->_board-< 
                [srcRow][srcCol] != NULL)
            {

            }
            else
            {
                return 
            }
        }
        else
        {
            return 7;
        }
    }
    else
    {
        return 5;
    }
}
