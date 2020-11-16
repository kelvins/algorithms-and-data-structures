#[derive(Debug)]
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

fn main(){
  let mut fila: Fila<i32> = Fila::<i32>::new();
  fila.enqueue(1);
  println!("{:?}", fila);
  fila.dequeue();
  println!("length: {:?}, is empty? {:?}", fila.length(), fila.is_empty());
  fila.enqueue(1);
  fila.enqueue(2);
  fila.enqueue(3);
  println!("{:?}", fila.peek());
}