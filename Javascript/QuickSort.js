function quickSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const pivot = arr[Math.floor(arr.length / 2)];
    const left = [];
    const middle = [];
    const right = [];

    arr.forEach(element => {
        if (element < pivot) {
            left.push(element);
        } else if (element > pivot) {
            right.push(element);
        } else {
            middle.push(element);
        }
    });

    return [...quickSort(left), ...middle, ...quickSort(right)];
}

const arr = [12, 4, 5, 6, 7, 3, 1, 15];
const sortedArr = quickSort(arr);
console.log(sortedArr);
