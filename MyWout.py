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



datafile = open("alltxt/marica.txt")
datalines = datafile.readlines()[1:]
date, weight, bike, bike_tot, bike_avg, run, run_tot, run_avg, stat, stat_tot, stat_avg, kg = ([] for i in range(12))
for line in datalines:
	alldata = line.split()
	date.append(alldata[0])
	#print alldata[0]
	weight.append(float(alldata[1]))
	bike.append(float(alldata[2]))
	run.append(5*float(alldata[3]))
	stat.append(6*float(alldata[4]))
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
plt.plot(x_bike,bike,'bo--', label = 'bike')
plt.plot(x_bike,bike_avg,'b*--', label = 'bike ave')
plt.plot(x_run,run,'ro--',label = 'run')
plt.plot(x_run,run_avg,'r*--',label = 'run avg')
plt.plot(x_stat,stat,'go--',label = 'stat')
plt.plot(x_stat,stat_avg,'g*--',label = 'stat avg')
plt.gca().set_title('Daily and average')
plt.gca().set_xlabel('Date')
plt.gca().set_ylabel('Km')
plt.gca().grid(True)
legend = plt.gca().legend(loc='upper left', fontsize='large')'''

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
plt.plot(x_run,run_tot,'ro--',label = '5*Run')
plt.plot(x_stat,stat_tot,'go--',label = '6*Stat')
plt.gca().set_title('Total distance')
plt.gca().set_xlabel('Date')
plt.gca().set_ylabel('kilometers')
plt.gca().grid(True)
legend = plt.gca().legend(loc='upper left', fontsize='large')
	
plt.figure(facecolor="white")
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
plt.plot(x_bike,bike_avg,'bo--', label= 'Bike')
plt.plot(x_run,run_avg,'ro--', label= '5*Run')
plt.plot(x_stat,stat_avg,'go--', label= '6*Stat')
plt.gca().set_title('Average')
plt.gca().set_xlabel('Date')
plt.gca().set_ylabel('kilometers')
plt.gca().grid(True)
legend = plt.gca().legend(loc='upper left', fontsize='large')
	
plt.figure(facecolor="white")
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
plt.plot(x_bike,bike,'bo--', label = 'Bike ')
plt.plot(x_run,run,'ro--', label = '5*run')
plt.plot(x_stat,stat,'go--', label= '6*stat')
plt.gca().set_title('Daily')
plt.gca().set_xlabel('Date')
plt.gca().set_ylabel('kilometers')
plt.gca().grid(True)
legend = plt.gca().legend(loc='upper left', fontsize='large')
plt.show()	
'''plt.figure(facecolor="white")
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
	
plt.figure(facecolor="white")
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
