import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class InsertionSort {
    public static void main(String args[]) {
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
            insertionSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void insertionSort(ArrayList<Integer> arr) {
        int size = arr.size();
        for (int i = 1; i < size; i++) {
            int min = i;
            while (min > 0 && arr.get(min - 1) > arr.get(min)) {
                int temp = arr.get(min - 1);
                arr.set(min - 1, arr.get(min));
                arr.set(min, temp);
                min--;
            }
        }
    }
}
