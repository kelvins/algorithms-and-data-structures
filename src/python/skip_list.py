"""
Skip list with:
    - skip connections made at random
    - sorted order
    - removing a node leaves a pseudo dead node
    - automatically rebuilds with only alive nodes once half of nodes are dead
    - can be rebuilt whenever desired as well
    - does not allow for duplicate numbers

"""

import random


class Node:
    def __init__(self, value):
        self.value = value
        self._down = None

        # layer number, 1 if on bottom layer
        self._layer = None
        self._right = None

        self._isAlive = True

    @property
    def status(self):
        return self._isAlive

    @property
    def kill(self):
        self._isAlive = False

    @property
    def next(self):
        return self._right

    @next.setter
    def next(self, ptr):
        self._right = ptr

    @property
    def get_value(self):
        return self.value

    @property
    def layer(self):
        return self._layer

    @layer.setter
    def layer(self, val):
        self._layer = val

    @property
    def down(self):
        return self._down

    @down.setter
    def down(self, ptr):
        self._down = ptr


class Skip_List:
    def __init__(self) -> None:
        self.head = None

        # current height of skip list
        self.height = 1

        # these counts do not consider duplicate elements for skip connections
        self.size = 0  # number of elements, alive or dead
        self.num_alive = 0  # number of living elements
        self.num_dead = 0  # number of dead elements

    def reset(self):
        # reinitialize values
        self.head = None
        self.height = 1
        self.size = 0
        self.num_alive = 0
        self.num_dead = 0

    def status(self):
        print(
            f"There are {self.size} element(s) in the skip list, of which "
            f"{self.num_alive} are alive and {self.num_dead} are dead"
        )
        print(f"The list has {self.height} layers")

    def insert(self, value):
        new = Node(value)
        # if empty
        if self.size == 0:
            # make new node the head
            self.head = new
            new.layer = 1

        # if new value is less than head
        elif value < self.head.get_value:
            # update head
            tmp = self.head
            self.head = new
            new.layer = tmp.layer
            new.next = tmp
            # create skip layers of new head
            i = tmp.layer
            if i > 1:
                curr = tmp.down
                prev_new = new
                curr_new = Node(value)
                curr_new.layer = curr.layer
                while i > 1:
                    prev_new.down = curr_new
                    curr_new.next = curr
                    curr_new.layer = curr.layer

                    curr = curr.down
                    prev_new = curr_new
                    curr_new = Node(value)

                    i -= 1
        else:
            curr = self.head
            while True:
                # move to the right if possible
                if curr.next is not None:
                    # move to the right if next value is still smaller
                    if curr.next.get_value < value:
                        curr = curr.next
                    # element already exists in the list
                    elif curr.next.get_value == value:
                        print("This value is already in the list")
                        return
                    # if next value is larger you can move down a level
                    elif curr.down is not None:
                        curr = curr.down
                    # otherwise you have found your spot
                    else:
                        tmp = curr.next
                        curr.next = new
                        new.layer = 1
                        new.next = tmp
                        break
                # move down if you cannot move right
                elif curr.down is not None:
                    curr = curr.down
                # otherwise you have reached the end of the list
                else:
                    curr.next = new
                    new.layer = 1
                    break

            # coin flips to see if new element gets skip connections
            coin = random.randint(0, 1)
            if coin:
                new_layer = 2
                prev_new = new

                while coin:
                    print(f"Skip connection added on {new_layer}!")
                    curr_new = Node(value)

                    # if adding to skip list height
                    if new_layer > self.height:
                        # update head
                        new_head = Node(self.head.get_value)
                        new_head.layer = new_layer
                        new_head.down = self.head
                        self.head = new_head
                        self.height += 1

                    curr = self.head

                    # start at head and move down to layer that gets new skip connection
                    while curr.layer != new_layer:
                        curr = curr.down

                    # move along layer new connection is being added
                    while True:
                        # found spot at end of skip connections
                        if curr.next is None:
                            # insert
                            curr.next = curr_new
                            curr_new.layer = new_layer

                            # update curr_new values
                            curr_new.down = prev_new

                            # update previous new
                            prev_new = curr_new
                            break
                        # keep moving to the right
                        elif curr.next.get_value < value:
                            curr = curr.next
                        # found skip connection location between values
                        else:
                            # insert between
                            tmp = curr.next
                            curr.next = curr_new
                            curr_new.next = tmp

                            # update new node values
                            curr_new.layer = new_layer
                            curr_new.down = prev_new

                            # update previous new
                            prev_new = curr_new
                            break

                    # flip another coin and increase list level
                    coin = random.randint(0, 1)
                    new_layer += 1

        # update skip list values
        self.size += 1
        self.num_alive += 1

    def find(self, value):
        """
        returns a pointer to the highest element in skip list with this value
            if it is alive and exists,
            otherwise returns none and not considered to be in the list

        """
        curr = self.head
        if curr.get_value == value:
            print(f"{value} is in the list")
            return curr

        while True:
            # if you can move right
            if curr.next is not None:
                # keep moving right if value not found yet and if it can still be in the list
                if curr.next.get_value < value:
                    curr = curr.next
                # if the next value is what you are looking
                elif curr.next.get_value == value:
                    # check if it is a living node
                    if curr.next.status:
                        print(f"{value} is in the list")
                        return curr.next
                    else:
                        print(f"{value} is not in the list")
                        return None
                elif curr.down is None:
                    # no need to keep looking all other values are larger and cant go down
                    print(f"{value} is not in the list")
                    return None
                else:
                    curr = curr.down
            # move down if you cant move right
            elif curr.down is not None:
                curr = curr.down
            # no where else to go! end of the list
            else:
                print(f"{value} is not in the list")
                return None

    def remove(self, value):
        """
        psuedo deletes an element with a value of value if it exists
        """
        curr = self.find(value)

        # remove highest occurance of this element
        if curr is not None:
            print(f"{value} was removed from the list")
            self.num_dead += 1
            self.num_alive -= 1
            i = curr.layer
            curr.kill
            # remove all other occurances of this element
            while i > 1:
                curr = curr.down
                curr.kill
                i = curr.layer

            # check if rebuild is needed
            if self.num_dead / self.size > 0.5:
                self.rebuild()

        else:
            print(f"{value} was not in the list")

    def show_layers(self, show_type="alive"):
        """
        prints out each layer of the skip list

        show_type
        - 'both' will print out both alive and dead elements
        - 'alive' will only print alive elements
        - 'dead' will only print dead elements
        - treats anything else as 'both'
        """
        if self.size == 0:
            print("The list is empty")
            return

        if show_type == "alive":
            print("List contains these living nodes at the following Layers:")
        elif show_type == "dead":
            print("List contains these dead nodes at the following Layers:")
        else:
            print("List contains these living and dead nodes at the following Layers:")

        # for each layer
        for curr_layer in range(self.height, 0, -1):
            curr = self.head
            vals = []  # values in this layer
            # move down to layer curr_layer
            while curr.layer != curr_layer:
                curr = curr.down

            # add elements until reaching end of this layer
            while curr is not None:
                if show_type == "alive":
                    if curr.status:
                        vals.append(curr.get_value)
                elif show_type == "dead":
                    if not curr.status:
                        vals.append(curr.get_value)
                else:
                    vals.append(curr.get_value)

                curr = curr.next

            print(f"\tLayer {curr_layer}: {vals}")

    def rebuild(self):
        """
        rebuild the data structure with only the alive nodes
        """

        print("\n\n\nRebuilding Skip List!\n\n\n")
        vals = []

        # find values of all living nodes
        curr = self.head

        # move to layer 1
        while curr.layer != 1:
            curr = curr.down

        # traverse list adding values of living elements
        while curr is not None:
            if curr.status:
                vals.append(curr.get_value)
            curr = curr.next

        # reinitalize values of skip list
        self.reset()

        for val in vals:
            self.insert(val)


def main():
    L = Skip_List()

    # testing first insert
    print("\n\n-------- Inserting 3 --------")
    L.insert(3)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing second insert
    print("\n\n-------- Inserting 4 --------")
    L.insert(4)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing insert of new minimum
    print("\n\n-------- Inserting 1 --------")
    L.insert(1)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing duplicate insert
    print("\n\n-------- Inserting Duplicate 3 --------")
    L.insert(3)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing removal
    print("\n\n-------- Removing 3 --------")
    L.remove(3)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing removal of non living element
    print("\n\n-------- Removing 3 Again--------")
    L.remove(3)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing removal of element not in list at all
    print("\n\n-------- Removing 5 (was never inserted) --------")
    L.remove(5)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing removal to empty and rebuilding
    print("\n\n-------- Removing Until Empty --------")
    L.remove(1)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    L.remove(4)
    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing arbitrary inserts
    print("\n\n------------ Arbitrary Inserts ------------\n\n")
    vals = []
    for i in range(0, 50):
        val = random.randint(0, 100)
        print(f"\n\n---Inserting {val}---")
        vals.append(val)
        L.insert(val)

    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing arbitrary removals
    print("\n\n------------ Arbitrary Removals ------------\n\n")
    for i in range(0, 30):
        idx = random.randint(0, len(vals) - 1)
        val = vals.pop(idx)
        print(f"\n\n---Removing {val}---")
        L.remove(val)

    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")

    # testing arbitary removal of number not in list (dead or alive)
    print("\n\n------------ Arbitrary Non-Existant Removals ------------\n\n")
    for i in range(0, 10):
        val = random.randint(100, 200)
        print(f"\n\n---Removing {val}---")
        L.remove(val)

    L.status()
    L.show_layers()
    L.show_layers("dead")
    L.show_layers("both")


if __name__ == "__main__":
    main()
