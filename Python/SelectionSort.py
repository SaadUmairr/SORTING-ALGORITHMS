arr = []
size = int(input('Enter size of the list: '))
for _ in range(size):
    el = int(input('Enter element: '))
    arr.append(el)

for i in range(size-1):
    min =i
    for j in range(i+1, size):
        if arr[j]<arr[min]:
            min = j
        if min != i:
            arr[min], arr[i] = arr[i], arr[min]
print('Sorted List: ', arr)

