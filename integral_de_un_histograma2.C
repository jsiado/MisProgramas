/***************************************
//integral de un histograma dando un solo limite
****************************************/
void getbincontent ()
{
	int i,n,w=1,a,x,A[20],y,ROC;
	double B[30];
	cout<<"cual ROC?.....:";cin>>ROC;	
	TFile *f1= new TFile("Pretest_0.root","update");
	TH1F *h = (TH1F*)f1.Get(Form("AddressLevels_C%i",ROC));
	cout<<"cuantos histogramas son......:";cin>>x;
	for( a=1; a<=x+1; a++)
	{
	  if (a==1){cout<<"escribe el limite inicial del primer histograma.....:";cin>>A[a];}
		else
		if (a==2){cout<<"escribe el limite final del primer histograma.....:";cin>>A[a];}
		else
		{
			cout<<"escribe el limite final del siguiente histograma.....:";cin>>A[a];
		}	
	}
	for( y=1; y<x+1; y++)
	{
		n=0;
		for( i=A[y]; i<=A[y+1]; i++)
		{
			double j = h->GetBinContent(i);
			n=n+j;
		}
		B[w]=n;
		w++;
	}
	for( w=1; w<=x; w++)
	{
		cout<<"la integral del histograma es # "<<w<<" es :"<<B[w]<<endl;	
	}	
	cout<<" el numero de barras es: "<<h->GetNbinsX()<<endl;
	h->Draw();
}
