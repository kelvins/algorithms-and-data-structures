use std::collections::HashMap;
fn existe_soma(lista: &[i32], x: i32) -> bool {
    let mut valores = HashMap::new();
    for (indice, valor) in lista.iter().enumerate() {
        valores.insert(valor, indice);
        let diff = x - valor;
        if valores.contains_key(&diff) {
            if valores[&diff] != indice {
                return true;
            }
        }
    }
    return false;
}

fn main() {
    let lista = vec![1, 2, 3, 4, 5, 6, 7, 8];
    println!("{}", existe_soma(&lista, 3));    
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn t_exite_soma() {
        let lista = vec![1, 2, 3, 4, 5, 6, 7, 8];
        
        assert_eq!(existe_soma(&lista, 3), true);
        assert_eq!(existe_soma(&lista, 5), true);
        assert_eq!(existe_soma(&lista, 7), true);
        assert_eq!(existe_soma(&lista, 15), true);

        assert_eq!(existe_soma(&lista, 1), false);
        assert_eq!(existe_soma(&lista, 2), false);
        assert_eq!(existe_soma(&lista, 16), false);
    }
}