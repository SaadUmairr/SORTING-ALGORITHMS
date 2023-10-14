function QuickSort(arr, low, high) {
    if (low < high) {
        let j = partition(arr, low, high);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

function partition(arr, low, high) {
    let pivot = arr[low];
    let i = low + 1,
        j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            [arr[i], arr[j]] = [arr[j], arr[i]];
        } else {
            break;
        }
    }

    [arr[low], arr[j]] = [arr[j], arr[low]];
    return j;
}

let arr = [5, 4, 3, 2, 1];
console.log("ARRAY BEFORE SORTING:");
console.log(arr);
QuickSort(arr, 0, arr.length - 1);
console.log("ARRAY AFTER SORTING:");
console.log(arr);
