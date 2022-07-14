
# Fatorial em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def factorial(value)
    aux = 1
    for i in 1..value
        aux *= i
    end

    return aux
end

def main
    for number in 0..10
        puts "#{number}! = #{factorial(number)}"
    end
end

main()