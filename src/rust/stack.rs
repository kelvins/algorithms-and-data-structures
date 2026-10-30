#[derive(Debug)]
struct Stack<T> {
    stack: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { stack: Vec::new() }
    }

    fn length(&self) -> usize {
        self.stack.len()
    }

    fn push(&mut self, item: T) {
        self.stack.push(item)
    }

    fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }

    fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }

    fn peek(&self) -> Option<&T> {
        self.stack.first()
    }
}

fn main() {
    let mut stack: Stack<i32> = Stack::<i32>::new();
    stack.push(1);
    stack.push(2);
    println!("{:?}", stack);
    stack.pop();
    println!("{:?}", stack);
    println!(
        "length: {:?}, is empty? {:?}",
        stack.length(),
        stack.is_empty()
    );
    stack.push(3);
    println!("{:?}", stack.peek());
}
