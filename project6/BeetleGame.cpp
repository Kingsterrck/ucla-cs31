//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
std::string BeetleGame::display( std::string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    std::string result = drawing.draw() + "\n" + msg;
    return( result );
}


// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount ) {
	if (amount == 0) {
          mHumanDie.roll();
	} else {
          mHumanDie.setValue(amount);
	}
}

// TODO return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    return mHumanDie.getValue();
}

// TODO convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay() {
    if (!mHuman.hasBody()) {
    	if (getHumanDie() == 6) { // doesnt have body and can build
        	mHuman.buildBody();
            return true;
    	} else { // cannot build
          	return false;
    	}
    } else {
      	if (getHumanDie() == 3) {
          	if (!mHuman.hasLeg1() || !mHuman.hasLeg2() || !mHuman.hasLeg3() || !mHuman.hasLeg4()) {
            	mHuman.buildLeg();
                return true;
          	} else {
                return false;
          	}
      	} else if (getHumanDie() == 4) {
          	if (!mHuman.hasTail()) {
                mHuman.buildTail();
                return true;
          	} else {
            	return false;
          	}
      	}

        if (!mHuman.hasHead()) {
        	if (getHumanDie() == 5) {
            	mHuman.buildHead();
                return true;
        	} else {
                return false;
        	}
        } else { // has head
			if (getHumanDie() == 1 && (!mHuman.hasEye1() || !mHuman.hasEye2())) {
            	mHuman.buildEye();
                return true;
			} else if (getHumanDie() == 2 && (!mHuman.hasAntenna1() || !mHuman.hasAntenna2())) {
                mHuman.buildAntenna();
                return true;
			} else {
                return false;
			}
        }

    }
}

void BeetleGame::computerRoll( int amount ) {
    if (amount == 0) {
          mComputerDie.roll();
	} else {
          mComputerDie.setValue(amount);
	}
}

int BeetleGame::getComputerDie( ) const {
    return mComputerDie.getValue();
}

bool BeetleGame::computerPlay( ) {
    if (!mComputer.hasBody()) {
    	if (getComputerDie() == 6) { // doesnt have body and can build
        	mComputer.buildBody();
            return true;
    	} else { // cannot build
          	return false;
    	}
    } else {
      	if (getComputerDie() == 3) {
          	if (!mComputer.hasLeg1() || !mComputer.hasLeg2() || !mComputer.hasLeg3() || !mComputer.hasLeg4()) {
            	mComputer.buildLeg();
                return true;
          	} else {
                return false;
          	}
      	} else if (getComputerDie() == 4) {
          	if (!mComputer.hasTail()) {
                mComputer.buildTail();
                return true;
          	} else {
            	return false;
          	}
      	}

        if (!mComputer.hasHead()) {
        	if (getComputerDie() == 5) {
            	mComputer.buildHead();
                return true;
        	} else {
                return false;
        	}
        } else { // has head
			if (getComputerDie() == 1 && (!mComputer.hasEye1() || !mComputer.hasEye2())) {
            	mComputer.buildEye();
                return true;
			} else if (getComputerDie() == 2 && (!mComputer.hasAntenna1() || !mComputer.hasAntenna2())) {
                mComputer.buildAntenna();
                return true;
			} else {
                return false;
			}
        }
	return false;
    }
}

BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const {
    if (mHuman.isComplete()) {
    	return GameOutcome::HUMANWONGAME;
    } else if (mComputer.isComplete()) {
    	return GameOutcome::COMPUTERWONGAME;
    } else {
      	return GameOutcome::GAMENOTOVER;
    }
}

std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// TODO has the game ended with a winner?
bool BeetleGame::gameIsOver() const {
    return determineGameOutcome() == GameOutcome::HUMANWONGAME || determineGameOutcome() == GameOutcome::COMPUTERWONGAME;
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


