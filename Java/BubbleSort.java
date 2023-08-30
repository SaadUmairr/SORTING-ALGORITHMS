import java.util.ArrayList;
import java.util.Scanner;

public class BubbleSort {
    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size of the list: ");
        int size = scanner.nextInt();
        System.out.println("Enter the elements: ");
        for (int i = 0; i < size; i++) {
            int el = scanner.nextInt();
            arr.add(el);
        }
        bubbleSort(arr);
        System.out.println("Sorted List: ");
        for (int num : arr)
            System.out.print(num + " "); 
        scanner.close();
    }

    public static void bubbleSort(ArrayList<Integer> arr) {
        int size = arr.size();
        boolean swapped;
        for(int i = 0; i < size - 1; i++) {
            swapped = false;
            for(int j = 0; j < size - i - 1; j++) {
                if(arr.get(j) > arr.get(j + 1)) {
                    int temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }
    }
}
