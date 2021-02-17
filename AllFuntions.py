#!/usr/bin/env python
from matplotlib import pyplot as mp
from dateutil.parser import parse
from datetime import date
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math
import datetime as dt
import matplotlib.dates as mdates
import datetime
#import pandas as pd
from pylab import figure, axes, pie, title, show
from decimal import *
from random import seed, randint

import MyFunctions


#use as python -c 'import allFuntions; print AllFuntions.functionname()'. To run a particular function

#draw several gaussians
def gaussian(x, mu, sig):
    return np.exp(-np.power(x - mu, 2.) / (2 * np.power(sig, 2.)))

def mulgaussian():
	for mu, sig in [(-1, 1), (0, 2), (1, 3), (2,4)]:
		mp.plot(gaussian(np.linspace(-3, 3, 50), mu, sig))
		print (mu, sig)
	mp.show()

def onegaussian():
	mu = 0
	variance = 1
	sigma = math.sqrt(variance)
	x = np.linspace(mu-3*variance,mu+3*variance, 100)
	plt.plot(x,mlab.normpdf(x, mu, sigma))
	plt.show()
	savefig('gauss.png')

def Poisson():
	s = np.random.poisson(5, 10000)
	plt.plot(s,10.)
	#count, bins, ignored = plt.hist(s, 14, normed=True)
	plt.show()
	
def alldist():
	gaussian = np.random.normal(0.5, 2*np.sqrt(2*np.log(2)), 1000)
	poisson = np.random.poisson(0.5, 1000)
	#plt.hist(gaussian)
	plt.plot(gaussian)
	#plt.hist(poisson)
	plt.show()
	#print(np.mean(gaussian))
	#print(np.var(gaussian))
	#print(np.mean(poisson))
	#print(np.var(poisson))

def charts2():
	objects = ('CONALPA', 'OCTAVIO MENDOZA', 'BENITO RAMOS', 'BOQUERON', 'LUIS CARLOS GALAN', 'JOSE GUILLERMO', 'LA VICTORIA', 'ESTADOS UNIDOS','ANGELA MARIA',' TRUJILLO')
	y_pos = np.arange(len(objects))
	performance = [22,22,20,17,19,22,19,17,20,38]
	plt.figure(facecolor="white")
	plt.bar(y_pos, performance, align='center', alpha=0.5)
	
	plt.xticks(y_pos, objects)
	plt.ylabel('Estudiantes')
	plt.title('Instituciones Educativas')
	
	plt.show()

#I vs V for February test beam
def IvsV():
	v = [0,5,10,15,20,30,40,50,60,70,80,90,100]
	v1 = [0,10,20,30,40,50,60,70,80,90,100]
	MJ131 = [41,85,88,90,92,99,105,112,120,121,125,126,129]
	MJ125 = [94,230,250,260,270,280,290,300,305,310,315,320,322]
	MJ139 = [57,119,120,122,125,126,129,126,131,130,133,130,136]
	MJ140 = [38,84,86,87,87,88,87,88,88,89,89,92,90]
	MJ138 = [25,66,76,80,83,88,87,89,91,92,93,93,94]
	MJ129 = [30,61,65,67,70,74,78,80,83,86,85,86,87]
	MJ127 = [27,49,53,52,55,56,57,59,59,61,62]
	
	#fig, ax = plt.subplots()
	plt.figure(facecolor="white")
	plt.ylabel('Current (-nA)')
	plt.xlabel('Voltage (-V)')
	#plt.title('el titulo')
	
	plt.plot(v, MJ131, 'bo', label='MJ131')
	plt.plot(v, MJ125, 'go', label='MJ125')
	plt.plot(v, MJ139, 'ro', label='MJ139')
	plt.plot(v, MJ140, 'b s', label='MJ140')
	plt.plot(v, MJ138, 'r s', label='MJ138')
	plt.plot(v, MJ129, 'y o', label='MJ29')
	plt.plot(v1, MJ127, 'k o', label='MJ127')
	#plt.plot(v, MJ131, '-b', label='MJ131')
	
	#plt.axis('equal')
	
	leg = plt.legend();
	plt.savefig('I_vs_V_feb.png')
	plt.show()
	
#prime numbers up to n
def primefactors(n):
	factorlist = []
	k = 2
	while k <= n:
		#print k
		while n % k == 0:
			factorlist.append(k)
			n //= k
		k += 1
	return factorlist

def otra():
	for n in range (2,10000):
		if len(primefactors(n)) == 1:
			print (n)

#Factorial of a number
def facto(n):
	fact = MyFunctions.factorial(n)
	print (fact)

#Distance in cilindrical coordinaates
def distincilin(r,theta,z):
	x = r * cos (theta)
	y = r * sin (theta)
	d = sqrt(x*x + y*y + z*z)
	return d

#convert from polar to cartesians
def ConPolCoo():
	r = float(input ("What is the lenght : "))
	the = float(input ("What is the angle : "))
	theta = the*pi/180
	x = r*cos(theta)
	y = r*sin(theta)
	print ("x= ",x," and y = ",y)
	return [x,y]
	
#convert to polar coordinates
def ConCarCoo():
	x = float(input ("What is the value of x : "))
	y = float(input ("What is the value of y : "))
	theta = atan(y/x)
	r = x/cos(theta)
	print ("r= ",r," and theta = ",theta*180/pi)

def no_se():
	random.seed (None)
	jmax = 1000
	print(jmax)
	xx = yy = zz =0.0
	graph1 = display(x= 0, y= 0, width = 600, height = 600, title ='hytr', forward = (-0.6,-0.5,-1))
	pts = curve(x= list(range(0,100)), radius= 10.0, color= color.yellow)
	xax = curve (x= list(range(0,1500)),color = color.red, pos= [(0,0,0),(1500,0,0)],radius = 10)
	yax = curve (x= list(range(0,1500)),color = color.red, pos= [(0,0,0),(0,1500,0)],radius = 10)
	zax = curve (x= list(range(0,1500)),color = color.red, pos= [(0,0,0),(0,0,1500)],radius = 10)
	xname = label(text= "X", pos = (1000,150,0), box =0)
	xname = label(text= "Y", pos = (-100,1000,0), box =0)
	xname = label(text= "Z", pos = (100,0,1000), box =0)
	pts.x[0]=pts.y[0]=pts.z[0]=0

	for i in range(1,100):
		xx += (random.random()-0.5)*2.
		yy += (random.random()-0.5)*2.
		zz += (random.random()-0.5)*2.
		pts.x[i] = 200 * xx -100
		pts.y[i] = 200 * xx -100
		pts.z[i] = 200 * xx -100
		rate(100)
	print("this walk was ", sqrt(xx*xx+yy*yy+zz*zz))

#Combination of IV 
def IV_comb():
	count = 0
	for i in range (0,16):
		for j in range(0,16):
			for k in range(0,16):
				if (i+j == 30) or (i+k == 30) or (j+k == 30):
					print (i,'	',j,'	',k)
					count = count +1
	print (count)

#no se que hace
def nose3():
	n = 4
	fact = 10
	num = 1.0
	den = 365
	for i in range (365-n+2,365):
		num = num*i
		den = den*365
		#print i,' ', num,' ', den
	tot = 1000*num/den
	print (tot)

def Sorry_amorcito():
	seed (1)
	sw=1
	while sw == 1:
		value = randint(1,12)
		#print value
		if value == 1: print (value, 'move forward 1 space \n')
		if value == 2: print (value, 'move forward 2 spaces \n')
		if value == 3: print (value, 'move forward 1 space \n')
		if value == 4: print (value, 'move forward 2 spaces \n')
		if value == 5: print (value, 'move forward 1 space \n')
		if value == 6: print (value, 'move forward 2 spaces')
		if value == 7: print (value, 'move forward 1 space')
		if value == 8: print (value, 'move forward 2 spaces')
		if value == 9: print (value, 'move forward 1 space')
		if value == 10: print (value, 'move forward 2 spaces')
		if value == 11: print (value, 'move forward 1 space')
		if value == 12: print (value, 'move forward 2 spaces')
		#sw = 0
		sw1 = str(raw_input('Push any key to exit 1 to keep plaing'))

#calculate the increase of number as twice the day before
def doubleday(n):
	suma = 0.01
	sumatot = 0.01
	i = 1
	print (i,' ',suma,' ',suma/i)
	for i in range(2,n):
		suma  = 2*suma
		sumatot = sumatot + suma
		avg = sumatot/i
		print (i,' ',sumatot,' ',("%.2f" % avg))

#calculate interest for money market
def mymoma():
	date = ['08-19','09-19','10-19','11-19','12-19','01-20','02-20','03-20','04-20','05-20','06-20','07-20']
	gain = [0.00, 0.38, 0.42, 0.41, 0.46, 0.51, 0.50, 0.66, 0.66, 0.54, 0.61, 0.72]
	total = [2500, 2500.38, 2500.80, 2501.21, 3001.67, 3501.18, 3502.68, 4003.34, 4004.00, 4304.54, 5005.15,10000]
	#datafile = open("alltxt/mymoma.txt")
	#datalines = datafile.readlines()[1:]
	#date, gain, gainT, total = ([] for i in range(4))#define emmpty list with the values in the file
	#xpd, walkd, catchd, hatchd, stopsd = ([] for i in range(5))#define empty list with values in the file wothout the date
	
	#i = 0
	gaint = 0
	gainT = []
	for i in range(len(gain)):
		gaint = gaint + float (gain[i])
		gainT.append(float(gaint))
		print (gainT)
	##gainT [0] = 0
	#for line in datalines:
		#alldata = line.split()
		#date.append(alldata[0])
		#trans.append(alldata[1])
		#dia.append(alldata[2])
		#inte.appenxp[i+1])-int(xp[i])))
		#walkd.append(int(walk[i+1])-int(walk[i]))
		#catchd.append(int(catch[i+1])-int(catch[i]))
		#hatchd.append(int(hatch[i+1])-int(hatch[i]))
		#stopsd.append(int(stops[i+1])-int(stops[i]))
		#batled.append(int(batle[i+1])-int(batle[i]))
		#feedd.append(int(feed[i+1])-int(feed[i]))
		#defendingd.append(int(defending[i+1])-int(defending[i]))
		#taskd.append(int(task[i+1])-int(task[i]))
		#i = i + 1
	
	#Calculate total days and array them
	
	#df['date'] = df['month'].map(str)+ '-' +df['year'].map(str)
	#df['date'] = pd.to_datetime(df['date'], format='%m-%Y').dt.strftime('%m-%Y')
	#fig, ax = plt.subplots()
	#plt.plot_date(df['date'], df['Value'])
	#plt.show()
	
	#dlev= len(date)
	#daytot =Decimal(850 + (len(date) - 25)*7)
	#print(daytot)
	x = [dt.datetime.strptime(m,'%m-%y').date() for m in date]
	
	#print '===================================================='
	#print '	',date[-1],'	week	 ave total'
	#print 'xp 		',int(xp[-1])-int(xp[-2]),'		',(int(xp[-1]))/int(daytot)
	#print 'walk 		',int(walk[-1])-int(walk[-2]),'		',(Decimal(float(walk[-1]))/daytot)
	#print 'pokemon		',int(catch[-1])-int(catch[-2]),'		',Decimal(float(catch[-1]))/daytot
	#print 'hatch		',int(hatch[-1])-int(hatch[-2]),'		',Decimal(float(hatch[-1]))/daytot
	#print 'stops 		',int(stops[-1])-int(stops[-2]),'		',Decimal(float(stops[-1]))/(daytot)
	##print 'Batles		',int(batle[-1])-int(batle[-2]),'		',Decimal(float(batle[-1]))/(daytot)
	#print 'Feed		',int(feed[-1])-int(feed[-2]),'		',Decimal(float(batle[-1]))/(daytot-379)
	#print 'defending 	',int(defending[-1])-int(defending[-2]),'		',Decimal(float((defending[-1])))/(daytot-379)
	#print 'task		',int(task[-1])-int(task[-2]),'		',Decimal(float(task[-1]))/(daytot-631)
	#print '==================================================='
	#fdiv = [float(walki)/hatchi for walki,hatchi in zip(walkd,hatchd)]
	
	fig, ax1 = plt.subplots()
	color = 'tab:red'
	ax1.set_xlabel('date')
	ax1.set_ylabel('total',color=color)
	ax1.xaxis.set_major_formatter(mdates.DateFormatter('%m-%y'))
	ax1.plot(x,total,color=color)
	ax1.tick_params(axis='y',labelcolor=color)
	
	ax2 = ax1.twinx()
	color = 'tab:blue'
	ax2.set_ylabel('interest', color=color)
	ax2.plot(x,gainT,color=color)
	ax2.tick_params(axis='y',labelcolor=color)
	
	fig.tight_layout()
	plt.show()
	
	#plt.figure(facecolor="white")
	#plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%m-%y'))
	#plt.plot(x,total,'b*--')
	#plt.gca().set_title('Total on the market')
	#plt.gca().set_xlabel('Date')
	#plt.gca().set_ylabel('total')
	#plt.gca().grid(True)
	#plt.show()
	
	#plt.figure(facecolor="white")
	#plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	#plt.plot(x,walkd,'ro--', label = 'Walked')
	#plt.plot(x,hatchd,'b*--', label= 'Hatch')
	#plt.gca().set_title('Weekly')
	#plt.gca().set_xlabel('Date')
	#plt.gca().set_ylabel('Counts')
	#plt.gca().grid(True)
	#legend = plt.gca().legend(loc='upper right', fontsize='large')
	
	#plt.figure(facecolor="white")
	#plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	#plt.plot(x,catchd,'ro--', label= 'Catched')
	#plt.plot(x,stopsd,'b*--', label= 'Spun')
	##plt.plot(x,feedd,'gs--', label= 'Feed')
	#plt.gca().set_title('Weekly')
	#plt.gca().set_xlabel('Date')
	#plt.gca().set_ylabel('Counts')
	#plt.gca().grid(True)
	#legend = plt.gca().legend(loc='upper right', fontsize='large')
	
	#plt.figure(facecolor="white")
	#plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	#plt.plot(x,batled,'ro--', label= 'Batle')
	#plt.plot(x,defendingd,'b*--', label= 'Defend')
	#plt.plot(x,taskd,'gs--', label= 'Task')
	#plt.gca().set_title('Weekly')
	#plt.gca().set_xlabel('Date')
	#plt.gca().set_ylabel('Counts')
	#plt.gca().grid(True)
	#legend = plt.gca().legend(loc='upper right', fontsize='large')
	#plt.show()
	
	return ''

def FatoCe():
	Ce = []
	Fa = []
	for i in range(-40,42,2):
		Ce.append(i)
	
	for i in range(len(Ce)):
		Fa.append( 9*Ce[i]/5.+32)
	plt.figure(facecolor="white")
	plt.ylabel('Farengeit')
	plt.xlabel('Celcius ')
	plt.plot(Ce, Fa, 'bo')
	plt.grid(True)
	plt.show()
	#print Fa
	
def FartoCel():
	ce = float(input ("Give me a number in Celcius :"))
	fa = 9*ce/5 + 32
	print (ce," celcuis are ",fa," Farengeit")
	return ''

#my exercise
def Exercise():
	Exercise_Bike()
	Exercise_Run()
	Exercise_Weight()
	return ''

#Myweight
def Exercise_Weight():
	datafile = open("alltxt/exercise_weight.txt")
	datalines = datafile.readlines()[1:]
	date, lb, kg = ([] for i in range(3))
	for line in datalines:
		alldata = line.split()
		date.append(alldata[0])
		lb.append(alldata[1])

	for y in range(len(lb)):
		kg.append(float(lb[y])/2.205)
	
	x = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in date]
	
	fig, ax1 = plt.subplots()
	color = 'tab:red'
	ax1.set_xlabel('date')
	ax1.set_ylabel('in pounds',color=color)
	ax1.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	ax1.plot(x,lb,color=color)
	ax1.tick_params(axis='y',labelcolor=color)
	
	ax2 = ax1.twinx()
	color = 'tab:blue'
	ax2.set_ylabel('in kg', color=color)
	ax2.plot(x,kg,color=color)
	ax2.tick_params(axis='y',labelcolor=color)
	
	fig.tight_layout()
	plt.show()
	return ''

#Biking Exercise
def Exercise_Bike():
	print (' ')
	return ''

#running exercise
def Exercise_Run():
	datafile = open("alltxt/exercise_run.txt")
	datalines = datafile.readlines()[1:]
	date, daily, avg, tot = ([] for i in range(4))
	for line in datalines:
		alldata = line.split()
		date.append(alldata[0])
		daily.append(float(alldata[1]))

	for i in range(len(daily)):
		if i == 0:
			tot.append(float(daily[i]))
			avg.append(float(tot[i]))
		else:
			tot.append(float(tot[i-1])+float(daily[i]))
			avg.append(float(tot[i])/(i+1))
	x = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in date]
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x,daily,'ro--', label = 'Daily')
	plt.plot(x,avg,'b*--', label= 'Average')
	plt.gca().set_title('Daily run')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')

	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x,tot,'bo--', label = 'Positive')
	#plt.plot(x,dai_test,'b*--', label= '# of tests')
	plt.gca().set_title('running distance')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	#legend = plt.gca().legend(loc='upper right', fontsize='large')
	plt.show()
	return ''

#covid cases at unl since mid august	
def Covid_unl():
	datafile = open("alltxt/covid_unl.txt")
	datalines = datafile.readlines()[1:]
	date, dai_pos, dai_test, tot_pos, tot_test, dai_porc, tot_porc = ([] for i in range(7))
	for line in datalines:
		alldata = line.split(' ')
		date.append(alldata[0])
		dai_pos.append(int(alldata[1]))
		dai_test.append(int(alldata[2]))
	
	for y in range(len(dai_pos)):
		if y == 0:
			tot_pos.append(int(dai_pos[y]))
		if y > 0:
			tot_pos.append(int(tot_pos[y-1]+dai_pos[y]))
	for y in range(len(dai_test)):
		if y == 0:
			tot_test.append(int(dai_test[y]))
		if y > 0:
			tot_test.append(int(tot_test[y-1]+dai_test[y]))
	
	for y in range(len(dai_test)):
		if (tot_test[y] == 0 or dai_test[y] == 0):
			dai_porc.append(0)
			tot_porc.append(0)
			continue
		else:
			num_dai = float("{:.2f}".format(100*float(dai_pos[y])/float(dai_test[y])))
			num_tot = float("{:.2f}".format(100*float(tot_pos[y])/float(tot_test[y])))
			dai_porc.append(num_dai)
			tot_porc.append(num_tot)	
		
		
	x = [dt.datetime.strptime(d,'%m-%d-%y').date() for d in date]
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x,dai_pos,'ro--', label = 'Positive')
	plt.plot(x,dai_test,'b*--', label= '# of tests')
	plt.gca().set_title('Daily covid UNL')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('# of test')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x,tot_pos,'ro--', label = 'Positive')
	plt.plot(x,tot_test,'b*--', label= '# of tests')
	plt.gca().set_title('Total covid UNL')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('# of test')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x,dai_porc,'ro--', label = 'daily')
	plt.plot(x,tot_porc,'b*--', label = 'total')
	plt.gca().set_title('Porcentage of covid UNL')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('Porcentage')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper right', fontsize='large')
	plt.show()
	return ''
	
def Plot_Style():
	x, y, y1, y2, y3, y4, y5, y6, y7, y8= ([] for i in range(10))
	for i in range(11):
		x.append(i)
		y.append(math.sin(i))
		y1.append(math.cos(i))
		y2.append(i+1)
		y3.append(i)
		y4.append(i-1)
		y5.append(i+2)
		y6.append(i+3)
		y7.append(i+4)
		y8.append(i+5)
		
		
	plt.figure(facecolor="white")
	plt.plot(x,y,'ro--', label = 'y = sin x ')
	plt.plot(x,y1,'g-.', label = 'y = cos x ')
	plt.plot(x,y2,'bv--', label = 'y = x+1 ')
	plt.plot(x,y3,'c^--', label = 'y =  x ')
	plt.plot(x,y4,'y<--', label = 'y = x-1 ')
	plt.plot(x,y5,'m>--', label = 'y =  x+2 ')
	plt.plot(x,y6,'k1--', label = 'y =  x+3 ')
	plt.plot(x,y7,'r*--', label = 'y =  x+4 ')
	plt.plot(x,y8,'bs--', label = 'y = x+5 ')
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.gca().set_title('Daily bike')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	plt.show()
	
def marica():
	datafile = open("alltxt/marica.txt")
	datalines = datafile.readlines()[1:]
	date, weight, bike, bike_tot, bike_avg, run, run_tot, run_avg, stat, stat_tot, stat_avg, kg = ([] for i in range(12))
	for line in datalines:
		alldata = line.split()
		date.append(alldata[0])
		print alldata[0]
		weight.append(float(alldata[1]))
		bike.append(float(alldata[2]))
		run.append(float(alldata[3]))
		stat.append(float(alldata[4]))
	
	for y in range(len(weight)):
		kg.append(float(weight[y])/2.205)

	bike_date = date[:]
	run_date = date[:]
	kg_date = date[:]
	stat_date = date[:]
	
	i= 0
	while i < len(bike):
		#print i,' ',bike[i]
		if float(bike[i]) == 0.0:
			bike.remove (0.0)
			del(bike_date[i])
			i=i-1
		i=i+1
		
	i= 0
	while i < len(kg):
		#print i,' ',kg[i]
		if float(kg[i]) == 0.0:
			kg.remove (0.0)
			del(kg_date[i])
			i=i-1
		i= i+1
		
	i= 0
	while i < len(run):
		#print i,' ',run[i]
		if float(run[i]) == 0.0:
			run.remove (0.0)
			del(run_date[i])
			i=i-1
		i= i + 1
	
	i= 0
	while i<len(stat):
		if float(stat[i]) == 0.0:
			stat.remove(0.0)
			del(stat_date[i])
			i = i - 1
		i = i + 1
	
	#Starting bike 	
	for i in range(len(bike)):
		if i == 0:
			bike_tot.append(float(bike[i]))
			bike_avg.append(float(bike_tot[i])/(i+1))
			#print bike_tot[i],' ',bike_avg[i]
		else:
			bike_tot.append(float(bike_tot[i-1])+float(bike[i]))
			bike_avg.append(float(bike_tot[i])/(i+1))

	#Starting run
	for i in range(len(run)):
		if i == 0:
			run_tot.append(float(run[i]))
			run_avg.append(float(run_tot[i]))
		else:
			run_tot.append(float(run_tot[i-1])+float(run[i]))
			run_avg.append(float(run_tot[i])/(i+1))
			
	#Starting static 	
	for i in range(len(stat)):
		if i == 0:
			stat_tot.append(float(stat[i]))
			stat_avg.append(float(stat_tot[i])/(i+1))
		else:
			stat_tot.append(float(stat_tot[i-1])+float(stat[i]))
			stat_avg.append(float(stat_tot[i])/(i+1))
	print()
	print ("          total  average as of ",date[-1])
	print ("biking ",round(bike_tot[-1],1),round(bike_tot[-1]/len(bike),1))
	print ("running",round(run_tot[-1],1),round(run_tot[-1]/(len(run)),1))
	print ("Static ",round(stat_tot[-1],1),round(stat_tot[-1]/(len(stat)),1))#,' Km in the static bike')
	x_bike = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in bike_date]
	x_run = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in run_date]
	x_weight = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in kg_date]
	x_stat = [dt.datetime.strptime(d,'%d-%m-%y').date() for d in stat_date]
	
	
	'''plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_bike,bike,'r--', label = 'bike')
	plt.plot(x_weight,kg,'k--', label= 'weight')
	plt.plot(x_run,run,'b--', label= 'run')
	plt.gca().set_title('Daily')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')'''
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_bike,bike_tot,'bo--', label = 'bike')
	plt.plot(x_run,run_tot,'ro--',label = 'run')
	plt.plot(x_stat,stat_tot,'go--',label = 'stat')
	plt.gca().set_title('Total distance')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_bike,bike_avg,'b*--', label= 'Bike')
	plt.plot(x_run,run_avg,'r*--', label= 'Run')
	plt.plot(x_stat,stat_avg,'g*--', label= 'Stat')
	plt.gca().set_title('Average')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_bike,bike,'bo--', label = 'Bike ')
	plt.plot(x_run,run,'ro--', label = 'run')
	plt.plot(x_stat,stat,'g*--', label= 'stat')
	plt.gca().set_title('Daily')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_bike,bike,'go--', label= 'Daily')
	plt.plot(x_bike,bike_avg,'ro--', label = 'Average')
	plt.plot(x_bike,bike_tot,'bo--', label = 'Total')
	plt.gca().set_title('Biking')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_run,run,'go--', label= 'Daily')
	plt.plot(x_run,run_avg,'ro--', label = 'Average')
	plt.plot(x_run,run_tot,'bo--', label = 'Total')
	plt.gca().set_title('Running')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_stat,stat,'go--', label= 'Daily')
	plt.plot(x_stat,stat_avg,'ro--', label = 'Avgerage')
	plt.plot(x_stat,stat_tot,'bo--', label = 'Total')
	plt.gca().set_title('Static')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')
	plt.show()
	
	'''plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_weight,kg,'bo--')
	#plt.plot(x,dai_test,'b*--', label= '# of tests')
	plt.gca().set_title('My weight')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('weight')
	plt.gca().grid(True)
	
	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_run,run,'ro--', label = 'Daily run')
	plt.plot(x_run,run_avg,'b*--', label= 'Average run')
	plt.plot(x_stat,stat_avg,'g*--', label= 'Average stat')
	plt.plot(x_stat,stat,'ms--', label= 'Daily stat')
	plt.gca().set_title('Exercise')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	legend = plt.gca().legend(loc='upper left', fontsize='large')

	plt.figure(facecolor="white")
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	plt.plot(x_run,run_tot,'bo--', label = 'running')
	plt.plot(x_stat,stat_tot,'g*--', label= 'Static bike')
	plt.gca().set_title('Run and static')
	plt.gca().set_xlabel('Date')
	plt.gca().set_ylabel('kilometers')
	plt.gca().grid(True)
	
	
	#fig, ax1 = plt.subplots()
	#color = 'tab:red'
	#ax1.set_xlabel('date')
	#ax1.set_ylabel('Weight',color=color)
	#ax1.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
	#ax1.plot(x,lb,color=color)
	#ax1.tick_params(axis='y',labelcolor=color)
	
	#ax2 = ax1.twinx()
	#color = 'tab:blue'
	#ax2.set_ylabel('in kg', color=color)
	#ax2.plot(x,kg,color=color)
	#ax2.tick_params(axis='y',labelcolor=color)
	
	#fig.tight_layout()
	
	#plt.show()'''
	return ' '

#readfile day,month,day,hour
def laloca():
	datafile = open("sealevelsantamartha.csv")
	#datafile = open("alltxt/loca.txt")
	datalines = datafile.readlines()[:]
	date, level = ([] for i in range(2))
	for line in datalines:
		alldata = line.split(",")
		#if int(alldata[1])<10: 
			#print alldata[1]
			#alldata[1]="0"+alldata[1]
			#print alldata[1]
		#if int(alldata[2])<10: 
			#print alldata[2]
			#alldata[2]="0"+alldata[2]
			#print alldata[2]
		#date.append(alldata[0] + "-" + alldata[1]+ "-" + alldata[2])
		#date.append(str(alldata[0]) + "-" + str(alldata[1])+ "-" + str(alldata[2]) + "-" + str(alldata[3]))
		#a.append(str(alldata[0]))
		#b.append(str(alldata[1]))
		#c.append(str(alldata[2]))
		#d.append(str(alldata[3]))
		#if (len(level)>100): break
		if (int(alldata[3])>0):
			#print alldata[0]
			#date.append(alldata[0] + alldata[1]+ alldata[2]+alldata[3])
			date.append(alldata[0] + "-" + alldata[1]+ "-" + alldata[2])
			level.append(int(alldata[3]))
		else: continue
	#print (date[0])
	#for i in range(len(a)):
		#print a[i],' ',b[i],' ',c[i],' ',d[i],' ',date[i],' ',level[i]
	#print len(level)
	x_date = [datetime.datetime.strptime(i,'%Y-%m-%d').date() for i in date]
	#print (x_date[0])
	
	
	plt.figure(facecolor="white")
	
	#plt.plot([],[])
	plt.plot(x_date,level,'r--')
	
	#plt.gcf().autofmt_xdate()
	#myFmt = mdates.DateFormatter('%y-%m-%d-%H')
	#plt.gca().xaxis.set_major_formatter(myFmt)
	
	plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m'))
	#plt.gcf().autofmt_xdate()
	#plt.plot(x_weight,kg,'k--', label= 'weight')
	#plt.plot(x_run,run,'b--', label= 'run')
	#plt.gca().set_title('loca')
	#plt.gca().set_xlabel('Date')
	#plt.gca().set_ylabel('values')
	#plt.gca().grid(True)
	#legend = plt.gca().legend(loc='upper left', fontsize='large')
	plt.show()
	
	return 'done'

	
def trys():
	import datetime
	import random
	import matplotlib.pyplot as plt
# make up some data
	x = [datetime.datetime.now() + datetime.timedelta(hours=i) for i in range(12)]
	y = [i+random.gauss(0,1) for i,_ in enumerate(x)]
	#print x
	print ('pause')
	#print y
# plot
	plt.plot(x,y)
# beautify the x-labels
	plt.gcf().autofmt_xdate()

	plt.show()


# matplotlib version
def seraque():
	import matplotlib.pyplot as plt
	import numpy as np

	arr = np.random.normal(size=20000)

	plt.ioff()
	plt.hist(arr, bins=np.arange(-3, 3 , 0.1), label='normal distr', histtype='step')
	plt.savefig("test_plot.pdf")

	#---------------------------------------
	# ROOT version

	import ROOT
	ROOT.gROOT.SetBatch(True)

	import numpy as np
	arr = np.random.normal(size=20000)

	h = ROOT.TH1D('h', 'h', 100, -3, 3)
	for v in arr:
		h.Fill(v)

	c1 = ROOT.TCanvas('c1', 'c1', 600, 600)
	h.Draw('hist')
	c1.Print('test_plot_ROOT.pdf')

def eff_126():
	Run_num0 = [41, 42, 43, 45, 46, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59]
	Run_num10 = [61, 62, 65, 66]
	eff0 = [98.918, 98.940, 98.852, 98.826, 98.976, 98.947, 98.846, 98.998, 98.948, 98.798, 98.939, 98.889, 98.861, 98.974, 98.957, 98.928]
	eff10 = [99.763, 99.718, 99.752, 99.786]
	eff_err0 = [0.0503, 0.0503, 0.0608, 0.0521, 0.05, 0.0507, 0.0605, 0.0526, 0.0499, 0.0528, 0.0508, 0.0511, 0.0557, 0.0497, 0.0503, 0.0532]
	eff_err10 = [0.0247, 0.0283, 0.0248, 0.0269]
	#print (len(Run_num),' ',len(eff))
	
	#fig, ax = plt.subplots()
	plt.figure(facecolor="white")
	plt.ylabel('Efficiency (%)')
	plt.xlabel('Run number (298)')
	plt.title('Eff vs Run number for MJ126')
	
	#plt.errorbar(Run_num, eff, 'bo')
	plt.errorbar(Run_num0, eff0, yerr = eff_err0, label='0 degrees')
	plt.errorbar(Run_num10, eff10, yerr = eff_err10, label='10 degrees')
	#plt.plot(v, MJ139, 'ro', label='MJ139')
	#plt.plot(v, MJ140, 'b s', label='MJ140')
	#plt.plot(v, MJ138, 'r s', label='MJ138')
	#plt.plot(v, MJ129, 'y o', label='MJ29')
	#plt.plot(v1, MJ127, 'k o', label='MJ127')
	#plt.plot(v, MJ131, '-b', label='MJ131')
	
	#plt.axis('equal')
	
	leg = plt.legend();
	plt.savefig('eff_126.png')
	plt.show()
	return 'none'

def miele(sta,Bi,Tr,Pr):
	to = (Bi+Tr)*100/Pr
	state = sta
	if Bi-Tr>0:
		return "----------------------------------------------------------------------------------------------------------- ",state,"faltan",int(to-Bi-Tr),"Bi gana por",int(Bi-Tr)," neceita",int((1+to/2)-Bi),int(100*((1+to/2)-Bi)/(to-Bi-Tr))
	else:
		return "----------------------------------------------------------------------------------------------------------- ",state,'faltan',int(to-Bi-Tr),"Tr gana por",int(Tr-Bi)," neceita",int((1+to/2)-Tr),int(100*((1+to/2)-Tr)/(to-Bi-Tr))
	 #" "
	#total = total1+total2
	#final = total*100.0/porce
	#remain = final - total
	#diff = total1 - total2
	#print diff
	


def chifuco(nivel,dias,great,ultra,best):
	total = 5000000
	falta = total - nivel
	nivel2 = nivel+great*10000+ultra*50000+best*100000
	falta2 = total - nivel2
	return "need ",(falta/dias)," or ",(falta2/dias)," a day"



