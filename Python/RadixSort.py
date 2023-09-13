def print_arr(arr):
    for value in arr:
        print(value, end='\t')
    print()

def get_max(arr):
    MAX = float('-inf')
    for i in arr:
        MAX = max(MAX, i)
    return MAX

def counting_sort(arr, exp):
    output = [0] * len(arr)
    count = [0] * 10
    
    for i in arr:
        count[(i // exp) % 10] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]

    i = len(arr) - 1
    while i >= 0:
        output[count[(arr[i] // exp) % 10] - 1] = arr[i]
        count[(arr[i] // exp) % 10] -= 1
        i -= 1
    
    for i in range(len(arr)):
        arr[i] = output[i]

def RadixSort(arr):
    MAX = get_max(arr)
    exp = 1
    
    while MAX // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

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
    RadixSort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")