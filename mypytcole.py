import random
import math
import sys
import fractions

## to get pi
f = math.pi*2	

## generates a random number between 1 and 5
x = random.choice ([1,2,3,4,5,6,7])									
y = random.choice ([1,2,3,4,5,6,7])
print (x)
print (y)
if x > y:
	print (x)
else: 
	if y > x:
		print (y)
	else:
		print ('the number are equal')


#S = 'Joaquin'			##define a string
#print len (S)			## print the length of the string
#print S[0]			#print the i-ism element of the string
#print S[2:5]			##slice to extract a part of a string
#print 'nada para ti'  

#calculate 2 to the 5th power
num = x ** y
den = y ** x
print (num,den)
#claculate the quotient of a/b
result = num / den
print ('result =',result)
## % gives the residue after performing integer division
residue = num % den
print ('residue =',residue)
## returns el cociente de la division
quotient = num // den
print ('quotient', quotient)
total = den*quotient+residue
print(total)
## define a fraction
e = fractions.Fraction(num , den)
## calculate sin of pi over 2
g = math.sin(math.pi / 2)										


###############################################################################
##################                                #############################
##################        Definiing list          #############################
##################                                #############################
###############################################################################
"""
ali = ['a', 'b', 'c', 'd']										## define a list
alid = ali + [5,6]                                                                                        ## adding some elements to the list

if 'seta' in alid: 													## to find weather an element is in the list
	print 'true'
else:
	print 'false'
aa = alid.count('seta')
print alid
print alid[5]
"""