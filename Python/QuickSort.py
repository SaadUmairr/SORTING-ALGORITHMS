def QuickSort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return QuickSort(left) + middle + QuickSort(right)

arr = []
size = int(input('Enter size of the list: '))
for _ in range(size):
    el = int(input('Enter element: '))
    arr.append(el)
print(QuickSort(arr))
