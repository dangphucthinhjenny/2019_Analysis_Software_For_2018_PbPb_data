//constants header

const int NSIDE = 2;
const int NRPD = 16;
const int NTS = 10;

int NChannels = 50;

double RPD_Cuts[2][16] = {0};

//Frac values begin
double SUM_Zero_Zero_blocks = 666;

double Fractionals_Zero_Zero_blocks[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

double RPD_fC_Sum[2] = {0};

double RPD_Data_Channel_SUM[2][16] = {0};

double Fractional_Weights[2][16] = {0};
//frac values end

double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
										    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos
double RPD = 3;

int N_bad_RPDs = 0;

int N_entries = 0;

int RunNumber = 0;