arr = []
size = int(input("Enter the size of the list: "))

for _ in range(size):
    el = int(input("Enter a number: "))
    arr.append(el)

for i in range(size):
    change = False
    for j in range(size - i - 1):
        if arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]
            change = True
    if not change:
        break

print("Sorted list:", arr)
