#include "maze.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


void get_identity(string my_id[])
{
  my_id[0] = "djbn65";
  my_id[1] = "12534397";
  cout << "University Username: " << my_id[0] << endl;
  cout << "Univeristy SID: " << my_id[1] << endl;

  return;
}


string * build_matrix(int rows)
{
  string* maze = new string[rows]; //dynamically allocate an array of strings to hold the maze

  return maze;
}


void fill_matrix(string *matrix, int rows, string *matrix_to_use)
{
  for (int i = 0; i < rows; i++) //read line by line and shove each line into the matrix[i] [position]
    matrix[i] = matrix_to_use[i];

  return;
}


void print_matrix(string *matrix, int rows)
{
  for (int i = 0; i < rows; i++) //print each line of the matrix passed in, which is the maze
    cout << matrix[i] << endl;

  return;
}


void delete_matrix(string *matrix, int rows)
{
  delete[] matrix;

  return;
}


void find_start(string *matrix, int rows, int &x, int &y)
{
  for (x = 0; x < rows; x++)
    for (y = 0; unsigned(y) < matrix[x].length(); y++) //loop through the matrix to find the N character
      if (matrix[x][y] == 'N')
        return;

  return;
}

bool find_exit(string *matrix, int x, int y)
{
  if (at_end(matrix, x, y)) //Base case that checks for the E character
    return true;

  if (matrix[x][y] != 'N') //Don't replace the N with an @ after first move
    matrix[x][y] = '@';

  for (int i = 0; i < 4; i++) //Loops through all directions to check if any direction is possible
  {
    if(valid_move(matrix, x, y, direction(i)))
    {
      if (i == NORTH)
        if(find_exit(matrix, x-1, y))  //recursive part that checks the next space after verifying it is valid to move there
          return true;
      if (i == EAST)
        if(find_exit(matrix, x, y+1))
          return true;
      if (i == SOUTH)
        if(find_exit(matrix, x+1, y))
          return true;
      if (i == WEST)
        if(find_exit(matrix, x, y-1))
          return true;
    }
  }

  if (matrix[x][y] != 'N') //Undoes the @ assigning as long as the tile is not an N
    matrix[x][y] = ' ';

  return false;
}


bool at_end(string *matrix, int x, int y)
{
  return matrix[x][y] == 'E'; //check whether x and y passed in are the E character
}

bool valid_move(string *matrix, int x, int y, direction d)
{
  switch(d)
  {
    case NORTH:
      if (matrix[x-1][y] == ' ' || matrix[x-1][y] == 'E')
        return true;
      break;
    case EAST:
      if (matrix[x][y+1] == ' ' || matrix[x][y+1] == 'E')
        return true;
      break;
    case SOUTH:
      if (matrix[x+1][y] == ' ' || matrix[x+1][y] == 'E')
        return true;
      break;
    case WEST:
      if (matrix[x][y-1] == ' ' || matrix[x][y-1] == 'E')
        return true;
      break;
  }
  return false;
}
