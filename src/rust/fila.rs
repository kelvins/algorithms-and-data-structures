struct Fila<T> {
  fila: Vec<T>
}

impl<T> Fila<T> {
  fn new() -> Self {
    Fila { fila: Vec::new() }
  }

  fn length(&self) -> usize {
    self.fila.len()
  }

  fn enqueue(&mut self, item: T) {
    self.fila.push(item)
  }

  fn dequeue(&mut self) -> T {
    self.fila.remove(0)
  }
  fn is_empty(&self) -> bool {
    self.fila.is_empty()
  }

  fn peek(&self) -> Option<&T> {
    self.fila.first()
  }
}