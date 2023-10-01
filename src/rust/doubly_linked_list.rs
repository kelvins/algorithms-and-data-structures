use std::cell::RefCell;
use std::rc::Rc;

pub struct Node<T> {
    value: T,
    next: Option<Rc<RefCell<Node<T>>>>,
    previous: Option<Rc<RefCell<Node<T>>>>,
}

impl<T> Node<T> {
    fn new(value: T) -> Self {
        Self {
            value: value,
            next: None,
            previous: None,
        }
    }
}

pub struct DoublyLinkedList<T> {
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
}

impl<T> DoublyLinkedList<T> {
    pub fn new() -> Self {
        DoublyLinkedList {
            head: None,
            tail: None,
        }
    }

    pub fn add_left(&mut self, value: T) {
        let node = Rc::new(RefCell::new(Node::new(value)));

        match &self.head {
            Some(head_ref) => {
                node.borrow_mut().next = Some(head_ref.clone());
                head_ref.borrow_mut().previous = Some(node.clone());
                self.head = Some(node.clone());
            }
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node.clone());
            }
        }
    }

    pub fn add_right(&mut self, value: T) {
        let node = Rc::new(RefCell::new(Node::new(value)));

        match &self.tail {
            Some(tail_ref) => {
                node.borrow_mut().previous = Some(tail_ref.clone());
                tail_ref.borrow_mut().next = Some(node.clone());
                self.tail = Some(node.clone());
            }
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node.clone());
            }
        }
    }

    pub fn remove_left(&mut self) -> Option<T>
    where
        T: Clone,
    {
        match &self.head {
            Some(head_ref) => {
                let value = head_ref.borrow().value.clone();

                match &head_ref.clone().borrow().next {
                    Some(next_ref) => {
                        next_ref.borrow_mut().previous = None;
                        self.head = Some(next_ref.clone());
                    }
                    None => {
                        self.head = None;
                        self.tail = None;
                    }
                }

                Some(value)
            }
            None => None,
        }
    }

    pub fn remove_right(&mut self) -> Option<T>
    where
        T: Clone,
    {
        match &self.tail {
            Some(tail_ref) => {
                let value = tail_ref.borrow().value.clone();

                match &tail_ref.clone().borrow().previous {
                    Some(previous_ref) => {
                        previous_ref.borrow_mut().next = None;
                        self.tail = Some(previous_ref.clone());
                    }
                    None => {
                        self.head = None;
                        self.tail = None;
                    }
                }

                Some(value)
            }
            None => None,
        }
    }

    pub fn peek_left(&self) -> Option<T>
    where
        T: Clone,
    {
        match &self.head {
            Some(head_ref) => Some(head_ref.borrow().value.clone()),
            None => None,
        }
    }

    pub fn peek_right(&self) -> Option<T>
    where
        T: Clone,
    {
        match &self.tail {
            Some(tail_ref) => Some(tail_ref.borrow().value.clone()),
            None => None,
        }
    }

    pub fn remove(&mut self, value: T) -> Option<T>
    where
        T: Clone + PartialEq,
    {
        let mut pointer = self.head.clone();

        while let Some(node) = pointer {
            if node.borrow().value == value {
                match &node.borrow().previous {
                    Some(previous_ref) => match &node.borrow().next {
                        Some(next_ref) => {
                            previous_ref.borrow_mut().next = Some(next_ref.clone());
                            next_ref.borrow_mut().previous = Some(previous_ref.clone());
                        }
                        None => {
                            previous_ref.borrow_mut().next = None;
                            self.tail = Some(previous_ref.clone());
                        }
                    },
                    None => match &node.borrow().next {
                        Some(next_ref) => {
                            next_ref.borrow_mut().previous = None;
                            self.head = Some(next_ref.clone());
                        }
                        None => {
                            self.head = None;
                            self.tail = None;
                        }
                    },
                }

                return Some(node.borrow().value.clone());
            }

            pointer = node.borrow().next.clone();
        }

        None
    }

    pub fn find(&self, value: T) -> Option<T>
    where
        T: Clone + PartialEq,
    {
        let mut pointer = self.head.clone();

        while let Some(node) = pointer {
            if node.borrow().value == value {
                return Some(node.borrow().value.clone());
            }

            pointer = node.borrow().next.clone();
        }

        None
    }

    pub fn to_vec(&self) -> Vec<T>
    where
        T: Clone,
    {
        let mut vec = Vec::new();

        let mut pointer = self.head.clone();

        while let Some(node) = pointer {
            vec.push(node.borrow().value.clone());
            pointer = node.borrow().next.clone();
        }

        vec
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add_left() {
        let mut list = DoublyLinkedList::new();

        list.add_left(1);
        list.add_left(2);
        assert_eq!(list.to_vec(), vec![2, 1]);
    }

    #[test]
    fn test_add_right() {
        let mut list = DoublyLinkedList::new();

        list.add_right(1);
        list.add_right(2);
        assert_eq!(list.to_vec(), vec![1, 2]);
    }

    #[test]
    fn test_remove_left() {
        let mut list = DoublyLinkedList::new();

        list.add_left(1);
        list.add_left(2);

        assert_eq!(list.remove_left(), Some(2));
        assert_eq!(list.remove_left(), Some(1));
        assert_eq!(list.remove_left(), None);
    }

    #[test]
    fn test_remove_right() {
        let mut list = DoublyLinkedList::new();

        list.add_right(1);
        list.add_right(2);

        assert_eq!(list.remove_right(), Some(2));
        assert_eq!(list.remove_right(), Some(1));
        assert_eq!(list.remove_right(), None);
    }

    #[test]
    fn test_peek_left() {
        let mut list = DoublyLinkedList::new();

        list.add_left(1);
        list.add_left(2);

        assert_eq!(list.peek_left(), Some(2));
        assert_eq!(list.peek_left(), Some(2));
    }

    #[test]
    fn test_peek_right() {
        let mut list = DoublyLinkedList::new();

        list.add_right(1);
        list.add_right(2);

        assert_eq!(list.peek_right(), Some(2));
        assert_eq!(list.peek_right(), Some(2));
    }

    #[test]
    fn test_remove() {
        let mut list = DoublyLinkedList::new();

        list.add_left(1);
        list.add_left(2);
        list.add_left(3);
        list.add_left(4);
        list.add_left(5);

        assert_eq!(list.remove(3), Some(3));
        assert_eq!(list.remove(1), Some(1));
        assert_eq!(list.remove(5), Some(5));
        assert_eq!(list.remove(2), Some(2));
        assert_eq!(list.remove(6), None);

        assert_eq!(list.to_vec(), vec![4]);
    }

    #[test]
    fn test_find() {
        let mut list = DoublyLinkedList::new();

        list.add_left(1);
        list.add_left(2);
        list.add_left(3);
        list.add_left(4);
        list.add_left(5);

        assert_eq!(list.find(3), Some(3));
        assert_eq!(list.find(1), Some(1));
        assert_eq!(list.find(5), Some(5));
        assert_eq!(list.find(2), Some(2));
        assert_eq!(list.find(6), None);
    }
}
