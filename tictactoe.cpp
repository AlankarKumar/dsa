#include <iostream>
#include <string>

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

class Game {
private:
  GameMoves grid[3][3];

public:
  Game()
      : grid{{GameMoves::B, GameMoves::X, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B}} {};
  GameMoves *getBoard() { return *this->grid; };
  void markMove(GameMoves m);
  void displayGrid(int gridSize);
};

void Game::markMove(GameMoves m) {}

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
  cout << endl;
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
    cout << endl;
  }
}

int main() {
  Game g;
  g.displayGrid(3);
  Player p1(GameMoves::X, "Alankar");
  p1.displayUserInfo();
  /*cout <<  *(g.getBoard() + 1)<< endl;*/
  return 0;
};
