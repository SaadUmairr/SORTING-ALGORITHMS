// Function to perform insertion sort
function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
      let currentElement = arr[i];
      let j = i - 1;
  
      while (j >= 0 && arr[j] > currentElement) {
        arr[j + 1] = arr[j];
        j--;
      }
  
      arr[j + 1] = currentElement;
    }
  }
  function main() {
    const readline = require('readline');
    const rl = readline.createInterface({
      input: process.stdin,
      output: process.stdout
    });
  
    rl.question('Enter numbers separated by spaces: ', (input) => {
      const unsortedArray = input.split(' ').map(Number);
  
      insertionSort(unsortedArray);
  
      console.log('Sorted array:', unsortedArray);
  
      rl.close();
    });
  }
  
  main();
  