from __future__ import print_function
import sys
import matplotlib.pyplot as plt

#Reading IV.log files from el comandante
#def Ivelcomandante():
lines = open(sys.argv[1], 'r').readlines()
lines = lines[9:]
volts, amps, times, times2 = zip(*[line.split('\t') for line in lines])
volts = [-float(volt) for volt in volts]
amps = [-float(amp)*10**6 for amp in amps]
#times = [int(time) for time in times]

#time_start = times[0]
#time_prev = time_start
#for i, (volt, amp, time) in enumerate(zip(volts, amps, times)):
#	time = int(time) - time_start
#	dt = time-time_prev
#	time_prev = time
#	print("{:5d}:{:10.3f}{:14.3E}{:7d}{:7d}".format(i, volt, amp, time, dt))
plt.plot(volts, amps, 'ro-')
plt.yscale('log')
plt.xlabel('Volts')
plt.ylabel('$\\mu$A')
plt.show()
