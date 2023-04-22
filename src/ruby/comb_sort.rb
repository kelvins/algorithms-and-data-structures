# frozen_string_literal: true

# Algoritmo de Comb sort em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def comb_sort(arr)
  gap = arr.length
  shrink = 1.3
  swapped = true

  while gap > 1 || swapped
    gap = (gap / shrink).floor
    gap = 1 if gap < 1
    swapped = false

    (0..(arr.length - gap) - 1).each do |i|
      if arr[i] > arr[i + gap]
        arr[i], arr[i + gap] = arr[i + gap], arr[i]
        swapped = true
      end
    end
  end

  arr
end

array = [86, 16, 10, 39, 49, 6, 32, 57, 72, 29]
print "Lista: #{array} \n"
print "Lista Ordenada: #{comb_sort(array)}"
