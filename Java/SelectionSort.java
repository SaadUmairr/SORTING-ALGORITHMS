import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class SelectionSort {
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
            selectionSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void selectionSort(ArrayList<Integer> arr) {
        int size = arr.size(), i, j, min;
        for (i = 0; i < size - 1; i++) {
            min = i;
            for (j = i + 1; j < size; j++)
                if (arr.get(j) < arr.get(min))
                    min = j;
            if (min != i) {
                int temp = arr.get(i);
                arr.set(i, arr.get(min));
                arr.set(min, temp);
            }

        }
    }
}