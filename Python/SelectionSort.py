def SelectionSort(arr):
    for i in range(size-1):
        min =i
        for j in range(i+1, size):
            if arr[j]<arr[min]:
                min = j
            if min != i:
                arr[min], arr[i] = arr[i], arr[min]
    return arr

arr = []
size = int(input('Enter size of the list: '))
for _ in range(size):
    el = int(input('Enter element: '))
    arr.append(el)
print("INPUT LIST:", arr)
arr = SelectionSort(arr)
print("SORTED LIST:", arr)