struct Deque<T> {
  deque: Vec<T>
}

impl<T> Deque<T> {
  fn new() -> Self {
    Deque { deque: Vec::new() }
  }

  fn add_last(&mut self, item: T) {
    self.deque.push(item)
  }

  fn remove_last(&mut self) -> Option<T> {
    self.deque.pop()
  }

  fn add_first(&mut self, item: T) {
    self.deque.insert(0 , item)
  }

  fn remove_first(&mut self) -> T {
    self.deque.remove(0)
  }

  fn length(&self) -> usize {
    self.deque.len()
  }

  fn is_empty(&self) -> bool {
    self.deque.is_empty()
  }

  fn peek(&self) -> Option<&T> {
    self.deque.first()
  }

  fn peek_last(&self) -> Option<&T> {
    self.deque.last()
  } 
}