const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function SelectionSort(arr) {
    const size = arr.length;
    for (let i = 0; i < size - 1; i++) {
        let min = i;
        for (let j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min !== i) {
            [arr[i], arr[min]] = [arr[min], arr[i]];
        }
    }
}

function printArray(arr) {
    console.log(arr.join(' '));
}

function getInput() {
    return new Promise((resolve) => {
        const arr = [];
        rl.question("Enter size of the array: ", (size) => {
            size = parseInt(size);

            if (size <= 0) {
                console.log("Size of the array cannot be negative");
                rl.close();
                resolve([]);
            } else {
                console.log("Enter elements of the array:");
                let inputCount = 0;

                rl.on('line', (line) => {
                    const el = parseInt(line);

                    if (!isNaN(el)) {
                        arr.push(el);
                        inputCount++;

                        if (inputCount === size) {
                            rl.close();
                            resolve(arr);
                        }
                    }
                });
            }
        });
    });
}

async function main() {
    const arr = await getInput();
    console.log("ARRAY BEFORE SORTING:");
    printArray(arr);
    SelectionSort(arr);
    console.log("ARRAY AFTER SORTING:");
    printArray(arr);
    process.exit(0);
}

main();
