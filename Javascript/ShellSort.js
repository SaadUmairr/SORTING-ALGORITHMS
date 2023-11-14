function ShellSort(arr) {
    let size = arr.length;
    for (let gap = Math.floor(size / 2); gap >= 1; gap = Math.floor(gap / 2)) {
        for (let j = gap; j < size; j++) {
            for (let i = j - gap; i >= 0; i -= gap) {
                if (arr[i + gap] > arr[i]) {
                    break;
                } else {
                    [arr[i + gap], arr[i]] = [arr[i], arr[i + gap]];
                }
            }
        }
    }
    return arr;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
arr = ShellSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
