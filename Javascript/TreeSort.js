class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function insert(root, value) {
    if (root === null) {
        return new TreeNode(value);
    }

    if (value < root.value) {
        root.left = insert(root.left, value);
    } else if (value > root.value) {
        root.right = insert(root.right, value);
    }

    return root;
}

function inOrderTraversal(root, result) {
    if (root !== null) {
        inOrderTraversal(root.left, result);
        result.push(root.value);
        inOrderTraversal(root.right, result);
    }
}

function treeSort(arr) {
    let root = null;

    for (let i = 0; i < arr.length; i++) {
        root = insert(root, arr[i]);
    }

    let sortedResult = [];
    inOrderTraversal(root, sortedResult);

    return sortedResult;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
const sortedArr = treeSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(sortedArr);
