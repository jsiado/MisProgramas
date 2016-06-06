#include <iostream.h>
#include <fstream.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> //tiene la definicion de la funcion RAND (random)
#include <iomanip>
// \\#include <TF1>
// \\#include <TGraph.h>
#include <TMath.h>
// #include <TGraphErrors.h>
// #include <cmath>
// #include <conio.h>
// #include "TMinuit.h"
using namespace std;


void pragma()
{
	float x, e, F, F1, F2, F3, k=2, F4, F5;
	const double 	k_B = 1.38066e-23;
	for(x=-1;x<=1;x=x+0.1)
	{
	  F1 = exp (x);
	  F4 = exp (-x);
	  F2 = exp ((9*x)/4);
	  F3 = exp (4*x);
	  F = -F1+F2/4+2*F3;// - exp (-x);
	  F5 = F1-F4;
// 	  if(F5<= 0.01 && F5>= -0.01)
// 	  {
	    cout<<x<<" "<<F5<<endl;
// 	  }
	}
}

void Statis_Phys()
{
	float F, F1;
	float p1, p2, p3;
	F= p1+p2+p3;
	F1= p1+2.25*p2+4*p3;
	for(p1=0;p1<=1;p1=p1+0.01)
	{
		for(p2=0;p2<=1;p2=p2+0.01)
		{
			
		  for(p3=0;p3<=1;p3=p3+0.01)
			{
				F= p1+p2+p3;
				F1= p1+2.25*p2+4*p3;
				if(F1<=2.001 && F1>= 1.999)
				{
					if(F<=1.001 && F>=0.999)
					{
						cout<<"F1 = "<<F1<<"	p1 = "<<p1<<"	p2 = "<<p2<<"	p3 = "<<p3<<endl;
					}
				}
			}
		}
	}
}

void Problem_Degeneracy()
{
	ofstream J4("Deg.txt");//create a file to write on it
	int x,y,z,i=0,D;
	for(x=1;x<7;x++)
	{
		for(y=1;y<7;y++)
		{
			for(z=1;z<7;z++)
			{
				D=x*x+y*y+z*z;
				J4<<x<<","<<y<<","<<z<<" = "<<D<<endl;
// 				J4<<X[i]=D;
				
			}
		}	
	}
	J4.close();
}


void Equation()
{
	double X, a, b, c, d, X, , Xo, Xi, Xf, F;
// 	cout<<"a-coeficient  = ";cin>>a;
// 	cout<<"b-coeficient  = ";cin>>b;
// 	cout<<"c-coeficient  = ";cin>>c;
// 	cout<<"d-coeficient  = ";cin>>d;
	cout<<"initial value = ";cin>>Xo;
	cout<<"final value   = ";cin>>Xf;
	cout<<"Increment     = ";cin>>Xi;
	for(X=Xo; X<=Xf; X=X+Xi)
	{
		F= 2*X*X*X+3*X*X-1*X-1	;
		cout<<X<<"	"<<F<<endl;
	}
}

//finding the roots of a equation using newton´s method
void 

//finding the roots of a equation using newton´s method
void roots()
{
	double F, F1, x,  xo, Xi, Xf;
	int sw=1;
	
	cout<<"initial value = ";cin>>xo;
	//write here the polynomial you wnat to find the roots
	while(sw==1)
	{
		x=xo;
		F= x*x*x-4*x*x+x+6;
		F1=3*x*x-8*x+1;
		x=xo-(F/F1);
		if(fabs(x-xo)<=0.01){
			sw = 0;
		}
		xo=x;
	}
		cout<<x<<endl;
}

void Quantum_Wave_packed()
{
	float X[150], Y[150], Z[150],A[150];
	for(int i=0; i<100; i++)
	{
		X[i]=i;
		Y[i]=sin(0.3*X[i]);
		Z[i]=sin(0.3*X[i])+sin(0.6*X[i])+sin(0.9*X[i])+sin(1.2*X[i])+sin(1.5*X[i]);
		A[i]=sin(0.3*X[i])+sin(0.6*X[i])+sin(0.9*X[i])+sin(1.2*X[i])+sin(1.5*X[i])+sin(1.8*X[i])+sin(2.1*X[i])+sin(2.4*X[i])+sin(2.7*X[i])+sin(3*X[i])+sin(3.3*X[i])+sin(3.6*X[i])+sin(3.9*X[i])+sin(4.2*X[i])+sin(4.5*X[i]);
	}
	TGraph *Q1 = new TGraph (100, X, Y);
	Q1->Draw("AC");
	Q1->SetTitle("Wave packet");
	Q1->Draw("ALP");
	Q1->GetXaxis()->SetTitle("Position (m)");
	Q1->GetYaxis()->SetTitle("Y(x) (m)");
	Q1->SetLineColor(4);
	TGraph *IQ1 = new TGraph (100, X, Z);
	IQ1->SetMarkerStyle(18);
	IQ1->SetLineColor(2);
	IQ1->Draw("L same ");
	TGraph *IQ2 = new TGraph (100, X, A);
	IQ2->SetMarkerStyle(21);
	IQ2->SetLineColor(3);
	IQ2->Draw("L same ");
	TLegend* leg = new TLegend(0.7, 0.74, .85, .89);
	leg->SetBorderSize(0);
	leg->SetLineColor(0);
	leg->AddEntry(Q1, "n=1", "L");
	leg->AddEntry(IQ1, "n=5", "L");
	leg->AddEntry(IQ2, "n=15", "L");
	leg->Draw();
}

void Fitting_a_Graph()
{
	float X[20], Y[20];
	for(int i=0; i<11;i++)
	{
		X[i]=i-5;
		Y[i]=X[i]*X[i]+3;
	}
	TGraph *HV = new TGraph (11, X, Y);
	HV->SetTitle("Trying a cuadratic fit");
	HV->SetName("Efficiecy_vs_Vbias");
	TCanvas* c1_=new TCanvas();
	TF1 *fitProve = new TF1("fitProve","[0]+[1]*x*x", -15,15);
	HV->Draw("AP*");
	HV->GetXaxis()->SetTitle("Vbias (V)");
	HV->GetYaxis()->SetTitle("Efficiency (Units)");
	c1_->SaveAs("../bla.pdf");
	HV->Fit("fitProve","R");
}
//calculate whether a number is prime
int Prime(int i)
{
	int Prim;
	for(int j=2;j<=i;j++)
	{
		div_t a;
		diva = div(i,j);
		if (diva.rem==0){
			if(i==j){Prim=1;}
			else{
				j=i+1;
				Prim=0;
			}
		}
	}
	return Prim;
}

//Calculate the center of mass of a system of particle
void CenterofMass()
{
	int i,n,a=5,b=5,c=5,d=5;
	float suma=0,M[20],X[20],Y[20],Z[20],m,x,y,z,Xcm=0,Ycm=0,Zcm=0;
	float Centro_masa(float X[20],float Y[20],float Z[20],float M[20],int n, float &Xcm, float &Ycm,float &Zcm);
	cout<<"how many particles..:?";cin>>n;
	for(i=1;i<=n;i++)
	{
		/*gotoxy(0,a+1);*/cout<<"M["<<i<<"] :";cin>>m;
		M[i]=m;
		a++;
		/*gotoxy(30,b+1);*/cout<<"X["<<i<<"] :";cin>>x;
		X[i]=x;
		b++;
		/*gotoxy(50,c+1);*/cout<<"Y["<<i<<"] :";cin>>y;
		Y[i]=y;
		c++;
		/*gotoxy(70,d+1);*/cout<<"Z["<<i<<"] :";cin>>z;
		Z[i]=z;
		d++;
	}
	for(i=1;i<=n;i++)
	{
		suma=suma+M[i];
		Xcm=Xcm+X[i]*M[i];
		Ycm=Ycm+Y[i]*M[i];
		Zcm=Zcm+Z[i]*M[i];
	}
	Xcm=Xcm/suma;
	Ycm=Ycm/suma;
	Zcm=Zcm/suma;
// 	centro_masa(X,Y,Z,M,n,Xcm,Ycm,Zcm);
	/*gotoxy(0,a+2);*/cout<<"Xcm"<<"		"<<"Ycm"<<"		"<<"Zcm"<<endl;
	cout<<Xcm<<endl;
	cout<<Ycm<<endl;
	cout<<Zcm<<endl;
}

//Calculate the center of mass of a system of particle
float Centro_masa(float X[20],float Y[20],float Z[20],float M[20],int n, float &Xcm, float &Ycm,float &Zcm)
{
	for(i=1;i<=n;i++)
	{
		suma=suma+M[i];
		Xcm=Xcm+X[i]*M[i];
		Ycm=Ycm+Y[i]*M[i];
		Zcm=Zcm+Z[i]*M[i];
	}
	Xcm=Xcm/suma;
	Ycm=Ycm/suma;
	Zcm=Zcm/suma;
}

//Calcula el promedio y la desviacion standar de para cada dato de una serie
void Promedio_Actual()
{
	int n=1,i=1,j;
	float A[5000];
	double sum=0,Pro,StDe;
			
	while(n<5000)
	{
		cout<<"Siguiente Numero...:";cin>>A[n];
		sum=sum+A[n];
		Pro=sum/(n);
		StDe=0;
		for(j=1;j<=n;j++)
		{
			StDe=StDe+(A[j]-Pro)*(A[j]-Pro);
		}
		StDe=sqrt(StDe/n);
		cout<<"En "<<i<<" datos el promedio es "<<Pro<<" y la desviacion estandar es "<<StDe<<endl;
		n++;
		i++;
	}
}

void mainer()
{
	int number;
	srand(time(NULL));
	number=rand()%(18);
	cout<<number<<endl;
// 	getch();
}

// hacer un histograma con valores gausianos. does not work. repeat the same values every time
void Histo()
{
	int i,k;
	TH1F *h1= new TH1F ("myHisto","Myhisto",50,-5,30);
	srand(time(NULL));
	for(i=1;i<20000;i++)
	{
// 		srand(time(NULL));
		k=rand()%(20);
		h1->Fill(k);
	}
// 	h1->FillRandom("gaus",10000000);
	h1->Draw();
}

/*// resuelve un sistema de ecuaciones
void Sistema_ecuaciones()
{
	int i,j,k,l,m,n,p,q;
	double A[50][50],sw,Dia;
	cout<<"cuantas ecuacones son?..:";cin>>n;
	m=n+1;
	//ingreso de datos
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j==m)
			{
				cout<<"escribe el termino independiente de la ecuacion # "<<i<<" ";cin>>A[i][j];
			}
			else
			{
				cout<<"escribe el coeficiente de la variable # "<<j<<" ";cin>>A[i][j];
			}
		}
	}
// 	escritura del sistema original
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"	"<<A[i][j]<<"";
		}
		cout<<endl;
	}
	cout<<endl;
// 	comienza el proceso
	for(i=1;i<=n;i++)
	{
// 		Dia=A[i][i];
		if(A[i][i]!=1)
		{
			Dia=A[i][i];
			for(p=i;p<=m;p++)
			{
				cout<<"srsaretfrghbyu"<<endl;A[i][p]=A[i][p]/Dia;
			}
			cout<<"srsaretfrghbyu"<<endl;
			for(l=1;l<=n;l++)
			{
				for(q=1;q<=m;q++)
				{
					cout<<"	"<<A[l][q]<<"";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		if(A[i][i]==1)
		{
			for(j=i+1;j<=n;j++)
			{
				sw=A[j][i];
				for(k=i;k<=m;k++)
				{
					cout<<A[j][k]<<" - "<<sw<<" * "<<A[i][k]<<" = ";
					A[j][k]=A[j][k]-sw*A[i][k];
					cout<<A[j][k]<<endl;
				}
				for(l=1;l<=n;l++)
				{
					for(q=1;q<=m;q++)
					{
						cout<<"	"<<A[l][q]<<"";
					}
					cout<<endl;
				}
				cout<<endl;
			}
		}
	}
// 	Resultado final
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"	"<<A[i][j]<<"";
		}
		cout<<endl;
	}
	cout<<endl;
}
*/
void Sistema_ecuaciones2 ()
{
	int i,j,n,piv,x,k;
	double A[50][50],sw,Dia;
	cout<<"cuantas ecuacones son?..:";cin>>n;
// 	m=n+1;
	//ingreso de datos
	for(i=0;i<n;i++)
	{
		//polinomio numero 1
		for(j=0;j<=n;j++)
		{
			if(j==n)
			{
				cout<<"escribe el termino independiente de la ecuacion # "<<i<<" ";cin>>A[i][j];
			}
			else
			{
				cout<<"escribe el coeficiente de la variable # "<<j<<" ";cin>>A[i][j];
			}
		}
	}
	//clrscr();
	cout<<"El sistema original es"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
// 			if (A[i][j]==1 || A[i][j]==-1
			cout<<""<<A[i][j]<<"";
		}
		cout<<endl;
	}
// 	comienza el proceso
	for(i=0;i<n;i++)
	{
		piv=A[i][i];
		for(j=i;j<=n;j++)
		{
			A[i][j]=A[i][j]/piv;
		}
		for(k=0;k<n;k++)
		{
			if(k!=i)
			{
				x=A[k][i];
				for(j=0;j<=n;j++)
				{
					A[k][j]=A[k][j]-x*A[i][j];
				}
			}
		}
	}
// 	Resultado final
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"	"<<A[i][j]<<"";
		}
		cout<<endl;
	}
	cout<<endl;
}

//Descompone un numero en sus factores primos
void Descomposicion(int n)
{
	int res,i=2;
	cout<<"Numero	|	factores primos"<<endl;
	cout<<"-----	|	---------------"<<endl;
	while(i<=n)
	{
		res =n/i;
		if(res*i==n)
		{
			cout<<n<<"	|	"<<i<<endl;
			n=res;
			i=2;
			if(res==1) cout<<res<<endl;
		}
		else i++;
	}
}

//Calcula la combinatoria de dos numeros
void Combinatoria(int m, int n)
{
	int C,M,N,R;
	M=Factorial(m);
	N=Factorial(n);
	R=Factorial(m-n);
	C=M/(N*R);
	cout<<"la combinatoria de "<<m<<" y "<<n<<" es "<<C<<endl;
}

//Conversion de temperatura entre Celcius y fahrenheit
void Conversion_grados()
{
	int a;
	float gC,gF;
	cout<<" para convertir Celcius a Fahrenheit presiona 1 "<<endl;
	cout<<" para convertir Fahrenheit a Celcius presiona 2 "<<endl;
	cin>>a;
	if(a==1)
	{
		cout<<"Escribe la temperatura en grados Celcius ...:";cin>>gC;
		gF=32+9*gC/5;
		cout<<gC<<" grados Celcius son "<<gF<<" grados Fahrenheit"<<endl;
	}
	if(a==2)
	{
		cout<<"Escribe la temperatura en grados Fahrenheit ...:";cin>>gF;
		gC=(gF-32)*5/9;
		cout<<gF<<" grados Fahrenheit son "<<gC<<" grados Celcius"<<endl;
	}
}

//Calculo del area y longitud de una circunferencia conociendo el radio
void Area_y_Longitut()
{
	float r,l,a;
	cout<<"escribe radio de la circunferencia...:";cin>>r;
	a=3.14159*r*r;
	l=6.28308*r;
	cout<<"una circunferencia de radio "<<r<<" tiene longitud "<<l<<" y area "<<a<<endl;
}

//resuelve un sistema de ecuaciones lineales 2*2
float Dos_Ecuaciones(float a,float b,float c,float d,float e,float f)
{
	float den,x,y;
	cout<<"para la primera ecuacion"<<endl;
	cout<<"escribe el coeficiente de x...:";cin>>a;
	cout<<"escribe el coeficiente de y...:";cin>>b;
	cout<<"escribe el termino independiente...:";cin>>c;
	cout<<"para la segunda ecuacion"<<endl;
	cout<<"escribe el coeficiente de x...:";cin>>d;
	cout<<"escribe el coeficiente de y...:";cin>>e;
	cout<<"escribe el termino independiente...:";cin>>f;
	den=a*e-b*d;
	if(den==0) cout<<"el sistema no tiene solucion"<<endl;
	else
	{
		x=(c*e-b*f)/den;
		y=(a*f-c*d)/den;
		cout<<"la solucion es x="<<x<<" y y="<<y<<endl;
	}
	return y;
}

//resuelve un sistema de ecuaciones lineales 3*3
void Tres_Ecuaciones()
{
	float a,b,c,d,e,f,g,h,i,j,k,l,den,x,y,z,A1,A2,A3,A4,A5,A6;
	cout<<"para la primera ecuacion"<<endl;
	cout<<"escribe el coeficiente de x...:";cin>>a;
	cout<<"escribe el coeficiente de y...:";cin>>b;
	cout<<"escribe el coeficiente de z...:";cin>>c;
	cout<<"escribe el termino independiente...:";cin>>d;
	cout<<"para la segunda ecuacion"<<endl;
	cout<<"escribe el coeficiente de x...:";cin>>e;
	cout<<"escribe el coeficiente de y...:";cin>>f;
	cout<<"escribe el coeficiente de z...:";cin>>g;
	cout<<"escribe el termino independiente...:";cin>>h;
	cout<<"para la tercera ecuacion"<<endl;
	cout<<"escribe el coeficiente de x...:";cin>>i;
	cout<<"escribe el coeficiente de y...:";cin>>j;
	cout<<"escribe el coeficiente de z...:";cin>>k;
	cout<<"escribe el termino independiente...:";cin>>l;
	A1=(i*f-e*j);
	A2=(c*e-a*g);
	A3=(e*b-a*f);
	A4=(i*g-e*k);
	A5=d*e-a*h;
	A6=i*h-e*l;
	den = A1*A2-A3*A4;
	if(den==0) cout<<"el sistema no tiene solucion"<<endl;
	else
	{
		z=Dos_Ecuaciones(A3,A2,A5,A1,A4,A6)
// 		z=(A1*A5-A3*A6)/den;
		y=(A5-A2*z)/A3;
		x=(d-c*z-b*y)/a;
		cout<<"la solucion es x="<<x<<" y y="<<y<<" z="<<z<<endl;
	}
}

//Resuelve una ecuacion cuadratica
void Ecuacion_Cuadratica()
{
	float a,b,c,D,X1,X2,X1R,X1I;
	cout<<"escribe el termino cuadratico......:";cin>>a;
	cout<<"escribe el termino lineal..........:";cin>>b;
	cout<<"escribe el termino independiente...:";cin>>c;
	D=b*b-4*a*c;
	if(a==0) cout<<"La solucion es X="<<-c/b<<endl;
	else
	{
		if(D<0)
		{
			D=-D;
			cout<<"las soluciones son imaginarias"<<endl;
			X1R=-b/(2*a);
			X1I=sqrt(D)/(2*a);
			if(a<0)
			{
				cout<<"la primera solucion es X1= "<<X1R<<"-i"<<-X1I<<endl;
				cout<<"la Segunda solucion es X2= "<<X1R<<"+i"<<-X1I<<endl;
			}
			else
			{
				cout<<"la primera solucion es X1= "<<X1R<<"+i"<<X1I<<endl;
				cout<<"la Segunda solucion es X2= "<<X1R<<"-i"<<X1I<<endl;
			}
		}
		else
		{
			cout<<"las soluciones son reales"<<endl;
			X1=(-b+sqrt(D))/(2*a);
			X2=(-b-sqrt(D))/(2*a);
			cout<<"la primera solucion es X1= "<<X1<<endl;
			cout<<"la Segunda solucion es X2= "<<X2<<endl;
		}
	}
}

//calcula la raiz cuadrad de un numero
void Square_Root()
{
// 	cout<<"this program use the Newton' interpolation method to calculate the square root of a given number"<<endl;
	int i=0,n,sw=1;
	double R[100000];
	cout<<"Give a number to extract the square root...:";cin>>n;
// 	cout<<"Write the initial value...:";cin>>R[0];
	R[0]=n/2;
	while (sw==1)
	{
		if(i==99999){cout<<"The square root of  "<<n<<" es "<<setprecision (14)<<R[i+1]<<endl;
			break ;
		}
		R[i+1]=(R[i]+(n/R[i]))/2;
		if(fabs((R[i+1]-R[i])/R[i])<=0.000001){
			sw = 0;
			cout<<"The square root of  "<<n<<" es "<<setprecision (14)<<R[i+1]<<endl;
		}
		else i++;
	}
}

//calcula el promedio de una serie de datos
void Promedio()
{
	int i,n;
	float A[100];
	double Std_Dev,Pro;
	cout<<"cuantos numeros son...";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Escribe el dato "<<i<<"..:";cin>>A[i];
	}
	for(i=1;i<=n;i++)
	{
		Pro=Pro+A[i];
	}
	Pro=Pro/n;
	for(i=1;i<=n-1;i++)
	{
		Std_Dev=Std_Dev+(A[i]-Pro)*(A[i]-Pro);
	}
	Std_Dev=sqrt(Std_Dev/n);
	cout<<"el promedio es "<<Pro<<" y la desviacion estandar es "<<Std_Dev<<endl;
}

//calcula la distancia entre puntos
void Distancia_entre_Puntos()
{
	int i,n;
	float X[20],Y[20];
	double x,y,D;
	cout<<"cuantos puntos son ";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Escribe el Punto X["<<i<<"]..:";cin>>X[i];
		cout<<"Escribe el Punto Y["<<i<<"]..:";cin>>Y[i];
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			x=(X[i]-X[j]);
			y=(Y[i]-Y[j]);
			D=sqrt(x*x+y*y);
			cout<<"la distancia entre el punto "<<i<<" y el punto "<<j<<" es "<<D<<endl;
		}
	}
}

void Lagrange_Interpolation()
{
	int i,n,x,y,j;
	float num,den,Y,X,Vx[50],Vy[50];
	cout<<"write a valuer for X :";cin>>X;
	cout<<"write the number of points n :";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"X["<<i<<"] :";cin>>x;
		Vx[i]=x;
		cout<<"Y["<<i<<"] :";cin>>y;
		Vy[i]=y;
	}
	for(i=1;i<=n;i++){
		cout<<Vx[i]<<"\t"<<Vy[i]<<endl;
	}
	Y=0;
	for(i=1;i<=n;i++)
	{
		num=1;
		den=1;
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				num=num*(X-Vx[j]);
				den=den*(Vx[i]-Vx[j]);
			}
		}
		Y=Y+(num/den)*Vy[i];
	}
	cout<<"\nEntonces para X="<<X<<"\t Y="<<Y<<"\n\n";
}

//calcula una integral por el metodo de los trapecios
void Metodo_Trapecios()
{
	int i,n;
	float a,b,h,Xo,X;
	double I,F;
	cout<<"escribe el limite inferior :";cin>>a;
	cout<<"escribe el limite superior :";cin>>b;
	cout<<"escribe el numero de pasos :";cin>>n;
	Xo=a;
	h=(b-a)/n;
	for(i=0;i<=n;i++)
	{
		X=Xo+i*h;
		F=X*exp(X);//function to integrate
		if(i==0 || i==n) I=I+F/2;
		else I=I+F;
	}
	I=I*h;
	cout<<" el valor de la integral es "<<I<<endl;
}

//calcula una integral por el metodo de simpson
void Metodo_Simpson()
{
	int i,n;
	float a,b,h,Xo;
	double F,I,X,s1,s2;
	cout<<"escribe el limite inferior :";cin>>a;
	cout<<"escribe el limite superior :";cin>>b;
	cout<<"escribe el numero de pasos :";cin>>n;
	Xo=a;
	h=(b-a)/n;
	cout<<"	"<<h<<" "<<(b-a)/n<<endl;
	for(i=0;i<=n;i=i+2)
	{
		X=Xo+i*h;
		// F represents the function that you are integrating as a function of X
		F=X*exp(X)	;
		if(i==0 || i==n) s1=s1+F;
		else s1=s1+2*F;
	}
	for(i=1;i<=n;i=i+2)
	{
		X=Xo+i*h;
		F=2*X;
		s2=s2+4*F;
	}
	I=(s1+s2)*h/3;
	cout<<" el valor de la integral es "<<I<<endl;
}

void Simpson2()
{
	long double x, y, a, b, h;
	int i, n;
	long double  Y[1000];
	cout<<"escribe el limite inferior :";cin>>a;
	cout<<"escribe el limite superior :";cin>>b;
	cout<<"escribe el numero de pasos :";cin>>n;
	h=(b-a)/(n);
	cout<<"	"<<h<<" "<<(b-a)/n<<endl;
	x=a;
	for(i=1;i<=n;i++)
	{
		Y[i]=x*exp(x);
		cout<<Y[i]<<endl;
		x=x+h;
	}
}

// calcula el coseno de un angulo
void Coseno()
{
	int i,n,y=-1,j;
	double pot,fac,suma=1,ang,x;
	cout<<" Escribe un angulo en grados....:";cin>>ang;
	x=3.14159*ang/180;
	cout<<ang<<" grados = "<<x<<" radiadnes"<<endl;
	cout<<" Cuantos terminos quieres que tenga la serie...: "; cin>>n;
	for(i=2;i<=n;i=i+2)
	{
		fac=pot=1;
		for(j=1;j<=i;j++)
		{
			pot=pot*x;
			fac=fac*j;
		}
		suma=suma+y*(pot/fac);
		y=-y;
	}
	cout<<" el cos("<<ang<<") is "<<suma<<endl;
}

// calcula el exponencial de un numero
void Euler(double x)
{
	int i,n=200,j;
	double pot,fac,suma=1,x;
// 	cout<<" Escribe el valor de x....:";cin>>x;
// 	cout<<" Cuantos terminos quieres que tenga la serie...: "; cin>>n;
	for(i=1;i<=n;i++)
	{
		fac=pot=1;
		for(j=1;j<=i;j++)
		{
			pot=pot*x;
			fac=fac*j;
		}
		suma=suma+(pot/fac);
	}
// 	cout<<"  "<<x<<endl;
// 	cout<<" e es "<<suma<<endl;
}

// ordena una cadena de numeros por el metodo de la burbuja
void Metodo_Burbuja()
{
	int i,j,n;
	float A[200],aux;
	cout<<"Cuantos terminos tiene la lista...:";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Escribe el termino # "<<i<<"..:";cin>>A[i];
	}
	cout<<"La lista dada es "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	for(i=n;i>0;i--)
	{
		for(j=1;j<i;j++)
		{
			if (A[j]>A[j+1])
			{
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
		}
	}
	cout<<"La lista ornenada es "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

// convierte un numero decimal a uno binario
void Binario()
{
	int p,i=1,n,sw=1,a,m,j;
	float A[25];
	cout<<"escribe un numero decimal para convertirlo a binario....:";cin>>n;
	p=n;
	while(sw==1)
	{
		m=n/2;
		if(2*m==n) A[i]=0;
		else A[i]=1;
		if(m<1) sw=0;
		n=n/2;
		i++;
	}
	cout<<p<<" en binario es ";
	for(j=i-1;j>0;j--) cout<<A[j]<<" ";
	cout<<endl;
}

// Multiplica dos matrices
void Producto_matrices()
{
	int i,j,k,n,m,q,p;
	float A[20][20],B[20][20],C[20][20];
	cout<<"numero de  filas  de la  matrix A ";cin>>n;
	cout<<"numero de columnas de la matrix A ";cin>>m;
	cout<<"numero de  filas  de la  matrix B ";cin>>p;
	cout<<"numero de columnas de la matrix B ";cin>>q;
	if(m==p){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cout<<"escribe el elemento A["<<i<<"]["<<j<<"] ";cin>>A[i][j];
			}
		}
		for(i=1;i<=p;i++){
			for(j=1;j<=q;j++){
				cout<<"escribe el elemento B["<<i<<"]["<<j<<"] ";cin>>B[i][j];
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=q;j++){
				C[i][j]=0;
				for(k=1;k<=m;k++){
						C[i][j]=C[i][j]+A[i][k]*B[k][j];
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=q;j++){
				cout<<"	"<<C[i][j]<<"";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else cout<<"No se puede efectuar el producto"<<endl;
}

// suma dos matrices
void Suma_Matrices()
{
	int i,j,n,m;
	float A[20][20],B[20][20],C[20][20];
	cout<<"numero  de filas  de las  matrices a sumar ";cin>>n;
	cout<<"numero de columnas de las matrices a sumar ";cin>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<"escribe el elemento A["<<i<<"]["<<j<<"] ";cin>>A[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<"escribe el elemento B["<<i<<"]["<<j<<"] ";cin>>B[i][j];
		}
	}
	cout<<endl;
	cout<<"   las matrices a sumar son"<<endl;
	cout<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<"	"<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"		y"<<endl;
	cout<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<"	"<<B[i][j]<<"";
		}
		cout<<endl;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	cout<<endl;
	cout<<"y el resultado es"<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<"	"<<C[i][j]<<"";
		}
		cout<<endl;
	}
	cout<<endl;
}

// calcula la posicion y velocidad de un cuerpo en caida libre
void Caida_libre()
{
	int Ho,sw=1;
	double t=0,Y,V;
	cout<<"A que altura esta la particula (en metros)";cin>>Ho;
	while(sw==1)
	{
		V=9.8*t;
		Y=Ho-4.9*t*t;
		if(Y<=0.001) sw=0;
		else
		{
			t=t+0.001;
			cout<<" En "<<t<<" segundos: la velocidad es "<<V<<" 	y la posicion es "<<Y<<endl;
		}
	}
	cout<<endl;
	cout<<" La particula llega al suelo en "<<t<<" Segundos y con velocidad de "<<V<<endl;
}

// calcula el factorial de un numero
int Factorial(int n)
{
	int i;
	double fac=1;
// 	cout<<" Escribe un numero....:";cin>>n;
	for(i=1;i<=n;i++) fac=fac*i;
// 	cout<<" el factorial de "<<n<<" is "<<fac<<endl;
	return fac;
}

//Calcula la potencia de un numero (x a la n)
void Potencia()
{
	int i,n;
	double pot=1,x;
	cout<<" Escribe la base........:";cin>>x;
	cout<<" Escribe el exponete....:";cin>>n;
	for(i=1;i<=n;i++) pot=pot*x;
	cout<<x<<" a la "<<n<<" is "<<pot<<endl;
}

//Calcular el seno de un angulo
void Seno()
{
	int i,n,y=1,j;
	double pot,fac,suma=0,ang,x;
	cout<<" Escribe un angulo en grados....:";cin>>ang;
	x=3.14159*ang/180;
	cout<<ang<<" grados = "<<x<<" radiadnes"<<endl;
	cout<<" Cuantos terminos quieres que tenga la serie...: "; cin>>n;
	for(i=1;i<=n;i=i+2)
	{
		fac=pot=1;
		for(j=1;j<=i;j++)
		{
			pot=pot*x;
			fac=fac*j;
		}
		suma=suma+y*(pot/fac);
		y=-y;
	}
	cout<<" el sen("<<ang<<") is "<<suma<<endl;
}

//crea un archivo con valores fijos
int Crea()
{
	// Crea un archivo de salida
	ofstream fs("DosCol.txt"); // Enviamos una cadena al fichero de salida
	for(int i=1;i<20;i++){
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
	for(int l=0;l<20;l++){
		fs>>X[l]>>Y[l]>>V[l];
	}
	for(int l=0;l<20;l++){
		M1=M1+X[l];
		M2=M2+Y[l];
		M3=M3+V[l];
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
	while(j<20){
		i=1+rand()%20;
		fs <<i<<"	"<<i*i<<"	"<<i*i*i<<endl;
		j++;
	}
	fs.close();
}

//genera numeros aleatorios
int random ()
{
	int c,d;
	double k;
	cout << "Cuantos números quiere generar?.....";cin >> c;
	for (d=1;d<=c;d++){
// 		randomize();
		k=rand()%20;
		cout<<k<<"	";
	}
	cout<<endl;
}

float Tan()
{
	a=sin
}