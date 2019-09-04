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

#include "MASTER_HEADER.h"



using namespace std;



void RPD_Mean_Position_CHAIN(){

	/// control variables
	double Fiber_Subtraction_Percentage_[2] = {0.05, 0.05};
	int NumberBinsPosition1D = 100;
	int NumberBinsPosition2D = 100;

	double PosX = 0;
	double PosY = 0;
	double NegX = 0;
	double NegY = 0;

	double RPD_Pos_Y_MEAN = 0;
	double RPD_Neg_Y_MEAN = 0;

	double EricWeighter[16] = {0};

	bool posNOTgood = true;
	bool negNOTgood = true;

	///

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

	TLeaf* eventLeaf;   //=   (TLeaf*)chain.GetLeaf("event");
	TLeaf* zsideLeaf ;  //=   (TLeaf*)chain.GetLeaf("zside");
	TLeaf* sectionLeaf; //= (TLeaf*)chain.GetLeaf("section");
	TLeaf* channelLeaf; //= (TLeaf*)chain.GetLeaf("channel");
	TLeaf* runLeaf;     //=     (TLeaf*)chain.GetLeaf("run");

	TLeaf* fCleaf[NTS];




	/// Histograms

	TH1D* RPD_Pos_X;
		  RPD_Pos_X = new TH1D(Form("RPD_Pos_X %d", RunNumber), Form("RPD_Pos_X_%d_NBins_%d; RPD cm", RunNumber, NumberBinsPosition1D), NumberBinsPosition1D, -4, 4);
	TH1D* RPD_Pos_Y;
		  RPD_Pos_Y = new TH1D(Form("RPD_Pos_Y %d", RunNumber), Form("RPD_Pos_Y_%d_NBins_%d; RPD cm", RunNumber, NumberBinsPosition1D), NumberBinsPosition1D, -4, 4);
	TH1D* RPD_Neg_X;
		  RPD_Neg_X = new TH1D(Form("RPD_Neg_X %d", RunNumber), Form("RPD_Neg_X_%d_NBins_%d; RPD cm", RunNumber, NumberBinsPosition1D), NumberBinsPosition1D, -4, 4);
	TH1D* RPD_Neg_Y;
		  RPD_Neg_Y = new TH1D(Form("RPD_Neg_Y %d", RunNumber), Form("RPD_Neg_Y_%d_NBins_%d; RPD cm", RunNumber, NumberBinsPosition1D), NumberBinsPosition1D, -4, 4);

	TH2D* RPD_XY_Pos;
		  RPD_XY_Pos = new TH2D(Form("RPD_XY_Pos %d", RunNumber), Form("RPD_XY_Pos_%d_NBins_%d; X cm; Y cm", RunNumber, NumberBinsPosition2D), NumberBinsPosition2D, -4, 4, NumberBinsPosition2D, -4, 4);
	TH2D* RPD_XY_Neg;
		  RPD_XY_Neg = new TH2D(Form("RPD_XY_Neg %d", RunNumber), Form("RPD_XY_Neg_%d_NBins_%d; X cm; Y cm", RunNumber, NumberBinsPosition2D), NumberBinsPosition2D, -4, 4, NumberBinsPosition2D, -4, 4);
	///


	restart:
	for (int i = 0; i < chain.GetEntries(); i++) {
		chain.GetEntry(i);
		//this is written this way bc this is how tchain workls otherwise it will break
			eventLeaf   =   (TLeaf*)chain.GetLeaf("event");
			zsideLeaf   =   (TLeaf*)chain.GetLeaf("zside");
			sectionLeaf = (TLeaf*)chain.GetLeaf("section");
			channelLeaf = (TLeaf*)chain.GetLeaf("channel");
			runLeaf     =     (TLeaf*)chain.GetLeaf("run");

			if ( i ==0){
				RunNumber = runLeaf->GetValue(0);
				RPD_Cuts_Generator(RunNumber, RPD_Cuts); //automatically determening runnumber and then choosing the cut values associated with that run
				RPD_Frac_Generator(RunNumber, RPD_Frac);
				cout << "RunNumber" << RunNumber << endl;
			}
			for (int iTS = 0; iTS < NTS; iTS++) {
				fCleaf[iTS] = (TLeaf*)chain.GetLeaf(Form("nfC%d", iTS));
				//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
			}

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
		}//end of n 50 loop
		
		double OC_RPD_Data[2][16] = {0};

		RPD_Data_Organizer_and_Cleaner(RawDataRPD, RPD_Cuts, OC_RPD_Data); // cleans and organizes RPD data into a sensible order start top left , read left to right, finish bottom right Quartz blocks

		double OCC_RPD_Data[2][16] = {0};

		for (int s = 0; s < 2; s ++){
			if (OC_RPD_Data[s][0] == -343){ //NOTE this can produce arrays that are defualt filled with zeros need logic to not fill if entire array is zeros
				N_bad_RPDs++;
				continue;
				//goto badvalue; // if a bad rpd event is detected it jumps the loop and counts up a bad rpd
			}
			for ( int c = 0; c < 16; c++){
				OCC_RPD_Data[s][c] = (OC_RPD_Data[s][c] * RPD_Frac[s][c]);
			}
		}

		double OCCS_RPD_Data[2][16] = {0}; // Organized Cleaned Centered SubtractedfiberEffect

		Fiber_Effect_Subtractor(OCC_RPD_Data, Fiber_Subtraction_Percentage_, OCCS_RPD_Data); 

		Returns_X_Y_P_N_RPD_Mean_Position(OCCS_RPD_Data, "Off", EricWeighter, PosX, PosY, NegX, NegY); // produces mean x and y positions

		if (posNOTgood){
			if (PosX != -343) {
				RPD_Pos_X->Fill(PosX);
			}
			if (PosY != -343) {
				RPD_Pos_Y->Fill(PosY);
			}
			if (PosX != -343 and PosY != -343){
				RPD_XY_Pos->Fill(PosX,PosY);
			}
		}
		if (negNOTgood){
			if (NegX != -343) {
				RPD_Neg_X->Fill(NegX);
			}
			if (NegY != -343){
				RPD_Neg_Y->Fill(NegY);
			}
			if (NegX != -343 and NegY != -343){
				RPD_XY_Neg->Fill(NegX,NegY);
			}
		}
		
		//continue;
		//badvalue:
		//	N_bad_RPDs++;
	}//END EVENT LOOP

	RPD_Pos_Y_MEAN = RPD_Pos_Y->GetMean();
	cout << "RPD_Pos_Y_MEAN " << RPD_Pos_Y_MEAN << " Fiber% " << Fiber_Subtraction_Percentage_[1] << endl;
	RPD_Neg_Y_MEAN = RPD_Neg_Y->GetMean();
	cout << "RPD_Neg_Y_MEAN " << RPD_Neg_Y_MEAN << " Fiber% " << Fiber_Subtraction_Percentage_[0] << endl;
	
	if( RPD_Pos_Y_MEAN < 0 ){
		Fiber_Subtraction_Percentage_[1] += 0.01;
		RPD_Pos_X->Reset();
		RPD_Pos_Y->Reset();
		RPD_XY_Pos->Reset();
		cout << "upping Pos" << endl;
		goto restart;
	}
	else{
		posNOTgood = false;
	}
	if ( RPD_Neg_Y_MEAN < 0){
		Fiber_Subtraction_Percentage_[0] += 0.01;
		RPD_Neg_X->Reset();
		RPD_Neg_Y->Reset();
		RPD_XY_Neg->Reset();
		cout << "upping Neg" << endl;
		goto restart;

	}
	else{
		negNOTgood = false;
	}

	TCanvas* c1 = new TCanvas(Form("c1"), Form("RUN_%d", RunNumber), 2000, 2000);

	RPD_Pos_X->Draw("HIST L");
	c1->Print(Form("RPD_Pos_X.png"));
	RPD_Pos_Y->Draw("HIST L");
	c1->Print(Form("RPD_Pos_Y.png"));
	RPD_Neg_X->Draw("HIST L");
	c1->Print(Form("RPD_Neg_X.png"));
	RPD_Neg_Y->Draw("HIST L");
	c1->Print(Form("RPD_Neg_Y.png"));
	RPD_XY_Pos->Draw("COLZ");
	c1->Print(Form("RPD_XY_Pos.png"));
	RPD_XY_Neg->Draw("COLZ");
	c1->Print(Form("RPD_XY_Neg.png"));

	cout << "num bad RPD" << N_bad_RPDs/2 << " " << "N_entries " << N_entries << endl;
	cout << "percentages for fibers" << " Neg " << Fiber_Subtraction_Percentage_[0] << " Pos " << Fiber_Subtraction_Percentage_[1] << endl;
		
}


//in event loop


// in event loop
