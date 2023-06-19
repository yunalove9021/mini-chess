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
    char board_value[7][2][BOARD_H][BOARD_W] = {{{
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
      {40, 40, 40, 40, 40},
      {15, 15, 20, 15, 15},
      {8, 8, 10, 8, 8},
      {5, 5, 5, 5, 5},
      {1, 1, 3, 1, 1},
      {1, 1, 1, 1, 1},
    }, {
      //Black Pawn
      {1, 1, 1, 1, 1},
      {1, 1, 3, 1, 1},
      {5, 5, 5, 5, 5},
      {8, 8, 10, 8, 8},
      {15, 15, 20, 15, 15},
      {40, 40, 40, 40, 40},
    }}, {{
      //Rook
      {10, 10, 10, 10, 10},
      {8, 8, 8, 8, 8},
      {5, 5, 8, 5, 5},
      {3, 3, 5, 3, 3},
      {2, 2, 2, 2, 2},
      {1, 1, 1, 1, 1},
    }, {//Black Rook
      {1, 2, 2, 2, 1},
      {2, 2, 2, 2, 2},
      {3, 3, 5, 3, 3},
      {5, 5, 8, 5, 5},
      {8, 8, 8, 8, 8},
      {10, 10, 10, 10, 10},
    }},{{
      //Knight
      {1, 1, 2, 1, 1},
      {1, 3, 5, 3, 1},
      {2, 8, 8, 8, 2},
      {2, 3, 5, 3, 2},
      {1, 2, 3, 2, 1},
      {1, 1, 1, 1, 1},
    }, {
      //Black Knight
      {1, 1, 1, 1, 1},
      {1, 2, 3, 2, 1},
      {2, 3, 5, 3, 2},
      {2, 8, 8, 8, 2},
      {1, 3, 5, 3, 1},
      {1, 1, 2, 1, 1},
    }},{{
      //Bishop
      {1, 1, 1, 1, 1},
      {1, 2, 3, 2, 1},
      {1, 3, 5, 3, 1},
      {1, 3, 5, 3, 1},
      {1, 2, 2, 2, 1},
      {1, 1, 1, 1, 1},
    }, {
      //Black Bishop
      {1, 1, 1, 1, 1},
      {1, 2, 2, 2, 1},
      {1, 3, 5, 3, 1},
      {1, 3, 5, 3, 1},
      {1, 2, 3, 2, 1},
      {1, 1, 1, 1, 1},
    }},{{
      //queen
      {1, 2, 2, 2, 1},
      {2, 3, 4, 3, 2},
      {2, 4, 6, 4, 2},
      {2, 4, 6, 4, 2},
      {2, 3, 4, 3, 2},
      {1, 2, 2, 2, 1},
    }, {
      //Black queen
      {1, 2, 2, 2, 1},
      {2, 3, 4, 3, 2},
      {2, 4, 6, 4, 2},
      {2, 4, 6, 4, 2},
      {2, 3, 4, 3, 2},
      {1, 2, 2, 2, 1},
    }},{{
      //king
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
    }, {
      //king
      {1, 1, 1, 1, 1},
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