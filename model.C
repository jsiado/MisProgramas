// void ramdon()
{
// 	TF1 *f1 = new TF1("f1","",0,10);
// 	double r = f1->GetRandom();
// 	cout<<r<<endl;
	int n_bins=200; //Number of bins
	double x_low=0.0; //Lowest bin value
	double x_high=1.0; //Highest bin value
	
	// Create two 1D histograms
	distribution1 = new TH1F("Distribution1","Distribution1",n_bins,x_low,x_high);
	TRandom* random1 = new TRandom;
  
  // Random seeds for the random generators are set
  // These are the starting values for the algorithm
  // producing the pseudo-random numbers
  // seed=0: actual computer clock time in seconds
	random1->SetSeed(5000);
  
  // Number of random numbers to be produced
	int n_random = 1000;
	  
	double x1 = 0;
	double x2 = 0;
	double weight = 0;
	double rand_no1, rand_no2;
  
  // Weighting factor to obtain a normalized distribution 
// 	double weight = 1.0/(double(n_random)*((x_high-x_low)/n_bins));
	for (Int_t i = 0; i < n_random; i++)
	{
    // Produce n-times uniform random numbers data1 and data2
		rand_no1 = random1->Rndm();
    
    // Fill the random numbers data1 and data2 in histograms
		data1 = rand_no1;
	    
		distribution1->Fill(data1/*/,weight*/);
    
	}
// 	TF1 *function1 = new TF1("function1","1.0/([0]-[1])",0.0,1.0);
//   function1->SetParameter(0,x_high);
//   function1->SetParameter(1,x_low);
  
  // Create a quadratic function with dependence on x
//   TF1 *function2 = new TF1("function2","[0]+[1]*x+[2]*x^2",0.0,1.0);
  //Fit the function to the distribution
//   distribution2->Fit(function2,"R"); // Force the function to fit within the range that it is defined
//   Double_t parameter0 = function2->GetParameter(0);
//   Double_t parameter1 = function2->GetParameter(1);
//   Double_t parameter2 = function2->GetParameter(2);
//   cout << "parameter0: " << parameter0 << " parameter1: " << parameter1 << " parameter2: " << parameter2 << endl;
  
  // Create canvas
  c1 = new TCanvas("c1","Uniform Distributions",200,10,600,800);
  // Divide canvas into 3 regions 
//   c1->Divide(1,3);
  
  // Plot figures into canvas c1
//   c1->cd(1);
  distribution1->Draw("");
//   function1->Draw("same"); // Draw the function on the same plot
//   c1->cd(2);
//   distribution2->Draw("e1 p"); //Draw also error bars (e1) and point (p)
//   function2->Draw("same");
//   c1->cd(3);
//   distribution3->Draw("");
  
  // Produce a png-file
//   c1.Print("example.pdf","pdf");
}