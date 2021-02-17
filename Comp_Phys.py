import matplotlib.pyplot as plt
#import datetime as dt
#import matplotlib.dates as mdates
import numpy as np
from math import pi,sin,cos,atan,sqrt, log, factorial, exp
from numpy import empty, zeros, array, linspace, sin, loadtxt, cos, dot, arange
from visual import sphere, color, display, rate, box
from random import random, randrange, seed

import MyFunctions
#from gaussxw import gaussxw
#import array as arr

#use it as python -c 'import Comp_Phys; print Comp_Phys.function_name()'

##############################################################################################
#####################STARTING CHAPTER 3 ######################################################
##############################################################################################


#calculates the series for hydrogen
def Ch1_Prob1():
	R = 1.097e-2
	for m in [1,2,3]:
		print "sries for m = ",m
		for k in [1,2,3,4,5]:
			n = m + k
			invlambda = R*(1./m**2 - 1./n**2)
			print n,'  ',1/invlambda,' nm'
	return

##############################################################################################
#####################STARTING CHAPTER 3 ######################################################
##############################################################################################

#Uses for chapter two
def Ch2_Uses():
	r = [1.0, 1.5, 2.2]
	lenght = sqrt(r[0]**2+r[1]**2+r[2]**2)
	total = sum(r)
	twir = list(map(sqrt,r))
	logr = list(map(log,r))
	r.append(6.1)
	r.pop()
	
	
	#print "the lenght is ",lenght
	##print "the sum is ",total
	#print "the min is ",min(r)
	#print "the max is ",max(r)
	#print "there are ",len(r)," elements"
	#print "the mean is",sum(r)/len(r)
	#print "square root is",twir
	#print "log are ",logr
	#print r
	
	a = array([1,2,3,4], int)
	b = array([2,3,4,5], int)
	#print (a+b," ")

	mylist = ['a', 'b', 'mpilgrim', 'z', 'example']#define a list
	mylist.append ('true')# add true at the end of the list
	mylist.insert (0,'list')# add Mio to the list in the position 0
	mylist.extend (['four','mas']) #add these two elemnets at the end of the list
	mylist.count ('four') # returns the number of times four is in the list
	mylist.index('four') # returns the position of the 'four' element in the list
	del mylist[1] #delete the element one of the list
	mylist.remove('mas') #remove mas element from the list
	mylist.pop()# remove the last element of the list
	lenght = (len(mylist))	# returns the size of the list
	y = mylist[1:3]# create a new list with elements from 1 to 2. (3-1)
	mytuple = ("tuple","a", "b", "mpilgrim", "z", "example")#Define a tuple. It can not be modified after it has been created.
	#creates an array with zeros
	a = zeros (4, int)
	# creates a matrix of mxn
	a = zeros((3,3),float)
	#converts a list to an array
	list1 = [1,2,3,4]
	#for 2D+ each list will become a row of the mxn array
	#a = array((list1, list1, list1, list1) , int)
	#to access an element of the array use a[0,1]
	#a[1,2] = 100
	a = array([[1,3],[2,4]],int)
	b = array([[4,-2],[-3,1]],int)
	c = array([[1,2],[2,1]],int)
	
	#add, substract, divide, multiply the whole array (matrix)
	aa = 2*a
	aaa = 1+a
	d = a-b
	e = a/2
	
	bb = array(list(map(sqrt,list1)),int)
	#print (bb,'  aqui')
	#calculate the dot product
	x = dot(list1,list1)
	#print ('dot product ',x)
	#y = dot(a,b)+2*a

	#total number of elements and size is
	x= a.size# total number of elements in a list matrix
	y = a.shape #size of the matrix nxm

	#print (x,y)

	#Start working with matrices
	#print ('que pasa')
	aa = loadtxt("alltxt/Values.txt",float)
	#print (aa)
	
	values = loadtxt('alltxt/Values.txt',float)
	logs = array(list(map(log,values)),float)
	geometric = exp(sum(logs)/len(logs))
	#print 'geometric sum of values ',geometric,'\n'
	
	#Slicing
	print '---------------------------------------------------------'
	print '-------------------- slicing -----------------------------'
	print '----------------------------------------------------------'
	r = [1,3,5,7,9,11,13,15]
	s = r[2:5]
	print s
	
	
	return 'Finished'
def Ch2_Exa1():
	g = 9.81
	hei = []
	time = [0]
	h = float(input ("What is the height of the tower :"))
	t = float(input ("What is the time interval :"))
	abgr = 1
	hei.append(h)
	while (abgr > 0):
		y = g*t*t/2
		hei.append(h-y)
		time.append(t)
		if(y>100): abgr = 0
		else: t= t + 0.1
	plt.plot(time, hei,'ro')
	plt.show()
	return
#convert to Cartesian coordinates
def Ch2_Exa2(r,theta):
	x = r * cos (theta)
	y = r * sin (theta)
	return [x,y]
def Ch2_Exa3():
	n = int(input("enter an integer number--> "))
	if n%2 == 0:
		print (n,' in an even number')
	else:
		print (n,' is an odd number')
	return ' '
#fibbonacci series
def Ch2_Exa4():
	f1 = 1
	f2 = 1
	while f1 <=200:
		print(f1)
		fnext = f1 + f2
		f1 = f2
		f2 = fnext
	return ' '
def Ch2_Exa5():
	values = loadtxt('alltxt/Values.txt',float)
	mean = sum(values)/len(values)
	return mean
def Ch2_Exa6():
	s = 0.0
	for k in range(1,101):
		s = s + 1.0/k
	print s
	values = loadtxt('alltxt/Values.txt',float)
	s = 0.0
	for x in values:
		s = s + x**2
	print s


#Ball dropped from a building
def Ch2_Prob1():
	g = 9.81
	h = float(input ("What is the height of the tower :"))
	print sqrt(2*h/9)
	return ''
#Altitude of a satellie
def Ch2_Prob2():
	G = 6.67E-11
	M = 5.97E24
	R = 6371000
	
	T1 = float(input ("Enter the first time: "))
	T2 = float(input ("Enter the second time: "))
	
	h1 = (M*G*T1*T1/(4*pi*pi) ** (1/3.0)) - R
	h2 = (M*G*T2*T2/(4*pi*pi) ** (1/3.0)) - R
	
	print 'the altitude at',T1,' is ',h1
	print 'the altitude at',T2,' is ',h2
	
	return ''
#Cartesian to polar
def Ch2_Prob3():
	x = float(input ("Enter the value of x: "))
	y = float(input ("Enter the value of y: "))
	theta_rad = atan(y/x)
	theta_deg = 180*theta_rad/pi
	r = sqrt(x**2 + y**2)
	print 'theta = ',theta_deg,' and r = ',r 
	print 'esta es'
	return ''
#Spaceship traveling at speed C
def Ch2_Prob4():
	print 'esta es'
	return ''
#Quantum potential step
def Ch2_Prob5():
	print 'esta es'
	return ''
#Planetary orbit
def Ch2_Prob6():
	G = 6.6738e-11
	M = 1.9891e30
	cont = 2*G*M
	l1 = float(input ("What is the distance of perihelion : "))
	v1 = float(input ("What is the velocity at perihelion : "))
	#solutions of the quadratic equation a=1,b,c
	b = cont/v1*l1
	c = v1*v1 - cont
	v2 = (cont/v1*l1)
	l2 = l1*v1/v2
	una = (l2-l1)/(l1+l2)
	dos = (l1+l2)/2
	tres = 2*pi*c*b
	x= una*dos*tres
	print (x)
	lsit = x = jei 
#catalan numbers
def Ch2_Prob7():
	n = int(input("enter the upper limit for the sequence: "))
	C0 = 1
	for i in range(1,n):
		print 'for ',i,' Cn is ',C0
		Cn = C0*(4*i + 2)/(i + 2)
		C0 = Cn
	return ''

#What it is printed	
def Ch2_Prob8():
	a = array([1,2,3,4],int)
	b = array([2,4,6,8],int)
	print (b/a+1)
	print (b/(a+1))
	print (1/a)
	return ''


##############################################################################################
#####################STARTING CHAPTER 3 ######################################################
##############################################################################################

#Uses for chapter three
def Ch3_Uses():
	print '-------------------- 3.1 Graphs ---------------------------\n'
	#simple plot
	plt.figure(facecolor="white")
	x = [0.5, 1.0, 2.0, 4.0, 7.0, 10.0]
	y = [1.0, 2.4, 1.7, 0.3, 0.6, 1.8]
	plt.plot (x,y,'ro-')
	plt.show()
	
	#two plots with legends and different colors
	plt.figure(facecolor="white")
	x = linspace(0,12.56,100) #linspace takes three arguments initial and final value and the number of divisions
	y = sin(x)
	z = cos(x)
	plt.plot(x,y,'g-',label = 'sin x')
	plt.plot(x,z,'ro',label = 'cos x')
	#colors allowed by python are r,g,b,c,m,y,k,w for red, green,blue,cyan,magenta,yellow,black,white
	#Styles are -,o,--,s,* for solid line, dots, dash line, squares, stars,
	plt.ylim(-1.1,1.1)
	plt.xlim(-0.5,13)
	plt.xlabel('from 0 to 4pi')
	plt.ylabel('Trigonometric functions')
	plt.title('la verdad')
	leg = plt.legend()
	plt.show()
	
	plt.figure(facecolor="white")
	data = loadtxt("alltxt/ch3-1.txt",float)
	x = data[:,0]
	y = data[:,1]
	plt.plot(x,y)
	plt.show()
	
	print '------------------- 3.2 Scatter --------------------------\n'
	print '------------------- 3.3 Density --------------------------\n'
	plt.figure(facecolor="white")
	data = loadtxt("cpresources/circular.txt",float)
	plt.imshow(data,origin='lower')
	#plt imshow()
	plt.colorbar()
	plt.show()
	
	print '------------------- 3.4 3D Graphics --------------------------\n'
	sphere()
	sphere(radius=0.5, pos=[1.0,-0.2,0.0])
	sphere(color = color.green)
	s = empty(10,sphere)
	for n in range(10):
		s[n]= sphere()
		d = display(background = color.blue)
		display(autoscale=False)#set the automatic zoom off
		
	print '------------------- 3.5 Animations --------------------------\n'
	s = sphere(pos=[0,0,0])
	s.pos = [1,4,3]
	
	return 'done'

def Ch3_Exa1():
	landa = 5.0
	k = 2*pi/landa
	xi0 = 1.0
	separation = 20.0
	side = 100.0
	points = 500
	spacing = side/points
	
	#calculate the centre of the circles
	x1c = side/2 + separation/2
	y1c = 75
	x2c = side/2 - separation/2
	y2c = 25
	
	xi = empty([points,points],float)
	for i in range(points):
		y = spacing*i
		for j in range(points):
			x = spacing*j
			r1 = sqrt((x-x1c)**2+(y-y1c)**2)
			r2 = sqrt((x-x2c)**2+(y-y2c)**2)
			xi[i,j] = xi0*sin(k*r1) + xi0*sin(k*r2)
	plt.figure(facecolor="white")
	plt.imshow(xi,origin="lower", extent=[0,side,0,side])
	plt.show()
def Ch3_Exa2():
	L = 5
	R = 0.3
	for i in range(-L,L+1):
		for j in range(-L,L+1):
			for k in range(-L,L+1):
				s = sphere(pos=[i,j,k],radius=R)
				if (i==j and i ==k):
					s.color=color.blue
def Ch3_Exa3():
	s = sphere(pos=[1,0,0],radius=0.1)
	for theta in arange(0,10*pi,0.1):
		rate(1)
		x= cos(theta)
		y = sin (theta)
		s.pos = [x,y,0]

def Ch3_Prob1():
	plt.figure(facecolor="white")
	data = loadtxt("alltxt/sunspots.txt",float)
	x = data[:,0]
	y = data[:,1]
	plt.plot(x,y)
	plt.show()
	return 'finished'
def Ch3_Prob2():
	plt.figure(facecolor="white")
def Ch3_Prob5(time):
	base = 57.9#base for distance from the sun. (x = 1 means 57.9 km )
	rad_base = 10*2440#base for the radius of the planets size of each
	#Per_base = 88# base for the period
	
	sun = sphere(pos = [0,0,0], radius = .5)
	mercu = sphere(pos = [(57.90/base), 0, 0], radius = (2440.0/rad_base))
	venus = sphere(pos = [(108.2/base), 0, 0], radius = (6052.0/rad_base))
	earth = sphere(pos = [(149.6/base), 0, 0], radius = (6371.0/rad_base))
	marss = sphere(pos = [(227.6/base), 0, 0], radius = (3386.0/rad_base))
	
	#frequencies
	Fmerc = 2*pi/88
	Fvenu = 2*pi/224.7
	Feart = 2*pi/365.3
	Fmars = 2*pi/687.0
	
	#colors
	sun.color = color.yellow
	mercu.color = color.gray(0.5)
	earth.color = color.blue
	marss.color = color.red
	
	for t in arange(0,time,0.01):
		#print t
		rate(100)
		mercu.pos = [(57.90/base)*cos(Fmerc*t), (57.90/base)*sin(Fmerc*t), 0]
		venus.pos = [(108.2/base)*cos(Fvenu*t), (108.2/base)*sin(Fvenu*t), 0]
		earth.pos = [(149.6/base)*cos(Feart*t), (149.6/base)*sin(Feart*t), 0]
		marss.pos = [(227.6/base)*cos(Fmars*t), (227.6/base)*sin(Fmars*t), 0]
	return 'done'

##############################################################################################
#####################STARTING CHAPTER 4 ######################################################
##############################################################################################

def Ch4_Uses():
	return 'done'

def Ch4_Exa2():
	terms = 10000000
	beta = 1.0/100
	S = 0.0
	Z = 0.0
	for n in range(terms):
		E = n + 0.5
		weight = exp(-beta*E)
		S = S + weight*E
		Z = Z + weight
	print (S/Z)
def Ch4_Exa3():
	N = 100
	C = zeros ([N,N],float)
	for i in range(N):
		for j in range(N):
			for k in range(N):
				C[i,j] = C[i,j] + A[i,k]*B[j,k]
	return 'done'

#integral of a simple function. terms= number of terms in the sum
def Ch4_Prob4(terms):
	Sum = 0.0
	h = 2.0/terms
	for i in range(terms):
		x = -1 + h*i
		y = sqrt(1-x*x)
		Sum = Sum + h*y
	return Sum
	

##############################################################################################
#####################STARTING CHAPTER 5 ######################################################
##############################################################################################
def Ch5_Uses():
	return 'done'

#The trapezoidal rule
def Ch5_Exa1(N):
	a = 0.0
	b = 1.0
	h = (b-a)/N
	s = 0.5*fun_to_int(a)+ 0.5*fun_to_int(b)
	for k in range(1,N):
		s = s + fun_to_int(a+k*h)
	return (h*s)

#Working with gaussian quadratures
def Ch5_Exa2():
	N = 100
	a = 0.0
	b = 1.0

	# Calculate the sample points and weights, then map them
	# to the required integration domain
	x,w = MyFunctions.gaussxw(N)
	xp = 0.5*(b-a)*x + 0.5*(b+a)
	wp = 0.5*(b-a)*w

	# Perform the integration
	s = 0.0
	for k in range(N):
		s = s + wp[k]*fun_to_int(xp[k])

	return (s)

def Ch5_Exa3():
	N = 50
	a = 0.0
	b = 1.0

	# Calculate the sample points and weights, then map them
	# to the required integration domain
	x,w = MyFunctions.gaussxwab(N,a,b)

	# Perform the integration
	s = 0.0
	for k in range(N):
		s = s + w[k]*fun_to_int(x[k])
	return (s)

#functions to integrate
def fun_to_int(x):
	#return x**4 - 2*x + 1
	#return sqrt(sin(x)*sin(x))
	return exp(-x**2/(1-x)**2)/(1-x)**2

##############################################################################################
#####################STARTING CHAPTER 6 ######################################################
##############################################################################################
def Ch6_Uses():
	return 'done'

def Ch6_Exa1():
	A = array([[2, 1, 4, 1],
			[3, 4, -1, -1],
			[1, -4, 1, 5],
			[2, -2, 1, 3]],float)
	v = array([-4, 3, 9, 7],float)
	N = len(v)
	#Start gaussian elimination
	for m in range (N):
		div = A[m,m]
		A[m,:] = A[m,:]/div
		v[m] = v[m]/div
		for i in range(m+1,N):
			mult = A[i,m]
			A[i,:] = A[i,:] - mult * A[m,:]
			v[i] = v[i] - mult * v[m]
	result = empty(N,float)
	for m in range (N-1,-1,-1):
		result[m] = v[m]
		for i in range(m+1,N):
			result[m] = result[m] - A[m,i]*result[i]
	return result

def Ch6_Exa2():
	N = 26
	C = 1.0
	m = 1.0
	k = 6.0
	omega = 2.0
	alpha = 2*k-m*omega*omega

	# Set up the initial values of the arrays
	A = zeros([N,N],float)
	for i in range(N-1):
		A[i,i] = alpha
		A[i,i+1] = -k
		A[i+1,i] = -k
	A[0,0] = alpha - k
	A[N-1,N-1] = alpha - k

	v = zeros(N,float)
	v[0] = C

	# Perform the Gaussian elimination
	for i in range(N-1):

	# Divide row i by its diagonal element
		A[i,i+1] /= A[i,i]
		v[i] /= A[i,i]

    # Now subtract it from the next row down
		A[i+1,i+1] -= A[i+1,i]*A[i,i+1]
		v[i+1] -= A[i+1,i]*v[i]

	# Divide the last element of v by the last diagonal element
	v[N-1] /= A[N-1,N-1]

	# Backsubstitution
	x = empty(N,float)
	x[N-1] = v[N-1]
	for i in range(N-2,-1,-1):
		x[i] = v[i] - A[i,i+1]*x[i+1]

	# Make a plot using both dots and lines
	plt.plot(x)
	plt.plot(x,"ko")
	plt.show()
	return 'done'


##############################################################################################
#####################STARTING CHAPTER 7 ######################################################
##############################################################################################
def Ch7_Uses():
	return 'done'





##############################################################################################
#####################STARTING CHAPTER 8 ######################################################
##############################################################################################
def Ch8_Uses():
	return 'done'




##############################################################################################
#####################STARTING CHAPTER 9 ######################################################
##############################################################################################
def Ch9_Uses():
	return 'done'


##############################################################################################
#####################STARTING CHAPTER 9 ######################################################
##############################################################################################
def Ch10_Uses():
	N = 100
	a = 1664525
	c = 1013904223
	m = 4294967296
	x = 1
	results = []

	for i in range(N):
		x = (a*x+c)%m
		results.append(x)
	plt.figure(facecolor="white")
	plt.plot(results,"o")
	plt.show()
	
	seed(42)
	for i in range(4):
		print (randrange(10))
	if random()<0.2:
		print 'head'
	else:
		print 'tails'
	x = random()#random number from 0 ot less than 1
	y = randrange(10) #random integer up to n-1
	z = randrange(1,10) #random integer from m up to n-1
	w = randrange(1,20,2)
	for i in range(10):
		print exp(i)
	return x,y,z,w

def Ch10_Exa1():
	NTl = 1000            # Number of thallium atoms
	NPb = 0               # Number of lead atoms
	tau = 3.053*60        # Half life of thallium in seconds
	h = 1.0               # Size of time-step in seconds
	p = 1 - 2**(-h/tau)   # Probability of decay in one step
	tmax = 1000           # Total time
	
	# Lists of plot points
	tpoints = arange(0.0,tmax,h)
	Tlpoints = []
	Pbpoints = []

	# Main loop
	for t in tpoints:
		Tlpoints.append(NTl)
		Pbpoints.append(NPb)

	# Calculate the number of atoms that decay
		decay = 0
		for i in range(NTl):
			if random()<p:
				decay += 1
		NTl -= decay
		NPb += decay

	# Make the graph
	plt.figure(facecolor="white")
	plt.plot(tpoints,Tlpoints)
	plt.plot(tpoints,Pbpoints)
	plt.xlabel("Time")
	plt.ylabel("Number of atoms")
	plt.show()
	return 'done'

def Ch10_Exa2():
	Z = 79
	e = 1.602e-19
	E = 7.7e6*e
	epsilon0 = 8.854e-12
	a0 = 5.292e-11
	sigma = a0/100
	N = 1000000
	count = 0
	for i in range(N):
		x,y = MyFunctions.gaussian(sigma)
		b = sqrt(x*x+y*y)
		if b<Z*e*e/(2*pi*epsilon0*E):
			count += 1
	print (count,"particles were reflected out of",N)
	return 'done'

def Ch10_Prob1():
	count = 0.0
	print (count+1)/36
	for i in range(10):
		d_one = randrange(7) #dice one
		d_two = randrange(7) #dice two
		#print d_one,' ',d_two
		if d_one == 6 and d_two ==6:
			count = count + 1
	print count
	return count/i

def Ch10_Prob5(a,b,N):
	suma = suma2 = 0.0
	for i in range(N):
		x = (b-a)*random()
		xval =  (sin(1/(x*(2-x))))**2
		#xval2 =  ((sin(1/(x*(2-x))))**2)**2
		suma = suma + xval
		suma2 = suma2 + xval*xval
	Error = (b-a)*sqrt(suma2/N - (suma/N)**2 )/sqrt(N)
	print (b-a)*suma/N, ' ',Error
	return 'done'

#not finished yet
def Ch10_Prob3():
	posx = posy = 0
	#mybox = box(pos = [0,0], axis = [0,0], lenght = 10, height = 10)
	Bromotion = sphere(pos = [posx, posy, 0], radius = 0.1)
	for t in range(0,100):
		rate(1)
		x = random()
		y = random()
		if x> 0.5:
			posx = posx + 1
		else:
			posx = posx - 1
		if y> 0.5:
			posy = posy + 1	
		else:
			posy = posy - 1
		
		Bromotion.pos = [posx, posy, 0]
	return 'done'

#not the rifht answer. 
def Ch10_Prob8(a,b,N):
	suma = 0.0
	for i in range(N):
		z = random()
		x =(1-z)**2
		f = 1.0/(exp(x)+1)
		#w = 1.0/sqrt(x)
		suma = suma + f
	print 'the intgral is ',2*suma/N
	return 'done'
		
		
		


