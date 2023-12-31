#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "../config.hpp"


typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;
class Board{
  public:
    char board[2][BOARD_H][BOARD_W] = {{
      //white
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {2, 3, 4, 5, 6},
    }, {
      //black
      {6, 5, 4, 3, 2},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }};
    
  double board_value_double[7][2][BOARD_H][BOARD_W] = {{{
      //empty
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }, {
      //empty
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }}, {{
      //Pawn
      {6, 6, 6, 6, 6},
      {4, 4, 5, 4, 4},
      {3, 3, 3, 3, 3},
      {2, 2, 2, 2, 2},
      {1, 1, 2, 1, 1},
      {1, 1, 1, 1, 1},
    }, {
      //Black Pawn
      {1, 1, 1, 1, 1},
      {1, 1, 2, 1, 1},
      {2, 2, 2, 2, 2},
      {3, 3, 3, 3, 3},
      {4, 4, 5, 4, 4},
      {6, 6, 6, 6, 6},
    }}, {{
      //Rook
      {6, 6, 6, 6, 6},
      {4, 6, 6, 6, 4},
      {2, 3, 3, 3, 2},
      {1, 2, 3, 2, 1},
      {1, 2, 3, 2, 1},
      {1, 1, 3, 1, 1},
    }, {//Black Rook
      {1, 1, 3, 1, 1},
      {1, 2, 3, 2, 1},
      {1, 2, 3, 2, 1},
      {2, 3, 3, 3, 2},
      {4, 6, 6, 6, 4},
      {6, 6, 6, 6, 6},
    }},{{
      //Knight
      {1, 1, 2, 1, 1},
      {1, 4, 4, 4, 1},
      {2, 4, 5, 4, 2},
      {2, 4, 5, 4, 2},
      {1, 4, 2, 4, 1},
      {1, 1, 1, 1, 1},
    }, {
      //Black Knight
      {1, 1, 1, 1, 1},
      {1, 4, 2, 4, 1},
      {2, 4, 5, 4, 2},
      {2, 4, 5, 4, 2},
      {1, 4, 4, 4, 1},
      {1, 1, 2, 1, 1},
    }},{{
      //Bishop
      {1, 1, 1, 1, 1},
      {1, 1, 2, 1, 1},
      {1, 2, 4, 2, 1},
      {2, 2, 4, 2, 2},
      {5, 2, 3, 2, 5},
      {1, -1, 1, -1, 1},
    }, {
      //Black Bishop
      {1, -1, 1, -1, 1},
      {5, 2, 3, 2, 5},
      {2, 2, 4, 2, 2},
      {1, 2, 4, 2, 1},
      {1, 1, 2, 1, 1},
      {1, 1, 1, 1, 1},
    }},{{
      //queen
      {1, 2, 2, 2, 1},
      {1, 2, 3, 2, 1},
      {2, 3, 3, 3, 2},
      {2, 3, 3, 3, 2},
      {1, 2, 3, 2, 1},
      {1, 2, 2, 2, 1},
    }, {
      //Black queen
      {1, 2, 2, 2, 1},
      {1, 2, 3, 2, 1},
      {2, 3, 3, 3, 2},
      {2, 3, 3, 3, 2},
      {1, 2, 3, 2, 1},
      {1, 2, 2, 2, 1},
    }},{{
      //king
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, -1, 1, 1},
    }, {
      //Black king
      {1, 1, -1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
    }}};
};

enum GameState {
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};


class State{
  public:
    //You may want to add more property for a state
    GameState game_state = UNKNOWN;
    Board board;
    int player = 0;
    std::vector<Move> legal_actions;
    
    State(){};
    State(int player): player(player){};
    State(Board board): board(board){};
    State(Board board, int player): board(board), player(player){};
    
    int evaluate(int player_);
    State* next_state(Move move);
    void get_legal_actions();
    std::string encode_output();
    std::string encode_state();
};

#endif