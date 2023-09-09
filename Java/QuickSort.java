import java.util.ArrayList;
import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        System.out.print("Enter the number of elements: ");
        int size = scanner.nextInt();
        if(size<=0){
            System.out.println("Size of list can not be negative or zero");
            scanner.close();
            return ;
        }
        System.out.println("Enter " + size + " elements:");
        for (int i = 0; i < size; i++) {
            int element = scanner.nextInt();
            list.add(element);
        }

        System.out.println("INPUT LIST: " + list);
        quickSort(list, 0, list.size() - 1);
        System.out.println("SORTED LIST: " + list);

        scanner.close();
    }

    public static void quickSort(ArrayList<Integer> arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    public static int partition(ArrayList<Integer> arr, int low, int high) {
        int pivot = arr.get(high);
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr.get(j) < pivot) {
                i++;
                int temp = arr.get(i);
                arr.set(i, arr.get(j));
                arr.set(j, temp);
            }
        }

        int temp = arr.get(i + 1);
        arr.set(i + 1, arr.get(high));
        arr.set(high, temp);

        return i + 1;
    }
}
