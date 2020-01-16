//
//  Pig.cpp
//  Pig
//
//

#include "Pig.h"
#include <iostream>

namespace cs31
{
    Pig::Pig()
    {
        
    }
    
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // lets the human player play
    // when the amount is zero, the Die is rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  In that case, this method forces a specific roll
    // amount.
    // once there is a rolled amount, informs the board that it is now
    // the human's turn, sets the board's rolled value and updates the board's
    // human score accordingly
    int Pig::humanPlay( int amount )
    {
        int amountrolled = 0;
        if(!isGameOver())
        {
            if (amount == 0)
            {
                amountrolled = mHuman.roll();
                mBoard.setHumanTurn();
            }
            else
            {
                amountrolled = mHuman.roll(amount);
                mBoard.setHumanTurn();
            }
        }
        
        return( amountrolled );
    }
    
    // informs the human Player that their turn has ended
    // updates the board's human total
    void Pig::humanEndTurn()
    {
        mHuman.endTurn();
        mBoard.setHumanTotal( mHuman.getTotal() );
    }
    
    // lets the computer player play
    // when the amount is zero, the Die is rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method forces a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the computer's turn, set the board's rolled value and update the board's
    // computer score accordingly
    int Pig::computerPlay( int amount )
    {
        int amountrolled = 0;
        if (!isGameOver())
        {
            if ( amount == 0)
            {
                amountrolled = mComputer.roll();
                mBoard.setComputerTurn();
            }
            else
            {
                amountrolled = mComputer.roll(amount);
                mBoard.setComputerScore(mComputer.getScore());
            }
        }
        return( amountrolled );
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const
    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {

            result = false;
        }
        return( result );
    }
    
    // informs the computer Player that their turn has ended
    // updates the board's computer total
    void Pig::computerEndTurn()
    {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
    }
    
    // determine the game outcome at this moment
    Pig::GAMEOUTCOME  Pig::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        if (mBoard.getHumanTotal() >= SCORENECESSARYTOWIN && mBoard.getComputerTotal() < SCORENECESSARYTOWIN)
        {
            result = GAMEOUTCOME::HUMANWONGAME;
        }
        if (mBoard.getComputerTotal() >= SCORENECESSARYTOWIN && mBoard.getHumanTotal() < SCORENECESSARYTOWIN)
        {
            result = GAMEOUTCOME::COMPUTERWONGAME;
        }
        return( result );
    }
    
    // determines if the game is over
    // if it is, returns true and inform the board that the game is over and
    // informs the board that the Human won or the Computer won, accordingly.
    bool Pig::isGameOver()
    {
        GAMEOUTCOME Finalresult = determineGameOutcome();
        if ( Finalresult == GAMEOUTCOME::HUMANWONGAME)
        {
            mBoard.markHumanAsWinner();
            mBoard.setGameOver(true);
            return(true);
        }
        if (Finalresult == GAMEOUTCOME::COMPUTERWONGAME)
        {
            mBoard.markComputerAsWinner();
            mBoard.setGameOver(true);
            return(true);
        }
        return( false );
    }

}
