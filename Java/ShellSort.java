import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class ShellSort {
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
            shellSort(arr);
            System.out.println("\nSORTED LIST: ");
            for (int num : arr)
                System.out.print(num + "\t");
        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void shellSort(ArrayList<Integer> arr) {
        int size = arr.size();
        for (int gap = size / 2; gap >= 2; gap /= 2)
            for (int j = gap; j < size; j++)
                for (int i = j - gap; i >= 0; i -= gap) {
                    if (arr.get(i + gap) > arr.get(i))
                        break;
                    else {
                        int temp = arr.get(i + gap);
                        arr.set(i + gap, arr.get(i));
                        arr.set(i, temp);
                    }
                }
    }
}