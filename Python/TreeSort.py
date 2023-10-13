class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(root, value):
    if root is None:
        return TreeNode(value)
    if value < root.value:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root

def in_order_traversal(root, result):
    if root:
        in_order_traversal(root.left, result)
        result.append(root.value)
        in_order_traversal(root.right, result)

def tree_sort(arr):
    root = None
   
    for value in arr:
        root = insert(root, value)

    arr.clear()  
    result = []
    in_order_traversal(root, result)
    arr.extend(result)

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
    tree_sort(arr)
    print("SORTED LIST:", arr)
except KeyboardInterrupt:
    print("Program interrupted by the user.")
except Exception as e:
    print("INPUT MUST BE A NUMBER")
