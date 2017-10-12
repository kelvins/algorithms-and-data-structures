
def busca_sentinela(l, value):
	l.append(value)
	index = 0
	while l[index] != value:
		index = index + 1
	l.pop()
	if index == len(l):
		return -1
	return index


if __name__ == "__main__":
	l = [1,9,2,8,7,4,5,6,4,3,10,0]
	value = 4
	index = busca_sentinela(l, value)
	print(l)
	if index >= 0:
		print("Found value {} at position {}.".format(value, index))
	else:
		print("Could not find value {}.".format(value))
