function CubeSort(arr) {
    let size = arr.length,
        n = size,
        swapped = true;
    while (swapped) {
        swapped = false;
        for (let i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
                swapped = true;
            }
        }
        n--;
        for (let i = n - 1; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
                swapped = true;
            }
        }
    }
    return arr;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
arr = CubeSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
