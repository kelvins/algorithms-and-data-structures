
def Hanoi(pin0, pin2, pin1, num)
   if num == 1
   		# Show the operations
       print "Move from ", pin0, " to ", pin2, "\n"
   else
       Hanoi(pin0, pin1, pin2, num-1)
       Hanoi(pin0, pin2, pin1, 1)
       Hanoi(pin1, pin2, pin0, num-1)
   end
end

# Move from Pin-0 to Pin-2 using Pin-1 as helper (number of disks = 3)
Hanoi(0, 2, 1, 3)