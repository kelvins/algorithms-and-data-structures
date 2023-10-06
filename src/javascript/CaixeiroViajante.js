/* 
O problema do caixeiro viajante é um problema de otimização combinatorial que envolve encontrar o caminho mais curto que visita cada cidade exatamente uma vez e retorna à cidade de origem. No exemplo abaixo segue um simples exemplo do algoritmo demonstrando.
*/

function caixeiroViajante(cidades) {
  const numCidades = cidades.length;

  // Rastrear quais cidades já foram visitadas
  const visitadas = new Array(numCidades).fill(false);

  // Começamos a partir da primeira cidade (índice 0)
  const caminho = [0];
  visitadas[0] = true;

  let distanciaTotal = 0;

  for (let i = 0; i < numCidades - 1; i++) {
    let cidadeAtual = caminho[caminho.length - 1];
    let menorDistancia = Number.POSITIVE_INFINITY;
    let cidadeMaisProxima = -1;

    for (let j = 0; j < numCidades; j++) {
      if (!visitadas[j]) {
        const distancia = calcularDistancia(cidades[cidadeAtual], cidades[j]);
        if (distancia < menorDistancia) {
          menorDistancia = distancia;
          cidadeMaisProxima = j;
        }
      }
    }

    caminho.push(cidadeMaisProxima);
    visitadas[cidadeMaisProxima] = true;
    distanciaTotal += menorDistancia;
  }

  // Completar o ciclo voltando para a cidade inicial
  distanciaTotal += calcularDistancia(
    cidades[caminho[numCidades - 1]],
    cidades[caminho[0]]
  );

  return { caminho, distanciaTotal };
}

// Calculo da distância entre duas cidades
function calcularDistancia(cidade1, cidade2) {
  const dx = cidade1.x - cidade2.x;
  const dy = cidade1.y - cidade2.y;
  return Math.sqrt(dx * dx + dy * dy);
}

// Exemplo de uso
const cidades = [
  { x: 0, y: 0 },
  { x: 2, y: 4 },
  { x: 3, y: 1 },
  { x: 5, y: 3 },
];

const resultado = caixeiroViajante(cidades);
console.log("Caminho: ", resultado.caminho);
console.log("Distância total: ", resultado.distanciaTotal);