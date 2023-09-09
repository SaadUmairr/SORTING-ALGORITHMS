def InsertionSort(arr):
    for i in range(1,size):
        min = i
        while arr[min-1]>arr[min] and min>0:
            arr[min-1], arr[min] = arr[min], arr[min-1]
            min = min - 1
    print('Sorted List: ', arr)
    return arr
arr = []
size = int(input('Enter size of the list: '))
for _ in range(size):
    el = int(input('Enter element: '))
    arr.append(el)
arr = InsertionSort(arr)
print('SORTED LIST',arr)