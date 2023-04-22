# frozen_string_literal: true

# Algoritmo de Dijkstra em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def dijkstra(matrix, vertices)
  visited = Array.new(vertices)

  (1..vertices - 1).each do |_i|
    min = nil
    min_value = nil

    (1..vertices - 1).each do |j|
      if !visited[j] && (!min_value || matrix[j][0] < min_value)
        min = j
        min_value = matrix[j][0]
      end
    end

    visited[min] = true

    (1..vertices - 1).each do |j|
      matrix[j][0] = matrix[min][0] + matrix[min][j] if matrix[min][0] + matrix[min][j] < matrix[j][0]
    end
  end
end

def main
  n_vertices = 5

  matrix = []
  ignore = 4_294_967_295

  matrix.push([0, 6, 10, ignore, ignore])
  matrix.push([6, 0, ignore, 2, ignore])
  matrix.push([10, ignore, 0, 1, 3])
  matrix.push([ignore, 2, 1, 0, 8])
  matrix.push([ignore, ignore, 3, 8, 0])

  matrix.to_a.each { |row| puts row.inspect }

  dijkstra(matrix, n_vertices)

  puts '============================================================'
  puts "Total caminho mais curto do vertice 0 ao 4: #{matrix[4][0]}"
  puts '============================================================'

  matrix.to_a.each { |row| puts row.inspect }
end

main
