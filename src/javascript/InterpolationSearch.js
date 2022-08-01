/**
 * @author octaviolage
 * @version 1.0
 * @date 2022-07-31
 * @description Busca por interpolação
 * @reference https://en.wikipedia.org/wiki/Interpolation_search
 */

/**
 * @param {Array} arr - Array de elementos a ser buscado
 * @param {Array} first - Primeiro indice do array
 * @param {Array} last - Último indice do array
 * @param {Number} value - Valor a ser buscado
 * @return {Number} - Index do elemento buscado ou -1 se não encontrado
 * @throws {Error} - Se o array estiver vazio
 */
const interpolationSearch = (arr, first, last, value) => {
  let pos;
  if (first <= last && value >= arr[first] && value <= arr[last]) {
    pos = first + Math.floor((last - first) * (value - arr[first]) / (arr[last] - arr[first]));
    if (arr[pos] === value)
      return pos;
    else if (arr[pos] < value)
      return interpolationSearch(arr, pos + 1, last, value);
    else 
      return interpolationSearch(arr, first, pos - 1, value);
  }
  return -1;
}

const main = () => {
  // O array precisa ser ordenado
  const arr = [10, 12, 13, 16, 18, 19, 20, 21, 
    22, 23, 24, 33, 35, 42, 47];
  let n = arr.length;

  // Buscando pelo valor 18
  let x = 18
  let index = interpolationSearch(arr, 0, n - 1, x);

  if (index != -1)
    console.log(`Indice do elemento buscado: ${index}`);
  else
    console.log("Elemento não encontrado");
}

main();
