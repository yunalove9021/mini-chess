#include <cstdlib>
#include <set>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

Move Minimax::get_move(State *state, int depth, int player)
{
    if(!state->legal_actions.size())
        state->get_legal_actions();

    auto actions = state->legal_actions;
    //std::multiset<std::pair<int, int>> all;
    Move step;
    int value_ = -1e9;
    int count = 0;
    for(auto i : actions)
    {
        int x = minimax_caculate(state->next_state(i), depth, false, player);
        if(value_ <= x)
            step = i;
        value_ = std::max(value_, x);
        count++;
    }
    //int x = all.lower_bound(all.rbegin()->first);
    return step;

}

int Minimax::minimax_caculate(State *state, int depth, bool maxiPlayer, int player)
{
    if(depth == 0 || !state->legal_actions.size())
        return state->evaluate(player);
    
    auto actions = state->legal_actions;
    if(maxiPlayer)
    {
        int value_ = -1e9;
        for(auto j : actions)
        {
            State* next = state->next_state(j);
            value_ = std::max(value_, minimax_caculate(next, depth-1, false, player));
        }
        return value_;
    }
    else
    {
        int value_ = 1e9;
        for(auto j : actions)
        {
            State* next = state->next_state(j);
            value_ = std::min(value_, minimax_caculate(next, depth-1, true, player));
        }
        return value_;
    }
}