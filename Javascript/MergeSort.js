function MergeSort(arr, left, right) {
    if (left >= right) return;
    let middle = left + Math.floor((right - left) / 2);
    MergeSort(arr, left, middle);
    MergeSort(arr, middle + 1, right);
    ActualWorker(arr, left, middle, right);
}

function ActualWorker(arr, left, middle, right) {
    let leftSide = middle - left + 1,
        rightSide = right - middle;
    let leftHalf = [],
        rightHalf = [];
    for (let i = 0; i < leftSide; i++) leftHalf[i] = arr[left + i];
    for (let i = 0; i < rightSide; i++) rightHalf[i] = arr[middle + i + 1];
    let i = 0,
        j = 0,
        k = left;
    while (i < leftSide && j < rightSide) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }
    while (i < leftSide) {
        arr[k] = leftHalf[i];
        i++, k++;
    }
    while (j < rightSide) {
        arr[k] = rightHalf[j];
        j++, k++;
    }
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
MergeSort(arr, 0, 4);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
