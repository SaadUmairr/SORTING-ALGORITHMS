import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class BucketSort {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size of the list: ");
        try {
            int size = scanner.nextInt();
            if (size <= 0) {
                System.out.println("size of list can not be negative or zero");
                scanner.close();
                return;
            }
            for (int i = 0; i < size; i++) {
                int el = scanner.nextInt();
                arr.add(el);
            }
            System.out.println("INPUT LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
            bucketSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");

        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void bucketSort(ArrayList<Integer> arr) {
        int size = arr.size();
        if (size <= 0)
            return;
        int maxVal = Collections.max(arr);
        int minVal = Collections.min(arr);

        int range = maxVal - minVal + 1;
        List<List<Integer>> buckets = new ArrayList<>(range);

        for (int i = 0; i < size; i++) {
            buckets.add(new ArrayList<>());
        }
        for (int i = 0; i < size; i++) {
            int index = arr.get(i) - minVal;
            buckets.get(index).add(arr.get(i));
        }

        for (int i = 0; i < range; i++) {
            Collections.sort(buckets.get(i));
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            for (int j = 0; j < buckets.get(i).size(); j++) {
                arr.set(index++, buckets.get(i).get(j));
            }
        }
    }
}
