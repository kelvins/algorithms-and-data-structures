"""
Implementação de uma hashtable
"""

import traceback


class HashTable:

    def __init__(self, size=10):
        self.size = size
        self.tables = [[] for _ in range(self.size)]

    def hashing(self, key):
        return hash(key) % self.size

    def __setitem__(self, key, value):
        hash_key = self.hashing(key)
        bucket = self.tables[hash_key]
        if bucket:
            for index, k_value in enumerate(bucket):
                k, v = k_value
                if key == k:
                    bucket[index] = key, value
                    return
        bucket.append((key, value))

    def __getitem__(self, key):
        hash_key = self.hashing(key)
        bucket = self.tables[hash_key]
        if bucket:
            for index, item in enumerate(bucket):
                k, value = item
                if key == k:
                    return value
        raise KeyError(key)

    def __delitem__(self, key):
        hash_key = self.hashing(key)
        bucket = self.tables[hash_key]
        if bucket:
            for index, item in enumerate(bucket):
                k, value = item
                if key == k:
                    del bucket[index]
                    return
        raise KeyError(key)


if __name__ == '__main__':

    # Cria as tabelas de dispersão
    hash_table = HashTable()

    # Insere as chaves e valores
    for i in range(143):
        hash_table[i] = hex(round(i * 23))

    # Deletar item
    print("Deletar chave 0 de valor: ", hash_table[0])
    del hash_table[0]

    # Procurar item
    print('Valor da chave 23: ', hash_table[23])

    # Subscrever um valor de uma chave
    hash_table[1] = 'TESTE DE SUBSCREVER'

    # Exibir dispersão
    for i, table in enumerate(hash_table.tables):
        print("Table {index} -> {table} Len -> {len}".
              format(index=i + 1,
                     table=table,
                     len=len(table)))

    # Tentar deletar uma chave que não existe
    try:
        del hash_table[493084]
    except KeyError:
        print(traceback.print_exc())

    # Tentar acessar uma chave que não existe
    try:
        print(hash_table[493084])
    except KeyError:
        print(traceback.print_exc())
