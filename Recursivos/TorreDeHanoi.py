def Hanoi(ori, dst, aux, nro):
	if nro == 1:
		print 'Move de ' + str(ori) + ' para ' + str(dst)
	else:
		Hanoi(ori, aux, dst, nro-1)
		Hanoi(ori, dst, aux, 1)
		Hanoi(aux, dst, ori, nro-1)

Hanoi(0, 2, 1, 6)
