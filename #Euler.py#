import random
import math
import MyFunctions
from decimal import *
from itertools import permutations




def Prob_11():
	#dato = open("Euler_prob_11.txt","r")
	line1 = [8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8]
	line2 = [49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0]
	line3 = [81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65]
	line4 = [52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91]
	line5 = [22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80]
	line6 = [24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50]
	line7 = [32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70]
	line8 = [67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21]
	line9 = [24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72]
	line10 = [21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95]
	line11 = [78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92]
	line12 = [16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57]
	line13 = [86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58]
	line14 = [19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40]
	line15 = [4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66]
	line16 = [88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69]
	line17 = [4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36]
	line18 = [20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16]
	line19 = [20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54]
	line20 = [1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48]
	
	k = 1
	value = 0
	#for i in range (0,17):
		#hor = line1[i]*line1[i+1]*line1[i+2]*line1[i+3]
		#if hor> value: value = hor
	#return (value)
	dato = open("alltxt/Euler_prob_11.txt")
	for line in dato:
		linex = []
		for i in range(0,20):
			linex.append(line.split(' ')[i])
		#value = 0
		for j in range (0,17):
			#print (j," ",int(linex[j])," ",int(linex[j+1])," ",int(linex[j+2])," ",int(linex[j+3]))
			hor = int(linex[j])*int(linex[j+1])*int(linex[j+2])*int(linex[j+3])
			if hor> value: 
				value = hor
	return value
		#k+=1
		#return linex
	#return " "



def Prob_15(n):
	side = [0,0,6]
	for i in range(3,n):
		value = 0
		for j in range(2,i):
			value = value + side[j]
		side.append(2*value+2*(i+1))
	print side
	return "not correct answer"



def Prob_26(i,n):
	f = open("alltxt/prob_26.txt","w") 
	#for i in range(1,n):
	while i<n:
		if ((i%5 !=0) & (i%3 != 0)):
			getcontext().prec = 4096
			f.write(str(Decimal(1)/Decimal(i)))
			print()
			#f.write(Decimal(1)/Decimal(i)) 
			print (Decimal(1)/Decimal(i))
		i+=2
	f.close()
	return ""



def Prob_23(n):
	abundant = []
	allnum = []
	total = 395465626
	for i in range(12,n):
		divisor = []
		isPrime = MyFunctions.Prime(i)
		if isPrime == False:
			for j in range (1,i):
				z = i % j
				if z == 0:
					divisor.append(j)
			if sum(divisor) > i:
				abundant.append(i)
			#if i == 945:
				#print divisor, ' ',sum(divisor)
			#if sum(divisor)<i:
				#print i, ' is deficient, its sum is ',sum(divisor),' ',divisor
			#elif sum(divisor) == i:
				#print i, ' is perfect,   its sum is ',sum(divisor),' ',divisor
			#else:
				#print i, ' is abundant,  its sum is ',sum(divisor),' ',divisor
				#abundant.append(i)
	#print abundant
	#print len(abundant)
	for x in range(1,28124):
		allnum.append(x)
	#print allnum
	print sum(allnum)
	return total





def Prob_27():
	for a in range(-3,4):
		for b in range(-3,4):
			sw = 1
			n = 0
			while (sw==1):
				#print(n,"^2 + ",a,n," + ",b) 
				x = n*n + a*n + b
				if (x>0):
					isPrime = MyFunctions.prime(x)
					print(a,b,n,x,isPrime)
					n+=1
					if(isPrime == 0):
						sw = 0
				else:
					break
				#print (a,b,n,x)
				#if (x<0):
					#number = MyFunctions.prime(-x)
					#print(a,b,n,-x,number)
				#else:
					#number = MyFunctions.prime(x)
					#print(a,b,n,x,number)
				#if number == True:
					#n+=1
				#else:
					#break
	return ""





def Prob_33():
	MyFile = open("alltxt/prob_33.txt","w")
	for i in range(10,100):
		for j in range (i+1,100):
			x = float(i)/float(j)
			print x
			if (x)<1:
				#print(i//j)
				MyFile.write(str(i)+str(j))
				MyFile.write("\n")



def Prob_35(n):
	count = 4
	for i in range (10,n):
		isPrime = MyFunctions.Prime(i)
		sw = 1
		if isPrime == True:
			number = map(str,str(i))
			perm = permutations(number)
			for j in list(perm): 
				magic = lambda number: int(''.join(str(j) for j in number)) # Generator exp.
				newnum = magic(j)
				isPrime2 = MyFunctions.Prime(newnum)
				if isPrime2 == True:
					continue
				else:
					sw = 0
			if sw == 1:
				count += 1			
	return count




def Prob_37(n):
	MyFile = open("prob_37.txt","w") 
	for i in range (11,n):
		isPrime = MyFunctions.Prime(i)
		if number == 1:
			values = list(str(i))
			#if str(4) not in values:
				#if str(6) not in values:
						#if str(8) not in values:
								#print(i," ",values)
			MyFile.write(str(i))
			print(i)
			MyFile.write("\n")
			#values = list(str(i))
			#print (values)
			#for value in values:
				#if 4,6,8,9
			#x = str(i)
			#print (x)
			#while(len(x)>=	1):
	return " "





def Prob_44(x):
	penta = [0]
	for n in range(1,x):
		print ("working with ",n," out of ",x)
		value = n*(3*n -1)/2
		penta.append(value)
		for i in range (1,n):
			for j in range(1,i):
				suma = penta[i]+penta[j]
				resta = penta[i]-penta[j]
				if (suma in penta):
					resta = penta[i] - penta[j]
					if resta in penta:
						print ("-------------------------------",i, j,penta[i]," ",penta[j],suma," ",resta)
	return ""





def Prob_45():
	mylistP = []
	mylistT = []
	mylistH = []
	n= 142
	a = 0
	while a == 0:
		P = n*(3*n-1)//2 
		T = n*(n+1)//2
		H = n*(2*n-1)
	
		mylistP.append(P)
		mylistT.append(T)
		mylistH.append(H)
		for i in range (0,len(mylistH)):
			if (mylistP[i]==mylistT[i]):
				print (mylistP[i])
		if n==286:
			a=1
		n+=1
	return " "
#print (mylistP)
#print (mylistT)
#print (mylistH)
#x = len(mylistP)
#print (x)

