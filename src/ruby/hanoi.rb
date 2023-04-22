# frozen_string_literal: true

def hanoi(pin0, pin2, pin1, num)
  if num == 1
    # Show the operations
    print "Move from ", pin0, " to ", pin2, "\n"
  else
    hanoi(pin0, pin1, pin2, num - 1)
    hanoi(pin0, pin2, pin1, 1)
    hanoi(pin1, pin2, pin0, num - 1)
  end
end

# Move from Pin-0 to Pin-2 using Pin-1 as helper (number of disks = 3)
hanoi(0, 2, 1, 3)
