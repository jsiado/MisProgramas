#include "TMath.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"


void P001()
{
	TF1 f1("f1","sin(x)/x",0,10);
	f1.Draw("P");
}





void graphing()
{
	int n = 20;
	double X[n], Y[n], Z[n], W[n];

	// create a blue graph with a cos function and red one with sin function
	for (int i=0; i<n; i++) 
	{
		X[i] = i;
		Y[i] = cos(i);
		Z[i] = cos(i)*sin(i);
		W[i] = sin(i);
	}
	TGraph *gr1 = new TGraph(n,X,Y);
	TGraph *gr2 = new TGraph(n,X,Z);
	TGraph *gr3 = new TGraph(n,X,W);
	TCanvas *c1 = new TCanvas("c1","Two Graphs",200,10,600,400);
  // draw the graph with axis, contineous line, and put a * at each point
	gr1->SetLineColor(1);
	gr1->Draw("AC*");
	gr1->SetTitle("harmonic functions");
	gr1->GetXaxis()->SetTitle("x");
	gr1->GetYaxis()->SetTitle("f(x)");
  // superimpose the second graph by leaving out the axis option "A"
// 	gr2->SetLineWidth(2);
	gr2->SetMarkerStyle(21);
	gr2->SetLineColor(2);
	gr2->Draw("CP");
	// superimpose the third graph by leaving out the axis option "A"
// 	gr3->SetLineWidth(3);
	gr3->SetMarkerStyle(21);
	gr3->SetLineColor(3);
	gr3->Draw("CP");
	// draw a legend
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(gr1, "cos(x)", "L");
	leg->AddEntry(gr2, "cos(x) * sin(x) ", "L");
	leg->AddEntry(gr3, "sin(x)", "L");
	leg->Draw();
}


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
