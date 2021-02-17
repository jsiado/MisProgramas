from matplotlib import pyplot as mp
from datetime import date
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math
import datetime as dt
import matplotlib.dates as mdates
#import pandas as pd
from pylab import figure, axes, pie, title, show
from decimal import *
from random import seed, randint

import MyFunctions

datafile = open("alltxt/loca.txt")
datalines = datafile.readlines()[:]
date, value = ([] for i in range(2))
for line in datalines:
	alldata = line.split(",")
	date.append(alldata[0] + "-" + alldata[1]+ "-" + alldata[2] + "-" + alldata[3])
	value.append(float(alldata[4]))
print date

x_date = [dt.datetime.strptime(m,'%y-%m-%d-%H').date() for m in date]
print x

return 'done'
