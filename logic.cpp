#include "logic.h"
#include <cstdlib>
#include <iostream>

bool **create_board(const int height, const int width) {
  bool **board = (bool **)malloc(sizeof(bool *) * height);
  for (int i = 0; i < height; i++) {
    board[i] = (bool *)malloc(sizeof(bool) * width);
  }
  return board;
}

void destroy_board(bool **board, const int height) {
  for (int i = 0; i < height; ++i) {
    free(board[i]);
  }
  free(board);
}

void place_ships(bool **board, const int shipcount, const int width,
                 const int height) {
  // First I want to declare random positions 
  
  int xpos;
  int ypos;

  int shipsleft = shipcount;

  //Afterwards have a for loop to iterate for how many ships there will be
  for(int i = 0; i < shipcount; i++)
  {
    xpos = rand()%(width - 1) + 1;
    ypos = rand()%(height - 1) + 1;
    //Checks to see if there is a ship there already
    if (board[xpos,ypos] != true && shipsleft != 0)
    {
      //Makes the position of the ship true
      board[xpos, ypos] = true;
      shipsleft--;
    }
    else
    {
      //If there is a ship there already then reiterate through the for loop
      i--;
    }

  }
  
}

void find_ships(bool **board, const int width, const int height) {
  // TODO implement
  // The most efficient way that I can think of would be to iterate through
  // the array until it finds a near miss, then once it does it checks all
  // adjacent slots not previously checked until it returns a hit, 
}

ResponseType guess(bool **board, const int x, const int y) {
  // TODO implement this

  return ResponseType::HIT;
}
