#include <iostream>
#include "RPD_Cuts_Generator.h"

using namespace std;

void TestCutGenerator(int RunNumber){
	double RPD_Cuts[2][16] = {0};

	RPD_Cuts_Generator( RunNumber,  RPD_Cuts);


	for (int s = 0; s < 2; s++){
		for ( int c = 0; c< 16; c++){
			cout << "side " << s << " " << "channel " << c << " :" << RPD_Cuts[s][c] << endl;
		}
	}
}