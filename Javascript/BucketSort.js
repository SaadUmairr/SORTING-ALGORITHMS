function BucketSort(arr) {
    let size = arr.length;
    if (size <= 0) return;
    const max_value = Math.max(...arr);
    const min_value = Math.min(...arr);
    const range = max_value - min_value + 1;

    const buckets = Array.from({ length: range }, () => []);

    for (let i = 0; i < size; i++) {
        let index = arr[i] - min_value;
        buckets[index].push(arr[i]);
    }

    for (let i = 0; i < range; i++) {
        buckets[i].sort((a, b) => {
            return a - b;
        });
    }
    let index = 0;
    for (let i = 0; i < range; i++) {
        for (let j = 0; j < buckets[i].length; j++)
            arr[index++] = buckets[i][j];
    }
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
BucketSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
