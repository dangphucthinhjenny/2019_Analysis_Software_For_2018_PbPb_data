/*create permanent array of 0,0 position

sum all blocks in rpd pos and neg

tchain the root files


a/b = F * c/d

a/b = geant

(a/b)/(c/d) = F





want roiot tree to output 2 branches 1 or 16 rpd pos and 1 of 16 rpd neg
also want cent
*/
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TLeaf.h"
#include "TROOT.h"

#include "MASTER_HEADER.h"


using namespace std;



void Fractional_weight_Eric_weighter(){

	TFile* f = new TFile("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_7.root");
	TTree* ZDCDigiTree = (TTree*)f->Get("zdcdigi");

	TLeaf* eventLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("event");
	TLeaf* zsideLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("zside");
	TLeaf* sectionLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("section");
	TLeaf* channelLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("channel");
	TLeaf* runLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("run");
	TLeaf* fCleaf[NTS];

	for (int iTS = 0; iTS < NTS; iTS++) {
			fCleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
			//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
		}

	N_entries =  ZDCDigiTree->GetEntries();

	ZDCDigiTree->GetEntry(0);
	int RunNumber = runLeaf->GetValue(0);

	cout << "RunNumber" << RunNumber << endl;

	RPD_Cuts_Generator(RunNumber, RPD_Cuts); //automatically determening runnumber and then choosing the cut values associated with that run



	for (int i = 0; i < ZDCDigiTree->GetEntries(); i++) {
		ZDCDigiTree->GetEntry(i);

		for (int n = 0; n < NChannels; n++) { //iterates through all channels of both ZDC + and -

			int side = (int)((zsideLeaf->GetValue(n) + 1) / 2.0);
			int type = (int)(sectionLeaf->GetValue(n)) - 1;
			int channel = (int)(channelLeaf->GetValue(n)) - 1;

			double TS_Zero  = (fCleaf[0]->GetValue(n) <= 0) ? 0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) <= 0) ? 0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) <= 0) ? 0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) <= 0) ? 0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) <= 0) ? 0 : (fCleaf[4]->GetValue(n));
			double TS_Five  = (fCleaf[5]->GetValue(n) <= 0) ? 0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) <= 0) ? 0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) <= 0) ? 0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) <= 0) ? 0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) <= 0) ? 0 : (fCleaf[9]->GetValue(n));
	

	
			double TS_ARRAY[NTS] = { TS_Zero, TS_One, TS_Two, TS_Three, TS_Four, TS_Five, TS_Six, TS_Seven, TS_Eight, TS_Nine};
	
			if (type == RPD){ // make sure to set cuttoff to 40 fC for RPD
				for (int TS = 0; TS < NTS; TS++){
					RawDataRPD[side][channel][TS] = TS_ARRAY[TS];
				}
			}
		}
		double OC_RPD_Data[2][16] = {0};

		RPD_Data_Organizer_and_Cleaner(RawDataRPD, RPD_Cuts, OC_RPD_Data);

		for (int s = 0; s < 2; s ++){
			if (OC_RPD_Data[s][0] == -343){
				goto badvalue; // if a bad rpd event is detected it jumps the loop and counts up a bad rpd
			}
			for (int c = 0; c < 16; c++){
				RPD_fC_Sum[s] += OC_RPD_Data[s][c];
				RPD_Data_Channel_SUM[s][c] += OC_RPD_Data[s][c];
			}
		}
		continue;
		badvalue:
			N_bad_RPDs++;
	}


	for (int s = 0; s < 2; s++){
		for (int c = 0; c < 16; c++){
			Fractional_Weights[s][c] = (Fractionals_Zero_Zero_blocks[c]/SUM_Zero_Zero_blocks)/(RPD_Data_Channel_SUM[s][c]/RPD_fC_Sum[s]);
			cout << "F" << " side " << s << " :" << Fractional_Weights[s][c] << endl;
			cout << "Cuts " << " side " << s << " :" << RPD_Cuts[s][c] << endl;
		}
	}

	cout << "num bad RPD" << N_bad_RPDs << " " << "N_entries " << N_entries << endl;

}


//in event loop


// in event loop
