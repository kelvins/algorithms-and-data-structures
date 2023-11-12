use std::collections::HashMap;

fn fibonacci(n: u32, memo: &mut HashMap<u32, u64>) -> u64 {
    if n <= 1 {
        return n as u64;
    }

    // Check if the result is already memoized
    if let Some(&cached_result) = memo.get(&n) {
        return cached_result;
    }

    // Calculate Fibonacci recursively and store the result in memoization
    let result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    memo.insert(n, result);

    result
}

fn main() {
    let index = 15;
    let mut memo: HashMap<u32, u64> = HashMap::new();

    println!(
        "Fibonacci (memoization) of {} is: {}",
        index,
        fibonacci(index, &mut memo)
    );
}
