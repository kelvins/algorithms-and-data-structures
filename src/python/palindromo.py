# A simple way to resolve the palindrome problem
# Note: this example does not deal with punctuation


def is_palindrome(content):
    processed_content = ''.join(content.lower().split())
    return processed_content == processed_content[::-1]


if __name__ == '__main__':
    assert is_palindrome('ovo')
    assert is_palindrome('osso')
    assert is_palindrome('Arara')
    assert is_palindrome('Amor a Roma')
    assert is_palindrome('O lobo ama o bolo')
    assert is_palindrome('A grama é amarga')

    assert not is_palindrome('Sentido')
    assert not is_palindrome('Algoritmos')
