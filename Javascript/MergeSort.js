function mergeSort(arr) {
    if (arr.length <= 1) {
      return arr;
    }
  
    const middle = Math.floor(arr.length / 2);
    const leftHalf = arr.slice(0, middle);
    const rightHalf = arr.slice(middle);
  
    const leftSorted = mergeSort(leftHalf);
    const rightSorted = mergeSort(rightHalf);
    return merge(leftSorted, rightSorted);
  }
  
  function merge(left, right) {
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;
  
    while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex]) {
        result.push(left[leftIndex]);
        leftIndex++;
      } else {
        result.push(right[rightIndex]);
        rightIndex++;
      }
    }
  
    return result.concat(left.slice(leftIndex), right.slice(rightIndex));
  }
  
  function main() {
    const readline = require('readline');
    const rl = readline.createInterface({
      input: process.stdin,
      output: process.stdout
    });
  
    rl.question('Enter numbers separated by spaces: ', (input) => {
      const unsortedArray = input.split(' ').map(Number);
  
      const sortedArray = mergeSort(unsortedArray);
  
      console.log('Sorted array:', sortedArray);
  
      rl.close();
    });
  }
  
  main();
  