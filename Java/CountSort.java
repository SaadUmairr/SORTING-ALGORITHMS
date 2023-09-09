import java.util.Scanner;

public class CountSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        int max = Integer.MIN_VALUE;

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        System.out.println("INPUT LIST: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        countingSort(arr, max);

        System.out.println("\nSORTED LIST: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        scanner.close();
    }

    public static void countingSort(int[] arr, int max) {
        int[] countArray = new int[max + 1];

        for (int num : arr) {
            countArray[num]++;
        }

        int outputIndex = 0;
        for (int i = 0; i < countArray.length; i++) {
            while (countArray[i] > 0) {
                arr[outputIndex] = i;
                outputIndex++;
                countArray[i]--;
            }
        }
    }
}
