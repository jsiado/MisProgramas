#include <iostream>
#include <fstream>
void Ivtest()
{
	int bat,sw=1,x;
	string pos,com,bas="no";
	ofstream myfile;
	myfile.open ("IVtest.txt");
	myfile << "Modules inspected today "<<endl;
	while (sw==1)
	{
		cout<<"write module batch :";cin>>bat;
		cout<<"what position: ";cin>>pos;
		cout<<"comments? if not type no: ";cin>>com; 
		if (com==bas){com="No comments";}
		myfile<<pos<<"_"<<bat<<"---->"<<com;
		cout<<"Have another module? yes =1 ";cin>>x;
		if(x==0){sw=0;}
		cout<<endl;
	}
	myfile.close();
	
// 	int a=4;
// 	ifstream ivte("IVtext.txt");
// 	string head="modules inspected today";
// 	ivte>>head;
// 	ivte>>a;
// 	cout<<"esta es"<<endl;
// 
	/*int i,a,v,k,j,aux,p,P;
	ifstream Posi("Posiciones.txt");
	ifstream Posf("Pos_Acu.txt");	
	TString A[25][25],C[25][25];
	TString Eq;
	float B[25][25],D[25][25];
	for(i=1;i<19;i++)
	{
		for(j=1;j<3;j++)
		{
			if(j==1)
			{
				Posi>>A[i][j];
				Posf>>C[i][j];
			}
			else 
			{
				Posi>>B[i][j];
				Posf>>D[i][j];
			}
		}
	}
	for(i=1;i<19;i++)
	{
		for(j=1;j<19;j++)
		{
			if(A[i][1]==C[j][1])
			{
				D[j][2]=D[j][2]+B[i][2];
			}
		}
	}
// 		************* ORDENACION POR PUNTOS ***********
	for(k=18;k>0;k--)
	{
		for(i=1;i<k;i++)
		{
			if(D[i+1][2]>D[i][2])
			{
				Eq=C[i][1];
				C[i][1]=C[i+1][1];
				C[i+1][1]=Eq;
				
				aux=D[i][2];
				D[i][2]=D[i+1][2];
				D[i+1][2]=aux;
			}
		}
	}
	for(i=1;i<19;i++)
	{
		for(j=1;j<3;j++)
		{
			if(j==1){cout<<C[i][j]<<"	";}
			else {cout<<D[i][j]<<"	";}
		}
		cout<<endl;
	}
	ofstream Posfi("Pos_Acu.txt");
	for(i=1;i<19;i++)
	{
		for(j=1;j<3;j++)
		{
			if(j==1){Posfi<<C[i][j]<<"	";}
			else{Posfi<<D[i][j]<<"	";}
		}
		Posfi<<endl;
	}
	Posfi.close();
}*/
}