def bogo(x):
    while not inorder(x):
        shuffle(x)
    return x
