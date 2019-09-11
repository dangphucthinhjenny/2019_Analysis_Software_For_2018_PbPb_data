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
#include "TChain.h"
#include <fstream> 
#include <cstring>
#include <iostream>

#include "/home/ebadams/TEST_FOR_ANALYSIS_SOFTWARE/HEADER/MASTER_HEADER.h"


using namespace std;



void Fractional_weight_CENTRALITY_Eric_weighter_CHAIN(){

	TChain chain("zdcdigi");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_1.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_10.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_11.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_12.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_13.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_14.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_15.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_16.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_17.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_18.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_19.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_2.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_20.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_21.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_22.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_23.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_24.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_25.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_26.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_27.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_28.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_29.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_3.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_30.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_31.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_4.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_5.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_6.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_7.root");
	chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_8.root");
	

	//chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_7.root");
	//chain.Add("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_25.root");
	//TFile* f = new TFile("/home/ebadams/PbPb2018_CMS_DATA_MB2/HIMinimumBias2/crab_rereco_PbPb2018_AOD_MinBias2_326943_ZDC/0000/testoftrimmer/parallelization_of_trimmer/ZDC_trimmed_rereco_PbPb2018_AOD_MinBias2_326943_RPDZDC_7.root");


	//TTree* ZDCDigiTree = (TTree*)T->chain.Get("zdcdigi")
	TLeaf* eventLeaf;   //=   (TLeaf*)chain.GetLeaf("event");
	TLeaf* zsideLeaf ;  //=   (TLeaf*)chain.GetLeaf("zside");
	TLeaf* sectionLeaf; //= (TLeaf*)chain.GetLeaf("section");
	TLeaf* channelLeaf; //= (TLeaf*)chain.GetLeaf("channel");
	TLeaf* runLeaf;     //=     (TLeaf*)chain.GetLeaf("run");
	TLeaf* CentralityLeaf;
	TLeaf* fCleaf[NTS];

	int iter = 0;
	double CentralityUnits[10] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
	double centralityUnitsDown[10] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180};

	N_entries = chain.GetEntries();

	ofstream file;
	string outputfilegeneral = "Centrality_fractions_";
	string filename = outputfilegeneral + std::to_string(RunNumber) + ".txt";
	file.open (filename);

		if (false){
			centup:
			iter++;
			cout << "moving on to next cent section" << endl;
		}

	file << "Centrality from " << centralityUnitsDown[iter] << " to <" << CentralityUnits[iter] << endl; 



	for (int i = 0; i < chain.GetEntries(); i++) {
		chain.GetEntry(i);
		//this is written this way bc this is how tchain workls otherwise it will break
			eventLeaf   =   (TLeaf*)chain.GetLeaf("event");
			zsideLeaf   =   (TLeaf*)chain.GetLeaf("zside");
			sectionLeaf = (TLeaf*)chain.GetLeaf("section");
			channelLeaf = (TLeaf*)chain.GetLeaf("channel");
			runLeaf     =     (TLeaf*)chain.GetLeaf("run");
			CentralityLeaf = (TLeaf*)chain.GetLeaf("cent");

			if ( i ==0 and iter == 0){
				RunNumber = runLeaf->GetValue(0);
				RPD_Cuts_Generator(RunNumber, RPD_Cuts); //automatically determening runnumber and then choosing the cut values associated with that run
				cout << "RunNumber" << RunNumber << endl;
			}
			for (int iTS = 0; iTS < NTS; iTS++) {
				fCleaf[iTS] = (TLeaf*)chain.GetLeaf(Form("nfC%d", iTS));
				//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
			}

			CentralityValue = CentralityLeaf->GetValue();
			centBin = getHiBinFromhiHF(CentralityValue);

		if (centBin >= centralityUnitsDown[iter] and centBin <  CentralityUnits[iter]){
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
	
			//if ( i % 100000 == 0) cout << "Events Processed: " << i << endl;
			continue;
			badvalue:
				N_bad_RPDs++;
		}	//	if ( i % 100000 == 0) cout << "Events Processed: " << i << endl;
	}


	for (int s = 0; s < 2; s++){
		for (int c = 0; c < 16; c++){
			Fractional_Weights[s][c] = (Fractionals_Zero_Zero_blocks[c]/SUM_Zero_Zero_blocks)/(RPD_Data_Channel_SUM[s][c]/RPD_fC_Sum[s]);
			file << "F" << " side " << s << " :" << Fractional_Weights[s][c] << endl;
		}
	}

	if (iter < 9){
		goto centup;
	}

	file.close();

	cout << "num bad RPD" << N_bad_RPDs << " " << "N_entries " << N_entries << endl;

}


//in event loop


// in event loop
