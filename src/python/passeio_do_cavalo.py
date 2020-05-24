""" Implementação do algoritmo passeio do cavalo """


def aceitavel(x, y):
    """
    Aceitavel se estiver dentro do tabuleiro e a casa ainda nao tiver sido
    visitada

    Retorna True ou False
    """
    if (
        x >= 0
        and x <= num - 1
        and y >= 0
        and y <= num - 1
        and tabuleiro[x][y] == 0
    ):
        return True
    else:
        return False


def tenta_mover(i, x, y):
    """
    Tenta o i-esimo movimento em (x,y), 1 <= i <= n^2
    """
    done = i > numSqr  # True ou False
    k = 0
    while not done and k < 8:
        u = x + dx[k]  # Coordenadas dos 8 movimentos possiveis do cavalo
        v = y + dy[k]  # Coordenadas dos 8 movimentos possiveis do cavalo
        if aceitavel(u, v):
            tabuleiro[u][v] = i
            done = tenta_mover(i + 1, u, v)  # Tenta outro movimento
            if not done:
                tabuleiro[u][v] = 0  # Sem sucesso, descarta movimento
        k += 1  # Passa ao proximo movimento possivel
    return done


def mostra_movimento(x, y):
    tabuleiro[x][y] = 1
    done = tenta_mover(2, x, y)
    string = ""
    if done:
        for x in range(0, num):
            for y in range(0, num):
                if tabuleiro[x][y] < 10:
                    string += "0" + str(tabuleiro[x][y]) + " "
                else:
                    string += str(tabuleiro[x][y]) + " "
            string += "\n"
        print(string)
    else:
        print("Nao ha passeio possivel\n")


dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

print("Digite o num de posicoes do tabuleiro: (ex.: 6) <= 10")
num = int(input())  # Numero de posicoes do tabuleiro
print("Digite a posicao x onde o cavalo deve iniciar: (ex.: 1) >= 0")
x = int(input())  # Numero de posicoes do tabuleiro
print("Digite a posicao y onde o cavalo deve iniciar: (ex.: 2) >= 0")
y = int(input())  # Numero de posicoes do tabuleiro
numSqr = num * num  # Numero total de casas

print()

tabuleiro = [[], [], [], [], [], [], [], [], [], []]  # Tabuleiro maximo 20x20
for x in range(0, num):
    for y in range(0, num):
        tabuleiro[x].append(0)
# print tabuleiro
mostra_movimento(x, y)
