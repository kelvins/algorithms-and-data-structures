#[derive(Debug)]
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

fn main(){
  let mut deque: Deque<i32> = Deque::<i32>::new();
  deque.add_first(1);
  deque.add_last(2);
  deque.add_first(3);
  println!("{:?}", deque);
  deque.remove_last();
  deque.remove_first();
  println!("{:?}", deque);
  println!("length: {:?}, is empty? {:?}", deque.length(), deque.is_empty());
  deque.add_first(1);
  deque.add_last(2);
  deque.add_first(3);
  println!("{:?}, {:?}", deque.peek(), deque.peek_last());
}