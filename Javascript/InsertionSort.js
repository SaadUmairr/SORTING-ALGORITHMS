function InsertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let min = i;
        while (arr[min - 1] > arr[min] && min > 0) {
            [arr[min - 1], arr[min]] = [arr[min], arr[min - 1]];
            min--;
        }
    }
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
InsertionSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
