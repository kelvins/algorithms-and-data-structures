def SequentialSearch(value, array):
	for x in xrange(0, len(array)):
		if array[x] == value:
			return x
	return -1

def SentinelSearch(value, array):
	array.append(value) # Puts the value at the end of the array
	index = 0
	while array[index] != value: # While the value is different
		index += 1
	array.pop() # Removes the value at the end of the array
	if index == len(array)-1: # If the 'index' variable is the last position of the array, returns -1
		return -1
	return index # Else, returns the position of the value on the array

array = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
print SequentialSearch(54, array)
print SentinelSearch(98, array)