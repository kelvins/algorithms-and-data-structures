# Algoritmo de Dijkstra em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def dijkstra(matrix, n)
    visited = Array.new(n)

    for i in 1..n-1
        min, min_value = nil, nil

        for j in 1..n-1
            if !visited[j] && (!min_value || matrix[j][0] < min_value)
                min = j
                min_value = matrix[j][0]
            end
        end

        visited[min] = true
        
        for j in 1..n-1
            if matrix[min][0] + matrix[min][j] < matrix[j][0]
                matrix[j][0] = matrix[min][0] + matrix[min][j]
            end
        end
    end
end

def main
    n_vertices = 5

    matrix = []
    ignore = 4294967295
    
    matrix.push([0, 6, 10, ignore, ignore])
    matrix.push([6, 0, ignore, 2, ignore])
    matrix.push([10, ignore, 0, 1, 3])
    matrix.push([ignore, 2, 1, 0, 8])
    matrix.push([ignore, ignore, 3, 8, 0])

    matrix.to_a.each {|row| puts row.inspect}

    dijkstra(matrix, n_vertices)

    puts "============================================================"
    puts "Total caminho mais curto do vertice 0 ao 4: #{matrix[4][0]}"
    puts "============================================================"
    
    matrix.to_a.each {|row| puts row.inspect}
end

main()