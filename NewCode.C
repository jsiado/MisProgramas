#include "TMath.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"


void Prenctest()
{
	TFile *f = new TFile("M-K-2-05/pxar.root");
	TH2D *h = (TH2D*)f->Get("PixelAlive/PixelAlive_C0_V0");
	int i,j,Pixellive=0,PixelDead=0;
	double bin;
	TH1F *Pix = new TH1F("Pixels distributions","Pixels distributions",130,0,50);
	for( i=0;i<52;i++)
	{
		for(j=0;j<80;j++)
		{
			bin=h->GetBinContent(i,j);
			Pix->Fill(bin);
			if(bin==10) Pixellive++;
			else PixelDead++;
		}
	}
	gStyle->SetPalette(1);
	Pix->Draw();
	TCanvas* c1=new TCanvas();
	h->Draw("colz");
	cout<<"Live Pixels "<<Pixellive<<" dead pixel "<<PixelDead<<endl;
}