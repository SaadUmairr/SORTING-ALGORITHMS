import java.util.ArrayList;
import java.util.Scanner;

public class MergeSort {
    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter size of the list: ");
        int size = scanner.nextInt();
        for (int i = 0; i < size; i++) {
            int el = scanner.nextInt();
            arr.add(el);
        }
        System.out.println("INPUT LIST");
        for (int num : arr)
            System.out.print(num + " ");
        mergesort(arr);
        System.out.println("\nSORTED LIST");
        for (int num : arr)
            System.out.print(num + " ");
        scanner.close();
    }

    public static void mergesort(ArrayList<Integer> arr) {
        if (arr.size() > 1) {
            int middle = arr.size() / 2;
            ArrayList<Integer> LeftHalf = new ArrayList<>(arr.subList(0, middle));
            ArrayList<Integer> RightHalf = new ArrayList<>(arr.subList(middle, arr.size() ));
            mergesort(LeftHalf);
            mergesort(RightHalf);
            ActualWorker(arr, LeftHalf, RightHalf);
        }
    }

    public static void ActualWorker(ArrayList<Integer> arr, ArrayList<Integer> left, ArrayList<Integer> right) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left.get(i) <= right.get(j)) {
                arr.set(k, left.get(i));
                i++;
            } else {
                arr.set(k, right.get(j));
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            arr.set(k, left.get(i));
            i++;
            k++;
        }

        while (j < right.size()) {
            arr.set(k, right.get(j));
            j++;
            k++;
        }
    }
}
