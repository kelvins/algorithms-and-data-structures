
def swap(l, pos1, pos2):
    temp = l[pos1]
    l[pos1] = l[pos2]
    l[pos2] = temp

def partition(l, start, end):
    pivot = l[start]
    while True:
        while l[start] < pivot:
            start = start + 1

        while l[end] > pivot:
            end = end - 1

        if start >= end:
            return end

        swap(l, start, end)

        start = start + 1
        end = end - 1

def quick_sort(l, start, end):
    if start < end:
        p = partition(l, start, end)
        quick_sort(l, start, p)
        quick_sort(l, p+1, end)

if __name__ == "__main__":
    a = [9,8,5,7,6,2,4,3,1]
    print(a)
    quick_sort(a, 0, len(a)-1)
    print(a)
