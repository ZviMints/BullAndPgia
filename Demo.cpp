/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include <chrono>

using namespace bullpgia;

int main() {
	ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
	ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

	RandomChooser randy;
	RandomGuesser guessy;
	// for (uint i=0; i<100; ++i) {
	// 	cout << play(randy, guessy, 2, 100) << endl;  // guesser should often win but sometimes lose.
	// }
	
	SmartGuesser smarty;
	
	for (uint i=0; i<200; ++i) {
		
		int len = rand()%12 + 1 ; // [1,12]
		
		auto t_start = std::chrono::high_resolution_clock::now();

		cout << "(" << len << ",";

		uint number_of_guesses;
		if( len < 7 ) {
		number_of_guesses = play(randy, smarty, len , 100);  // smarty should always win in at most 10 turns!
		}
		else {
		number_of_guesses = play(randy, smarty, len , 100);  // smarty should always win in at most 50 turns!
		}

		auto t_end = std::chrono::high_resolution_clock::now();
		
		double elaspedTimeMs = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    	
		cout << number_of_guesses << " ," << elaspedTimeMs << ") for (Len,# Guesses,Time (mills))" << endl;
	
	
	}
	return 0;
}

