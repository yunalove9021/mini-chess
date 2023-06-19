#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alphabeta::get_move(State *state, int depth, int player){
    if(!state->legal_actions.size())
        state->get_legal_actions();
  
    auto actions = state->legal_actions;
    //std::multiset<std::pair<int, int>> all;
    Move step;
    int value_ = -1e9;
    int count = 0;
    for(auto i : actions)
    {
        int x = alphabeta_caculate(state->next_state(i), depth, -1e9, 1e9, false, player);
        if(value_ <= x)
        {
            step = i;
            //value_ = x;
        }
        value_ = std::max(value_, x);
        count++;
    }
    //int x = all.lower_bound(all.rbegin()->first);
    return step;
}

int Alphabeta::alphabeta_caculate(State *state, int depth, int alpha, int beta, bool maxiPlayer, int player)
{
    if(depth == 0 || !state->legal_actions.size())
        return state->evaluate(player);

    auto actions = state->legal_actions;
    if(maxiPlayer)
    {
        int value_ = -1e9;
        for(auto i : actions)
        {
            State* next = state->next_state(i);
            int x = alphabeta_caculate(next, depth-1, alpha, beta, false, player);
            value_ = std::max(value_, x);
            alpha = std::max(alpha, value_);

            if(alpha >= beta)
                break;
        }
        return value_;
    }
    else
    {
        int value_ = 1e9;
        for(auto i : actions)
        {
            State* next = state->next_state(i);
            int x = alphabeta_caculate(next, depth-1, alpha, beta, true, player);
            value_ = std::min(value_, x);
            beta = std::min(beta, value_);
            
            if(beta <= alpha)
                break;
        }
        return value_;
    }
}