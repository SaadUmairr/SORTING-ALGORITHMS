def CubeSort(arr):
    cube_dict = {}
    for element in arr:
        cube_dict[element] = element**3
    for i in range(1, len(arr)):
        current_element = arr[i]
        current_cube = cube_dict[current_element]
        insertion_point = i
        while (
            insertion_point > 0 and cube_dict[arr[insertion_point - 1]] > current_cube
        ):
            arr[insertion_point] = arr[insertion_point - 1]
            insertion_point -= 1
        arr[insertion_point] = current_element

    return arr


try:
    size = int(input("Enter the size of the list: "))
    arr = []
    for _ in range(size):
        while True:
            try:
                element = int(input("Enter a number: "))
                arr.append(element)
                break
            except ValueError:
                print("Invalid input. Please enter a valid number.")
    print("INPUT LIST:", arr)
    sorted_array = CubeSort(arr)
    print("SORTED LIST:", sorted_array)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print(f"INPUT MUST BE IN NUMBER")
