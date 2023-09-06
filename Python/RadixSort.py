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

def radix_sort(arr):
    MAX = get_max(arr)
    exp = 1
    
    while MAX // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

def main():
    print("Enter size of the array: ")
    size = int(input())
    
    if size <= 0:
        print("Size of list cannot be negative")
        return
    
    arr = []
    
    for _ in range(size):
        el = int(input())
        arr.append(el)
    
    print("ARRAY BEFORE SORTING:")
    print_arr(arr)
    
    radix_sort(arr)
    
    print("ARRAY AFTER SORTING:")
    print_arr(arr)

if __name__ == "__main__":
    main()
