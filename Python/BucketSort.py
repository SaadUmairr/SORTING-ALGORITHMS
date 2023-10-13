def InsertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def BucketSort(arr):
    if len(arr) == 0:
        return arr

    min_val, max_val = min(arr), max(arr)
    num_buckets = max(max_val - min_val, 1)
    bucket_range = (max_val - min_val) / num_buckets

    buckets = [[] for _ in range(num_buckets)]

    for num in arr:
        index = int((num - min_val) / bucket_range)
        if index == num_buckets:
            index -= 1
        buckets[index].append(num)

    sorted_arr = []
    for bucket in buckets:
        InsertionSort(bucket)
        sorted_arr.extend(bucket)

    return sorted_arr


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
    sorted_arr = BucketSort(arr)
    print("SORTED LIST:", sorted_arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"An error occurred: {e}")
