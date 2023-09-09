const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function quickSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const pivot = arr[Math.floor(arr.length / 2)];
    const left = [];
    const middle = [];
    const right = [];

    arr.forEach(element => {
        if (element < pivot) {
            left.push(element);
        } else if (element > pivot) {
            right.push(element);
        } else {
            middle.push(element);
        }
    });

    return [...quickSort(left), ...middle, ...quickSort(right)];
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
    const sortedArr = quickSort(arr);
    console.log("SORTED LIST:");
    printArray(sortedArr);
    process.exit(0);
}

main();
