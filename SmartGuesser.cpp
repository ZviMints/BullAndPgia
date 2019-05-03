#include "SmartGuesser.hpp"
using namespace std;
/** This Method is responsoble to guess a "smart" guess, this function 
 * Takes into account previous guesses and allows quick calculation of the solution */

string SmartGuesser::guess() {
	string ans;
	(this->length < 7) ? ans = SmartGuesser::guessShort() :  ans = 	SmartGuesser::guessLong();
	return ans;
} // End SmartGuesser::guess()

/* ======================================================================================== */

void SmartGuesser::learn(string calculateBullAndPgia_ans) {
	(this->length < 7) ? SmartGuesser::learnShort(calculateBullAndPgia_ans) : 	SmartGuesser::learnLong(calculateBullAndPgia_ans);
} // End SmartGuesser::learn

/* ======================================================================================== */

void SmartGuesser::startNewGame(unsigned int length) {
	if(length <= 0 ) throw std::invalid_argument("Invalid argument for length [ le 0 ] ");
	(length < 7) ? SmartGuesser::startNewGameShort(length) : SmartGuesser::startNewGameLong(length);
}

/* *************************************************************************** */
/* ========================= Long Algorithm ================================== */
/*       This Algorithm will run if the input is at least 7 digits (>=)        */
/* *************************************************************************** */


/* ======================================================================================== */
/**
 * This Method is responsible to convert number to a string sequence in fixed length
 * for example, an input (2,5) will return "22222" 
 * This method return string. */

string SmartGuesser::toSequence(int num, int digits) {
	string ans;
	for(int i=0; i<digits; i++) { ans += to_string(num); }
	return ans;
}
/* ======================================================================================== */
/** This Method is responsoble to guess a "smart" guess, this function 
 * Takes into account previous guesses and allows quick calculation of the solution */
string SmartGuesser::guessLong() {
string ans = "" ;
if( _perm.length() != this->length ) {
	ans = this->toSequence(curr,this->length);
	curr++;
} // End if
else
{
	ans = AllPerms.front();
	AllPerms.pop_front();
	_perm = ans;
}
return ans;
} // End SmartGuesser::guess()
/* ======================================================================================== */
void SmartGuesser::learnLong(string calculateBullAndPgia_ans) {
SmartGuesser::Guesser::learn(calculateBullAndPgia_ans);
if(_perm.length() < this->length) { 
	string delimiter = ",";
	string token = this->last_ans.substr(0, this->last_ans.find(delimiter)); // token is Bull results
	int Bull = stoi(token);
	if( Bull > 0) {
			for(int i=0; i<Bull; i++) {
				_perm += to_string(curr-1);
			}
	} // End Bull > 0 IF
	if(_perm.length() == this->length)
	{
		sort(_perm.begin(), _perm.end());
		do 
		{
			AllPerms.push_front(_perm); // Push to database
		} while(next_permutation(_perm.begin(), _perm.end()));
	}
} // End if
else
{
	list<string>::iterator iterator = AllPerms.begin(); // Initialize iterator
	while(iterator != AllPerms.end()) // While there items
	{
		string current_perm = *iterator; // Cudrrent item
		int equals = calculateBullAndPgia(_perm,current_perm).compare(this->last_ans);
		if(equals != 0)
		{
			iterator = AllPerms.erase(iterator); // Erasing element represented by iterator 
		}
		else iterator++;
	}
} // End else
	// for (auto v : AllPerms) // Priniting Values
    // cout << v << ","; // Printing Values
	// cout << endl;
} // End SmartGuesser::learn

/* ======================================================================================== */
void 
SmartGuesser::startNewGameLong(unsigned int length) {
SmartGuesser::Guesser::startNewGame(length);
	curr = 0;
	_perm.clear();
	AllPerms.clear();
}

/* ***************************************************************************             SSSSSSSSSSSSSSSSSSSS     */           
/* ========================= Short Algorithm =================================             SSSSSSSSSSSSSSSSSSSS     */
/*       This Algorithm will run if the input is at most 7 digits (<)                      SSSSSSSSSSSSSSSSSSSS     */
/* ***************************************************************************             SSSSSSSSSSSSSSSSSSSS     */
	
string SmartGuesser::guessShort() {
	//the first guess in the game
	string r="";
	if (AllPerms.size()==pow(10,length)) {
		for (uint i=0; i < this->length; ++i) {
			char c = '0' + i+1;
			r += c;
		}
		_guess = r;
		return r;
	}
	//random choice from all_option after filtering
	list<string>::iterator i=AllPerms.begin();
	if (AllPerms.size()>1)
		advance(i,rand()%(AllPerms.size()-1));
	_guess = *i;
	return _guess;
 }
void SmartGuesser::learnShort(string calculateBullAndPgia_ans) {
	list<string>::iterator i=AllPerms.begin();
	while (i != AllPerms.end()) {
        	string curr_result =calculateBullAndPgia(*i, _guess); 
	  	if (calculateBullAndPgia_ans.compare(curr_result)!=0){
			i=AllPerms.erase(i);
		}
		else i++;
	}
 }
void SmartGuesser::startNewGameShort(unsigned int length) { 
	AllPerms.clear();
	this->length = length;//bullpgia::Guesser::startNewGame(length);
	unsigned int max = pow(10,length);

	for ( unsigned int i=0;i<max;i++){
		stringstream ss;
		ss << setw(length) << setfill('0') << i;
		string s = ss.str();
		AllPerms.push_front(s);
	}
 }
