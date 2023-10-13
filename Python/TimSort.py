def timSort(arr):
    size = len(arr)
    for i in range(size):
        InsertionSort(arr, i, min((i + 32 - 1), size - 1))
    for i in range(32, size, i * 2):
        for left in range(0, size, i):
            middle = left + i - 1
            right = min((left + 2 * i - 1), size - 1)
            if middle < right:
                merge(arr, left, middle, right)

def InsertionSort(arr, left, right):
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, left, middle, right):
    leftSide = middle - left + 1
    rightSide = right - middle
    leftHalf = []
    rightHalf = []
    for i in range(leftSide):
        leftHalf.append(arr[left + i])
    for i in range(rightSide):
        rightHalf.append(arr[middle + i + 1])
    i = 0
    j = 0
    k = left
    while i < leftSide and j < rightSide:
        if leftHalf[i] <= rightHalf[j]:
            arr[k] = leftHalf[i]
            i += 1
        else:
            arr[k] = rightHalf[j]
            j += 1
        k += 1
    while i < leftSide:
        arr[k] = leftHalf[i]
        i += 1
        k += 1
    while j < rightSide:
        arr[k] = rightHalf[j]
        j += 1
        k += 1

try:
    arr = []
    size = int(input("Enter the size of the list: "))
    for _ in range(size):
        while True:
            try:
                el = int(input("Enter a number: "))
                arr.append(el)
                break
            except ValueError:
                print("Invalid input. Please enter a valid number.")

    print("INPUT LIST:", arr)
    timSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"An error occurred: {e}")
