
def fibonacci1(n):
    last = 0
    curr = 1
    for i in range(0, n):
        temp = curr
        curr = curr + last
        last = temp
    return last

def fibonacci2(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci2(n-1) + fibonacci2(n-2)

if __name__ == "__main__":
    print fibonacci1(12)
    print fibonacci2(12)
