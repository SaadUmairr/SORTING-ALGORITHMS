def CountSort(arr):
    high = max(arr)
    freq = [0] * (high + 1)
    for num in arr:
        freq[num] += 1
    for i in range(1, high + 1):
        freq[i] += freq[i - 1]
    
    sorted_list = [0] * len(arr)
    
    for i in range(len(arr) - 1, -1, -1):
        sorted_list[freq[arr[i]] - 1] = arr[i]
        freq[arr[i]] -= 1
    
    return sorted_list

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
    arr = CountSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")