import random
import math
import funciones

def non_unique():
	data = [10,9,10,10,9,8]
	x= int(len(data))
	i=0
	while i<x:
		j=0
		sw=0
		while j<x:
			if i != j and data[i] == data[j]:
				sw=1
			j+=1
		if sw == 0:
			data.remove(data[i])
			x-=1
			i-=1
		i+=1
	return (data)

def home_median():
	data = [3, 1, 2, 5, 3]
	data.sort()
	x= int(len(data))
	y = x % 2
	z = int (x/2) 
	if y==0:
		fin = ((data[z-1]+data[z])/2)
	else:
		fin = (data[z])
	return (fin)





























