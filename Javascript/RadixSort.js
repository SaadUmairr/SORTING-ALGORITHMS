const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function printArray(arr) {
    console.log(arr.join('\t'));
}

function getMax(arr) {
    let max = Number.MIN_SAFE_INTEGER;
    for (const el of arr) {
        max = Math.max(max, el);
    }
    return max;
}

function countingSort(arr, exp) {
    const output = new Array(arr.length).fill(0);
    const count = new Array(10).fill(0);

    for (const el of arr) {
        count[Math.floor(el / exp) % 10]++;
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (let i = arr.length - 1; i >= 0; i--) {
        output[count[Math.floor(arr[i] / exp) % 10] - 1] = arr[i];
        count[Math.floor(arr[i] / exp) % 10]--;
    }

    for (let i = 0; i < arr.length; i++) {
        arr[i] = output[i];
    }
}

function radixSort(arr) {
    const max = getMax(arr);
    let exp = 1;

    while (Math.floor(max / exp) > 0) {
        countingSort(arr, exp);
        exp *= 10;
    }
}

rl.question("Enter size of the array: ", (size) => {
    size = parseInt(size);

    if (size <= 0) {
        console.log("Size of list cannot be negative");
        rl.close();
    } else {
        const arr = [];
        console.log("Enter elements of the array:");

        rl.on('line', (line) => {
            const el = parseInt(line);

            if (!isNaN(el)) {
                arr.push(el);
            }

            if (arr.length === size) {
                rl.close();
            }
        });

        rl.on('close', () => {
            console.log("ARRAY BEFORE SORTING:");
            printArray(arr);
            radixSort(arr);
            console.log("ARRAY AFTER SORTING:");
            printArray(arr);
        });
    }
});
