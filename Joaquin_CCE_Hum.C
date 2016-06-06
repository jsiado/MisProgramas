// Efficiency Measuments
#include "TMath.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
// #include "BasePixel/CalibrationTable.h"
// #include "SCurve.h"
// #include "TMinuit.h"

void RisetimeTodoVsFluence()
{
	float Fluence [10]={0,0,0,0,0,0,3,3,6,12};
	float FluenceErr[10]={0};
	
	float Risetime[10]={32.8, 34.0, 31.0, 29.2, 33.1, 31.0, 38.4, 38.4, 38.5, 38.8};
	float RisetimeErr[10]={1.2, 2.7, 3.2, 2.4, 3.2, 2.7, 1.6, 2.6, 2.5, 2.8};

	TCanvas* c1=new TCanvas();
// 	TGraphErrors *risefluence = new TGraphErrors (10, Risetime, Fluence, RisetimeErr, FluenceErr);
	TGraphErrors *risefluence = new TGraphErrors (10, Fluence, Risetime, FluenceErr, RisetimeErr);
	risefluence->Draw("AP*");
	risefluence->SetMarkerSize(1);			//change the size of the markers
	risefluence->SetMarkerStyle(21);
	risefluence->SetMarkerColor(4);
	gStyle->SetFillColor(0);		//remove the background color in default histograms
	gStyle->SetCanvasColor(10);		//remove the color in the histograms.
	risefluence->SetTitle("");
	risefluence->GetXaxis()->SetTitle("Fluece (10^{14}n_{eq}/cm^{2})");
	risefluence->GetYaxis()->SetTitle("Risetime (ns)");
	risefluence->SetMinimum(0);		//minimum in the axis
	risefluence->SetMaximum(50);		//maximum in the axis
// 	c1->SaveAs("../PIRE/07-04-2011//Vana_vs_Temp.gif");
}
void ClusterAPS()
{
	new TCanvas;
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TFile *f = new TFile("../../log/bt05r001111/spectra_001111.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1111");
	CluSize->Draw();
	CluSize->SetTitle("");
	CluSize->GetYaxis()->SetTitle("# Pixels");
	CluSize->GetXaxis()->SetTitle("Cluster Size");
	CluSize->SetLineColor(1);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "Not irradiated", "L");
}

void Jajoja()
{
	TFile *f1 = new TFile("/home/joaquin/MAESTRIA/l_tester/singleROCTesting/output/ROC_1/RTDistrNew_ROC_1.root");
	TH1D *h = (TH1D*)f1->Get("RTDistrNew_1");
	double j, sum=0,sum3=0,k;
	for( double i=20; i<=49/*	/h->GetNbinsX()*/; i=i+0.5)
	{
		j = h->GetBinContent(i);
		k=j*i;
		if(j!=0)
		{
			sum=sum+j;
			sum3=sum3+k;
			cout<<i<<" "<<j<<"  "<<k<<" "<<sum<<" "<<sum3<<endl;
		}
	}
	h->Draw();
	cout<<" "<<sum<<" "<<sum3/1040<<endl;
}
void Unified()
{
	TFile *f1 = new TFile("/home/joaquin/Tesis/Rum_Joaquin/Graph/RtdistNew_1.root");
	TH1F *h1 = (TH1F*)f1->Get("c1_n4");
	TFile *f2 = new TFile("/home/joaquin/Tesis/Rum_Joaquin/Graph/RtdistNew_2.root");
	TH1F *h2 = (TH1F*)f2->Get("c1_n4");
// 	TFile *f1 = new TFile("/home/joaquin/MAESTRIA/l_tester/singleROCTesting/output/ROC_1/RtdistrNew_1.root");
// 	TH1D *h1 = (TH1D*)f1->Get("c1_n4");
// 	TFile *f2 = new TFile("/home/joaquin/MAESTRIA/l_tester/singleROCTesting/output/ROC_2/RTDistrNew_ROC_2.root");
// 	TH1D *h2 = (TH1D*)f2->Get("c1_n4");
// 	TFile *f3 = new TFile("/home/joaquin/MAESTRIA/l_tester/singleROCTesting/output/ROC_3/RTDistrNew_ROC_3.root");
// 	TH1D *h3 = (TH1D*)f3->Get("c1_n4");
// 	TFile *f4 = new TFile("/home/joaquin/MAESTRIA/l_tester/singleROCTesting/output/ROC_4/RTDistrNew_ROC_4.root");
// 	TH1D *h4 = (TH1D*)f4->Get("c1_n4");
	TCanvas *J = new TCanvas ("laferia", "la feria");
	J-> Divide(2,2);
	J->cd(1);
	h1->Draw();
	J->cd(2);
	h2->Draw();
// 	J->cd(3);
// // 	h3->Draw();
// 	J->cd(4);
// 	h4->Draw();
}

void TesisRiseTime ()
{
	int Col=0,Row=0,iRow,iCol,sw,ROC;
	double PHmax=0,RT,p0,p1,p2,function,derivative,z,max,y;
// 	ofstream fs(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/dead_%i.txt",ROC));
// 	ofstream fs1(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/bump_%i.txt",ROC));
// 	TH2F *RTMapOld = new TH2F(Form("RTMapOld_%i",ROC),Form("RTMapOld_%i",ROC),52,0,52,80,0,80);
// 	TH1F *RTDistrOld = new TH1F(Form("RTDistrOld_%i",ROC), Form("RTDistrOld_%i",ROC),100,0,50);
// 	TH2F *RTMapNew = new TH2F(Form("RTMapNew_%i",ROC), Form("RTMapNew_%i",ROC),52,0,52,80,0,80);
	TH1F *RTDistr1 = new TH1F("RTDistr_1","RTDistrNew_1",100,0,50);
	TH1F *RTDistr2 = new TH1F("RTDistr_2","RTDistrNew_2",100,0,50);
	TH1F *RTDistr3 = new TH1F("RTDistr_3","RTDistrNew_3",100,0,50);
	TH1F *RTDistr4 = new TH1F("RTDistr_4","RTDistrNew_4",100,0,50);
// 	TH1F *Diff = new TH1F(Form("diff_ROC_%s",ROC), Form("diff_ROC_%s",ROC),60,-8,8);
// 	TH2F *RTime = new TH2F(Form("risetime",ROC), Form("risetime",ROC),52,0,52,80,0,80);
// 	TH1F *RTD = new TH1F(Form("Risetime Dist %s",ROC), Form("Risetime Dist %s",ROC),130,0,50);
// 	TFile *g = new TFile(Form("../../singleROCTesting/output/ROC_%s/Fulltest.root",ROC));
// 	h1 = (TH2D*)g->Get("PixelMap_C0");
// 	h2 = (TH2D*)g->Get("vcals_xtalk_C0");
	for(ROC=1;ROC<5;ROC++)
	{
	for(Col=0; Col<3; Col=Col+2){
		for(Row=0; Row<3; Row=Row+2){
			TFile *f = new TFile(Form("../../singleROCTesting/output/ROC_%i/PulseShape_%i_%i.root",ROC,Col,Row));
			for(iCol=Col; iCol<52; iCol=iCol+4){
				for(iRow=Row; iRow<80; iRow=iRow+4){
// 					double bin1=h1->GetBinContent(iCol+1, iRow+1);
// 					double bin2=h2->GetBinContent(iCol+1, iRow+1);
// 					if (bin1<=0 /*|| bin2>=-5*/ ) {//dead pixels or bump problems
// 						/*if (bin1<=0){*/fs<<"Col "<<iCol<<" row "<<iRow<<endl;//}
						/*else if (bin2>=-5){fs1<<"Col "<<iCol<<" row "<<iRow"<<endl;}*/
// 					}
// 					else{
						cout<<iCol<<" "<<iRow<<endl;
						TGraph *PH = (TGraph*)f->Get(Form("PH_C%i_R%i",iCol,iRow));
						double X[256],Y[256];
						PHmax=0; int n=0;
						for (int i=0; i<PH->GetN(); i++){
							PH->GetPoint(i,X[i],Y[i]);
							if(Y[i]<=1){break;}
							else {n++;}
						}
						TGraphErrors* PH3=new TGraphErrors();
						for(int i=0;i<PH->GetN();i++){
							PH3->SetPoint(i,PH->GetX()[i],PH->GetY()[i]);
							PH3->SetPointError(i,0.,5.);
						}
						for (int i=PH->GetN();i>0;i--){
							if (Y[i] > PHmax) PHmax = Y[i];
						}
						for (int i=PH->GetN();i>0;i--){
							if (Y[i] > 0.9*PHmax){
								RT=X[i];
								break;
							}
						}
// 						RTMapOld->Fill(iCol,iRow,RT);
// 						RTDistrOld->Fill(RT);
						double x1,y1,z1;
						TF1 *fitProbe = new TF1("fitProbe","[0]+[1]*x*exp(-x/[2])", 15, 45);
						fitProbe->SetParameters(-10,8,40);
						PH3->Fit("fitProbe","R");
						x1=fitProbe->GetParameter(0);
						y1=fitProbe->GetParameter(1);
						z1=fitProbe->GetParameter(2);
						p0=x1;
						p1=y1;
						p2=z1;
						max=0.9*(p0+p1*p2*exp(-1));
						y=15;sw=1;
						while(sw==1){
							function=p0-max+p1*y*exp(-y/p2);
							derivative=p1*(1-y/p2)*exp(-y/p2);
							z=y-function/derivative;
							if(fabs(y-z)<0.001) {	sw=0; }
							y=z;
						}
// 						if (y>100){fs<<iCol<<"	"<<iRow<<" 	RT	"<<y<<endl;}
// 						else{
// 							RTMapNew->Fill(iCol,iRow,y);
							if(ROC==1) {RTDistr1->Fill(y);}
							if(ROC==2) {RTDistr2->Fill(y);}
							if(ROC==3) {RTDistr3->Fill(y);}
							if(ROC==4) {RTDistr4->Fill(y);}
// 							RTDistrNew->Fill(y);
// 							Diff->Fill(y-RT);
// 							RTime->Fill(iCol,iRow,y);
// 						}
					}
				}
			}
		}
	}
	RTDistr1->GetXaxis()->SetTitle("Risetime (ns)");
	RTDistr1->GetYaxis()->SetTitle("# of Pixel");
	RTDistr2->GetXaxis()->SetTitle("Risetime (ns)");
	RTDistr2->GetYaxis()->SetTitle("# of Pixel");
	RTDistr3->GetXaxis()->SetTitle("Risetime (ns)");
	RTDistr3->GetYaxis()->SetTitle("# of Pixel");
	RTDistr4->GetXaxis()->SetTitle("Risetime (ns)");
	RTDistr4->GetYaxis()->SetTitle("# of Pixel");

	TCanvas *J = new TCanvas ("laferia", "la feria");
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	J-> Divide(2,2);
	J->cd(1);
	RTDistr1->Draw();
	J->cd(2);
	RTDistr2->Draw();
	J->cd(3);
	RTDistr3->Draw();
	J->cd(4);
	RTDistr4->Draw();
// 	RTDistrNew->GetXaxis()->SetTitle("Risetime (ns)");
// 	RTDistrNew->GetYaxis()->SetTitle("# of Pixel");
// 	RTDistrOld->GetXaxis()->SetTitle("Risetime (ns)");
// 	RTDistrOld->GetYaxis()->SetTitle("# of Pixel");
// 	Diff->GetXaxis()->SetTitle("Risetime (ns)");
// 	Diff->GetYaxis()->SetTitle("# of Pixel");
// 	gStyle->SetPalette(1);
// 	RTMapNew->SetStats(kFALSE);
// 	RTMapOld->SetStats(kFALSE);
// 	RTMapNew->GetXaxis()->SetTitle("Columns");
// 	RTMapNew->GetYaxis()->SetTitle("Rows");
// 	RTMapOld->GetXaxis()->SetTitle("Columns");
// 	RTMapOld->GetYaxis()->SetTitle("Rows");
// 	new TCanvas;
// 	RTMapOld->Draw("COLZ");
// 	new TCanvas;
// 	RTMapNew->Draw("COLZ");
// 	new TCanvas;
// 	RTDistrOld->Draw();
// 	new TCanvas;
// 	RTDistrNew->Draw();
// 	new TCanvas;
// 	Diff->Draw();
// 	RTMapNew->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTMapNew_Temp_%i.root",ROC,Temp));
// 	RTMapNew->SaveAs(Form("../../../../Desktop/RtmapNew_%s.root",ROC));
// 	RTMapNew->SaveAs("/home/joaquin/Tesis/Rum_Joaquin/Graph/Rtmap_1.gif");
// 	RTMapOld->SaveAs(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/RtMapOld_%s.root",ROC));
// 	RTDistrOld->SaveAs(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/RtMapOld_%s.root",ROC));
// 	RTDistrNew->SaveAs(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/RtdistNew_%s.root",ROC));
// 	RTDistrNew->SaveAs("/home/joaquin/Tesis/Rum_Joaquin/Graph/Rtdist_1.gif");
// 	Diff->SaveAs(Form("/home/joaquin/Tesis/Rum_Joaquin/Graph/Diff_%s.root",ROC));
// 	Diff->SaveAs("/home/joaquin/Tesis/Rum_Joaquin/Graph/Diff_1.gif");
}





//risetime histograms for nonsensors ROCs
void Nosensor ()
{
	double bin;
	int i,j;
// 	TFile *f = new TFile(Form("../Rise_Time/output/ROC_%s/risetime.root",ROC));
	TFile *f = new TFile("../Rise_Time/output/ROC_1/risetime.root");
	TH2D *RT = (TH2D*)f->Get("risetime");
	TH1F *RtDis = new TH1F("Risetime distributions","Risetime distributions",130,15,45);
	cout<<"1"<<endl;
	for(i=1;i<52;i++){
		for(i=1;i<52;i++){
			bin=RT->GetBinContent(i,j);
			if (bin>0) {Rtdist->Fill(bin);}
		}
	}
	cout<<"2"<<endl;
	RT->Draw();
	cout<<"3"<<endl;
}

/*void Ratio()
{
	int RunNr[]={698,923,1149,1111,1006,1321};
	int notr1[]={};
	int notr2[]={};
	int r3E141[]={};
	int r3E142[]={};
	int r6E14[]={};
	int r12E142[]={};
// 	int r3142[]={};
	
	for(int i=0;i<5;i++){
		if(i<1000)TFile *f = new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",RunNr[i],RunNr[i]));
		else TFile *f = new TFile(Form("../../log/bt05r00%i/spectra_00%i.root",RunNr[i],RunNr[i]));
		TH1D *PHMain = (TH1D*)f->Get(Form("cQ1_%i",i));
		
// 		new TCanvas ;
// 		PHMain->Draw();
// 		PHMain->GetXaxis()->SetTitle("Charge (DAC)");
// 		PHMain->GetYaxis()->SetTitle("# pixels");
// 		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",i));
// 		Myfit->Draw("same");
// 		double MP=0.065*Myfit->GetParameter(1);
// 		double MPe=0.065*Myfit->GetParError(1);
// 		cout<<MP<<" +/- "<<MPe<<endl;
	}
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TFile *f = new TFile("../../log/bt05r000698/spectra_000698.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_698");
	CluSize->Draw();
	CluSize->SetTitle("");
	CluSize->GetYaxis()->SetTitle("# Pixels");
	CluSize->GetXaxis()->SetTitle("Cluster Size");
	CluSize->SetLineColor(1);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "Not irradiated", "L");
	
	TFile *f = new TFile("../../log/bt05r000923/spectra_000923.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_923");
	CluSize->Draw("Same");
	CluSize->SetLineColor(2);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "Not irradiated", "L");

	TFile *f = new TFile("../../log/bt05r001149/spectra_001149.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1149");
	CluSize->Draw("Same");
	CluSize->SetLineColor(3);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "3E14", "L");

	TFile *f = new TFile("../../log/bt05r001111/spectra_001111.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1111");
	CluSize->Draw("Same");
	CluSize->SetLineColor(4);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "3E14", "L");

	TFile *f = new TFile("../../log/bt05r001006/spectra_001006.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1006");
	CluSize->Draw("Same");
	CluSize->SetLineColor(6);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "6E14", "L");
	
	TFile *f = new TFile("../../log/bt05r001251/spectra_001251.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1251");
	CluSize->Draw("Same");
	CluSize->SetLineColor(7);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "1.2E15", "L");
	
	TFile *f = new TFile("../../log/bt05r001321/spectra_001327.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1321");
	CluSize->Draw("Same");
	CluSize->SetLineColor(9);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "1.2E15", "L");
	leg->Draw();
}*/

//the risetime plots for one pixel
void RTunic(const char *ROC, int Col, int Row, int iCol, int iRow)
{
	int sw;
	double PHmax=0,RT,p0,p1,p2,function,derivative,z,max,y;
	TFile *f = new TFile(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/PulseShape_%i_%i.root",ROC,Col,Row));
	TGraph *PH = (TGraph*)f->Get(Form("PH_C%i_R%i",iCol,iRow));
	double X[256],Y[256];
	PHmax=0; int n=0;
	for (int m=0; m<256; ++m)
	{
		PH->GetPoint(m,X[m],Y[m]);
	}
// 	TGraphErrors* PH3=new TGraphErrors();
// 	for(int i=0;i<PH->GetN();i++)
// 	{
// 		PH3->SetPoint(i,PH->GetX()[i],PH->GetY()[i]);
// 		PH3->SetPointError(i,0.,5.);
// 	}
	TF1 *fitProbe = new TF1("fitProbe","[0]+[1]*x*exp(-x/[2])", 15, 45);
	fitProbe->SetParameters(-10,8,40);
	PH->Fit("fitProbe","R");
	p0=fitProbe->GetParameter(0);
	p1=fitProbe->GetParameter(1);
	p2=fitProbe->GetParameter(2);
	max=0.9*(p0+p1*p2*exp(-1));
	y=25;sw=1;
	while(sw==1)
	{
		function=p0-max+p1*y*exp(-y/p2);
		derivative=p1*(1-y/p2)*exp(-y/p2);
		z=y-function/derivative;
		if(fabs(y-z)<0.001) {	sw=0; }
		y=z;
	}
	PH->Draw("AP");
	PH->SetMarkerSize(0.5);			//change the size of the markers
	PH->SetMarkerStyle(21);
	PH->SetMarkerColor(4);
	gStyle->SetFillColor(0);		//remove the background color in default histograms
	gStyle->SetCanvasColor(10);		//remove the color in the histograms.
	PH->GetYaxis()->SetTitle("Pulse Height (Vcal)");
	PH->GetXaxis()->SetTitle("Time (ns)");
	
}

void Pretest2()
{
	TFile *f = new TFile("../Rise_Time/output/ROC_1/PreteFulltest.root");
	TH2D *PHMain = (TH2D*)f->Get("PixelMap_C0");
	int i,j,Pixellive=0,PixelDead=0;
	double bin;
	TH1F *Pix = new TH1F("Pixels distributions","Pixels distributions",130,0,50);
	for( i=0;i<52;i++)
	{
		for(j=0;j<80;j++)
		{
			bin=PHMain->GetBinContent(i,j);
			Pix->Fill(bin);
			if(bin==10) Pixellive++;
			else PixelDead++;
		}
	}
	gStyle->SetPalette(1);
	Pix->Draw();
	cout<<"Live Pixels "<<Pixellive<<" dead pixel "<<PixelDead<<endl;
}

//make the pixel maps plots reading the pretest file.
void PulseHeight()
{
	TFile *f = new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T0/Pretest.root");
	TH2D *PHMain = (TH2D*)f->Get("PHVcal_VoffsetOp50_VOffsetR0120_C0");
	PHMain->GetXaxis()->SetTitle("Vcal (DAC Units)");
	PHMain->GetYaxis()->SetTitle("PH (ADC units)");
	PHMain->SetMarkerColor(2);
	PHMain->SetStats(kFALSE);
	PHMain->SetTitle("Pulse Height Calibration");
	PHMain->Draw();
	/*int i,j,Pixellive=0,PixelDead=0;
	double bin;
	TH2F *Pix = new TH1F("Pixels distributions","Pixels distributions",130,0,50);
	for( i=0;i<52;i++)
	{
		for(j=0;j<80;j++)
		{
			bin=PHMain->GetBinContent(i,j);
			Pix->Fill(bin);
			if(bin==10) Pixellive++;
			else PixelDead++;
		}
	}
// 	gStyle->SetPalette(1);
	Pix->Draw();
	cout<<"Live Pixels "<<Pixellive<<" dead pixel "<<PixelDead<<endl;*/
	
}

//make the risetime vs temperature plots
void RT_vs_Temp(const char *ROC, int Temp)
{
	int Col=0,Row=0,iRow,iCol,sw;
	double PHmax=0,RT,p0,p1,p2,function,derivative,z,max,y;
	TH2F *RTMapOld = new TH2F(Form("RTMapOld_%i",Temp),Form("RTMapOld_%i",Temp),52,0,52,80,0,80);
	TH1F *RTDistrOld = new TH1F(Form("RTDistrOld_%i",Temp),Form("RTDistrOld_%i",Temp),130,0,50);
	TH2F *RTMapNew = new TH2F(Form("RTMapNew_%i",Temp),Form("RTMapNew_%i",Temp),52,0,52,80,0,80);
	TH2F *RTime = new TH2F("risetime","risetime",52,0,52,80,0,80);
	TH1F *RTDistrNew = new TH1F(Form("RTDistrNew_%i",Temp),Form("RTDistrNew_%i",Temp),130,0,50);
	TH1F *Diff = new TH1F(Form("diff_Temp_%i",Temp),Form("diff_Temp_%i",Temp),130,-8,8);
	TFile *f = new TFile(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/PulseShape_%i.root",ROC,Temp));
	ofstream Data(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Risetime.txt",ROC));
	Data<<"Pixel	Old	new	Diff"<<endl;
	for(iCol=Col; iCol<52; iCol=iCol+6)
	{
		for(iRow=Row; iRow<80; iRow=iRow+6)
		{
			TGraph *PH = (TGraph*)f->Get(Form("PH_C%i_R%i",iCol,iRow));
			double X[256],Y[256];
			PHmax=0; int n=0;
			cout<<iCol<<"	"<<iRow<<endl;
			for (int m=0; m<256; ++m)
			{
				PH->GetPoint(m,X[m],Y[m]);
			}
			TGraphErrors* PH3=new TGraphErrors();
			for(int i=0;i<PH->GetN();i++)
			{
				PH3->SetPoint(i,PH->GetX()[i],PH->GetY()[i]);
				PH3->SetPointError(i,0.,5.);
			}
			for (int i=256;i>0;--i)
			{
				if (Y[i] > PHmax) PHmax = Y[i];
			}
			for (int i=256;i>0;i--)
			{
				if (Y[i] > 0.9*PHmax)
				{
					RT=X[i];
					break;
				}
			}
			RTMapOld->Fill(iCol,iRow,RT);
			RTDistrOld->Fill(RT);
			TF1 *fitProbe = new TF1("fitProbe","[0]+[1]*x*exp(-x/[2])", 15, 45);
			fitProbe->SetParameters(-10,8,40);
			PH3->Fit("fitProbe","R");
			p0=fitProbe->GetParameter(0);
			p1=fitProbe->GetParameter(1);
			p2=fitProbe->GetParameter(2);
			max=0.9*(p0+p1*p2*exp(-1));
			y=15;sw=1;
			while(sw==1)
			{
				function=p0-max+p1*y*exp(-y/p2);
				derivative=p1*(1-y/p2)*exp(-y/p2);
				z=y-function/derivative;
				if(fabs(y-z)<0.001) {	sw=0; }
				y=z;
			}
			if (y>18){
				RTDistrNew->Fill(y);
				RTMapNew->Fill(iCol,iRow,y);
				RTime->Fill(iCol,iRow,y);
				Diff->Fill(y-RT);
				Data<<"C"<<iCol<<"_R"<<iRow<<"	"<<RT<<"	"<<y<<"	"<<y-RT<<endl;
			}
		}
	}
	Data<<endl;
	Data<<"Mean old "<<RTDistrOld->GetMean()<<endl;
	Data<<"Mean new "<<RTDistrNew->GetMean()<<endl;
	RTDistrOld->GetXaxis()->SetTitle("Time (ns)");
	RTDistrOld->GetYaxis()->SetTitle("# of pixels");
	RTime->GetXaxis()->SetTitle("Columns");
	RTime->GetYaxis()->SetTitle("Rows");
	RTDistrNew->GetXaxis()->SetTitle("Time (ns)");
	RTDistrNew->GetYaxis()->SetTitle("# of pixels");
	RTMapOld->GetXaxis()->SetTitle("Columns");
	RTMapOld->GetYaxis()->SetTitle("Rows");
	RTMapNew->GetXaxis()->SetTitle("Columns");
	RTMapNew->GetYaxis()->SetTitle("Rows");
	gStyle->SetPalette(1);
	RTMapNew->SetStats(kFALSE);
	RTime->SetStats(kFALSE);
// 	RTMapOld->SetStats(kFALSE);
// 	RTMapOld->Draw("COLZ");
	new TCanvas;
	RTMapNew->Draw("COLZ");
	new TCanvas;
	RTDistrOld->Draw();
	new TCanvas;
	RTDistrNew->Draw();
// 	new TCanvas;
// 	Diff->Draw();
	new TCanvas;
	RTime->Draw("COLZ");
	RTMapNew->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTMapNew_Temp_%i.root",ROC,Temp));
// 	RTMapOld->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTMapOld_Temp_%i.root",ROC,Temp));
// 	RTDistrOld->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTDistrOld_Temp_%i.root",ROC,Temp));
	RTDistrNew->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTDistrNew_Temp_%i.root",ROC,Temp));
// 	Diff->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Diff_Temp_%i.root",ROC,Temp));
	RTime->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/risetime.root",ROC,Temp));
	Data.close();
}


//risetime for a single run
void RTSolo(const char *ROC)
{
	int Col=0,Row=0,iRow,iCol,sw;
	double PHmax=0,RT,p0,p1,p2,function,derivative,z,max,y;
	TH2F *RTMapOld = new TH2F(Form("RTMapOld_%s",ROC),Form("RTMapOld_%s",ROC),52,0,52,80,0,80);
	TH1F *RTDistrOld = new TH1F(Form("RTDistrOld_%s",ROC),Form("RTDistrOld_%s",ROC),100,0,50);
	TH2F *RTMapNew = new TH2F(Form("RTMapNew_%s",ROC),Form("RTMapNew_%s",ROC),52,0,52,80,0,80);
	TH1F *RTDistrNew = new TH1F(Form("RTDistrNew_%s",ROC),Form("RTDistrNew_%s",ROC),100,0,50);
	TH1F *Diff = new TH1F(Form("diff_ROC_%s",ROC),Form("diff_ROC_%s",ROC),60,-8,8);
	TH2F *RTime = new TH2F("risetime","risetime",52,0,52,80,0,80);

	ofstream fs3(Form("../slc5/Output/Efficiency_measurements/ROC_%s/risetime.txt", ROC));
	fs3<<"Col	row	RTnew	RTold	new-old	Chi/NDF"<<endl;
	ofstream fs4(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Fit_Problems.txt", ROC));
	fs4<<"Col	row	RT"<<endl;
	TFile *f = new TFile(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/PulseShape_0_0.root",ROC));
	for(iCol=Col; iCol<52; iCol=iCol+4){
		for(iRow=Row; iRow<80; iRow=iRow+4){
			cout<<iCol<<" "<<iRow<<endl;
			TGraph *PH = (TGraph*)f->Get(Form("PH_C%i_R%i",iCol,iRow));
			double X[256],Y[256];
			PHmax=0; int n=0;
			for (int i=0; i<PH->GetN(); i++){
			PH->GetPoint(i,X[i],Y[i]);
			if(Y[i]<=1){break;}
				else {n++;}
			}
			TGraphErrors* PH3=new TGraphErrors();
			for(int i=0;i<PH->GetN();i++){
				PH3->SetPoint(i,PH->GetX()[i],PH->GetY()[i]);
				PH3->SetPointError(i,0.,5.);
			}
			for (int i=PH->GetN();i>0;i--){
				if (Y[i] > PHmax) PHmax = Y[i];
			}
			for (int i=PH->GetN();i>0;i--){
				if (Y[i] > 0.9*PHmax){
					RT=X[i];
					break;
				}
			}
			RTMapOld->Fill(iCol,iRow,RT);
			RTDistrOld->Fill(RT);
			double x1,y1,z1;
			TF1 *fitProbe = new TF1("fitProbe","[0]+[1]*x*exp(-x/[2])", 15, 45);
			fitProbe->SetParameters(-10,8,40);
			PH3->Fit("fitProbe","R");
			x1=fitProbe->GetParameter(0);
			y1=fitProbe->GetParameter(1);
			z1=fitProbe->GetParameter(2);
			p0=x1;
			p1=y1;
			p2=z1;
			max=0.9*(p0+p1*p2*exp(-1));
			y=15;sw=1;
			while(sw==1){
				function=p0-max+p1*y*exp(-y/p2);
				derivative=p1*(1-y/p2)*exp(-y/p2);
				z=y-function/derivative;
				if(fabs(y-z)<0.0001) {	sw=0; }
				y=z;
			}
			if (y>100){fs4<<iCol<<"	"<<iRow<<"	"<<y<<endl;}
			else{
				RTMapNew->Fill(iCol,iRow,y);
				RTDistrNew->Fill(y);
				Diff->Fill(y-RT);
				RTime->Fill(iCol,iRow,y);
				cout<<fitProbe->GetChisquare()<<endl;
				fs3<<iCol<<" "<<iRow<<"	"<<y<<"	"<<RT<<"	"<<y-RT<<"	"<<fitProbe->GetChisquare()<<"/"<<fitProbe->GetNDF()<<"	"<<PH->GetN()<<endl;
			}
		}
	}
	new TCanvas;
	RTime->GetXaxis()->SetTitle("Columns");
	RTime->GetYaxis()->SetTitle("Rows");
	RTime->SetStats(kFALSE);
	RTime->Draw("COLZ");
	RTime->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/risetime.root",ROC));
	gStyle->SetPalette(1);
	RTMapNew->SetStats(kFALSE);
	RTMapOld->SetStats(kFALSE);
	new TCanvas;
	RTMapOld->Draw("COLZ");
	new TCanvas;
	RTMapNew->Draw("COLZ");
	new TCanvas;
	RTDistrOld->Draw();
	new TCanvas;
	RTDistrNew->Draw();
	new TCanvas;
	Diff->Draw();
	RTMapNew->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTMapNew_ROC_%s.root",ROC,ROC));
	RTMapOld->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTMapOld_ROC_%s.root",ROC,ROC));
	RTDistrOld->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTDistrOld_ROC_%s.root",ROC,ROC));
	RTDistrNew->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/RTDistrNew_ROC_%s.root",ROC,ROC));
	Diff->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Diff_ROC_%s.root",ROC,ROC));
}

//make the IVtest plots
void IV_Test(const char *ROC)
{

	double Vbias[80];
	double Ileak[80];
	double Ileak1[80];
	ifstream read_in;
	char IVFile [200];
	sprintf(IVFile,"/home/l_tester/slc5/Output/Efficiency_measurements/ROC_%s/IV_Test.txt",ROC);
	read_in.open(IVFile);
	int n=0;//Line number
	cout << "Reading file " << IVFile << endl;
	cout << "Bias         I leak  "<< endl;
	while(!read_in.eof() && read_in >> Vbias[n] >> Ileak[n])
	{
		cout << Vbias[n] <<"	"<< Ileak[n] << endl;
		Ileak1[n]=-Ileak[n];
		n++;
	}
	cout<<n<<endl;
	read_in.close();
	TGraph *IVG = new TGraph (n, Vbias, Ileak1);
	IVG->Draw("AP*");
	IVG->SetTitle(Form("Leakage Current vs Bias Voltage (%s)",ROC));
	IVG->GetXaxis()->SetTitle("Voltage (V)");
	IVG->GetYaxis()->SetTitle("I leak (A)");
	IVG->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/IV_Test.root", ROC ));
}

//make the delay scan plots
void Delay_Scan(const char *ROC)
{
	int n=15,i,j,k=0; //n= # points plus 1
	TString A[35][35];
	float B[35][35],D1[15],E1[15],D2[15],E2[15],D3[15],E3[15],D4[15],E4[15],D5[15],E5[15],E6[15],E7[15];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Delay_Scan.txt",ROC));
	for(i=0;i<35;i++){
		for(j=0;j<8;j++){
			if(i==0) {fs>>A[i][j];}
			else {fs>>B[i][j];}
		}
	}
	
	j=0;
	for(i=0;i<9;i++)	{
		if(i==0) {cout<<endl;}
		if(i>0)
		{
			D1[j]=B[i][0];
			E1[j]=B[i][1];
			E2[j]=B[i][2];
			E3[j]=B[i][3];
			E4[j]=B[i][4];
			E5[j]=B[i][5];
			E6[j]=B[i][6];
			E7[j]=B[i][7];
			cout<<D1[j]<<"	"<<E1[j]<<"	"<<E2[j]<<"	"<<E3[j]<<"	"<<E4[j]<<"	"<<E5[j]<<"	"<<E6[j]<<"	"<<E7[j]<<endl;
			j++;
		}
	}
	TGraph *Del1 = new TGraph (j, D1, E1);
	Del1->Draw("AP");
	Del1->SetMinimum(0.0);
	Del1->SetMaximum(100);
	Del1->SetTitle("Efficiency vs Clock delay at differents Trigger delays");
	Del1->GetXaxis()->SetTitle("Delay (ns)");
	Del1->GetYaxis()->SetTitle("Efficiency (%)");
	Del1->SetMarkerStyle(21);
	Del1->SetMarkerColor(1);

	TGraph *Del2 = new TGraph (j, D1, E2);
	Del2->SetMarkerStyle(20);
	Del2->SetMarkerColor(2);
	Del2->Draw("CP");

	TGraph *Del3 = new TGraph (j, D1, E3);
	Del3->SetMarkerStyle(22);
	Del3->SetMarkerColor(3);
	Del3->Draw("CP");

	TGraph *Del4 = new TGraph (j, D1, E4);
	Del4->SetMarkerStyle(3);
	Del4->SetMarkerColor(4);
	Del4->Draw("CP");

	TGraph *Del5 = new TGraph (j, D1, E5);
	Del5->SetMarkerStyle(25);
	Del5->SetMarkerColor(5);
	Del5->Draw("CP");

	TGraph *Del6 = new TGraph (j, D1, E6);
	Del6->SetMarkerStyle(27);
	Del6->SetMarkerColor(6);
	Del6->Draw("CP");

	TGraph *Del7 = new TGraph (j, D1, E7);
	Del7->SetMarkerStyle(28);
	Del7->SetMarkerColor(7);
	Del7->Draw("CP");

	TLegend* leg = new TLegend(0.85, 0.75, .75, .89);
	leg->SetBorderSize(0);
// 	leg->SetTitle("");
	leg->SetLineColor(0);
	leg->AddEntry(Del1, "4 ns", "P");
	leg->AddEntry(Del2, "8 ns", "P");
	leg->AddEntry(Del3, "12 ns", "P");
	leg->AddEntry(Del4, "16 ns", "P");
	leg->AddEntry(Del5, "20 ns", "P");
	leg->AddEntry(Del6, "24 ns", "P");
	leg->AddEntry(Del6, "28 ns", "P");
	leg->Draw();
	c1->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Delay_Scan.gif",ROC));
}

//make the most probable value and efficiency plots for one ROC
void CCE_Plots(const char *ROC)
{
	gStyle->SetOptFit(1111);
	int n=30,i,j,k=0;
	TString A[30][30];
	double B[30][30],V[30],E[30],Ev[30],Emp[30],MP[30];
	int R[30];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Data.txt", ROC ));
	
	// Reading the data (Run_#, Voltage and Efficiency)
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			if(i==0) {fs>>A[i][j];}
			else {
				fs>>B[i][j];
				if (B[i][j]!=0) k++;
			}
		}
// 		cout<<i<<"	"<<k/3<<endl;
	}
	j=0;
	for(i=0;i<(k/3)+1;i++){
		if(i==0) cout<</*A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<*/endl;
		if(i>0){
			V[j]=B[i][0];
			R[j]=B[i][1];
			E[j]=B[i][2];
// 			cout<<R[j]<<" "<<V[j]<<" "<<E[j]<<endl;
			j++;
		}
	}
	//Reading the most probable values from the files
	for(i=0;i<j;i++){
		if(R[i]<1000) TFile *f= new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",R[i],R[i]));
		else TFile *f= new TFile(Form("../../log/bt05r00%i/spectra_00%i.root",R[i],R[i]));
		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",R[i]));
		MP[i]=(0.065)*(Myfit->GetParameter(1));
		Emp[i]=(0.065)*(Myfit->GetParError(0));
		Ev[i]=0;
// 		cout<<Myfit->GetParameter(0)<<"	"<<Myfit->GetParameter(1)<<"	"<<Myfit->GetParameter(2)<<"	"<<Myfit->GetParameter(3)<<endl;
	}
// 	new TCanvas;
// 	Myfit->Draw();
	//Making the plots
	TFile *aaa =new TFile(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/CCE_Plots.root",ROC),"RECREATE");
	TCanvas* c1_=new TCanvas();
	TGraph *E_V = new TGraph (j, V, E);
	E_V->SetTitle(Form("Efficiecy vs Bias Voltage ROC_%s", ROC));
	E_V->SetName("Efficiecy_vs_Vbias");
	E_V->SetMinimum(0.0);
	E_V->SetMaximum(110.0);
	E_V->Draw("AP*");
	E_V->GetXaxis()->SetTitle("Vbias (V)");
	E_V->GetYaxis()->SetTitle("Efficiency (%)");
	c1_->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/Eff_vs_Vbias.gif",ROC));
	
	TCanvas* c2_=new TCanvas();
	TGraphErrors *H_Vb = new TGraphErrors (j, V, MP, Ev, Emp);
	H_Vb->SetTitle(Form("Most Probable Value vs Vbias ROC_%s",ROC));
	H_Vb->SetName("Most_Probable_Value_vs_Vbias");
	H_Vb->SetMinimum(0.0);
	H_Vb->SetMaximum(30.0);
	H_Vb->Draw("AP*");
	H_Vb->GetXaxis()->SetTitle("Vbias (v)");
	H_Vb->GetYaxis()->SetTitle("Charge (Ke^{- })");
	c2_->SaveAs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/MPV_vs_Vbias.gif",ROC));

	E_V->Write();
	H_Vb->Write();
	aaa->Write();
	aaa->Close();
}

//linearity of the p1
void linearity(const char *ROC, int k)
{
	FILE *inputFile;
	int a,b;
	float par0, par1, par2, par3, par4, par5
	float A[52][80];
	char string[200];
	ofstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_8613-08-09_12E14_2/ph_%i.txt",k));
	sprintf(string, "%s/phCalibrationFitTan_C0.dat", ROC);
	inputFile = fopen(string, "r");
	if (!inputFile)
	{
		printf("chipSummary> !!!!!!!!!  ----> phCal: Could not open file %s to read fit results\n", string);
	}
	else
	{
		for (int i = 0; i < 2; i++) fgets(string, 200, inputFile);
		for (int icol = 0; icol < 52; ++icol)
		{
			for (int irow = 0; irow < 80; ++irow)
			{
				fscanf(inputFile, "%e %e %e %e %s %2i %2i", &par0, &par1, &par2, &par3, string, &a, &b);
				if (par2 != 0.)  // dead pixels have par2 == 0.
				{
// 					A[a][b]=par1;
					fs<<par1<<endl;
// 					cout<<par1<<endl;
				}
			}
		}
	}
	fs.close();
}

//linearity of trhe p1
void Mylinearity(const char *ROC)
{
	TString A[4163][7];
	float B[4160][7];
	int k=170,n=0;
	
	float p1[4160],p2[4160],p3[4160],p4[4160];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/phCalibrationFitTan_C0_%i.dat", ROC, k));
	for(int i=0;i<4160;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(i==0 || i==1 || i==2 ) {fs>>A[i][j];}
			else
			{
				fs>>B[i][j];
				if (j=2) n++;
				
			}
		}
	}
	cout<<n<<endl;
}

//calculate the most probable value for a specific run number
void MostProbableValue(int RunNr1, int RunNr2)
{
	for(int i=RunNr1;i<RunNr2;i++){
		gStyle->SetOptFit(1111);
		if(i<1000)TFile *f = new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",i,i));
		else TFile *f = new TFile(Form("../../log/bt05r00%i/spectra_00%i.root",i,i));
		TH1D *PHMain = (TH1D*)f->Get(Form("cQ1_%i",i));
		new TCanvas ;
		PHMain->Draw();
		PHMain->GetXaxis()->SetTitle("Charge (DAC)");
		PHMain->GetYaxis()->SetTitle("# pixels");
 		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",i));
	 	Myfit->Draw("same");
		double MP=0.065*Myfit->GetParameter(1);
		double MPe=0.065*Myfit->GetParError(1);
		cout<<MP<<" +/- "<<MPe<<endl;
	}	
}

//calculate the most probable value vs Vbias plots
void MostProbableValue_vs_Vbias(/*const char *ROC, int Temp*/)
{
/*	int n = 11,i;
	TGraph *MPV_Vb = new TGraph (n-1, V, MP);
	MPV_Vb->SetTitle("Most Probable Value vs Bias Voltage");
	MPV_Vb->Draw("ALP");
	MPV_Vb->GetXaxis()->SetTitle("Voltage (v)");
	MPV_Vb->GetYaxis()->SetTitle("Most Probable Value (e)");
	MPV_Vb->Draw("AP*");
*/
	int RunNr[]={478,479,480,481,482,483,484,487,488,489};
	double V[]={25,50,75,100,125,150,200,250,300,350};
	double eV[10];
	double mp[10],e_mp[10];	
	TFile *f;

	for(int i=0;i<10;i++){
	f= new TFile(Form("../../log/bt05r000%d/spectra_000%d.root",RunNr[i],RunNr[i]));
	TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%d",RunNr[i]));
	mp[i]=Myfit->GetParameter(1);
	e_mp[i]=Myfit->GetParError(1);
	eV[i]=0.;
	cout<<RunNr[i]<<"   "<<mp[i]<<"   "<<e_mp[i]<<endl;
	}
	
	cout<<"pokefkie"<<endl;
	TGraphErrors *H_Vb = new TGraphErrors (10, V, mp, eV, e_mp);
	H_Vb->SetTitle("Most pro vs Bias Voltage");
	H_Vb->Draw("ALP");
	H_Vb->GetXaxis()->SetTitle("Voltage (v)");
	H_Vb->GetYaxis()->SetTitle("Hits");
	H_Vb->Draw("AP*");

}


void risetime()
{
	double RT[] ={30.4,35,38.4,38.5};
	double RA[] ={0,0,3,6};
	double RTE[] ={1,3,1.6,2.5};
// 	double RAE[] = {};
// 	TGraphErrors *H_Vb = new TGraphErrors (10, V, mp, eV, e_mp);
	TGraphErrors *RTRA = new TGraphErrors (4, RA, RT, 0, RTE);
	RTRA->Draw("AP*");
}

// void gauus()
// {
// 	TH1F *h1 = new TH1F(Form("","",130,0,50);
// 	h1->FillRandom("gaus",10000);
// 	h1->Draw();
// }




void Hits_vs_Vbias(const char *ROC)
{

// 	std::vector <int> RunNr;
// 	RunNr.push_back(478);
// 	RunNr.push_back(479);	
// ......
// 
// 	RunNr.size()


	
	int RunNr[]={478,479,480,481,482,483,484,487,488,489};
	int V[]={25,50,75,100,125,150,200,250,300,350};
	int hits[10];	
	gStyle->SetOptFit(1111);
	TFile *f;
	for(int i=0;i<10;i++){
	f	= new TFile(Form("../../log/bt05r000%d/spectra_000%d.root",RunNr[i],RunNr[i]));
	TH1D *PHMain = (TH1D*)f->Get(Form("cQ1_%d",RunNr[i]));
	hits[i]=PHMain->GetEntries();
	}	
	
	TGraph *H_Vb = new TGraph (10, V, hits);
	H_Vb->SetTitle("Hits vs Bias Voltage");
	H_Vb->Draw("ALP");
	H_Vb->GetXaxis()->SetTitle("Voltage (v)");
	H_Vb->GetYaxis()->SetTitle("Hits");
	H_Vb->Draw("AP*");
}



void Prueba()
{
	char maskFileName[200];
	int i=0;
	float V,I;
	sprintf(maskFileName,"../PIRE/07-04-2011//T_5/IV_Test.txt");
	ifstream maskFile;
	maskFile.open(maskFileName);
	char keyWord[100], line[1000];
	while(maskFile.good())
	{
		maskFile>>keyWord;
		if (strcmp(keyWord,"#")==0)
		{
			maskFile.getline(line,60, '\n');
			cout << "# "<<line << endl;// ignore rows starting with "#" = comment
		}
		else
		{
			maskFile>>V>>I;
			cout<<V<<endl;//<<"	"<<I<<endl;
// 			i++;
		}
	}
}

void compostela(const char *ROC, int Temp)
{
	int n=14,i,j;
	TString A[15][15];
	float B[15][15],V[14],I[14],I1[14];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/T_%i/IV_Test.txt", ROC , Temp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==0) {fs>>A[i][j];}
			else { fs>>B[i][j];}
		}
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(i==0) cout<<endl;
		if(i>0)
		{
			V[j]=B[i][0];
			I[j]=B[i][1];
			I1[j]=B[i][2];
			cout<<V[j]<<"	"<<I[j]<<"	"<<I1[j]<<endl;
			j++;
		}
	}
	TGraph *IV = new TGraph (j, V, I);
	TGraph *IV1 = new TGraph (j, V, I1);
	IV->SetLineColor(4);
	IV->Draw("AC*");
	IV1->SetMarkerStyle(21);
	IV1->SetLineColor(2);
	IV1->Draw("CP");
}


void compostela2222(/*const char *ROC*/, int Temp)
{
	int n=12,i,j; //n= # points plus 1
	TString A[15][15];
	float B[15][15],V[14],I[14],I1[14],I2[14],I3[14],I4[14];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/T_%i/IV_TestVar.txt", ROC , Temp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			if(i==0) {fs>>A[i][j];}
			else { fs>>B[i][j];}
		}
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(i==0) cout<<endl;
		if(i>0)
		{
			V[j]=B[i][0];
			I[j]=B[i][1];
			I1[j]=B[i][2];
			I2[j]=B[i][3];
			I3[j]=B[i][4];
			I4[j]=B[i][5];
// 			cout<<V[j]<<"	"<<I[j]<<"	"<<I1[j]<<"	"<<I2[j]<<"	"<<I3[j]<<"	"<<I4[j]<<endl;
			j++;
		}
	}
	TGraph *IV = new TGraph (j, V, I);
	IV->Draw("AC*");
	IV->SetTitle("Leakage Current vs Bias Voltage at differents temperatures");
	IV->Draw("ALP");
	IV->GetXaxis()->SetTitle("Voltage (V)");
	IV->GetYaxis()->SetTitle("I leak (nA)");
	IV->SetLineColor(4);
	TGraph *IV1 = new TGraph (j, V, I1);
	IV1->SetMarkerStyle(18);
	IV1->SetLineColor(2);
	IV1->Draw("L same *");
	TGraph *IV2 = new TGraph (j, V, I2);
	IV2->SetMarkerStyle(21);
	IV2->SetLineColor(3);
	IV2->Draw("L same CP");
	TGraph *IV3 = new TGraph (j, V, I3);
	IV3->SetMarkerStyle(21);
	IV3->SetLineColor(1);
	IV3->Draw("L same *");
	TGraph *IV4 = new TGraph (j, V, I4);
	IV4->SetMarkerStyle(22);
	IV4->SetLineColor(5);
	IV4->Draw("L same *");
}


void compostela3333333333(const char *ROC, int Temp)
{
	int n=6,i,j; //n= # points plus 1
	TString A[15][15];
	float B[15][15],V[14],I[14],I1[14];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/T_%i/IV_TestMini.txt", ROC , Temp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==0) {fs>>A[i][j];}
			else { fs>>B[i][j];}
		}
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(i==0) cout<<endl;
		if(i>0)
		{
			V[j]=B[i][0];
			I[j]=B[i][1];
			I1[j]=B[i][2];
			cout<<V[j]<<"	"<<I[j]<<"	"<<I1[j]<<endl;
			j++;
		}
	}
	TGraph *IV = new TGraph (j, V, I);
	IV->Draw("AC*");
	IV->SetTitle("Leakage Current vs Temperature at differents Bias Voltage");
	IV->Draw("ALP");
	IV->GetXaxis()->SetTitle("Temperature (C)");
	IV->GetYaxis()->SetTitle("I leak (nA)");
	IV->SetLineColor(4);
	TGraph *IV1 = new TGraph (j, V, I1);
	IV1->SetMarkerStyle(18);
	IV1->SetLineColor(2);
	IV1->Draw("L same *");
	TF1 *fitProbe = new TF1("fitProbe","[0]*x*x*exp(-[1]/x)", -20, -2);
	fitProbe->SetParameters(10,8);
	IV->Fit("fitProbe","R");
	fitProbe->Draw("L same");
}


void IV(const char *ROC)
{
	int n=14,i,j;
	TString A[15][15];
	float B[15][15],V[14],I1[14],I2[14],I3[14],I4[14],I5[14];
	ifstream fs(Form("../../slc5/Output/Efficiency_measurements/ROC_%s/IV.txt", ROC ));
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			if(i==0) {
				fs>>A[i][j];
				cout<<A[i][j];
			}
			else {
				fs>>B[i][j];
				cout<<B[i][j];
			}
		}
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(i==0) cout<<endl;
		if(i>0)
		{
			V[j]=B[i][0];
			I1[j]=B[i][1];
			I2[j]=B[i][2];
			I3[j]=B[i][3];
			I4[j]=B[i][4];
			I5[j]=B[i][5];
			cout<<V[j]<<"	"<<I1[j]<<"	"<<I2[j]<<"	"<<I3[j]<<"	"<<I4[j]<<"	"<<I5[j]<<endl;
			j++;
		}
	}
	TGraph *IV1 = new TGraph (j, V, I1);
	TGraph *IV2 = new TGraph (j, V, I2);
	TGraph *IV3 = new TGraph (j, V, I3);
	TGraph *IV4 = new TGraph (j, V, I4);
	TGraph *IV5 = new TGraph (j, V, I5);
	IV1->SetLineColor(4);
	IV1->Draw("AC*");
	IV2->SetMarkerStyle(21);
	IV2->SetLineColor(2);
	IV2->Draw("CP");
// 	IV->SetTitle("Leakage Current vs Bias Voltage");
// 	IV->Draw("ALP");
// 	IV->GetXaxis()->SetTitle("Voltage (v)");
// 	IV->GetYaxis()->SetTitle("I leak (nA)");
// 	IV->Draw("AP*");
}

void Plots(/*const char *ROC, int Temp*/)
{
	int runN[5]={518,519,520,521,522};
	double Pos[5]={1,2,3,4,5};
	TFile *f;
	double MP[5],Sig[5],Wd[5],eMP[5],eSig[5],eWd[5];
	for(int i=0;i<5;i++)
	{
		f= new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",runN[i],runN[i]));
		TH1D *PH = (TH1D*)f->Get(Form("cQ1_%d",runN[i]));
		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",runN[i]));
		Wd[i]=Myfit->GetParameter(0);
		cout<<Wd[i]<<"	";
// 		eWd[i]=Myfit->GetParError(0);
		MP[i]=Myfit->GetParameter(1);
		cout<<MP[i]<<"	";
// 		eMP[i]=Myfit->GetParError(1);
		Sig[i]=Myfit->GetParameter(3);
// 		eSig[i]=Myfit->GetParError(3);
		cout<<endl;
	}
	TGraph *MPV = new TGraph (i, Pos, MP);
	MPV->Draw("AP*");
	MPV->SetTitle("MP value vs source's position");
	MPV->GetXaxis()->SetTitle("Source's Position (Arbitrary units)");
	MPV->GetYaxis()->SetTitle("MP values (e)");
	new TCanvas;
	TGraph *WD = new TGraph (i, Pos, Wd);
	WD->Draw("AP*");
	WD->SetTitle("Width vs source's position");
	WD->GetXaxis()->SetTitle("Source's Position (Arbitrary units)");
	WD->GetYaxis()->SetTitle("Width (e)");
	new TCanvas;
	TGraph *Si = new TGraph (i, Pos, Sig);
	Si->Draw("AP*");
	Si->SetTitle("Sigma vs source's position");
	Si->GetXaxis()->SetTitle("Source's Position (Arbitrary units)");
	Si->GetYaxis()->SetTitle("Sigma (e)");
}

void MPV_Temp()
{
	int runN[8]={523,483,545,588,567,578,599,609};
	int runN1[8]={524,484,547,590,569,580,601,611};
	double Temp[8]={20,5,2,0,-5,-10,-15,-20};
	double MP[8],MP1[8],eMP[8],eMP1[8];
	TFile *f,*g;
	for(int i=0;i<8;i++){
		f= new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",runN[i],runN[i]));
		g= new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",runN1[i],runN1[i]));
		TH1D *PH = (TH1D*)f->Get(Form("cQ1_%d",runN[i]));
		TH1D *PH1 = (TH1D*)g->Get(Form("cQ1_%d",runN1[i]));
		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",runN[i]));
		TF1 *Myfit1 = (TF1*)g->Get(Form("Fitfcn_cQ1_%i",runN1[i]));
		MP[i]=Myfit->GetParameter(1);
		eMP[i]=Myfit->GetParError(1);
		MP1[i]=Myfit1->GetParameter(1);
		eMP1[i]=Myfit1->GetParError(1);
	}
	TGraph *MPV = new TGraph (i, Temp, MP);
	MPV->Draw("AP");
	MPV->SetTitle("MP value vs Temperature");
	MPV->GetXaxis()->SetTitle("Temperature (C)");
	MPV->GetYaxis()->SetTitle("MP values (e)");
	MPV->SetMarkerStyle(22);
	MPV->SetLineWidth(1);
	MPV->SetLineColor(1);
	TGraph *MPV1 = new TGraph (i, Temp, MP1);
	MPV1->SetMarkerStyle(21);
	MPV1->SetLineWidth(2);
	MPV1->SetLineColor(2);
	MPV1->SetMarkerColor(2);
	MPV1->Draw("P");
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(MPV, "150V", "P");
	leg->AddEntry(MPV1, "200V", "P");
	leg->Draw();
	c1->SaveAs("../PIRE/07-04-2011//MPV_vs_Temp.gif");


}

//all dac plot as a function of temperature
void All_Plots()
{
	float Temp2[10]={293,278,275,273,268,263,258,253,293,268};
	float TempErr[8]={0.3};
	
	/*float Vana[8]={170,175,176,176,177,182,185,189};
	float VanaErr[8]={0};*/
	
	/*float CalDel[8]={73,75,76,77,77,79,80,81};
	float CalDelErr[8]={0};*/
	
	float VThr[8]={99,98,98,100,97,95,94,93};
	float VThrErr[8]={0};
	
	float VTrim[8]={136,137,147,143,145,148,147,152};
	float VTrimErr[8]={0};
	
	float Temp[8]={20,5,2,0,-5,-10,-15,-20};
	/*float RTime[8]={28.4,28.3,27.4,27.9,24.9,31.3,28.6,27.1};
	float RTimeErr[8]={0.9,1.2,0.9,1.1,1.9,1,1.4,1.2};*/

	/*float I[8]={37,19,17,16,13,7};
	float Tem[6]={293,278,275,273,268,253};
	float IErr[8]={0};*/

	/*float MP[8]={21.8,22.3,22.1,21.9,21.8,20.8,20.6,20};
	float MPErr[8]={0.9,0.8,0.8,0.6,0.7,0.8,1.2,2.1};*/
	
	/*float [8]={142.5,145,144.6,145.3,143.3,144.8,145.6,138.3};
	float NoiseErr[8]={15.9,13.8,13.8,13.9,16.2,14.8,15.2,16.2};*/

	/*TCanvas* c1=new TCanvas();
	TGraphErrors *VaT = new TGraphErrors (8, Temp, Vana, TempErr, VanaErr);
	VaT->Draw("AP*");
	VaT->SetTitle("Vana vs Temperature");
	VaT->GetXaxis()->SetTitle("Temperature (C)");
	VaT->GetYaxis()->SetTitle("Vana (DAC units)");
	VaT->SetMinimum(0);
	VaT->SetMaximum(210);
// 	c1->SaveAs("../PIRE/07-04-2011//Vana_vs_Temp.gif");*/
	
	/*TCanvas* c2=new TCanvas();
	TGraphErrors *VCaT = new TGraphErrors (8, Temp, CalDel, TempErr, CalDelErr);
	VCaT->Draw("AP*");
	VCaT->SetTitle("CalDel vs Temperature");
	VCaT->GetXaxis()->SetTitle("Temperature (C)");
	VCaT->GetYaxis()->SetTitle("CalDel (DAC units)");
	VCaT->SetMinimum(0.0);
	VCaT->SetMaximum(110.0);
	VCaT->SetMinimum(0.0);
	VCaT->SetMaximum(100);*/
// 	c2->SaveAs("../PIRE/07-04-2011//CalDel_vs_Temp.gif");

	TCanvas* c3=new TCanvas();
	TGraphErrors *VtrT = new TGraphErrors (8, Temp, VTrim, TempErr, VTrimErr);
	VtrT->Draw("AP*");
	VtrT->SetTitle("VTrim vs Temperature");
	VtrT->GetXaxis()->SetTitle("Temperature (C)");
	VtrT->GetYaxis()->SetTitle("Vtrim (DAC units)");
	VtrT->SetMinimum(0.0);
	VtrT->SetMaximum(170);
// 	c3->SaveAs("../PIRE/07-04-2011//VTrim_vs_Temp.gif");

	TCanvas* c4=new TCanvas();
	TGraphErrors *VtrhT = new TGraphErrors (8, Temp, VThr, TempErr, VThrErr);
	VtrhT->Draw("AP*");
	VtrhT->SetTitle("Vthreshold vs Temperature");
	VtrhT->GetXaxis()->SetTitle("Temperature (C)");
	VtrhT->GetYaxis()->SetTitle("Vtthr (DAC units)");
	VtrhT->SetMinimum(0.0);
	VtrhT->SetMaximum(120);
// 	c4->SaveAs("../PIRE/07-04-2011//VThr_vs_Temp.gif");

	/*TCanvas* c5=new TCanvas();
	TGraphErrors *RT = new TGraphErrors (8, Temp, RTime, TempErr, RTimeErr);
	RT->Draw("AP*");
	RT->SetTitle("Risetime vs Temperature");
	RT->GetXaxis()->SetTitle("Temperature (C)");
	RT->GetYaxis()->SetTitle("Risetime (ns)");
	RT->SetMinimum(0.0);
	RT->SetMaximum(40);
// 	c5->SaveAs("../PIRE/07-04-2011//Rtime_vs_Temp.gif");*/

	/*TCanvas* c6=new TCanvas();
	TGraphErrors *NoiseT = new TGraphErrors (8, Temp, Noise, TempErr, NoiseErr);
	NoiseT->Draw("AP*");
	NoiseT->SetTitle("Noise vs Temperature");
	NoiseT->GetXaxis()->SetTitle("Temperature (C)");
	NoiseT->GetYaxis()->SetTitle("Noise (e)");
	NoiseT->SetMinimum(0.0);
	NoiseT->SetMaximum(180);
// 	c6->SaveAs("../PIRE/07-04-2011//Noise_vs_Temp.gif");*/
	
	/*TCanvas* c7=new TCanvas();
	TGraphErrors *MPT = new TGraphErrors (8, Temp, MP, TempErr, MPErr);
	MPT->Draw("AP*");
	MPT->SetTitle("MP Value vs Temperature");
	MPT->GetXaxis()->SetTitle("Temperature (C)");
	MPT->GetYaxis()->SetTitle("MP Value (Ke^{- })");
	MPT->SetMinimum(0.0);
	MPT->SetMaximum(30);
// 	c7->SaveAs("../PIRE/07-04-2011//MPV_vs_Temp.gif");*/

	/*TCanvas* c8=new TCanvas();
	TGraphErrors *LekT = new TGraphErrors (6, Tem, I, TempErr, IErr);
	LekT->Draw("AP*");
	LekT->SetTitle("Current vs Temperature at 150V");
	LekT->GetXaxis()->SetTitle("Temperature (K)");
	LekT->GetYaxis()->SetTitle("Leakeage Current (nA)");
// 	float As[8];
// 	for(int i=0;i<8;i++)
	TF1 *fite = new TF1("fite","[0]*x*x*exp(-[1]/x)", 253, 294);
	fite->SetParameters(200000,5000);
	LekT->Fit("fite","R");
// 	LekT->Fit("fite","R");
// 	{
// 		fite=2000000*Temp2[i]*Temp2[i]*exp(-6511/Temp2[i]);
// 	}
	
// 	TGraphErrors *LekTw = new TGraphErrors (8, Temp2, As);
// 	LekTw->SetMarkerColor(2);
// 	fite->SetParameter(100);
	fite->Draw("L Same");
// 	c8->SaveAs("../PIRE/07-04-2011//Leak_vs_Temp.gif");*/
}

void Scurve(int col, int row)
{
	double Temp[8]={20,5,2,0,-5,-10,-15,-20};
	TFile *f;
	TCanvas* c1=new TCanvas();
	TMultiGraph *Scurve = new TMultiGraph();
	TGraph* SC[8];	
		for(int i=0;i<8;i++){
			f= new TFile(TString::Format("../PIRE/07-04-2011//T_%d/Scurve.root",(int)Temp[i]).Data());
		SC[i] = (TGraph*)f->Get(Form("SCurve_c%ir%i_C0",col, row));
		SC[i]->SetMarkerStyle(i+1);
		SC[i]->SetMarkerColor(i+1);
		Scurve->Add(SC[i]);
	}
	Scurve->Draw("AP");

}

void Scurve2(int col, int row)
{
	TFile *f= new TFile("../PIRE/07-04-2011//T_20/Scurve.root");
	TGraph *SC = (TGraph*)f->Get(Form("SCurve_c%ir%i_C0",col, row));
	new TCanvas;
	SC->Draw("AP*");
	SC->SetMarkerStyle(2);
	SC->SetMarkerColor(1);
// 	f.close();

	TFile *f1= new TFile("../PIRE/07-04-2011//T_5/Scurve.root");
	TGraph *SC1 = (TGraph*)f1->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC1->Draw("P same");
	SC1->SetMarkerStyle(3);
	SC1->SetMarkerColor(2);
// 	f.close();

	TFile *f2= new TFile("../PIRE/07-04-2011//T_2/Scurve.root");
	TGraph *SC2 = (TGraph*)f2->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC2->Draw("P Same");
	SC2->SetMarkerStyle(4);
	SC2->SetMarkerColor(3);
// 	f2.close();

	TFile *f3= new TFile("../PIRE/07-04-2011//T_0/Scurve.root");
	TGraph *SC3 = (TGraph*)f3->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC3->Draw("P ssame");
	SC3->SetMarkerStyle(5);
	SC3->SetMarkerColor(4);
// 	f3.close();

	TFile *f4= new TFile("../PIRE/07-04-2011//T_-5/Scurve.root");
	TGraph *SC4 = (TGraph*)f4->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC4->Draw("P same");
	SC4->SetMarkerStyle(20);
	SC4->SetMarkerColor(5);
// 	f4.close();

	TFile *f5= new TFile("../PIRE/07-04-2011//T_-10/Scurve.root");
	TGraph *SC5 = (TGraph*)f5->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC5->Draw("P same");
	SC5->SetMarkerStyle(21);
	SC5->SetMarkerColor(6);
// 	f5.close();

	TFile *f6= new TFile("../PIRE/07-04-2011//T_-15/Scurve.root");
	TGraph *SC6 = (TGraph*)f6->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC6->Draw("P same");
	SC6->SetMarkerStyle(22);
	SC6->SetMarkerColor(7);
// 	f6.close();

	TFile *f7= new TFile("../PIRE/07-04-2011//T_-20/Scurve.root");
	TGraph *SC7 = (TGraph*)f7->Get(Form("SCurve_c%ir%i_C0",col, row));
	SC7->Draw("P same");
	SC7->SetMarkerStyle(23);
	SC7->SetMarkerColor(8);

	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(SC, "20C", "P");
	leg->AddEntry(SC1, "5C", "P");
	leg->AddEntry(SC2, "2C", "P");
	leg->AddEntry(SC3, "0C", "P");
	leg->AddEntry(SC4, "-5C", "P");
	leg->AddEntry(SC5, "-10C", "P");
	leg->AddEntry(SC6, "-15C", "P");
	leg->AddEntry(SC7, "-20C", "P");
	leg->Draw();
// 	f7.close();
}


void Current()
{
	double Temp[8]={20,5,2,0,-5,-10,-15,-20};
	TCanvas* c1=new TCanvas();
// 	TMultiGraph *Current = new TMultiGraph();
	for(int i=0;i<8;i++)
	{
		ifstream fs(Form("../PIRE/07-04-2011//T_%i/IV_Test.txt" , Temp[i]));
		int k=0;
		double V[15],I[15];
		for(int j=0;j<15;j++)
		{
			fs>>V[j]>>I[j];
			if(V[j]==0) {break;}
			cout<<V[j]<<"	"<<I[j]<<endl;
			k++;
		}
		cout<<endl;
		TGraph *IV = new TGraph (k, V, I);
		new TCanvas;
		IV->Draw("AP*");
		IV->SetMarkerStyle(i+1);
		IV->SetMarkerColor(i+1);
// 		Current->Add(IV);
	}
// 	Current->Draw("AP");
}

void Current2()
{
	ifstream fs("../PIRE/07-04-2011//T_-20/IV_Test.txt");
	int k=0;
	double V7[15],I7[15];
	for(int j=0;j<15;j++){
		fs>>V7[j]>>I7[j];
		if(V7[j]==0) {break;}
		k++;
	}
	TGraph *IV7 = new TGraph (k, V7, I7);
	new TCanvas;
	IV7->Draw("AP*");
	IV7->SetTitle("Leakeage Current vs Vbias at different Temperatures");
	IV7->GetXaxis()->SetTitle("Bias Voltage (V)");
	IV7->GetYaxis()->SetTitle("Leakeage Current (nA)");
	IV7->SetMarkerStyle(22);
	IV7->SetMarkerColor(9);

	ifstream fs("../PIRE/07-04-2011//T_-5/IV_Test.txt");
	int k=0;
	double V4[15],I4[15];
	for(int j=0;j<15;j++){
		fs>>V4[j]>>I4[j];
		if(V4[j]==0) {break;}
		k++;
	}
	TGraph *IV4 = new TGraph (k, V4, I4);
	IV4->Draw("P same");
	IV4->SetMarkerStyle(5);
	IV4->SetMarkerColor(6);

	ifstream fs("../PIRE/07-04-2011//T_20/IV_Test.txt");
	int k=0;
	double V[15],I[15];
	for(int j=0;j<15;j++){
		fs>>V[j]>>I[j];
		if(V[j]==0) {break;}
		k++;
	}
	TGraph *IV = new TGraph (k, V, I);
	IV->Draw("P same");
	IV->SetMarkerStyle(29);
	IV->SetMarkerColor(1);
	
	ifstream fs("../PIRE/07-04-2011//T_5/IV_Test.txt");
	int k=0;
	double V1[15],I1[15];
	for(int j=0;j<15;j++){
		fs>>V1[j]>>I1[j];
		if(V1[j]==0) {break;}
		k++;
	}
	TGraph *IV1 = new TGraph (k, V1, I1);
	IV1->Draw("P same");
	IV1->SetMarkerStyle(2);
	IV1->SetMarkerColor(2);

	ifstream fs("../PIRE/07-04-2011//T_2/IV_Test.txt");
	int k=0;
	double V2[15],I2[15];
	for(int j=0;j<15;j++){
		fs>>V2[j]>>I2[j];
		if(V2[j]==0) {break;}
		k++;
	}
	TGraph *IV2 = new TGraph (k, V2, I2);
	IV2->Draw("P same");
	IV2->SetMarkerStyle(3);
	IV2->SetMarkerColor(3);

	ifstream fs("../PIRE/07-04-2011//T_0/IV_Test.txt");
	int k=0;
	double V3[15],I3[15];
	for(int j=0;j<15;j++){
		fs>>V3[j]>>I3[j];
		if(V3[j]==0) {break;}
		k++;
	}
	TGraph *IV3 = new TGraph (k, V3, I3);
	IV3->Draw("P same");
	IV3->SetMarkerStyle(4);
	IV3->SetMarkerColor(4);



	ifstream fs("../PIRE/07-04-2011//T_-10/IV_Test.txt");
	int k=0;
	double V5[15],I5[15];
	for(int j=0;j<15;j++){
		fs>>V5[j]>>I3[j];
		if(V5[j]==0) {break;}
		k++;
	}
	TGraph *IV5 = new TGraph (k, V5, I5);
	IV5->Draw("P same");
	IV5->SetMarkerStyle(20);
	IV5->SetMarkerColor(7);
	
	ifstream fs("../PIRE/07-04-2011//T_-15/IV_Test.txt");
	int k=0;
	double V6[15],I6[15];
	for(int j=0;j<15;j++){
		fs>>V6[j]>>I6[j];
		if(V6[j]==0) {break;}
		k++;
	}
	TGraph *IV6 = new TGraph (k, V6, I6);
	IV6->Draw("P same");
	IV6->SetMarkerStyle(21);
	IV6->SetMarkerColor(8);



	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(IV, "20C", "P");
	leg->AddEntry(IV1, "5C", "P");
	leg->AddEntry(IV2, "2C", "P");
	leg->AddEntry(IV3, "0C", "P");
	leg->AddEntry(IV4, "-5C", "P");
	leg->AddEntry(IV5, "-10C", "P");
	leg->AddEntry(IV6, "-15C", "P");
	leg->AddEntry(IV7, "-20C", "P");
	leg->Draw();
}

void C2()
{
	double T[8]={293,278,275,273,268,263,258,253};
	double IC[8];
	for(int i=0;i<8;i++)
	{
		IC[i]=2000000*T[i]*T[i]*exp(-0.56/(T[i]*0.000086));
	}
	TGraph *IVTh = new TGraph (i, T, IC);
	IVTh->Draw("AL");
}

void Humidity(double volt)
{
	double Hum=(volt-0.771633)/0.0328315;
	cout<<"the humidity is "<<Hum<<endl;
// 	double V[5]={0.8,2,2.75,4.07};
// 	double H[5]={0,39,60,100};
// 	TGraph *VH = new TGraph (4, H, V);
// // 	VH->Draw("AP");
// 	TF1 *Pro = new TF1("Pro","pol1", 0, 100);
// 	VH->Fit("Pro","R");
// 	VH->Draw("L same");
// 	double Hum=(volt-Pro->GetParameter(0))/(Pro->GetParameter(1));
// 	cout<<"the humidity is "<<Hum<<endl;
// 	0.8)/0.022;p0=fitProbe->GetParameter(0);
}

void Noise()
{
	double A[4161][5];
	TString B[4161];
	ifstream fs("../PIRE/07-04-2011/_T20/SCurve_C0Calibration.dat");
	if(fs){
		cout<<"lo abrio"<<endl;
		for(int i=0;i<4161;i++){
			for(int j=0;j<4161;j++){
				fs>>B[i][j];
			}
		}
		for(int i=0;i<4161;i++){
			for(int j=0;j<4161;j++){
				cout<<B[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else {cout<<"se jodio"<<;}
}

void nanana(const char *ROC)
{
	float thre[4160], sigm[4160],thr,sig;
	int a,b,k=0;
	FILE *inputFile;
	char string[200];
	sprintf(string, "%s/SCurve_C0Calibration.dat", ROC);
	inputFile = fopen(string, "r");
	double minThrDiff(-5.);
	double maxThrDiff(5.);
	TH1F *sigma = new TH1F("Noise distribution","Noise distribution",200,0,250);
	if (!inputFile){printf("chipSummary> !!!!!!!!!  ----> SCurve: Could not open file %s to read fit results\n", string);}
	else
	{
		for (int i = 0; i < 2; i++) fgets(string, 200, inputFile);
		{
			for (int icol = 0; icol < 52; ++icol)
			{
				for (int irow = 0; irow < 80; ++irow)
				{
					fscanf(inputFile, "%e %e %s %2i %2i", &thr, &sig, string, &a, &b);  //comment
// 					hw->Fill(sig);
					thr = thr / 65;
					thre[k] = thr;
					sigm[k] = sig;
					sigma->Fill(sig);
					k++;
// 					ht->SetBinContent(icol+1, irow+1, thr);
				}
			}
		}
	}
	sigma->GetXaxis()->SetTitle("Noise (e^{- })");
	sigma->GetYaxis()->SetTitle("# of pixels");
	sigma->Draw();
}

Double_t Erffcn( Double_t *x, Double_t *par)
{
	return par[0]*TMath::Erf(par[2]*(x[0]-par[1]))+par[3];
}

Double_t Erffcn2( Double_t *x, Double_t *par)
{
	return par[0]*(1+TMath::Erf(par[2]*(x[0]-par[1])))+par[3];
}
void Error_Function(float mu, float sigma)
{
// 	gSystem->Load("../lib/libana.so");
// 	SCurve sCurve;

	int k;
	double c,v,Y[200],X[200],E[200];
	c=sigma*sqrt(6.28);
	for(double i=0; i<2; i=i+0.01)
	{
		v=((i-mu)/sigma);
		Y[k]=(exp(-v*v/2))/c;
		X[k]=i;
		E[k]=TMath::Erf(i);
		k++;
	}
	new TCanvas;
	TGraph *Gaus = new TGraph (k, X, Y);
	TGraph *Err = new TGraph (k, X, E);
	Gaus->Draw("AP*");
// 	IV->GetXaxis()->SetTitle("Vcal(DAC)");
// 	IV->GetYaxis()->SetTitle("# trigg");
	Err->SetMarkerStyle(21);
	Err->SetMarkerColor(2);
	Err->Draw("P Same");
	TCanvas* c_=new TCanvas();
	TFile *f= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T20/Scurve.root");
	SC = (TGraph*)f->Get("SCurve_c0r0_C0");
	SC->SetMarkerStyle(3);
	SC->SetMarkerColor(3);
	SC->Draw("AP*");
	SC->GetXaxis()->SetTitle("Calibration Voltage (V)");
	SC->GetYaxis()->SetTitle("# trigg");
	fit1 = new TF1("fit1",Erffcn2,0.07,0.11,4);
	fit1->SetParameters(25., SC->GetMean(), 167., 25.);
	SC->Fit("fit1", "Q", "", 0.0, 0.3);
	fit1->SetMarkerColor(3);
	SC->Fit("fit1","R");
	SC->SetTitle("John's fit");
	fit1->Draw("L same");
// 	c_->SaveAs("../PIRE/Scurve_c0r0FitMio.gif");
// 	new TCanvas();
// 	SC->Draw("AP*");
// 	fit2 = new TF1("fit2",Erffcn2,0.067,0.11,4);
// // 	fit2->SetParameters(25., SC->GetMean(), 167., 25.);
// 	fit2->SetMarkerColor(2);
// 	fit2->SetMarkerSize(8);
// 	SC->Fit("fit2", "Q", "", 0.0, 0.3);
// 	SC->Fit("fit2","R");
// 	fit2->Draw("L same");
// 	Computation of the error function erf(x).
// 	Erf(x) = (2/sqrt(pi)) Integral(exp(-t^2))dt between 0 and x
	//Try to integrate
// 	for(double i=0; i<10; i=i+0.1)
// 	{
// 		TF1 *fitProbe = new TF1("fitProbe","[0]+[1]*x*exp(-x/[2])", 15, 45);
// 	fitProbe->SetParameters(-10,8,40);
// 	PH3->Fit("fitProbe","R");
// 	}
}


/******************************************************************
/******************************************************************

	function for the report

/******************************************************************
/*******************************************************************/

//IV plots for diferent fluences
void IV_vs_VbiasGood()
{
	TMultiGraph *IV = new TMultiGraph();
	TCanvas* mia=new TCanvas();
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	f1= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T-20_3/IV_Test.root");
	TGraphErrors *MPV1 = (TGraphErrors*)f1->Get("Graph");
	MPV1->SetMarkerStyle(21);
	MPV1->SetMarkerColor(1);
	MPV1->Draw("");
	IV->Add(MPV1);

	f2= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8246-15-10_3E14_2/IV_Test.root");
	TGraphErrors *MPV2 = (TGraphErrors*)f2->Get("Graph");
	MPV2->SetMarkerStyle(22);
	MPV2->SetMarkerColor(2);
	IV->Add(MPV2);
	
	f3= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8246-15-12_3E14/IV_Test.root");
	TGraphErrors *MPV3 = (TGraphErrors*)f3->Get("Graph");
	MPV3->SetMarkerStyle(23);
	MPV3->SetMarkerColor(3);
	IV->Add(MPV3);
	
	f4= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-21-05_6E14_2/IV_Test.root");
	TGraphErrors *MPV4 = (TGraphErrors*)f4->Get("Graph");
	MPV4->SetMarkerStyle(25);
	MPV4->SetMarkerColor(6);
	IV->Add(MPV4);

	/*f5= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-07_12E14/IV_Test.root");
	TGraphErrors *MPV5 = (TGraphErrors*)f5->Get("Graph");
	MPV5->SetMarkerStyle(26);
	MPV5->SetMarkerColor(7);
	IV->Add(MPV5);*/

	f6= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-06_12E14/IV_Test.root");
	TGraphErrors *MPV6 = (TGraphErrors*)f6->Get("Graph");
	MPV6->SetMarkerStyle(27);
	MPV6->SetMarkerColor(8);
	IV->Add(MPV6);

	IV->Draw("AP");
	IV->SetTitle("");
	IV->GetXaxis()->SetTitle("Voltage (V)");
	IV->GetYaxis()->SetTitle("Current (A)");

	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(MPV1, "Un-Irradiated", "P");
	leg->AddEntry(MPV2, "3x10^{14}", "P");
	leg->AddEntry(MPV3, "3x10^{14}", "P");
	leg->AddEntry(MPV4, "6x10^{14}", "P");
	//leg->AddEntry(MPV5, "12x10^{14}", "P");
	leg->AddEntry(MPV6, "12x10^{14}", "P");
	leg->Draw("ap*");
// 	mia->SaveAs("../../JO_SI/Report/IV5Chips.gif");
// 	mia->SaveAs("../../JO_SI/Report/IV5Chips.root");
}


void IV_vs_VbiasBad()
{
	TMultiGraph *IV = new TMultiGraph();
	TCanvas* mia=new TCanvas();
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	f1= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-21-07_6E14/IV_Test.root");
	TGraphErrors *MPV1 = (TGraphErrors*)f1->Get("Graph");
	MPV1->SetMarkerStyle(21);
	MPV1->SetMarkerColor(1);
	MPV1->Draw("");
	IV->Add(MPV1);

	f2= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-05_12E14/IV_Test.root");
	TGraphErrors *MPV2 = (TGraphErrors*)f2->Get("Graph");
	MPV2->SetMarkerStyle(22);
	MPV2->SetMarkerColor(2);
	IV->Add(MPV2);
	
	f3= new TFile("../../slc5/Output/Efficiency_measurements/ROC_260961-15-10_12E14/IV_Test.root");
	TGraphErrors *MPV3 = (TGraphErrors*)f3->Get("Graph");
	MPV3->SetMarkerStyle(23);
	MPV3->SetMarkerColor(3);
	IV->Add(MPV3);
	
	f4= new TFile("../../slc5/Output/Efficiency_measurements/ROC_260961-15-11_12E14_2/IV_Test.root");
	TGraphErrors *MPV4 = (TGraphErrors*)f4->Get("Graph");
	MPV4->SetMarkerStyle(25);
	MPV4->SetMarkerColor(1);
	IV->Add(MPV4);

	f5= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-02-07_30E14/IV_Test.root");
	TGraphErrors *MPV5 = (TGraphErrors*)f5->Get("Graph");
	MPV5->SetMarkerStyle(24);
	MPV5->SetMarkerColor(6);
	IV->Add(MPV5);

	f6= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-02-05_30E14/IV_Test.root");
	TGraphErrors *MPV6 = (TGraphErrors*)f6->Get("Graph");
	MPV6->SetMarkerStyle(25);
	MPV6->SetMarkerColor(7);
	IV->Add(MPV6);

	f7= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8210-22-07_30E14/IV_Test.root");
	TGraphErrors *MPV7 = (TGraphErrors*)f7->Get("Graph");
	MPV7->SetMarkerStyle(26);
	MPV7->SetMarkerColor(8);
	IV->Add(MPV7);

	f8= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8210-22-05_30E14/IV_Test.root");
	TGraphErrors *MPV8 = (TGraphErrors*)f8->Get("Graph");
	MPV8->SetMarkerStyle(27);
	MPV8->SetMarkerColor(2);
	IV->Add(MPV8);

	f9= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8616-11-06_60E14/IV_Test.root");
	TGraphErrors *MPV9 = (TGraphErrors*)f9->Get("Graph");
	MPV9->SetMarkerStyle(28);
	MPV9->SetMarkerColor(3);
	IV->Add(MPV9);

	f10= new TFile("../../slc5/Output/Efficiency_measurements/ROC_260961-08-10_60E14/IV_Test.root");
	TGraphErrors *MPV10 = (TGraphErrors*)f10->Get("Graph");
	MPV10->SetMarkerStyle(29);
	MPV10->SetMarkerColor(1);
	IV->Add(MPV10);

	f11= new TFile("../../slc5/Output/Efficiency_measurements/ROC_260961-08-11_60E14/IV_Test.root");
	TGraphErrors *MPV11 = (TGraphErrors*)f11->Get("Graph");
	MPV11->SetMarkerStyle(30);
	MPV11->SetMarkerColor(2);
	IV->Add(MPV11);

	f12= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8610-11-05_60E14/IV_Test.root");
	TGraphErrors *MPV12 = (TGraphErrors*)f12->Get("Graph");
	MPV12->SetMarkerStyle(31);
	MPV12->SetMarkerColor(3);
	IV->Add(MPV12);

	/*f13= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-02-05_30E14/IV_Test.root");
	TGraphErrors *MPV14 = (TGraphErrors*)f13->Get("Graph");
	MPV14->SetMarkerStyle(27);
	MPV14->SetMarkerColor(7);
	IV->Add(MPV14);*/

	IV->Draw("AP");
	IV->SetTitle("");
	IV->GetXaxis()->SetTitle("Voltage (V)");
	IV->GetYaxis()->SetTitle("Current (A)");

	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(MPV1, "6x10^{14}", "P");
	leg->AddEntry(MPV2, "12x10^{14}", "P");
	leg->AddEntry(MPV3, "12x10^{14}", "P");
	leg->AddEntry(MPV4, "12x10^{14}", "P");
	leg->AddEntry(MPV5, "30x10^{14}", "P");
	leg->AddEntry(MPV6, "30x10^{14}", "P");
	leg->AddEntry(MPV7, "30x10^{14}", "P");
	leg->AddEntry(MPV8, "30x10^{14}", "P");
	leg->AddEntry(MPV9, "60x10^{14}", "P");
	leg->AddEntry(MPV10, "60x10^{14}", "P");
	leg->AddEntry(MPV11, "60x10^{14}", "P");
	leg->AddEntry(MPV12, "60x10^{14}", "P");
	leg->Draw("ap*");
// 	mia->SaveAs("../../JO_SI/Report/IVBad.gif");
// 	mia->SaveAs("../../JO_SI/Report/IVBad.root");
}

//suoer imposed the the plots for different cluster size
void Cluster()
{
	new TCanvas;
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TFile *f = new TFile("../../log/bt05r000698/spectra_000698.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_698");
	CluSize->Draw();
	CluSize->SetTitle("");
	CluSize->GetYaxis()->SetTitle("# Pixels");
	CluSize->GetXaxis()->SetTitle("Cluster Size");
	CluSize->SetLineColor(1);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "Not irradiated", "L");
	
	TFile *f = new TFile("../../log/bt05r000923/spectra_000923.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_923");
	CluSize->Draw("Same");
	CluSize->SetLineColor(2);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "Not irradiated", "L");

	TFile *f = new TFile("../../log/bt05r001149/spectra_001149.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1149");
	CluSize->Draw("Same");
	CluSize->SetLineColor(3);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "3E14", "L");

	TFile *f = new TFile("../../log/bt05r001111/spectra_001111.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1111");
	CluSize->Draw("Same");
	CluSize->SetLineColor(4);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "3E14", "L");

	TFile *f = new TFile("../../log/bt05r001006/spectra_001006.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1006");
	CluSize->Draw("Same");
	CluSize->SetLineColor(6);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "6E14", "L");
	
	TFile *f = new TFile("../../log/bt05r001251/spectra_001251.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1251");
	CluSize->Draw("Same");
	CluSize->SetLineColor(7);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "1.2E15", "L");
	
	TFile *f = new TFile("../../log/bt05r001321/spectra_001327.root");
	TH1F *CluSize = (TH1F*)f->Get("cSize_1321");
	CluSize->Draw("Same");
	CluSize->SetLineColor(9);
	CluSize->SetStats(kFALSE);
	leg->AddEntry(CluSize, "1.2E15", "L");
	leg->Draw();
}

// make the charge as a function of voltage Vbuas superimposed 
void Charge_vs_Vbias()
{
	TMultiGraph *ChageVbias = new TMultiGraph();
// 	TCanvas* c1_=new TCanvas();
	
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
			
	f1= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T-20_3/CCE_Plots.root");
	TGraphErrors *MPV1 = (TGraphErrors*)f1->Get("Most_Probable_Value_vs_Vbias");
	MPV1->SetMarkerStyle(21);
	MPV1->SetMarkerColor(1);
	ChageVbias->Add(MPV1);

	f2= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8609-11-11_T-20/CCE_Plots.root");
	TGraphErrors *MPV2 = (TGraphErrors*)f2->Get("Most_Probable_Value_vs_Vbias");
	MPV2->SetMarkerStyle(22);
	MPV2->SetMarkerColor(2);
	ChageVbias->Add(MPV2);
	
	f3= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8246-15-10_3E14_2/CCE_Plots.root");
	TGraphErrors *MPV3 = (TGraphErrors*)f3->Get("Most_Probable_Value_vs_Vbias");
	MPV3->SetMarkerStyle(23);
	MPV3->SetMarkerColor(3);
	ChageVbias->Add(MPV3);
	
	f4= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8246-15-12_3E14/CCE_Plots.root");
	TGraphErrors *MPV4 = (TGraphErrors*)f4->Get("Most_Probable_Value_vs_Vbias");
	MPV4->SetMarkerStyle(24);
	MPV4->SetMarkerColor(4);
	ChageVbias->Add(MPV4);
	
	f5= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-21-05_6E14_2/CCE_Plots.root");
	TGraphErrors *MPV5 = (TGraphErrors*)f5->Get("Most_Probable_Value_vs_Vbias");
	MPV5->SetMarkerStyle(25);
	MPV5->SetMarkerColor(9);
	ChageVbias->Add(MPV5);
	
	/*f6= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-07_12E14/CCE_Plots.root");
	TGraphErrors *MPV6 = (TGraphErrors*)f6->Get("Most_Probable_Value_vs_Vbias");
	MPV6->SetMarkerStyle(26);
	MPV6->SetMarkerColor(6);
	ChageVbias->Add(MPV6);*/
	
	f7= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-06_12E14/CCE_Plots.root");
	TGraphErrors *MPV7 = (TGraphErrors*)f7->Get("Most_Probable_Value_vs_Vbias");
	MPV7->SetMarkerStyle(27);
	MPV7->SetMarkerColor(8);
	ChageVbias->Add(MPV7);
	
	ChageVbias->Draw("AP");
	ChageVbias->SetTitle("");
	ChageVbias->GetXaxis()->SetTitle("Voltage (V)");
	ChageVbias->GetYaxis()->SetTitle("Charge (Ke^{- })");
	
	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(MPV1, "Un-Irradiated", "P");
	leg->AddEntry(MPV2, "Un-Irradiated", "P");
	leg->AddEntry(MPV3, "3x10^{14}", "P");
	leg->AddEntry(MPV4, "3x10^{14}", "P");
	leg->AddEntry(MPV5, "6x10^{14}", "P");
	//leg->AddEntry(MPV6, "1.2x10^{15}", "P");
	leg->AddEntry(MPV7, "1.2x10^{15}", "P");
	leg->Draw();

// 	c1->SaveAs("../../JO_SI/Report/ChargeFluence.root");
// 	c1->SaveAs("../../JO_SI/Report/IV5Chips.root");
}

//make the charge vs fluencee for every ROC
void Charge_Fluence()
{
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TMultiGraph *ChaFlu = new TMultiGraph();
	ChaFlu->SetMinimum(0);
	
	double Fluence0[2]={0,0};
	double Charge0[2]={21.13,21.75};
	double e_Charge0[2]={0.025,0.03};
	TGraphErrors *Cha0 = new TGraphErrors (2, Fluence0, Charge0, 0, e_Charge0);
	Cha0->SetMarkerStyle(21);
	Cha0->SetMarkerColor(1);
	Cha0->SetMarkerSize(1.5);
	ChaFlu->Add(Cha0);

	double Fluence3[2]={3,3};
// 	double Charge3[2]={16.94,15.91};
	double Charge3[2]={17.01,15.81};
// 	double e_Charge3[2]={0.04,0.06};
	double e_Charge3[2]={0.03,0.02};
	TGraphErrors *Cha3 = new TGraphErrors (2, Fluence3, Charge3, 0, e_Charge3);
	Cha3->SetMarkerStyle(20);
	Cha3->SetMarkerColor(6);
	Cha3->SetMarkerSize(1.5);
	ChaFlu->Add(Cha3);

	double Fluence6[1]={6};
// 	double Charge6[1]={15.14};
	double Charge6[1]={14.36};
	double e_Charge6[1]={0.02};
	TGraphErrors *Cha6 = new TGraphErrors (1, Fluence6, Charge6, 0, e_Charge6);
	Cha6->SetMarkerStyle(23);
	Cha6->SetMarkerColor(3);
	Cha6->SetMarkerSize(1.5);
	ChaFlu->Add(Cha6);

	double Fluence12[2]={12};
	double Charge12[2]={13.99};
	double e_Charge12[2]={0.03};
	TGraphErrors *Cha12 = new TGraphErrors (1, Fluence12, Charge12, 0, e_Charge12);
	Cha12->SetMarkerStyle(22);
	Cha12->SetMarkerColor(4);
	Cha12->SetMarkerSize(1.5);
	ChaFlu->Add(Cha12);

	/*double Fluence122[2]={12};
	double Charge122[2]={13.39};
	double e_Charge122[2]={0.03};
	TGraphErrors *Cha122 = new TGraphErrors (1, Fluence12, Charge12, 0, e_Charge12);
	Cha122->SetMarkerStyle(23);
	Cha122->SetMarkerColor(2);
	Cha122->SetMarkerSize(1.5);
	ChaFlu->Add(Cha122);*/
	
	ChaFlu->Draw("AP");
	ChaFlu->GetXaxis()->SetTitle("Fluence 10^{14}n_{eq}/cm^{2}");
	ChaFlu->GetYaxis()->SetTitle("Charge (Ke^{- })");
	ChaFlu->Draw("AP");

	TLegend* leg = new TLegend(0.15, 0.6, 0.3, 0.89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(Cha0, "200 V", "P");
	leg->AddEntry(Cha3, "450 V", "P");
	leg->AddEntry(Cha6, "450 V", "P");
	//leg->AddEntry(Cha122, "600 V", "P");
	leg->AddEntry(Cha12, "1000 V", "P");
	leg->Draw();
}

//make the risetime distribution for the different ROCs
void RiseVarious()
{
	new TCanvas;
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	
	f1= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T-20_3/RTDistrNew_ROC_8608-3-11_T-20_3.root");
	TH1F *MPV1 = (TH1F*)f1->Get("RTDistrNew_8608-3-11_T-20_3");
	MPV1->Draw();
	MPV1->SetTitle("Risetime for diferent fluences");
	MPV1->GetXaxis()->SetTitle("Time (ns)");
	MPV1->GetYaxis()->SetTitle("# Pixels");
	MPV1->SetLineColor(1);
	MPV1->SetStats(kFALSE);
	leg->AddEntry(MPV1, "Not irradiated", "L");

	f3= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8246-15-10_3E14_2/RTDistrNew_ROC_8246-15-10_3E14_2.root");
	TH1F *MPV3 = (TH1F*)f3->Get("RTDistrNew_8246-15-10_3E14_3");
	MPV3->Draw("same");
	MPV3->SetLineColor(2);
	MPV3->SetStats(kFALSE);
	leg->AddEntry(MPV3, "3E14", "L");

	f4= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-21-05_6E14_2/RTDistrNew_ROC_8613-21-05_6E14_2.root");
	TH1F *MPV4 = (TH1F*)f4->Get("RTDistrNew_8613-21-05_6E14_2");
	MPV4->Draw("same");
	MPV4->SetLineColor(3);
	MPV4->SetStats(kFALSE);
	leg->AddEntry(MPV4, "6E14", "L");

	f5= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8613-08-06_12E14/RTDistrNew_ROC_8613-08-06_12E14.root");
	TH1F *MPV5 = (TH1F*)f5->Get("RTDistrNew_8613-08-06_12E14");
	MPV5->Draw("same");
	MPV5->SetLineColor(4);
	MPV5->SetStats(kFALSE);
	leg->AddEntry(MPV5, "12E14", "L");
	
	leg->Draw();
}

void Source_Posicion()
{
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	double MP[5];
	double MPe[5];
// 	double R[5]={518,519,520,521,522};
	double na[]={1,2,3,4,5};
	int j=0;
	for(int i=519;i<524;i++){
		TFile *f = new TFile(Form("../../log/bt05r000%i/spectra_000%i.root",i,i));
		TH1D *PHMain = (TH1D*)f->Get(Form("cQ1_%i",i));
		TF1 *Myfit = (TF1*)f->Get(Form("Fitfcn_cQ1_%i",i));
		MP[j]=0.065*Myfit->GetParameter(1);
		MPe[j]=0.065*Myfit->GetParError(1);
		cout<<MP[j]<<"	"<<MPe[j]<<endl;
		j++;
	}
	TGraphErrors *Pos = new TGraphErrors (5, na, MP, 0, MPe);
	Pos->SetMinimum(18);
	Pos->SetMaximum(26);
	Pos->Draw("AP");
	Pos->SetTitle("");
	Pos->GetXaxis()->SetTitle("Position ");
	Pos->GetYaxis()->SetTitle("Charge (Ke^{- })");
	Pos->Draw("AP");

	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry("","1 Left");
	leg->AddEntry("","2 Down");
	leg->AddEntry("","3 Right");
	leg->AddEntry("","4 Up");
	leg->AddEntry("","5 Center");
	leg->Draw();
}

void Noise_Vbias()
{
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	TMultiGraph *Noise = new TMultiGraph();
	f1= new TFile("../../slc5/Output/Efficiency_measurements/ROC_8608-3-11_T-20_3/AvNoiseVsVbias.root");
	TGraphErrors *N1 = (TGraphErrors*)f1->Get("c1_n13");
// 	if(N1){
	N1->Draw("AP");
// 	N1->SetMarkerStyle(22);
// 	N1->SetMarkerColor(2);
// 	N1->Draw("AP");
// 	Noise->Add(N1);
// 	else{cout<<"la monda"<<endl;}
// 	Noise->Draw("AP");
// 	N1->Draw("AP");

// 	Noise->Draw("AP");
// 	Noise->SetTitle("pal");
// 	Noise->GetXaxis()->SetTitle("Voltage (V)");
// 	Noise->GetYaxis()->SetTitle("Noise (e^{- })");
// 	Noise->Draw("AP");

}

void RiseFluence()
{
	gStyle->SetFillColor(0);
	gStyle->SetCanvasColor(10);
	double rise[]={0,33.5,34.0,38.4,38.5,38.8};
	double erise[]={0,2.5,1.6,1.6,2.5,2.8};
	double fluence[]={-0.8,0,0,3,6,12};
	TGraphErrors *ris = new TGraphErrors (6, fluence, rise, 0, erise);
	ris->Draw("AP");
	ris->SetMinimum(0);
	ris->SetMarkerSize(2);
	ris->SetMarkerColor(2);
// 	ris->SetMaximum(26);

	ris->SetTitle("risetime vs fluence");
	ris->GetXaxis()->SetTitle("fluence 10^{14}n_{eq}/cm^{2}");
	ris->GetYaxis()->SetTitle("risetime (ns)");
	ris->Draw("AP");
}















