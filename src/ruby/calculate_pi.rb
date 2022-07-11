# Calculo do PI (Leibniz) em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def calculate_pi(number)
    denominator = 1.0
    operation = 1.0
    pi = 0

    for count in 1..number
        pi += operation * (4.0 / denominator)
        denominator += 2.0
        operation *= -1.0
    end

    return pi
end

def main
    terms = [10, 1000, 100000, 10000000]

    terms.each do |term|
        puts "PI #{term}: #{calculate_pi(term)}"
    end
end

main()