/*
This header serves to organize and cluster the raw data into a sensible and cleaned up format

The software consumes the raw data in an array form then processes the data and organizes it into cleaned signals per channel and for the RPD organizes the channels into a sensible format

for BOTH RPDS the data is organized as follows

 1  2  3  4 
 5  6  7  8 
 9 10 11 12
13 14 15 16

where 1 is the first element of the array and the beam is going into the screen
*/


#ifndef Data_Organizer
#define Data_Organizer


void RPD_Data_Organizer_and_Cleaner(double RawDataRPD[2][16]/*[10]*/, /*double RPD_Cuts[2][16],*/ double (&OC_RPD_Data)[2][16]){

	//👁 constants for operation of softrware

	int LookUpRPD_Pos[16] = {11, 15, 2, 5,
						  	  8, 12, 1, 6,
						      9, 13, 0, 4,
						     10, 14, 3, 7};

	//ch 5 and 6 switched due to inverted cable
	//NEG SIDE COLUMNS ARE INVERETED THIS IS CORRECTED FOR BY THESE ARRAYS

	int LookUpRPD_Neg[16] = { 6, 2, 15, 11,
							  5, 1, 12, 8,
							  4, 0, 13, 9,
							  7, 3, 14, 10};


	//double O_DataRPD[2][16][10] = {0}; // array for organized RPD data



	for (int c = 0; c < 16; c++){

		OC_RPD_Data[0][c] = RawDataRPD[0][LookUpRPD_Neg[c]];
		OC_RPD_Data[1][c] = RawDataRPD[1][LookUpRPD_Pos[c]];
		//do check on all valuies if pas fill if any value bad set all values to -3000 and return
		/*for (int ts = 0; ts < 10; ts++){
			O_DataRPD[0][c][ts] = RawDataRPD[0][LookUpRPD_Neg[c]][ts];
			O_DataRPD[1][c][ts] = RawDataRPD[1][LookUpRPD_Pos[c]][ts];
		}*/

	}

	/*for (int c = 0; c < 16; c++){
		if (((O_DataRPD[0][c][3] + O_DataRPD[0][c][4])/O_DataRPD[0][c][5]) > RPD_Cuts[0][c]){ //checks to se if TS distribution is good if yes it fills the output rpd array with the sum of those TS
			OC_RPD_Data[0][c] = (O_DataRPD[0][c][3] + O_DataRPD[0][c][4] + O_DataRPD[0][c][5]);
		}
		else{
			for (int b = 0; b < 16; b ++){
				OC_RPD_Data[0][b] = -343;
			}
			break; //if a bad channel is detected in the rpd the rpd is tossed
		}
	}

	for (int c = 0; c < 16; c++){
		if (((O_DataRPD[1][c][3] + O_DataRPD[1][c][4])/O_DataRPD[1][c][5]) > RPD_Cuts[1][c]){
			OC_RPD_Data[1][c] = (O_DataRPD[1][c][3] + O_DataRPD[1][c][4] + O_DataRPD[1][c][5]);
		}
		else{
			for (int b = 0; b < 16; b ++){
				OC_RPD_Data[1][b] = -343;
			}
			break; // if a bad channel is detected entire rpd is tossed
		}
	}*/

	return;
} //end function

#endif