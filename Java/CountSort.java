public class CountSort {
    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3, 3, 1};

        System.out.println("Original Array:");
        printArray(arr);

        countingSort(arr);

        System.out.println("\nSorted Array:");
        printArray(arr);
    }

    public static void countingSort(int[] arr) {
        int max = findMax(arr);

        // Create a counting array to store the count of each element
        int[] countArray = new int[max + 1];

        // Populate the counting array
        for (int value : arr) {
            countArray[value]++;
        }

        // Reconstruct the sorted array
        int index = 0;
        for (int i = 0; i < countArray.length; i++) {
            while (countArray[i] > 0) {
                arr[index] = i;
                index++;
                countArray[i]--;
            }
        }
    }

    public static int findMax(int[] arr) {
        int max = arr[0];
        for (int value : arr) {
            if (value > max) {
                max = value;
            }
        }
        return max;
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
