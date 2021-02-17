def approximate_size(size, a_kilobyte_is_1024_bytes=True):
	'''Convert a file size to human-readable form.
	Keyword arguments:
	size -- file size in bytes
	a_kilobyte_is_1024_bytes -- if True (default), use multiples of 1024
	if False, use multiples of 1000
	Returns: string
	'''
	SUFFIXES = {1000: ['KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'],
			1024: ['KiB', 'MiB', 'GiB', 'TiB', 'PiB', 'EiB', 'ZiB', 'YiB']}

	if size < 0:
		raise ValueError('number must be non-negative')
	multiple = 1024 if a_kilobyte_is_1024_bytes else 1000
	for suffix in SUFFIXES[multiple]:
		size /= multiple
		if size < multiple:
			return '{0:.1f} {1}'.format(size, suffix)
	raise ValueError('number too large')
if __name__ == '__main__':
	print(approximate_size(1000000000000, False))
	print(approximate_size(1000000000000))
	
'''
\ normal division
\\ dividend
** power of
% returns the residue
'''


import fractions
import math


y=math.pi
z=math.sin(math.pi)
x=fractions.Fraction(1,3)
print(x,y,z)

username = 'mark'
password = 'PapayaWhip'
a="{0}'s password is {1}".format(username, password)
'''{0} and {1} are called positional indices and are replaced by arguments of the format '''
print (a)
#from diveintopython import approximate_size
#print()
#si=SUFFIXES
#print(si)

#creates empty:

ylist= []       #creating an empty list
tup=()          #cretaes an empty tuple
a_set = set()   #creates an empty set
mydic={}        # creates an empty dictionary


mylist=['a','b','c']
print (mylist)
for i in range (0,9):
	ylist.append(i)
print (ylist)

a_tuple = ("a", "b", "mpilgrim", "z", "example")
print (a_tuple)

a_set = {1, 2}
print(a_set)

a_dict = {'server': 'db.diveintopython3.org', 'database': 'mysql'}
print(a_dict)


a_list = [1, 9, 8, 4]
lt =[elem *2 for elem in a_list]
print (a_list)
print (lt)












