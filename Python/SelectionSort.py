def SelectionSort(arr):
    for i in range(size-1):
        min =i
        for j in range(i+1, size):
            if arr[j]<arr[min]:
                min = j
            if min != i:
                arr[min], arr[i] = arr[i], arr[min]
    return arr

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
    SelectionSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")