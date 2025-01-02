#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Create a class for each game board
// create a 2d array as the board
// create methods that represent move in the game
// create a method that creates the boad on the terminal for the user
// create a method that numbers the cells of the board
// create a method that ask the user for an input to which cell.board
// Create a method to check the winning condition
// Create a player class
// Create the methods for actions of the user , that is make the move

enum class GameMoves { X, O, B };
const int gridSize = 3;
class Game {
private:
  GameMoves grid[3][3];

public:
  Game()
      : grid{{GameMoves::B, GameMoves::X, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B}} {};
  GameMoves *getBoard() { return *this->grid; };
  void markMove(GameMoves m, string cell);
  bool checkValidMove(string cell);
  void displayGrid(int gridSize);
  vector<string> getEmptyCells();
};
// Return a list of all empty cells in the grid
vector<string> Game::getEmptyCells() {
  vector<string> emptyCells;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (grid[i][j] == GameMoves::B) {
        emptyCells.push_back(to_string(i) + to_string(j));
      };
    }
  };
  for (string x : emptyCells) {
    cout << x << " - ";
  }
  return emptyCells;
};

// Check if the cell value entered by the user is  a valid cell on the grid
bool Game::checkValidMove(string cell) {
  if (cell.size() != 2)
    return false;
  if (stoi(cell) > stoi(to_string(gridSize - 1) + to_string(gridSize - 1)))
    return false;
  vector<string> emptyCells = this->getEmptyCells();
  if (emptyCells.size() == 0)
    return false;
  bool isCellEmpty = true;
  for (string value : emptyCells) {
    if (value == cell) {
      isCellEmpty = true;
      break;
    } else {
      isCellEmpty = false;
    }
  };
  if (isCellEmpty == false)
    return false;
  return true;
};

// Take input from the user and mark the move on the board
void Game::markMove(GameMoves m, string cell) {

};

// Overload the << operator to display the enum values
ostream &operator<<(ostream &os, GameMoves move) {
  switch (move) {
  case GameMoves::X:
    os << "X";
    break;
  case GameMoves::O:
    os << "O";
    break;
  case GameMoves::B:
    os << " ";
    break;
  default:
    break;
  }
  return os;
}

class Player {
private:
  string playerName;
  GameMoves selection;

public:
  Player(GameMoves userSelection, string name) {
    this->selection = userSelection;
    this->playerName = name;
  };
  void displayUserInfo() {
    cout << playerName << endl;
    cout << selection << endl;
  };
};

// TODO:  Need to do beautification of the terminal display
void Game::displayGrid(int gridSize) {
  // displaying the first line of grid
  for (int i = 0; i < gridSize; i++)
    cout << "----";
  cout << "-" << endl;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      switch (grid[i][j]) {
      case GameMoves::X:
      case GameMoves::O:
        cout << "| " << grid[i][j] << " ";
        break;
      case GameMoves::B:
        cout << "| " << i << j;
        break;
      default:
        cout << "|  ";
        break;
      }
    }
    cout << "|" << endl;
    for (int i = 0; i < gridSize; i++)
      cout << "----";
    cout << "-" << endl;
  }
}

int main() {
  Game g;
  g.displayGrid(3);
  Player p1(GameMoves::X, "Alankar");
  p1.displayUserInfo();
  string cell;
  cout << "Enter your cell number from the above grid : ";
  cin >> cell;
  bool isValidCell = g.checkValidMove(cell);
  if (!isValidCell) {
    cout << "Invalid cell number entered" << endl;
  } else {
    // mark the move
  };
  /*cout <<  *(g.getBoard() + 1)<< endl;*/
  return 0;
};
