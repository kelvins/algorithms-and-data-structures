# Algoritmo Gnome sort em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def gnome_sort(array)
    count = 0

    while count < array.length - 1 do
        if array[count] > array[count + 1]
            array[count + 1], array[count] = array[count], array[count + 1]
            count -= 2 if count > 0
        end
        count += 1
    end
    
    return array
end

def main
    array = [10, 8, 4, 3, 1, 9, 0, 2, 7, 5, 6]
    print(gnome_sort(array))
end

main()