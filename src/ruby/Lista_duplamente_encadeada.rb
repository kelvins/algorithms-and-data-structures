class Node
    attr_accessor :data, :next, :previous
    def initialize(data)
        @data = data
        @next = nil
        @previous = nil
    end
end

class DoublyLinkedList
    def initialize
        @head = nil
    end

    def append(data)
        if @head.nil?
            @head = Node.new(data)
        else
            tail_node = find_tail
            new_node = Node.new(data)
            tail_node.next = new_node
            new_node.previous = tail_node
        end
    end

    def find_tail
        current_tail = @head
        until current_tail.next.nil?
            current_tail = current_tail.next
        end
        return current_tail
    end


    def delete(value)
        if @head.data == value
            @head = @head.next
            @head.previous = nil
        else
            target = find(value)
            if target.next.nil?
                target.previous.next = nil
            else
                target.previous.next = target.next
                target.next.previous = target.previous
            end
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
        current.next.previous = current
        current.next.next.previous = current.next
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

list = DoublyLinkedList.new
list.append(10)
list.append(20)
list.append(30)
list.insert_after(20, 22)
list.print_list
list.delete(30)
list.print_list
list.delete(10)
list.print_list