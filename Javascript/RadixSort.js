function RadixSort(arr) {
    let MAX = arr[0];
    for (let i = 1; i < arr.length; i++) {
        MAX = Math.max(MAX, arr[i]);
    }
    for (let exp = 1; MAX / exp >= 1; exp *= 10) {
        arr = CountSort(arr, exp);
    }
    return arr;
}

function CountSort(arr, exp) {
    let output = Array.apply(null, Array(arr.length)).map(() => 0);
    let count = Array.apply(null, Array(10)).map(() => 0);
    for (let i = 0; i < arr.length; i++) {
        count[Math.floor(arr[i] / exp) % 10]++;
    }
    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (let i = arr.length - 1; i >= 0; i--) {
        output[count[Math.floor(arr[i] / exp) % 10] - 1] = arr[i];
        count[Math.floor(arr[i] / exp) % 10]--;
    }
    return output;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
arr = RadixSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
