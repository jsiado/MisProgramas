#calculate wether a number is prime
def prime (number):
	j = 2
	if number <= 0:
		return 0
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
		
