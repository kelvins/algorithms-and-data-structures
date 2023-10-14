fn fibonacci(n: u32) -> u64 {
    if n <= 1 {
        return n as u64;
    }

    let mut a: u64 = 0;
    let mut b: u64 = 1;

    for _ in 2..=n {
        let temp = a;
        a = b;
        b += temp;
    }

    b
}

fn main() {
    let index = 15;
    println!("Fibonacci (iterative) of {} is: {}", index, fibonacci(index));
}
