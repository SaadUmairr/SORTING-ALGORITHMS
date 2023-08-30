function bubbleSort(array) {
    let n = array.length;
    let swapped = true;

    while (swapped) {
        swapped = false;
        for (let i = 0; i < n - 1; i++) {
            if (array[i] > array[i + 1]) {
                [array[i], array[i + 1]] = [array[i + 1], array[i]];
                swapped = true;
            }
        }
        n--;
    }

    return array;
}

var arr = [];
var size = prompt('Enter size of the list: ');

for (let i = 0; i < size; i++) {
    let number = parseInt(prompt('Enter a number: '));
    arr.push(number);
}

console.log("BEFORE SORTING:");
for (let i = 0; i < size; i++) {
    console.log(arr[i]);
}

bubbleSort(arr);

console.log("AFTER SORTING:");
for (let i = 0; i < size; i++) {
    console.log(arr[i]);
}
