

from matplotlib import pyplot as mp
from datetime import date
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import datetime as dt
import matplotlib.dates as mdates
import datetime
from pylab import figure, axes, pie, title, show

datafile = open("alltxt/myfile.txt")
datalines = datafile.readlines()[:]
date, level = ([] for i in range(2))
for line in datalines:
	alldata = line.split(",")#file is in the format 1989,9,2,17,210
	if int(alldata[1])<10: 
		alldata[1]="0"+alldata[1]#to add a zero to the month, i.e converts 9 into 09
	if int(alldata[2])<10:
		alldata[2]="0"+alldata[2]
	
	date.append(alldata[0] + "-" + alldata[1]+ "-" + alldata[2] + "-" + alldata[3])
	level.append(float(alldata[4]))
	if (len(level)>50): break
	
x_date = [datetime.datetime.strptime(d,'%Y-%m-%d-%H').date() for d in date]
	
plt.figure(facecolor="white")
plt.plot(x_date,level,'r--')
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%m-%d-%H'))
plt.gca().grid(True)
plt.show()
