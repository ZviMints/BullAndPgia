
#include "calculate.hpp"
std::string calculateBullAndPgia(std::string choice, std::string guess) { 
int bull = 0;
int pgia = 0;
int length = choice.length();
int numbers[10] = {0}; // Initialize the array with zero's
for(int i=0; i<length; i++)
{
    if(choice.at(i) == guess.at(i))
    {
        bull++;
    }
    else
    {
        if(numbers[guess.at(i) - '0'] ++ < 0) pgia++;
        if(numbers[choice.at(i) - '0'] -- > 0) pgia++;
    } 
} // End for
std::string ans = std::to_string(bull) + "," + std::to_string(pgia);
return ans;
} // End calculateBullAndPgia



