package exponenciacao

func Exponenciacao(base int, expoente int) int {
	for index := 0; index < (expoente - 1); index++ {
		base *= expoente
	}
	return base
}
