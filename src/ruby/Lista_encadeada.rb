class Node
    attr_accessor :data, :next
    def initialize(data)
        @data = data
        @next = nil
    end
end

class LinkedList
    def initialize
        @head = nil
    end

    def append(data)
        if @head.nil?
            @head = Node.new(data)
        else
            find_tail.next = Node.new(data)
        end
    end

    def find_tail
        current_tail = @head
        until current_tail.next.nil?
            current_tail = current_tail.next
        end
        return current_tail
    end

    def find_before_node(value)
        current = @head
        until current.next.data == value
            current = current.next
        end
        return current
    end

    def delete(value)
        if @head.data == value
            @head = @head.next
        else
            target = find(value)
            before = find_before_node(value)
            before.next = target.next
        end
    end

    def find(value)
        current = @head
        until current.data == value
            current = current.next
        end
        current
    end

    def insert_after(target, value)
        current = find(target)
        temp = current.next
        current.next = Node.new(value)
        current.next.next = temp
    end

    def print_list
        current = @head
        puts "List: "
        until current.nil?
            print "#{current.data} "
            current = current.next
        end
    end
end

list = LinkedList.new
list.append(10)
list.append(20)
list.append(30)
list.insert_after(20, 22)
list.print_list
list.delete(30)
list.print_list