const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

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

function printArray(arr) {
    for (let i = 0; i < arr.length; i++) {
        console.log(arr[i]);
    }
}

function getInput() {
    return new Promise((resolve) => {
        const arr = [];
        rl.question("Enter size of the list: ", (size) => {
            size = parseInt(size);

            if (size <= 0) {
                console.log("Size of the list cannot be negative");
                rl.close();
                resolve([]);
            } else {
                console.log("Enter elements of the list:");
                let inputCount = 0;

                rl.on('line', (line) => {
                    const number = parseInt(line);

                    if (!isNaN(number)) {
                        arr.push(number);
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
    console.log("INPUT LIST:");
    printArray(arr);
    bubbleSort(arr);
    console.log("SORTED LIST:");
    printArray(arr);
    process.exit(0);
}

main();
