//RPD cuts generator these cuts were made by Alice and this header merely calls them based on the runnumber of the root file

#include <cstdint>
#include <cstring>
#include <math.h>

#ifndef RPD_CUTS
#define RPD_CUTS


using namespace std;

//Cuts
double Cut_326776[2][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
double Cut_326822[2][16] = {{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1}};
double Cut_326943[2][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
double Cut_Default[2][16] = {{pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9)},{pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9),pow(9,9)}};

void RPD_Cuts_Generator(int RunNumber, double (&RPD_Cuts)[2][16]){

	switch (RunNumber) {
		case 326776 :
			memcpy(RPD_Cuts, Cut_326776, sizeof(RPD_Cuts));
			break;
		case 326822 :
			memcpy(RPD_Cuts, Cut_326822, sizeof(RPD_Cuts));
			break;
		case 326943 :
			memcpy(RPD_Cuts, Cut_326943, sizeof(RPD_Cuts));
			break;
		default:
			memcpy(RPD_Cuts, Cut_Default, sizeof(RPD_Cuts));

	}

}

#endif