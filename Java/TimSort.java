import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class TimSort {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size of the list: ");
        try {
            int size = scanner.nextInt();

            if (size <= 0) {
                System.out.println("Size of list can not be negative or zero");
                scanner.close();
                return;
            }
            System.out.println("Enter the elements: ");
            for (int i = 0; i < size; i++) {
                int el = scanner.nextInt();
                arr.add(el);
            }
            System.out.println("INPUT LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
            timSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void timSort(ArrayList<Integer> arr) {
        int n = arr.size();
        int minRun = minRunLength(n);

        // Perform insertion sort on small runs
        for (int i = 0; i < n; i += minRun) {
            int end = Math.min(i + minRun, n);
            insertionSort(arr, i, end);
        }

        // Merge runs
        for (int size = minRun; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = Math.min(left + size, n);
                int right = Math.min(left + 2 * size, n);
                if (mid < right) {
                    merge(arr, left, mid, right);
                }
            }
        }
    }

    public static void insertionSort(ArrayList<Integer> arr, int left, int right) {
        for (int i = left + 1; i < right; i++) {
            int key = arr.get(i);
            int j = i - 1;
            while (j >= left && arr.get(j) > key) {
                arr.set(j + 1, arr.get(j));
                j--;
            }
            arr.set(j + 1, key);
        }
    }

    public static void merge(ArrayList<Integer> arr, int left, int mid, int right) {
        int n1 = mid - left;
        int n2 = right - mid;

        ArrayList<Integer> leftArr = new ArrayList<>();
        ArrayList<Integer> rightArr = new ArrayList<>();

        for (int i = 0; i < n1; i++) {
            leftArr.add(arr.get(left + i));
        }
        for (int i = 0; i < n2; i++) {
            rightArr.add(arr.get(mid + i));
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr.get(i) <= rightArr.get(j)) {
                arr.set(k++, leftArr.get(i++));
            } else {
                arr.set(k++, rightArr.get(j++));
            }
        }

        while (i < n1) {
            arr.set(k++, leftArr.get(i++));
        }

        while (j < n2) {
            arr.set(k++, rightArr.get(j++));
        }
    }

    public static int minRunLength(int n) {
        int r = 0;
        while (n >= 64) {
            r |= n & 1;
            n >>= 1;
        }
        return n + r;
    }
}
