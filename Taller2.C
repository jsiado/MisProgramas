#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "iostream"
#include <sstream>
using namespace std;

TH1F *histvcal[52][80][16];
TH1F *histroc[16];
TH1F *histrocph[16];
TH1F *colhistvcal[52][16];
TH1F *rowhistvcal[80][16];
TH1F *histph[52][80][16];
TH2F *curve[52][80]; 
TH1F *Scurve_pixel[52][80][16];
TH1F *Scurve_roc[16];
TH1F *Scurve_row[80][16];
TH1F *Scurve_col[52][16];

TH1F *pick_vcal[16]; 
TH1F *pick_ph[16]; 
TH1F *pick_vcal_2[16];



double error;
double m=0,b=0;


void inicialize()
{
	Int_t col, roc, row;
	Double_t vcal,ph;
	char name[40];
	for(int jro=0;jro<16;jro++)
	{
		for (int jc = 0;jc < 52;jc++)
		{
			for (int jr= 0;jr < 80;jr++)
			{
				sprintf(name,"vcal_%d_%d_%d",jr,jc,jro);
				histvcal[jc][jr][jro] = new TH1F(name, name, 300, 0., 600.);
				sprintf(name,"ph_%d_%d_%d",jr,jc,jro);
				histph[jc][jr][jro] = new TH1F(name, name, 1000, -1000., 500.);
			}
		}
		sprintf(name,"PH_%d",jro);
		histrocph[jro] = new TH1F(name, name, 500, -1000., 500.);
		sprintf(name,"vcal1_%d",jro);
		histroc[jro] = new TH1F(name, name, 300, 0., 600.);
		sprintf(name,"pick_vcal_%d",jro);
		pick_vcal[jro]=new TH1F(name, name, 25,18.75,81.25);
		sprintf(name,"pick_ph_%d",jro);
		pick_ph[jro]= new TH1F(name, name, 25,18.75,81.25);
		sprintf(name,"2_pick_vcal_%d",jro);
		pick_vcal_2[jro]=new TH1F(name, name, 25,18.75,81.25);
		for (int jc = 0;jc < 52;jc++)
		{
			sprintf(name,"vcalcol_%d_%d",jc,jro);
			colhistvcal[jc][jro]=new TH1F(name, name, 256, 0., 1800.);
		}
		for (int jr= 0;jr < 80;jr++)
		{
			sprintf(name,"vcalrow_%d_%d",jr,jro);
			rowhistvcal[jr][jro]=new TH1F(name, name, 256, 0., 1800.);
		}
	}
	for(int l=0;l<80;l++)
	{
		for (int k = 0;k < 52;k++)
		{
			sprintf(name,"curve_%d_%d",l,k);
			curve[k][l]=new TH2F(name,name,100,0,1400,100,-500,1200);
		}
	}

}

void memory(const char *file1)
{
	TFile *f;
	Int_t col, roc, row,ph, eventNr;
	Float_t vcal;
	TTree *events;
	f = new TFile(file1);  events = (TTree*)f->Get("events");
	events->SetBranchAddress("roc", &roc);
	events->SetBranchAddress("row", &row);
  	events->SetBranchAddress("col", &col);
	events->SetBranchAddress("vcal", &vcal);
	events->SetBranchAddress("ph", &ph);
	events->SetBranchAddress("eventNr", &eventNr);
	double maxvical=0,maxph=0;
	printf("\n entradas0 %d\n",events->GetEntries());
	for ( Int_t i=0; i<events->GetEntries(); i++) 
	{
		events->GetEntry(i);
		if(col>-1 && row > -1)
		{	
			histvcal[col][row][roc]->Fill(vcal);	
			histrocph[roc]->Fill(ph);
			histroc[roc]->Fill(vcal);		
			colhistvcal[col][roc]->Fill(vcal);
			rowhistvcal[row][roc]->Fill(vcal);
			histph[col][row][roc]->Fill(ph);
		}
	}
}

void saveVcal(const char *fileout)
{//esta toma el fit
	double result_fit;
	for(int ROC=0;ROC<16;ROC++)
	{
		char nameROC[40],nameph[20],namevcal[40], name[40];
		sprintf(nameph,"map_PH_%d",ROC);
		sprintf(namevcal,"map_VCAL_%d",ROC);
		sprintf(nameROC,"ROC_%d",ROC);
		if(ROC==0)
		{
			TFile *f= new TFile(fileout,"recreate");
		}
		else 
		{
			TFile *f= new TFile(fileout,"update");
		}	
		TDirectory *subDir=f->mkdir(nameROC);
		subDir->cd();
		gStyle->SetPalette(1,0);
		sprintf(nameROC,"ROC_hit_ph_%d",ROC);
		TH1F *h1 = new TH1F(nameROC,"distribution mean ph",500,-300,200);
		sprintf(nameROC,"ROC_hist_vcal_%d",ROC);
 		TH1F *h2 = new TH1F(nameROC,"distribution mean vcal",200,50,250);
		TH2F *hph = new TH2F(nameph,"map mean ph",52,0,51,80,0,79);
		hph->SetOption("colz");
		TH2F *hvcal = new TH2F(namevcal,"map MPV vcal",52,0,51,80,0,79);
		hvcal->SetOption("colz");
		sprintf(namevcal,"map_VCALerror_%d",ROC);
		TH2F *hvcalerror = new TH2F(namevcal,"map error MPV vcal",52,0,51,80,0,79);
		hvcal->SetOption("colz");			
		sprintf(nameROC,"map_entries_%d",ROC);
		TH2F *hentries = new TH2F(nameROC,"map entries",52,0,51,80,0,79);
		hentries->SetOption("colz");
		sprintf(nameROC,"entries_vs_vcal_ROC%d",ROC);
		TH2F *h3 = new TH2F(nameROC,"2D Vcal vs Entries",300,0,300,500,0,500);
          sprintf(nameROC,"entries_vs_ph_ROC%d",ROC);
		TH2F *h4 = new TH2F(nameROC,"2D Ph vs Entries",300,-1000,1000,500,0,500);
		sprintf(nameROC,"scurve_ph_vs_vcal_ROC%d",ROC);
		TH2F *h5 = new TH2F(nameROC,"scurve Ph vs vcal",256,0,500,1000,-1000,1000);
		for(int i=0;i<80;i++)
		{
			for(int j=0;j<52;j++)
			{
				hph->SetBinContent(j+1,i+1,histph[j][i][ROC]->GetMean());
				result_fit=Fitvcal(histvcal[j][i][ROC]);
				cout<<endl<<error<<endl;
				hvcal->SetBinContent(j+1,i+1,result_fit);
				hvcalerror->SetBinContent(j+1,i+1,error);
				hentries->SetBinContent(j+1,i+1,histvcal[j][i][ROC]->GetEntries());
				h1->Fill(histph[j][i][ROC]->GetMean());
				h2->Fill(result_fit);
				h3->Fill(result_fit,(histvcal[j][i][ROC]->GetEntries()));
				h4->Fill((histph[j][i][ROC]->GetMean()),(histph[j][i][ROC]->GetEntries()));	
				h5->Fill(result_fit,(histph[j][i][ROC]->GetMean()));
			}
		}
		sprintf(name,"vcal_col-vs-roc_%d",ROC);
		hprofcol = new TProfile(name,name,52,0,52,0,1500);
		hprofcol->SetOption("E1");
		sprintf(name,"vcalerror_col-vs-roc_%d",ROC);
		hprofcolerror = new TProfile(name,name,52,0,52,0,1500);
		hprofcolerror->SetOption("E1");
		sprintf(name,"histvcal_col-vs-roc_%d",ROC);
		histcol = new TH1F(name,name,500,-300,1500);
		sprintf(name,"histvcalerror_col-vs-roc_%d",ROC);
		histcolerror = new TH1F(name,name,500,-300,1500);

		sprintf(name,"vcal_row-vs-roc_%d",ROC);
		hprofrow = new TProfile(name,name,80,0,80,0,1500);
		hprofrow->SetOption("E1");

		sprintf(name,"vcalerror_row-vs-roc_%d",ROC);
		hprofrowerror = new TProfile(name,name,80,0,80,0,1500);
		hprofrowerror->SetOption("E1");
	
		sprintf(name,"histvcal_row-vs-roc_%d",ROC);
		histrow = new TH1F(name,name,500,-300,1500);

		sprintf(name,"histvcalerror_row-vs-roc_%d",ROC);
		histrowerror = new TH1F(name,name,500,-300,1500);
		for(int i=0;i<52;i++)
		{
			hprofcol->Fill(i,result_fit);
			hprofcolerror->Fill(i,error);
			histcol->Fill(result_fit);
			histcolerror->Fill(error);
		}
		for(int j=0;j<80;j++)
		{
			result_fit=Fitvcal(rowhistvcal[j][ROC]);
			hprofrow->Fill(j,result_fit);
			hprofrowerror->Fill(j,error);
			histrow->Fill(result_fit);
			histrowerror->Fill(error);
		}
		f->Write();	
		delete f;
	}
}

TH2F *maps(const char *file1)
{
	char nameDIR[40],namehis[40];

	TFile *g= new TFile(file1,"update");
	TH2F *mapentries = new TH2F("ENTRIES","entries",160,0,159,416,0,415);
	mapentries->SetOption("colz");
	gStyle->SetPalette(1,0);
	TH2F *mapvcal = new TH2F("MEANSVCAL","entries",160,0,159,416,0,415);
	mapvcal->SetOption("colz");
	gStyle->SetPalette(1,0);
	TH2F *mapmean = new TH2F("MEANSPH","means",160,0,159,416,0,415);
	mapmean->SetOption("colz");

	hprofroc = new TProfile("ROCvsVCAL","Profile of vcal versus roc",16,0,16,0,300);
	TH1F *entries1D = new TH1F("1D entries ","distribution of Entries",1000,0,10000);
	TH1F *vcal1D = new TH1F("1D vcal ","distribution of vcal",1000,0,1900);
	for(int ROC=0;ROC<16;ROC++)
	{
		sprintf(nameDIR,"ROC_%d/map_entries_%d",ROC,ROC);
		TH2F *entries = (TH2F*)g->Get(nameDIR);
		sprintf(nameDIR,"ROC_%d/map_VCAL_%d",ROC,ROC);
		TH2F *vcal = (TH2F*)g->Get(nameDIR);
		sprintf(nameDIR,"ROC_%d/map_PH_%d",ROC,ROC);
		TH2F *pulseh = (TH2F*)g->Get(nameDIR);
		for(int i=0;i<80;i++)
		{
			for(int j=0;j<52;j++)
			{
				if(ROC<8)
				{
					mapentries->SetBinContent(i+1,416-(j+1+52*ROC),entries->GetBinContent(j+1,i+1));
					mapmean->SetBinContent(i+1,416-(j+1+52*ROC),pulseh->GetBinContent(j+1,i+1));
					mapvcal->SetBinContent(i+1,416-(j+1+52*ROC),vcal->GetBinContent(j+1,i+1));
				}
				if(ROC>7)
				{
					printf("j %d  i %d \n",j+53,i+1+(640-(ROC-7)*80));
					mapentries->SetBinContent(159-i,(j+1+52*(ROC-8)),entries->GetBinContent(j+1,i+1));
					mapmean->SetBinContent(159-i,(j+1+52*(ROC-8)),pulseh->GetBinContent(j+1,i+1));
					mapvcal->SetBinContent(159-i,(j+1+52*(ROC-8)),vcal->GetBinContent(j+1,i+1));
				}
				entries1D->Fill(entries->GetBinContent(j+1,i+1));
				vcal1D->Fill(vcal->GetBinContent(j+1,i+1));
			}
		}
		hprofroc->Fill(ROC,vcal->GetMean(),1);
	}
	g->Write();
//delete g;
	return mapvcal;
}


void main(){


inicialize(); 
memory("events1023.root"); 
maps("data2447.root")->Draw();  

}


void Fit(const char *file1) {
TCanvas *micanvas = new TCanvas("canvas","canvas",400,600);
micanvas -> Divide(2,8);
micanvas->SetFillColor(20);
 micanvas->SetFrameFillColor(31);
  micanvas->SetGrid();
 //Bevington Exercise by Peter Malzacher, modified by Rene Brun
 char nameDIR[20];
  sprintf(nameDIR,"histogram slope");
gStyle->SetPalette(1,0);
for(int ROC =0;ROC<16;ROC++){
f1 = new TFile(file1);
sprintf(nameDIR,"ROC_%d/dis_slope_ROC_%d",ROC,ROC);
TH1F *h1 = (TH1F*)f1->Get(nameDIR);
micanvas->cd(ROC+1);

  h1->SetMarkerStyle(21);
   h1->SetMarkerSize(0.8);
   h1->SetStats(0);
 
   // create a TF1 with the range from 0 to 3 and 6 parameters
   TF1 *fitFcn = new TF1("fitFcn","landau",0,400);
   fitFcn->SetNpx(400);
   fitFcn->SetLineWidth(2);
   fitFcn->SetLineColor(kRed);
   fitFcn->SetParameters(1,1,1,1,1,1);
   h1->Fit("fitFcn","0");
  
 
   h1->Fit("fitFcn","V+","ep");
h1->Draw(); 
} 

TFile *sl= new TFile(file1,"update");
micanvas->Update();
sl->Append(micanvas);
sl->Write();
delete sl;
}


double Fitvcal(TH1F *histo) {

double moda=histo->GetBinCenter(histo->GetMaximumBin());
histo->Fit("gaus","0","0",moda-20,moda+20);//que tan ancho se hace el fit, como sigma es menor que 10 recomiendo +-20
   
//cout<< fitFcn->GetParameter(1)<<endl; 
TF1* func = histo->GetFunction("gaus");

// error of the mean
//error=func->GetParError(1);
//sdv
error=func->GetParameter(2);
//delete func;
return func->GetParameter(1); 
delete histo;


}



Double_t Erffcn( Double_t *x, Double_t *par)
{
return par[0]*TMath::Erf(par[2]*(x[0]-par[1]))+par[3];

}

Double_t fitf(Double_t *x, Double_t *par)
{
   Double_t arg = 0;
   if (par[2] != 0) arg = (x[0]*par[0] - par[1]);

   Double_t fitval =par[3]+par[2]*TMath::TanH(arg);
   return fitval;
}


