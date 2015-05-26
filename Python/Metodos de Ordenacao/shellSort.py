def shellSort(alist):
	sublistcount = len(alist)//2
	while sublistcount > 0:

		for startposition in range(sublistcount):
			gapInsertionSort(alist,startposition,sublistcount)

		sublistcount = sublistcount // 2

def gapInsertionSort(alist,start,gap):
	for i in range(start+gap,len(alist),gap):

		currentvalue = alist[i]
		position = i

		while position>=gap and alist[position-gap]>currentvalue:
			alist[position]=alist[position-gap]
			position = position-gap

		alist[position]=currentvalue

alist = [54,26,93,17,77,31,44,55,20]
shellSort(alist)
print(alist)

def shell(seq):
    inc = len(seq) // 2
    while inc:
        for i, el in enumerate(seq):
            while i >= inc and seq[i - inc] > el:
                seq[i] = seq[i - inc]
                i -= inc
            seq[i] = el
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)
 
data = [22, 7, 2, -5, 8, 4]
shell(data)
print data # [-5, 2, 4, 7, 8, 22]