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
  string status;

public:
  Game()
      : grid{{GameMoves::B, GameMoves::B, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B},
             {GameMoves::B, GameMoves::B, GameMoves::B}} {
    status = "live";
  };
  GameMoves *getBoard() { return *this->grid; };
  void markMove(GameMoves m, string cell);
  string getStatus() { return this->status; };
  bool checkValidMove(string cell);
  void displayGrid();
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
  grid[stoi(cell.substr(0, 1))][stoi(cell.substr(1, 1))] = m;
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
  Player() {};
  void initializePlayer(GameMoves userSelection, string name) {
    this->selection = userSelection;
    this->playerName = name;
  };
  void displayUserInfo() {
    cout << playerName << endl;
    cout << selection << endl;
  };
  string getPlayerName() { return this->playerName; }
  GameMoves getPlayerSelection() { return this->selection; }
};

// TODO:  Need to do beautification of the terminal display
void Game::displayGrid() {
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

vector<Player> createPlayers(int numberOfPlayers) {
  string playerName;
  string playerSelection;
  vector<Player> players;
  for (int i = 0; i < numberOfPlayers; i++) {
    players.push_back(Player());
  }
  for (int i = 0; i < numberOfPlayers; i++) {
    cout << "Enter Player" << i + 1 << " name : ";
    cin >> playerName;
    cout << "Which Symbol do you want to play with X or O ? : ";
    cin >> playerSelection;
    players[i].initializePlayer(
        playerSelection == "X" ? GameMoves::X : GameMoves::O, playerName);
  }
  return players;
};

// Configure game
Game initializeGame() {
  Game g;
  return g;
}

void initiateGame() {
  Game game = initializeGame();
  int MAX_MOVES = 9;
  int moveCounter = 0;
  vector<Player> players = createPlayers(2);
  while (game.getStatus() != "over" && moveCounter < MAX_MOVES) {
    for (int i = 0; i < players.size(); i++) {
      moveCounter++;
      string userInputCell;
      game.displayGrid();
      cout << players[i].getPlayerName() << "\'s "
           << "turn....Please enter the cell number in which you want to play";
      cin >> userInputCell;
      game.markMove(players[i].getPlayerSelection(), userInputCell);
      game.displayGrid();
      cout << "............Move successfully marked............" << endl;
      cout << "\033[2J\033[H";
    }
  }
}

int main() {
  initiateGame();
  // Game g;
  // g.displayGrid();
  // string cell;
  // cout << "Enter your cell number from the above grid : ";
  // cin >> cell;
  // bool isValidCell = g.checkValidMove(cell);
  // if (!isValidCell) {
  //   cout << "Invalid cell number entered" << endl;
  // } else {
  //   cout << "Marking move ...." << endl;
  //   g.markMove(GameMoves::X, cell);
  //   g.displayGrid();
  // };

  /*cout <<  *(g.getBoard() + 1)<< endl;*/
  return 0;
};
