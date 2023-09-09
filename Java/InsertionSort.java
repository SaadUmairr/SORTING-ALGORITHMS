import java.util.ArrayList;
import java.util.Scanner;

public class InsertionSort {
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
        System.out.println("INPUT LIST");
        for (int num : arr)
            System.out.print(num + " ");
        insertionSort(arr);
        System.out.println("SORTED LIST");
        for (int num : arr)
            System.out.print(num + " ");
        scanner.close();
    }

    public static void insertionSort(ArrayList<Integer> arr)
    {
        int size = arr.size();
        for(int i=1;i<size;i++)
        {
            int min = i;
            while(min>0 && arr.get(min-1)>arr.get(min))
            {
                int temp = arr.get(min-1);
                arr.set(min - 1, arr.get(min));
                arr.set(min, temp);
                min--;
            }
        }
    }
}
