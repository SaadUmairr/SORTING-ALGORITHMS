import java.util.ArrayList;
import java.util.Scanner;

public class SelectionSort {
    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size of the list: ");
        int size = scanner.nextInt();
        System.out.println("Enter element: ");
        for (int i = 0; i < size; i++) {
            int el = scanner.nextInt();
            arr.add(el);
        }
        selectionSort(arr);
        System.out.println("SORTED LIST");
        for (int num : arr)
            System.out.print(num + " ");
        scanner.close();
    }

    public static void selectionSort(ArrayList<Integer> arr) {
        int size = arr.size(), i, j, min;
        for (i = 0; i < size - 1; i++) {
            min = i;
            for(j=i+1;j<size;j++)
                if(arr.get(j)<arr.get(min))
                    min=j;
                if(min!=i)
                {
                    int temp = arr.get(i);
                    arr.set(i, arr.get(min));
                    arr.set(min, temp);
                }
                    
        }
    }
}