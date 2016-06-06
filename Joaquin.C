#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> //tiene la definicion de la funcion RAND (random)
#include <TF1.h>
#include <TGraph.h>
#include <TMath.h>
#include <TGraphErrors.h>
#include "TMinuit.h"


using namespace std;

//crea un archivo con valores fijos
int Crea() 
{
	// Crea un archivo de salida
	ofstream fs("DosCol.txt"); // Enviamos una cadena al fichero de salida
	for(int i=1;i<20;i++)
	{
		fs <<i<<"	"<<i*i<<"	"<<i*i*i<<endl; // Cerrar el fichero, para luego poder abrirlo para lectura
	}
	fs.close();
	return 0;
	//Open  a File*/	
}

//lee un Archivo y halla el promedio de cada columna
int Lee()
{
	double X[200],Y[200],V[200],Z=0,M1=0,M2=0,M3=0,i;
	ifstream fs("TresCol.txt");
	for(int l=0;l<20;l++)
	{
		fs>>X[l]>>Y[l]>>V[l];
	}
	for(int l=0;l<20;l++)
	{
		M1=M1+X[l];
		M2=M2+Y[l];
		M3=M3+V[l];
		//cout<<X[l]<<"	"<<Y[l]<<"	"<<V[l]<<endl;
		//cout<<M1<<"	"<<M2<<endl;
	}
	M1=M1/20;
	M2=M2/20;
	M3=M3/20;
	cout<<M1<<"	"<<M2<<"	"<<M3<<endl;
	return 0;
}

//crea un archivo de tres columnas con numeros aleatorios
int Alazar()
{
	int j=0;
	double i;
	ofstream fs("TresCol.txt");
	while(j<20)
	{
		i=1+rand()%20;
		fs <<i<<"	"<<i*i<<"	"<<i*i*i<<endl;
		j++;
		//cout<<i<<endl;
		//return 0;
	}
	fs.close();
}

//genera numeros aleatorios
int random ()
{
	int c,d;
	double k;
	cout << "Cuantos números quiere generar?.....";cin >> c;
	for (d=1;d<=c;d++)
	{
		k=rand()%20;
		cout<<k<<endl;
	}
}

//integral de un histogramas
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
		if (a==1)
		{
			cout<<"escribe el limite inicial del primer histograma.....:";cin>>A[a];
		}
		else
		if (a==2)
		{
			cout<<"escribe el limite final del primer histograma.....:";cin>>A[a];
		}
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

//Calculate lineal Range betwen ph and Vcal
void PhVcal()
{
	ofstream Ran("Rangos.txt");
	for(int Roc=0;Roc<16;Roc++)
	{
		int i=0,k=0,sw=0,a,p,l;
		double j,Chi,Min,Max,s,C[500],Mi[500],Ma[500],Q[1000],T=0,r,R;
		//cout<<"cual ROC?.....:";cin>>ROC;
		TFile *f1= new TFile("Pretest_0.root","update");
		TH1F *h = (TH1F*)f1.Get(Form("PHVcal_VoffsetOp0_VOffsetR0120_C%i",Roc));
		//hallar el valor minimo
		while (i<=h->GetNbinsX())
		{
			s=h->GetNbinsX();
			j = h->GetBinContent(i);
			if(j!=0 && j!=7777)
			{
				Min=i;
				i=2*s;
			}
			else
			{
				i++;
			}
		}
		Max=250;
		//hallar el valor maximo
		while(sw==0)
		{
			TF1 *f2= new TF1("f2","pol1",Min,Max);
			h->Fit("f2","R");
			if(f2->GetNDF()!=0)
			{
				Chi = f2->GetChisquare()/f2->GetNDF();
				if(Chi>2)
				{
					Max=Max-5;
				}
				if(Chi<2)
				{
					sw=1;
					Max=Max+20;
				}
			}
			else
			{
				Max=Max-5;
			}
		}
		p=Min+20;
		a=Min;
		k=0;
		//Hallar en todos los Rangos entre Min y Max
		while(p<Max)
		{
			Min=a;
			while(Min<p-10)
			{
				TF1 *f2= new TF1("f2","pol1",Min,p);
				h->Fit("f2","R");
				if(f2->GetNDF()!=0)
				{
					Chi = f2->GetChisquare()/f2->GetNDF();
					if(Chi<1.1 && Chi>0.9)
					{
						C[k]=Chi;
						Mi[k]=Min;
						Ma[k]=p;
						Q[k]=(Ma[k]-Mi[k])/C[k];
						if(Q[k]>T)
						{
							r=Mi[k];
							R=Ma[k];
							T=Q[k];
						}
						k++;
					}
				}
				Min=Min+5;
			}
			p=p+5;
		}
		Ran<<Roc<<"	"<<r<<"	"<<R<<"	"<<R-r<<endl;
	}
	Ran.close();
}

//mi word
void MiWord()
{
	ofstream jos("hot.txt");
	int i,Lim,j,k;
	char A[100];
	for(i=0;i<10;i++)
	{
		cout<<"escribe A["<<i<<"]....";cin>>A[i];
	}
	for(i=0;i<10;i++)
	{
		//cout<<A[i]<<endl;
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				jos<<A[i]<<A[j]<<A[k]<<endl;
			}
		}
	}
	jos.close();
}




