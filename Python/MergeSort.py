def Merge(arr, left, middle, right):
    LeftHalf = middle - left + 1
    RightHalf = right - middle
    LeftArr = []
    RightArr = []
    for i in range(LeftHalf):
        LeftArr.append(arr[left + i])
    for i in range(RightHalf):
        RightArr.append(arr[middle + i + 1])
    i = 0
    j = 0
    k = left
    while i < LeftHalf and j < RightHalf:
        if LeftArr[i] <= RightArr[j]:
            arr[k] = LeftArr[i]
            i = i + 1
        else:
            arr[k] = RightArr[j]
            j = j + 1
        k = k + 1
    while i < LeftHalf:
        arr[k] = LeftArr[i]
        i = i + 1
        k = k + 1
    while j < RightHalf:
        arr[k] = RightArr[j]
        j = j + 1
        k = k + 1

def MergeSort(arr, left, right):
    if left < right:
        middle = left + (right - left) // 2
        MergeSort(arr, left, middle)
        MergeSort(arr, middle + 1, right)
        Merge(arr, left, middle, right)

arr = []
size = int(input('Enter size of the list: '))
for _ in range(size):
    el = int(input('Enter element: '))
    arr.append(el)
print("INPUT LIST:", arr)
MergeSort(arr, 0, size - 1)
print("SORTED LIST:", arr)
