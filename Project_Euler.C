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


//Find the sum of all the multiples of 3 or 5 below 1000.
void One()
{
	int i,n;
	int sum=0,sum2,Diff;
	cout<<"digit a number to calculate the sum of all the multiples of 3 0r 5 below it...: ";cin>>n;
	for(i=1;i<n;i++)	{
		div_t a;
		diva=div (i,3);
		if(diva.rem==0){sum=sum+i;}
		else{
			diva=div (i,5);
			if(diva.rem==0)	{sum=sum+i;}
		}
	}
	cout<<" The sum of all the multiplies of 3 or 5 below "<<n<<" is "<<sum<<endl;
}

//Fibonacci series
void Two()
{
	int i, sum=0, n;
	int A[50];
	cout<<"What number in the term in fibonacci series do you want? ...:";cin>>n;
	A[0]=1, A[1]=2;
	for(i=2;i<=n;i++)
	{
		A[i]=A[i-1]+A[i-2];
		if(A[i]>4000000)
		{
			j=i;
			i=n;
		}
	}
	for(i=0;i<=j;i++)
	{
		cout<<"A["<<i<<"]= "<<A[i]<<endl;
	}
	for(i=0;i<=j;i++)
	{
		div_t a;
		diva = div(A[i],2);
		if(diva.rem==0) 
		{
			sum=sum+A[i];
			cout<<A[i]<<"	"<<sum<<endl;
		}
	}
}

//largest prime factor of a number
void Three(){
float i, j, ii, k	, bn=143, n=600851475143, A[2000];
float const m=600475143;
	A[1]=2, A[2]=3;
// 	cout<<"initial value of k ...:";cin>>k;
// 	cout<<"start of calculation ...:";cin>>ii;
// 	cout<<"end of calculation ...:";cin>>n;
	for(i=1;i<m;i++)
	{
		div_t b;
		divb = div(m,i);
		if (divb.rem==0){cout<<m<<" / "<<i<<" = "<<divb.quot<<endl;}
	}
	/*for(i=ii;i<=n;i=i+2)	{
		int Prim;
		for(j=2;j<=i;j++){
			div_t a;
			diva = div(i,j);
			if (diva.rem==0){
				if(i==j){
					Prim=1;
// 					cout<<k<<"	"<<i<<"	";
					k++;
				}
				else{
					j=i+1;
					Prim=0;
				}
			}
		}
		if(Prim==1){
			div_t b;
			divb = div(n,i);
			if (divb.rem==0){cout<<i<<endl;}
			else {endl;}
		}
	}*/
}

//Palindrome product
void Four()
{
	int k, a, b, c, d, e, f, i, j;
	for(i=100;i<=999;i++){
		for(j=100;j<=999;j++){
			k=i*j;
			// 3 digits number
			if (k>=100 && k<=999)	{
				a=k/100;
				b=(k-a*100)/10;
				c=(k-100*a-10*b);
				if(a==c){	cout<<a<<b<<c<<endl;}
			}
			// 4 digits number
			if (k>=1000 && k<=9999){
				a=k/1000;
				b=(k-a*1000)/100;
				c=(k-1000*a-100*b)/10;
				d=(k-1000*a-100*b-10*c);
				if(a==d){
					if(b==c) {cout<<a<<b<<c<<d<<endl;}
				}
			}
			// 5 digits number
			if (k>=10000 && k<=99999)	{
				a=k/10000;
				b=(k-a*10000)/1000;
				c=(k-10000*a-1000*b)/100;
				d=(k-10000*a-1000*b-100*c)/10;
				e=(k-10000*a-1000*b-100*c-10*d);
				if(a==e){
					if(b==d){	cout<<a<<b<<c<<d<<e<<endl;}
				}
			}
			// 6 digits number
			if (k>=100000 && k<=999999){
				a=k/100000;
				b=(k-a*100000)/10000;
				c=(k-100000*a-10000*b)/1000;
				d=(k-100000*a-10000*b-1000*c)/100;
				e=(k-100000*a-10000*b-1000*c-100*d)/10;
				f=(k-100000*a-10000*b-1000*c-100*d-10*e);
				if(a==f){
					if(b==e){
						if(c==d){cout<<i<<" x "<<j<<" = "<<a<<b<<c<<d<<e<<f<<endl;}
					}
				}
			}
		}
 	}
}

// What is the smallest number divisible by each of the numbers from 1 to n(an integer)? 
void Five()
{
	int j, n;
	int i, ii, m;
	cout<<"Write a number to calculate the smallest number divisible by each of the numbers from 1 to it :";cin>>n;
	cout<<"Write a number to start the process :";cin>>i;
	cout<<"Write a number to start the process :";cin>>ii;
	for(m=i;m<=ii;m=m+10)
	{
		for(j=2;j<=n;j++)
		{
			div_t a;
			diva = div(m,j);
			if(diva.rem!=0) {j=n+1;	}
			else
			{
				if (j==n)
				{
					cout<<"the smallest number divisible by each of the numbers from 1 to "<<n<<" is "<<m<<endl;
					m=ii;
				}
				else {if(m==ii){cout<<"no yet "<<endl;}
				}
			}
		}		
	}
}

// What is the difference between the sum of the squares and the square of the sums?
void Six()
{
	int i,n;
	int sum1=0,sum2,Diff;
	cout<<"digit a number to calculate the difference between of the square and the sqaure of sum...: ";cin>>n;
	for(i=1;i<=n;i++){
		sum1=sum1+i*i;
		sum2=sum2+i;
	}
	sum2=pow(sum2,2);
	Diff=sum2-sum1;
	cout<<"The difference between of the square sum  and the sqaure of sum between 1 and "<<n<<" is "<<Diff<<endl;
}

//Find the 10001st prime.
void Seven()
{
	int Prim, i=5, q, counter=2, x;
	while(counter<10001)
	{
		for(int j=2;j<=i;j++)
		{
			x=i % j;
			if(x==0)
			{
				if(j==i){counter++;	}
				else{j=i+1;}
			}
		}
		i=i+2;
	}	
	cout<<i-2<<endl;
}

//Find the thirteen adjacent digits in the 1000-digit number that have the greatest product
void Problem_Eigth(){
	int Bla;
	int craizy;
	"	";
	
	
	
	
	
}

//Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.
void Nine()
{
	float a,b,c,d,e,f;
	int pro,z=0;
	for(b=2;b<1000;b++)	{
		for(a=1;a<b;a++){
			c=sqrt(a*a + b*b);
			cout<<a<<"  "<<b<<"  "<<c<<"  sum "<<a+b+c<<endl;
			if((a+b+c)==1000){
				d=a;
				e=b;
				f=c;
			}
		}
	}
	pro=d*e*f;
	cout<<d<<"  "<<e<<"  "<<f<<" pro "<<pro<<endl;
}

//Calculate the sum of all the primes below a number.
void Ten()
{
	int i, perpri;
	long int sum=0;
// 	cout<<"digit a number to calculate the sum of all prime up to it:";cin>>n;
	ofstream fs("10_2.txt");
	for(i=1999999;i>1;i=i-2)
	{
		perpri=Prime(i);
		if(perpri==1) {sum=sum+i;
// 		cout<<i<<"  "<<sum<<endl;
		fs <<i<<"		"<<sum<<endl;
		}
	}
	fs.close();
}

//What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
double Eleven()
{
	int i,sum=2,n,perpri;
	cout<<"...:";cin>>n;
	ofstream fs("11.txt");
	for(i=2000000;i>2n;i=i-2)
	{
		perpri=Prime(i);
		if(perpri==1) {sum=sum+i;
// 		cout<<i<<"  "<<sum<<endl;
		fs <<i<<"		"<<sum<<endl;
		}
	}
	fs.close();
}

//What is the value of the first triangle number to have over five hundred divisors?
double Twelve()
{
	int i,sum=2,n,perpri;
	cout<<"..:";cin>>n;
	ofstream fs("12.txt");
	for(i=2000000;i>2n;i=i-2)
	{
		perpri=Prime(i);
		if(perpri==1) {sum=sum+i;
// 		cout<<i<<"  "<<sum<<endl;
		fs <<i<<"		"<<sum<<endl;
		}
	}
	fs.close();
}

//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
double Thirteen()
{
	int i,sum=2,n,perpri;
	cout<<"...:";cin>>n;
	ofstream fs("13.txt");
	for(i=2000000;i>2n;i=i-2)
	{
		perpri=Prime(i);
		if(perpri==1) {sum=sum+i;
// 		cout<<i<<"  "<<sum<<endl;
		fs <<i<<"		"<<sum<<endl;
		}
	}
	fs.close();
}

//longest collatz sequence. Hatsa 113382 el mayor es 106239 con una cadena de 354 numeros		
void Problem_Fourteen(){
	int sw, n, k, j, m, l=1;
	long double int i;
	cout<<"write the starting number in the series.....:";cin>>n;
	cout<<"write the ending number in the series.......:";cin>>m;
	ofstream fs("14.txt");	
	for(j=n;j<m;j++){
		i=j;
		sw=1, k=1;
// 		ofstream fs(Form("/home/joaquin/Mas/Data_%i.txt",j));
// 		cout<<k<<"	"<<i<<endl;
		while (sw==1){
			div_t a;
			diva = div(i,2);
			if(diva.rem==0){
				i=i/2;
				k++;
			}
			else{
				i=3*i+1;
				k++;
			}
			if(i==1){sw=0;}
		}
		if(k>=l){
			l=k;
			cout<<j<<"	"<<k<<endl;
			fs <<j<<"		"<<k<<endl;}
			else{
				cout<<j<<endl;
			}
			
	}
	fs.close();
}


void Problem_FourteenDos(){
	int sw=1, n, k=1, j, m, l=1;
	long double int i;
	cout<<"write a number.....:";cin>>i;
	div_t a;
	cout<<i<<"	"<<k<<endl;
	while(sw==1)
	{
		diva = div(i,2);
		if(diva.rem==0)
		{
			i=i/2;
			k=k+1;;
		}
		else
		{
			i=3*i+1;
			k=k+1;;
		}
		if(i==1){sw=0;}
		k=k++;
		cout<<i<<"	"<<k<<endl;
	}
}

//How many such routes are there through a 20×20 grid?
void Fifteen(){
	int sw=1, n, k=1, j, m, l=1;
	long double int i;
	cout<<"write a number.....:";cin>>i;
	div_t a;
	cout<<i<<"	"<<k<<endl;
	while(sw==1)
	{
		diva = div(i,2);
		if(diva.rem==0)
		{
			i=i/2;
			k=k+1;;
		}
		else
		{
			i=3*i+1;
			k=k+1;;
		}
		if(i==1){sw=0;}
		k=k++;
		cout<<i<<"	"<<k<<endl;
	}
}

//What is the sum of the digits of the number 21000?
void Sixteen(){
	int n=1, i;
// 	ofstream fs("16.txt");	
	for(i=1;i<5;i++){
		n=n*2;
		cout<<n<<endl;
	}
// 	fs.close();
}

//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
void Nineteen(){
	int i, j, k, sun=0;
	int M=11, T=22, W=33, T=44, S=55, U=66, D=77;
	ofstream fs("19.txt");	
	for(i=1;i<5;i++){
		for(j=1;j<3;j++){
			for(k=1;k<30;k++){
				for(l=1;l<8;l++){cout<<i<<"	"<<j<<"	"<<k<<"	"<<M<<endl;
				}
			}
		}
	}
}


//Find the sum of the digits in the number 100!
void Twenty(){
	int i;
	long int fac=1;
	ofstream fs("20.txt");	
	for(i=1;i<101;i++)
	{
		fac=fac*i;
		cout<<i<<"	"<<fac<<endl;
		fs <<i<<"		"<<fac<<endl;
	}
	fs.close();
}

//Amicable Number
void TwentyOne(){
	int x;
	ofstream fs("21.txt");
	div_t a;
	for(int i=2;i<11;i++)
	{
		fs<<i<<"	";
		for{int j=1;j<i;j++}
		{
			x=i%j;
			cout<<i<<"	"<<j<<"	"<<x<<"	";
			if(x==0){
// 			diva=div (i,j);
// 			if(diva.rem==0){
// 				cout<<i<<j<<endl;}
// 				fs<<j<<"	";}
// 			else{
// 			diva=div (i,5);
// 			if(diva.rem==0)	{sum=sum+i;}
// 			fs <<i<<"		"<<fac<<endl;
		}}
		cout<<endl;
		fs<<endl;
	}
	cout<<endl;
	fs.close();
}

void Trial()
{
	int i, j, x,n, sum;
	cout<<"write a number.....:";cin>>n;
	ofstream fs("21-2.txt");
	for(i=2;i<n;i++)
	{
// 		fs<<i<<"	";
		sum=0;
		for(j=1;j<i;j++)
		{
			x=i%j;
			if(x==0){
				sum=sum+j;
// 			fs<<"	";
				
			}
		}
		fs<<i<<"	"<<sum<<endl;
	}
	fs.close();
}

void TwentyFour()
{
	int sum=0;
	ofstream fs("24.txt");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					for(int m=0;m<10;m++){
						for(int n=0;n<10;n++)
						{
							for(int o=0;o<10;o++)
							{
								for(int p=0;p<10;p++)
								{
									for(int q=0;q<10;q++)
									{
										for(int r=0;r<10;r++)
										{
											if(i!=j && i!=k && j!=k && i!=l && j!=l && k!=l && i!=m && j!=m && k!=m && l!=m && i!=n && j!=n &&
k!=n && l!=n && m!=n && i!=o && j!=o && k!=o && l!=o && m!=o && n!=o && i!=p && j!=p && k!=p && l!=p && m!=p && n!=p && o!=p && i!=q && j!=q && k!=q && l!=q && m!=q && n!=q && o!=q &&
p!=q && i!=r && j!=r && k!=r && l!=r && m!=r && n!=r && o!=r && p!=r && q!=r)
											{
												fs<<i<<j<<k<<l<<m<<n<<o<<p<<q<<r<<endl;
												sum++;
												if (sum==1000000)
												{
													cout<<i<<j<<k<<l<<m<<n<<o<<p<<q<<r<<endl;
													break;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}






//example Functions
double main(){
	double x,z,i=10;
	int n=10;
	z=Prime(i);
	if(z==1){	cout<<x<<"Prime "<<endl;}
	if(z==0){	cout<<x<<"No Prime "<<endl;}
}

//return the prime number
int FindPrime(int Number){
	int Prime, x, y;
	x=Number%2;
	y=Number%5;
	if(x==0 || y==0){Prime=0;}
	else{
		for(int j=2;j<=Number;j++){
			x=Number % j;
			cout<<x<<endl;
			if(x==0){
				if(j==Number){Prime=1;}
				else{Prime=0;
					j=Number;
				}}}}
	if(Prime==1){return Number;}
	else(){return 0;}
}

//returm 1 if number if prime
int Prime(int Number){
	int Prime ,x, y;
	x=Number%2;
	y=Number%5;
	if(x==0 || y==0){Prime=0;}
	else{
		for(int j=2;j<=Number;j++){
			x=Number % j;
			if(x==0){
				if(j==Number){Prime=1;}
				else{Prime=0;
					j=Number;
				}}}}
	return Prime;
}