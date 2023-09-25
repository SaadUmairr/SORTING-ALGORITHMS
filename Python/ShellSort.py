def ShellSort(arr):
    size = len(arr)
    gap = size // 2
    while gap > 0:
        for j in range(gap, size):
            i = j - gap
            while i >= 0:
                if arr[i + gap] > arr[i]:
                    break
                else:
                    arr[i + gap], arr[i] = arr[i], arr[i + gap]
                i -= gap
        gap //= 2


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
    ShellSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")