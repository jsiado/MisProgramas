import random
import math
import funciones


def Non_uni_ele
	data = [10,9,10,10,9,8]
	#data = [1,2,3,4,5]
	#data = [5,5,5,5,5]
	#data = [1,2,3,1,3]
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
	print (data)



def fizz_buzzn():
	#data = [3, 1, 2, 5, 3]#) == 3
	#data = [1,3,12,10,9,10,10,9,14,8]
	#data = [1, 2, 3, 4, 5] #  3
	#data = [1, 300, 2, 200, 1]#) == 2
	#data = [3, 6, 20, 99, 10, 15]#) == 12.5
	#data.sort()
	#x= int(len(data))
	x = input ('enter a number : ')
	y = x % 5
	z = x % 3
	if y==0 and z==0:
		print('FB')
	else:
		if y==0:
			print('F')
		else:
			if z==0:
				print(B)
			else:
				print('nada')
























