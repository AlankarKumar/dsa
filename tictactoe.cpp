#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
  void setStatus(string status) { this->status = status; }
  bool checkValidMove(string cell);
  void displayGrid();
  vector<string> getEmptyCells();
  bool checkForResult();
  bool isGameOver();
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

bool Game::checkForResult() {
  bool isGameWon = false;
  // row travesal
  for (int i = 0; i < gridSize; i++) {
    if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] &&
        grid[i][0] != GameMoves::B && grid[i][1] != GameMoves::B &&
        grid[i][2] != GameMoves::B)
      return true;
  }

  // column traversal
  for (int j = 0; j < gridSize; j++) {
    if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j] &&
        grid[0][j] != GameMoves::B && grid[1][j] != GameMoves::B &&
        grid[2][j] != GameMoves::B)
      return true;
  }

  // diagonal traversal
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] &&
      grid[0][0] != GameMoves::B && grid[1][1] != GameMoves::B &&
      grid[2][2] != GameMoves::B)
    return true;
  if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] &&
      grid[0][2] != GameMoves::B && grid[1][1] != GameMoves::B &&
      grid[2][0] != GameMoves::B)
    return true;

  return isGameWon;
}

bool Game::isGameOver() {
  bool isGameOver = false;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (grid[i][j] == GameMoves::B) {
        isGameOver = false;
        break;
      } else {
        isGameOver = true;
      }
    }
  }
  return isGameOver;
}

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
           << "turn....Please enter the cell number in which you want to play "
              ": ----->>> ";
      cin >> userInputCell;
      game.markMove(players[i].getPlayerSelection(), userInputCell);
      game.displayGrid();
      cout << "............Move successfully marked............" << endl;
      cout << "\033[2J\033[H";
      bool checkResult = game.checkForResult();

      if (!checkResult) {
        bool isGameOver = game.isGameOver();
      };
      if (checkResult) {
        cout << "Congratulations " << players[i].getPlayerName()
             << " you have won the game" << endl;
        game.displayGrid();
        game.setStatus("over");
        break;
      }
    }
  }
}

void diplayGameArt() {
  cout << R"(
    
    
    
    
    
TTTTTTTTTTTTTTTTTTTTTTT  iiii                           TTTTTTTTTTTTTTTTTTTTTTT                                        TTTTTTTTTTTTTTTTTTTTTTT                                  
T:::::::::::::::::::::T i::::i                          T:::::::::::::::::::::T                                        T:::::::::::::::::::::T                                  
T:::::::::::::::::::::T  iiii                           T:::::::::::::::::::::T                                        T:::::::::::::::::::::T                                  
T:::::TT:::::::TT:::::T                                 T:::::TT:::::::TT:::::T                                        T:::::TT:::::::TT:::::T                                  
TTTTTT  T:::::T  TTTTTTiiiiiii     cccccccccccccccc     TTTTTT  T:::::T  TTTTTTaaaaaaaaaaaaa      cccccccccccccccc     TTTTTT  T:::::T  TTTTTTooooooooooo       eeeeeeeeeeee    
        T:::::T        i:::::i   cc:::::::::::::::c             T:::::T        a::::::::::::a   cc:::::::::::::::c             T:::::T      oo:::::::::::oo   ee::::::::::::ee  
        T:::::T         i::::i  c:::::::::::::::::c             T:::::T        aaaaaaaaa:::::a c:::::::::::::::::c             T:::::T     o:::::::::::::::o e::::::eeeee:::::ee
        T:::::T         i::::i c:::::::cccccc:::::c             T:::::T                 a::::ac:::::::cccccc:::::c             T:::::T     o:::::ooooo:::::oe::::::e     e:::::e
        T:::::T         i::::i c::::::c     ccccccc             T:::::T          aaaaaaa:::::ac::::::c     ccccccc             T:::::T     o::::o     o::::oe:::::::eeeee::::::e
        T:::::T         i::::i c:::::c                          T:::::T        aa::::::::::::ac:::::c                          T:::::T     o::::o     o::::oe:::::::::::::::::e 
        T:::::T         i::::i c:::::c                          T:::::T       a::::aaaa::::::ac:::::c                          T:::::T     o::::o     o::::oe::::::eeeeeeeeeee  
        T:::::T         i::::i c::::::c     ccccccc             T:::::T      a::::a    a:::::ac::::::c     ccccccc             T:::::T     o::::o     o::::oe:::::::e           
      TT:::::::TT      i::::::ic:::::::cccccc:::::c           TT:::::::TT    a::::a    a:::::ac:::::::cccccc:::::c           TT:::::::TT   o:::::ooooo:::::oe::::::::e          
      T:::::::::T      i::::::i c:::::::::::::::::c           T:::::::::T    a:::::aaaa::::::a c:::::::::::::::::c           T:::::::::T   o:::::::::::::::o e::::::::eeeeeeee  
      T:::::::::T      i::::::i  cc:::::::::::::::c           T:::::::::T     a::::::::::aa:::a cc:::::::::::::::c           T:::::::::T    oo:::::::::::oo   ee:::::::::::::e  
      TTTTTTTTTTT      iiiiiiii    cccccccccccccccc           TTTTTTTTTTT      aaaaaaaaaa  aaaa   cccccccccccccccc           TTTTTTTTTTT      ooooooooooo       eeeeeeeeeeeeee  
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                

                    
)";
};

int main() {
  diplayGameArt();
  initiateGame();
  /*cout <<  *(g.getBoard() + 1)<< endl;*/
  return 0;
};
