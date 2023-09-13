def InsertionSort(arr):
    for i in range(1,size):
        min = i
        while arr[min-1]>arr[min] and min>0:
            arr[min-1], arr[min] = arr[min], arr[min-1]
            min = min - 1
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
    InsertionSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")