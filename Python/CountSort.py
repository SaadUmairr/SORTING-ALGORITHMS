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

arr = []
size = int(input("Enter size of the list: "))
for _ in range(size):
    el = int(input("Enter element: "))
    arr.append(el)
print("INPUT LIST:", arr)
arr = CountSort(arr)
print("SORTED LIST:", arr)
