#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Alphabeta{
public:
  static Move get_move(State *state, int depth, int player);
  static int alphabeta_caculate(State *state, int depth, int alpha, int beta, bool maxiPlayer, int player);
};