void example()
{
  // TFile *f1= new TFile("Pretest_0.root","update");
  //TH1F *h = (TH1F*)f1.Get(Form("AddressLevels_C%i",ROC));
  
  TFile *f1 = new TFile( "Chewie_Run16069.root");
  TH1F *h = (TH1F*)f1.get("hXResiduals_Dut0");
    //TCanvas *can0 = (TCanvas*)file1->Get( "Resolutions");
    //TH1D *Xres = (TH1D*)Resolution->FindObject( "hXresiduals_Dut0");
    //	TH1D *Yres = (TH1D*)Resolution->FindObject( "Yresiduals");
	//TH1D *Pro = (TH1D*)c1->FindObject( "Proton");
	//canv = new TCanvas( "canv", "Canvas", 0, 0, 600, 400);

	//But->SetTitle();
	//But->SetStats( 0);
	//But->GetXaxis()->SetDecimals( kTRUE);
	/*But->GetXaxis()->SetLabelFont( 132);
	But->GetYaxis()->SetLabelFont( 132);
	But->GetXaxis()->SetTitleOffset( 1.15);
	But->GetXaxis()->SetTitleSize( 0.04);
	But->GetYaxis()->SetTitleOffset( 1.35);
	But->GetYaxis()->SetTitleSize( 0.04);
	But->GetXaxis()->SetLabelSize( 0.04);
	But->GetXaxis()->SetLabelOffset( 0.015);
	But->GetYaxis()->SetLabelSize( 0.04);
	But->GetYaxis()->SetLabelOffset( 0.01);
	But->GetXaxis()->SetDecimals( kTRUE);
	But->GetXaxis()->SetLabelFont( 132);
	But->GetYaxis()->SetLabelFont( 132);
	But->GetXaxis()->CenterTitle();
	But->GetXaxis()->SetTitle( "M_{miss} (MeV/c^{2})");
	But->GetXaxis()->SetTitleFont( 132);
	But->GetYaxis()->CenterTitle();
	But->GetYaxis()->SetTitleFont( 132);
	But->GetYaxis()->SetTitle( "Counts (a.u.)");
	But->Draw( "L");*/

    h->Draw();
    /*C12->SetStats( 0);
	C12->SetFillStyle( 3001);
	C12->Draw( "same");

	Pro->SetStats( 0);
	Pro->SetFillStyle( 3002);
	Pro->Draw( "same");*/
}
