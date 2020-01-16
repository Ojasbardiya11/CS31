//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die rolls for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes. In that case, this method forces a specific roll
    // amount.
    int Player::roll( int amount )
    {
        
        if ( amount == 0)
        {
            mDie.roll();
            int dieRoll = mDie.getValue();
            amount = dieRoll;
            if (dieRoll == 1)
            {
                mScore = 0;
            }
            else
            {
                mScore = mScore + dieRoll;
            }
        }
        else
        {
            if (amount == 1)
            {
                mScore = 0;
            }
            else
            {
                mScore = mScore + amount;
            }
        }
        return( amount );
    }
    
    //  adds the current score into the running total since the turn ended
    //       resets the current score to 0 for the next round of play
    void Player::endTurn()
    {
        mTotal = mTotal + mScore;
        mScore = 0;
    }
    
    //  returns the current total
    int Player::getTotal( ) const
    {
        return( mTotal );
    }
    
    // returns the current total
    int  Player::getScore( ) const
    {
        return( mScore );
    }
}
