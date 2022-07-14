# Mínimo e Máximo recursivo em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def recursive_min_and_max(arr, min, max, index)
    min = arr[index] if arr[index] < min
    max = arr[index] if arr[index] > max

    if index < arr.length - 1
        recursive_min_and_max(arr, min, max, index + 1)
    else
        puts "Mínimo: #{min}"
        puts "Máximo: #{max}"
    end
end

list = [37, 53, 1, 43, 11, 49, 32, 55, 40, 47, 25, 4]
recursive_min_and_max(list, list[0], list[0], 0)