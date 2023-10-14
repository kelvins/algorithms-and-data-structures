from typing import Generic, TypeVar

T = TypeVar("T")


class RingBuffer(Generic[T]):
    def __init__(self, capacity: int) -> None:
        self._capacity = capacity
        self._init_buffer()

    def __str__(self) -> str:
        if self.is_empty():
            return "[]"

        if self._tail > self._head:
            buffer_state = self._buffer[self._head : self._tail]
        else:
            buffer_state = self._buffer[self._head :] + self._buffer[: self._tail]
        return str(buffer_state)

    def __repr__(self) -> str:
        return self.__str__()

    def __len__(self) -> int:
        return self._size

    def _init_buffer(self) -> None:
        self._buffer = [None] * self._capacity
        self._head = 0
        self._tail = 0
        self._size = 0

    def clear(self) -> None:
        self._init_buffer()

    def push(self, item: T) -> None:
        if self.is_full():
            raise IndexError("Ring buffer is full")

        self._buffer[self._tail] = item
        self._tail = (self._tail + 1) % self._capacity
        self._size = min(self._size + 1, self._capacity)

    def get(self) -> T:
        if self.is_empty():
            raise IndexError("Ring buffer is empty")

        item = self._buffer[self._head]
        self._head = (self._head + 1) % self._capacity
        self._size -= 1
        return item

    def is_full(self) -> bool:
        return self._size == self._capacity

    def is_empty(self) -> bool:
        return self._size == 0


if __name__ == "__main__":
    import unittest

    class TestRingBuffer(unittest.TestCase):
        def test_push(self):
            ring_buffer = RingBuffer[int](3)
            ring_buffer.push(7)
            ring_buffer.push(3)
            self.assertEqual("[7, 3]", str(ring_buffer))
            ring_buffer.push(10)
            self.assertEqual("[7, 3, 10]", str(ring_buffer))

        def test_get(self):
            ring_buffer = RingBuffer[int](3)
            ring_buffer.push(17)
            ring_buffer.push(35)
            self.assertEqual(17, ring_buffer.get())
            self.assertEqual(35, ring_buffer.get())

        def test_clear(self):
            ring_buffer = RingBuffer[int](3)
            ring_buffer.push(6)
            ring_buffer.push(11)
            self.assertEqual("[6, 11]", str(ring_buffer))
            ring_buffer.clear()
            self.assertEqual("[]", str(ring_buffer))
            self.assertEqual(0, len(ring_buffer))

        def test_push_with_full_error(self):
            ring_buffer = RingBuffer[int](1)
            ring_buffer.push(7)
            self.assertRaises(IndexError, ring_buffer.push, 9)

            ring_buffer = RingBuffer[int](2)
            ring_buffer.push(23)
            ring_buffer.push(14)
            self.assertRaises(IndexError, ring_buffer.push, 11)

        def test_get_with_empty_error(self):
            ring_buffer = RingBuffer[int](1)
            self.assertRaises(IndexError, ring_buffer.get)
            ring_buffer.push(15)
            ring_buffer.get()
            self.assertRaises(IndexError, ring_buffer.get)

        def test_size(self):
            ring_buffer = RingBuffer[int](3)
            ring_buffer.push(5)
            self.assertEqual(1, len(ring_buffer))
            ring_buffer.push(3)
            self.assertEqual(2, len(ring_buffer))
            ring_buffer.get()
            self.assertEqual(1, len(ring_buffer))

        def test_str(self):
            ring_buffer = RingBuffer[int](3)
            self.assertEqual("[]", str(ring_buffer))
            ring_buffer.push(10)
            self.assertEqual("[10]", str(ring_buffer))
            ring_buffer.get()
            ring_buffer.push(11)
            ring_buffer.push(9)
            self.assertEqual("[11, 9]", str(ring_buffer))
            ring_buffer.push(7)
            self.assertEqual("[11, 9, 7]", str(ring_buffer))

        def test_with_str_type(self):
            ring_buffer = RingBuffer[str](3)
            ring_buffer.push("mug")
            ring_buffer.push("cup")
            self.assertEqual("['mug', 'cup']", str(ring_buffer))

    suite = unittest.TestLoader().loadTestsFromTestCase(TestRingBuffer)
    unittest.TextTestRunner(verbosity=2).run(suite)
