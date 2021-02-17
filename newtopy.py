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
	
	
Run_num = [41, 42,43,45,46,49,50,51,52,53,54,55,56,57,58,59,61,62,65,66]
eff = [98.918, 98.940, 98.852, 98.826, 98.976, 98.947, 98.846, 98.998, 98.948, 98.798, 98.939, 98.889, 98.861, 98.974, 98.957, 98.928, 99.763, 99.718, 99.752, 99.786]
#eff_err = [0.0503, 0.0503, 0.0608, 0.0521, 0.05, 0.0507, 0.0605, 0.0526, 0.0499, 0.0528, 0.0508, 0.0511, 0.0557, 0.0497, 0.0503, 0.0532, 0.0247, 0.0283, 0.0248, 0.0269]
	
	
	#fig, ax = plt.subplots()
plt.figure(facecolor="white")
plt.ylabel('Current (-nA)')
plt.xlabel('Voltage (-V)')
	#plt.title('el titulo')
	
#plt.errorbar(plot(Run_num, eff, yerr=eff_err, 'bo',)
plt.plot(Run_num, eff, 'go', label='MJ125')
	#plt.plot(v, MJ139, 'ro', label='MJ139')
	#plt.plot(v, MJ140, 'b s', label='MJ140')
	#plt.plot(v, MJ138, 'r s', label='MJ138')
	#plt.plot(v, MJ129, 'y o', label='MJ29')
	#plt.plot(v1, MJ127, 'k o', label='MJ127')
	#plt.plot(v, MJ131, '-b', label='MJ131')
	
	#plt.axis('equal')
	
	#leg = plt.legend();
	#plt.savefig('I_vs_V_feb.png')
plt.show()
