/*
    Contributors
        - Dromedario de Chapéu

    Binary search efficiently finds a value in a sorted list. It repeatedly
    halves the portion that may contain the target until it finds the value
    or determines that the value is absent.

    The Khan Academy tutorial uses binary search in a guessing game:
    https://pt.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
*/

// In Rust, <T> indicates a generic type rather than a specific type.
// Here, T is the type of the list values and the value to be
// searched for.
fn binary_search<T>(list: &[T], value: T) -> (bool, usize)
where
    // T must implement the PartialEq and PartialOrd traits so
    // it can be compared and ordered.
    T: PartialEq,
    T: PartialOrd,
{
    // center is the midpoint of the list or sublist.
    let mut middle = list.len() / 2;

    // limit_r is the greatest possible index, at the right edge
    // of the current list. It lets us narrow the original list without
    // cloning or physically splitting it. It acts as the sublist’s [-1].
    let mut right_limit = list.len() - 1;

    // limit_l is like limit_r, but for the left edge,
    // that is, the sublist’s [0].
    let mut left_limit = 0;

    loop {
        // The value is passed by reference and accessed through its
        // pointer under Rust’s ownership system. This can be done with a simple
        // assignment such as `value_p = list[middle]` in Python, for example.
        let value_p = &list[middle];

        // The first if block checks whether the value we are
        // searching for was found. If not, it checks whether the previous operation left
        // the midpoint unchanged, meaning there are no more values to check
        // and the item is not present.
        if *value_p == value {
            return (true, middle);
        } else if middle == left_limit && middle == right_limit {
            return (false, 0);
        }

        // The second block checks the distance between the input value
        // and the current value_p. If value_p is greater, the target
        // is earlier in the list, so center moves to the midpoint of the previous sublist.
        // If value is greater than value_p, move center
        // to the midpoint of the next sublist.
        if *value_p > value {
            right_limit = middle;
            middle = middle / 2;
        } else if *value_p < value {
            left_limit = middle;
            // This if checks whether the gap between limit_r and limit_l is 1
            // because the default operation would produce 0 in that case, since
            // Rust rounds down, so 0.5 becomes 0.
            // This could be done on one line using type conversion and rounding,
            // but I do not think the performance gain is worth it.

            middle = if (right_limit - left_limit) == 1 {
                middle + 1
            } else {
                middle + (right_limit - left_limit) / 2
            };
            // One-line version -
            //     middle = middle + (((right_limit - left_limit) as f32 / 2.0).ceil() as usize);
        }
    }
}

fn main() {
    let list = vec![-5, -4, -3, -2, -1];
    let (exists, middle) = binary_search(&list, 6);
    println!("{}, {}", exists, middle);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn search() {
        let list = vec![-3, -2, -1, 0, 1, 2, 3];
        assert_eq!(binary_search(&list, -7), (false, 0));
        assert_eq!(binary_search(&list, -2), (true, 1));
        assert_eq!(binary_search(&list, 0), (true, 3));
        assert_eq!(binary_search(&list, 2), (true, 5));
        assert_eq!(binary_search(&list, 7), (false, 0));
    }
}
