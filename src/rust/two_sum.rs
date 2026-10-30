use std::collections::HashMap;
fn has_pair_with_sum(list: &[i32], x: i32) -> bool {
    let mut values = HashMap::new();
    for (index, value) in list.iter().enumerate() {
        values.insert(value, index);
        let diff = x - value;
        if values.contains_key(&diff) {
            if values[&diff] != index {
                return true;
            }
        }
    }
    return false;
}

fn main() {
    let list = vec![1, 2, 3, 4, 5, 6, 7, 8];
    println!("{}", has_pair_with_sum(&list, 3));
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_has_pair_with_sum() {
        let list = vec![1, 2, 3, 4, 5, 6, 7, 8];

        assert_eq!(has_pair_with_sum(&list, 3), true);
        assert_eq!(has_pair_with_sum(&list, 5), true);
        assert_eq!(has_pair_with_sum(&list, 7), true);
        assert_eq!(has_pair_with_sum(&list, 15), true);

        assert_eq!(has_pair_with_sum(&list, 1), false);
        assert_eq!(has_pair_with_sum(&list, 2), false);
        assert_eq!(has_pair_with_sum(&list, 16), false);
    }
}
