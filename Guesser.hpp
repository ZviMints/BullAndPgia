#ifndef GUESSER_HPP
#define GUESSER_HPP
#include <iostream>
#include "calculate.hpp"

namespace bullpgia {
class Guesser {
protected:
    unsigned int length; // Length of the string _ _ _ _ _ _.
    std::string last_ans; // [Bull,Pgia]
    

public:
   /* Pure virtual method */
    /* ----> Returns std::string */
    virtual std::string 
    guess() = 0;

    /* This method is responsible to start a new game with input length */
    /* ----> Returns void */
    virtual void 
    startNewGame(unsigned int length) { this->length = length; }
   
   /* This method is responsible to learn the last result of BullAndPgia */
   /* ----> Returns void */
    virtual void 
    learn(std::string calculateBullAndPgia_ans) {
    this->last_ans = calculateBullAndPgia_ans;
    }
};
}
#endif
