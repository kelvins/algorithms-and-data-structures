#[derive(Debug)]
struct Pilha<T> {
  pilha: Vec<T>
}

impl<T> Pilha<T> {
  fn new() -> Self {
    Pilha { pilha: Vec::new() }
  }

  fn length(&self) -> usize {
    self.pilha.len()
  }

  fn push(&mut self, item: T) {
    self.pilha.push(item)
  }

  fn pop(&mut self) -> Option<T> {
    self.pilha.pop()
  }
  
  fn is_empty(&self) -> bool {
    self.pilha.is_empty()
  }

  fn peek(&self) -> Option<&T> {
    self.pilha.first()
  }
}

fn main() {
  let mut pilha: Pilha<i32> = Pilha::<i32>::new();
  pilha.push(1);
  pilha.push(2);
  println!("{:?}", pilha);
  pilha.pop();
  println!("{:?}", pilha);
  println!("length: {:?}, is empty? {:?}", pilha.length(), pilha.is_empty());
  pilha.push(3);
  println!("{:?}", pilha.peek());
}