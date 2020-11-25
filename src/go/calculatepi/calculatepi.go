package calculatepi

func CalculatePi(terms []int) []float64 {
	var denominator float64 = 1.0
	var operation float64 = 1.0
	pi := make([]float64, len(terms))

	for i := 0; i < len(terms); i++ {
		denominator = 1.0
		operation = 1.0
		for cont := 0; cont < terms[i]; cont++ {
			pi[i] += operation * (4 / denominator)
			denominator += 2
			operation *= -1
		}
	}
	return pi
}
