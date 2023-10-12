function SelectionSort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        let min = i;
        for (j = i + 1; j < arr.length; j++) if (arr[j] < arr[min]) min = j;
        if (min != j) [arr[i], arr[min]] = [arr[min], arr[i]];
    }
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
SelectionSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
