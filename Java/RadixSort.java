import java.util.*;

public class RadixSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        System.out.print("Enter size of the array: ");
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
            radixSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void printList(List<Integer> arr) {
        for (int value : arr) {
            System.out.print(value + "\t");
        }
        System.out.println();
    }

    public static int getMax(List<Integer> arr) {
        int max = Integer.MIN_VALUE;
        for (int i : arr) {
            max = Math.max(max, i);
        }
        return max;
    }

    public static void countingSort(List<Integer> arr, int exp) {
        List<Integer> output = new ArrayList<>(Collections.nCopies(arr.size(), 0));
        int[] count = new int[10];

        for (int i : arr) {
            count[(i / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output.set(count[(arr.get(i) / exp) % 10] - 1, arr.get(i));
            count[(arr.get(i) / exp) % 10]--;
        }

        arr.clear();
        arr.addAll(output);
    }

    public static void radixSort(List<Integer> arr) {
        int max = getMax(arr);
        int exp = 1;

        while (max / exp > 0) {
            countingSort(arr, exp);
            exp *= 10;
        }
    }
}
