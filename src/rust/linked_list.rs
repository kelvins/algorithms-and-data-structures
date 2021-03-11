#[derive(Debug)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

impl<T> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList {
            head: None,
            size: 0,
        }
    }

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn push(&mut self, data: T) {
        self.head = Some(Box::new(Node {
            data: data,
            next: self.head.take(),
        }));
        self.size += 1;
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|h| {
            self.head = h.next;
            self.size -= 1;
            h.data
        })
    }
}

fn main() {
    let mut linked_list: LinkedList<u16> = LinkedList::new();
    linked_list.push(1);
    linked_list.push(2);
    linked_list.push(3);
    println!("{:#?}", linked_list);
    linked_list.pop();
    println!("{:#?}", linked_list);
    println!("Linked List Length: {}", linked_list.len());
}
