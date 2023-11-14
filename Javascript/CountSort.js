function CountSort(arr) {
    let high = arr[0],
        i;
    for (i = 0; i < arr.length; i++) high = Math.max(high, arr[i]);
    const freq = Array.from({ length: high + 1 }, () => 0);
    for (i = 0; i < arr.length; i++) freq[arr[i]]++;
    for (i = 1; i <= high; i++) freq[i] += freq[i - 1];
    const sorted = new Array(arr.length);
    for (i = high - 1; i >= 0; i--) sorted[--freq[arr[i]]] = arr[i];
    return sorted;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
arr = CountSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
