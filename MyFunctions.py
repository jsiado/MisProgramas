from math import pi,sin,cos,atan,sqrt, log, factorial, exp
from numpy import ones,copy,cos,tan,pi,linspace, arange
from random import random

#calculate wether a number is prime
def Prime (number):
	j = 2
	if number <= 0:
		return 0
	elif number == 1:
		return True
	elif number ==2:
		return True
	else:
		while j < number:
			zz = number % j
			if zz == 0:
				return False
				#print (number, "no es primo")
				j = number
			else:
				if j == number-1:
				#print (number, "primo")
					return True
			j = j+1


#convert a number from base 10 to binary



#Is it odd or even
def OddOrEven(number):
	j = int(number/2)*2
	if j == number:
		return True
	else:
		return False

#calculate the factorial of a number
def factorial(n):
	f = 1
	for k in range(1,n+1):
		f *= k
	return f

#Generate a ramdon number 
def Ran_num():
	return 'done'

#integral of a function using the simpson's rule. Enter the limits and the number of points by hand
def int_simpson(N,a,b):
	h = (b-a)/N
	s = h/3*(fun_to_calc(a)+fun_to_calc(b))
	for k in range(1,N,2):
		s = s + (4*h/3)*fun_to_calc(a+k*h)
	for k in range (2,N,2):
		s = s + (2*h/3)*fun_to_calc(a+k*h)
	return s

#integral of a function using the trapezoidal rule. Enter the limits and the number of points by hand
def int_trapez(N,a,b):
	h = (b-a)/N
	s = 0.5*fun_to_calc(a)+ 0.5*fun_to_calc(b)
	for k in range(1,N):
		s = s + fun_to_calc(a+k*h)
	return (h*s)

#integral of a function using gausian quadratures. Enter the limits and the number of points by hand
def int_gauss(N,a,b):
	x,w = gaussxw(N)# Calculate the sample points and weights, then map them
	xp = 0.5*(b-a)*x + 0.5*(b+a)# to the required integration domain
	wp = 0.5*(b-a)*w
	# Perform the integration
	s = 0.0
	for k in range(N):
		s = s + wp[k]*fun_to_calc(xp[k])
	return (s)

#functions to integrate with the different methods
def fun_to_calc(x):
	return (sin(1/(x*(2-x))))**2
	#return 4*sqrt(x)
	#return x**4 - 2*x + 1
	#return sqrt(sin(x)*sin(x))
	#return exp(x**2)

#function to calculate the roots of the Legendre polinomials
def gaussxw(N):
    a = linspace(3,4*N-1,N)/(4*N+2)
    x = cos(pi*a+1/(8*N*N*tan(a)))
    # Find roots using Newton's method
    epsilon = 1e-15
    delta = 1.0
    while delta>epsilon:
        p0 = ones(N,float)
        p1 = copy(x)
        for k in range(1,N):
            p0,p1 = p1,((2*k+1)*x*p1-k*p0)/(k+1)
        dp = (N+1)*(p0-x*p1)/(1-x*x)
        dx = p1/dp
        x -= dx
        delta = max(abs(dx))

    # Calculate the weights
    w = 2*(N+1)*(N+1)/(N*N*(1-x*x)*dp*dp)
    return x,w

#Another gausian quadratures
def gaussxwab(N,a,b):
    x,w = gaussxw(N)
    return 0.5*(b-a)*x+0.5*(b+a),0.5*(b-a)*w


#Integral using precision. Enter the initial number of slides, inferior and superior limit and the error
def Simp_error(N1,a,b,Err):
	sw = 1
	while sw == 1:
		N2 = 2*N1
		int1 = int_simpson(N1,a,b)
		int2 = int_simpson(N2,a,b)
		#print int1,' ',int2, ' ', N1
		TheError = abs(int1 - int2)/15
		if TheError < Err:
			return int2
			sw = 0
		else:
			temp = N1
			N1 = N2
			N2 = 2*temp  


#derivate of a function
def simple_deri(x,Err):
	h1 = 0.01
	sw = 1
	h2 = h1/10
	h3 = h1/100
	while sw == 1:
		s1 = (fun_to_deri(x+h1) - fun_to_deri(x))/h1
		s2 = (fun_to_deri(x+h2) - fun_to_deri(x))/h2
		#s3 = (fun_to_deri(x+h3) - fun_to_deri(x))/h3

		#print h1,' ',s1,'  ',s2,'  ',s3,' ',s2-s1
		#print sqrt(2)
		print (abs(s2 - s1) - Err)
		if abs(s2 - s1) < Err:
			return s2
			print ('bla')
			sw = 0
		else:
			print ('else bla')
			#temp = h2
			h1 = h2
			h2 = h2/10


#Monte carlo integracion
def Mon_Car_Int(Area,N):
	count = 0
	for i in range(N):
		x = 2*random()
		y = random()
		if y<fun_to_calc(x):
			count += 1
	I = Area*count/N
	Error = sqrt(I*(Area-I)/N)
	print ('the integral is ',I,' with ',Error,' error')
	return 'done'


# Function to generate two Gaussian random numbers. 
def gaussian(sigma):
    r = sqrt(-2*sigma*sigma*log(1-random()))
    theta = 2*pi*random()
    x = r*cos(theta)
    y = r*sin(theta)
    return x,y


#Integral using the mean value method of Monte-Carlo
def Mean_Var_Int(a,b,N):
	suma = suma2 = 0.0
	for i in range(N):
		x = (b-a)*random()
		xval =  (sin(1/(x*(2-x))))**2
		#xval2 =  ((sin(1/(x*(2-x))))**2)**2
		suma = suma + xval
		suma2 = suma2 + xval*xval
	Error = (b-a)*sqrt(suma2/N - (suma/N)**2 )/sqrt(N)
	print ('the integral is '(b-a)*suma/N, ' with error ',Error)
	return 'done'


#Integral using the Importance sample of Monte-Carlo
#step 1 define w(x)
#step 2 integrate w(x)
#step 3 calculate p(x)
#step 4 derive transformation formula x(z)
#step 5 draw random number z and feed them into x(z)
#step 6 calculate the sum f(x)/w(x)
#step 7 the intgral is #2*#6/N
def Impor_Sample(a,b,N):
	suma = 0.0
	for i in range(N):
		z = random()
		x =z**2
		f = 1.0/(exp(x)+1)
		#w = 1.0/sqrt(x)
		suma = suma + f
	print ('the intgral is ',2*suma/N)
	return 'done'








