def Hanoi(pin0, pin2, pin1, num):
	if num == 1:
		print 'Move from ' + str(pin0) + ' to ' + str(pin2)
	else:
		Hanoi(pin0, pin1, pin2, num-1)
		Hanoi(pin0, pin2, pin1, 1)
		Hanoi(pin1, pin2, pin0, num-1)

# Parameters: (from)Pin0, (to)Pin2, (helper)Pin1, Number of Disks
Hanoi(0, 2, 1, 3)

