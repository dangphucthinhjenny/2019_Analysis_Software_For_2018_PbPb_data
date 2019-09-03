//RPD cuts generator these cuts were made by Alice and this header merely calls them based on the runnumber of the root file

#include <cstdint>
#include <cstring>
#include <math.h>

#ifndef RPD_FRAC
#define RPD_FRAC


using namespace std;

//Cuts

double Fractions_326776[2][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
double Fractions_326822[2][16] = {{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1}};
double Fractions_326943[2][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
double Fractions_Defualt[2][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void RPD_Frac_Generator(int RunNumber, double (&RPD_Frac)[2][16]){

	switch (RunNumber) {
		case 326776 :
			memcpy(RPD_Frac, Fractions_326776, sizeof(RPD_Frac));
			break;
		case 326822 :
			memcpy(RPD_Frac, Fractions_326822, sizeof(RPD_Frac));
			break;
		case 326943 :
			memcpy(RPD_Frac, Fractions_326943, sizeof(RPD_Frac));
			break;
		default:
			memcpy(RPD_Frac, Fractions_Defualt, sizeof(RPD_Frac));

	}

}

#endif