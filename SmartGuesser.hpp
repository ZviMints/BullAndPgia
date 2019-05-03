#ifndef SMARTGUESSER_HPP
#define SMARTGUESSER_HPP

#include "Guesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <list>
#include <math.h>

/**
 * SmartGuesser is a guesser that always smart
 */
class SmartGuesser: public bullpgia::Guesser {

	std::list<std::string> AllPerms;
	
	/* ==== Short Algorithm ===== */
	std::string _guess;
	/* ========================== */
	/* ===== Long Algorithm ===== */
	int curr = 0;
	std::string _perm = "";


	/* =================================================================== */
	

	virtual std::string guess() override;
	virtual void learn(std::string calculateBullAndPgia_ans) override;
	virtual void startNewGame(unsigned int length) override;

/* ========================= Long Algorithm ================================== */
	
	std::string guessLong() ;
	void learnLong(std::string calculateBullAndPgia_ans) ;
	void startNewGameLong(unsigned int length) ;
	std::string toSequence(int,int);

/* ========================= Short Algorithm ================================== */

	std::string guessShort() ;
	void learnShort(std::string calculateBullAndPgia_ans) ;
	void startNewGameShort(unsigned int length) ;
	
};

#endif
