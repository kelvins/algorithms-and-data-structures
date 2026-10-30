/*
    Contributors
        - Dromedario de chapeu

    Quicksort is an efficient sorting algorithm in most cases, with an average
    time complexity of O(n log n). Its worst-case complexity is O(n²), such as
    when the input is already ordered in the unfavorable direction.

    The algorithm uses divide and conquer: choose a pivot, move smaller values
    before it and larger values after it, then recursively sort both sides.

    Learn more:
    https://en.wikipedia.org/wiki/Quicksort
    https://rosettacode.org/wiki/Sorting_algorithms/Quicksort
*/

// l = left bound
// r = right bound
// These bounds are passed instead of creating a new list at each split
// so we always work on the same list and update its values
// and because creating new lists during recursion would be expensive.
fn partition(list: &mut [i32], l: usize, r: usize) -> isize {
    // Set the first item in the list as the pivot
    let pivot = list[l];

    // To move values less than or equal to the pivot before it,
    // we need a variable to count how many positions to move forward
    // the next value without repeatedly swapping the same value.
    let mut count = l;

    // Use a for loop to iterate over the list. We do not use enumerate because we need
    // simulate the sublists
    for j in l + 1..r + 1 {
        if list[j] <= pivot {
            count += 1;
            list.swap(count, j);
        }
    }

    // Swap the pivot with the last value that is less than or equal to it, because
    list.swap(l, count);

    // Return the pivot’s index after the swap so it can be used
    // as the boundary for the two sublists: 0..count - 1 and count + 1..len.
    // the new sublists.
    return count as isize;
}

fn quick_sort(list: &mut [i32], l: isize, r: isize) {
    // The recursion stops when the left and right bounds
    // are equal, meaning the list has only one element.
    if l < r {
        let pivot_index = partition(list, l as usize, r as usize);
        quick_sort(list, l, pivot_index - 1);
        quick_sort(list, pivot_index + 1, r);
    }
}

fn print_list(list: Vec<i32>) {
    for i in list.iter() {
        print!("{} ", *i);
    }
    println!();
}

fn main() {
    let mut list = vec![1, 6, 3, 9, 3, 8, 5, 2, 7];
    let len = list.len() as isize;

    print_list(list.clone());
    quick_sort(&mut list, 0, len - 1);
    print_list(list.clone());
}

#[cfg(test)]
mod test {
    use crate::*;

    #[test]
    fn quick() {
        let mut list = vec![9, 8, 7, 6, 5, 4, 3, 2, 1];
        let len = list.len() as isize - 1;
        quick_sort(&mut list, 0, len);
        assert_eq!(vec![1, 2, 3, 4, 5, 6, 7, 8, 9], list);

        let mut list = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
        let len = list.len() as isize - 1;
        quick_sort(&mut list, 0, len);
        assert_eq!(vec![1, 2, 3, 4, 5, 6, 7, 8, 9], list);
    }
}
