const RUN = 32;

function InsertionSort(arr, left, right) {
    for (let i = left + 1; i <= right; i++) {
        let key = arr[i],
            j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

function merge(arr, left, middle, right) {
    let leftSide = middle - left + 1;
    let rightSide = right - middle;
    let leftHalf = new Array(leftSide);
    let rightHalf = new Array(rightSide);
    for (let i = 0; i < leftSide; i++) leftHalf[i] = arr[left + i];
    for (let i = 0; i < rightSide; i++) rightHalf[i] = arr[middle + 1 + i];

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
        i++;
        k++;
    }

    while (j < rightSide) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

function TimSort(arr) {
    for (let i = 0; i < arr.length; i += RUN) {
        InsertionSort(arr, i, Math.min(i + RUN - 1, arr.length - 1));
    }

    for (let size = RUN; size < arr.length; size *= 2) {
        for (let left = 0; left < arr.length; left += 2 * size) {
            let middle = left + size - 1;
            let right = Math.min(left + 2 * size - 1, arr.length - 1);
            if (middle < right) {
                merge(arr, left, middle, right);
            }
        }
    }
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
TimSort(arr);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
