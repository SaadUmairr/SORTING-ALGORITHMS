function countingSort(arr) {
    if (arr.length === 0) {
      return arr;
    }
  
    let max = arr[0];
    for (let i = 1; i < arr.length; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
  
    const countArray = new Array(max + 1).fill(0);
  
    for (let i = 0; i < arr.length; i++) {
      countArray[arr[i]]++;
    }
  
    let sortedIndex = 0;
    for (let i = 0; i < countArray.length; i++) {
      while (countArray[i] > 0) {
        arr[sortedIndex] = i;
        sortedIndex++;
        countArray[i]--;
      }
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
  
      countingSort(unsortedArray);
  
      console.log('Sorted array:', unsortedArray);
  
      rl.close();
    });
  }
  
  main();
  