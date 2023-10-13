import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class CubeSort {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size of the list: ");
        try {
            int size = scanner.nextInt();
            if(size<=0){
                System.out.println("size of list can not be negative or zero");
                scanner.close();
                return;
            }
            for(int i=0;i<size;i++){
                int el = scanner.nextInt();
                arr.add(el);
            }
            System.out.println("INPUT LIST: ");
            for(int num:arr)
                System.out.print(num+"\t");
                cubeSort(arr);
            System.out.println("\nSORTED LIST: ");
            for(int num:arr)
                System.out.print(num+"\t");

        } catch (InputMismatchException e) {
            System.out.println("INPUT MUST BE IN NUMBERS");
        }
        scanner.close();
    }

    public static void cubeSort(ArrayList<Integer> arr) {
        int size = arr.size();
        int n = size;
        boolean swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; i++) {
                if (arr.get(i) > arr.get(i + 1)) {
                    int temp = arr.get(i);
                    arr.set(i, arr.get(i + 1));
                    arr.set(i + 1, temp);
                    swapped = true;
                }
            }
            n--;
            for (int i = n - 1; i >= 0; i--) {
                if (arr.get(i) > arr.get(i + 1)) {
                    int temp = arr.get(i);
                    arr.set(i, arr.get(i + 1));
                    arr.set(i + 1, temp);
                    swapped = true;
                }
            }
        } while (swapped);

    }
}
