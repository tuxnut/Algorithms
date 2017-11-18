import java.util.*;
import java.lang.Math;

public class SortingAlgorithms {
    public static void selectionSort(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            int indexMin = i;
            for(int j = i + 1; j < arr.length; j++) {
                indexMin = (arr[j] < arr[indexMin]) ? j : indexMin;
            }
            if (indexMin == i) {
                continue;
            }
            int tmp = arr[i];
            arr[i] = arr[indexMin];
            arr[indexMin] = tmp;
        }
    }

    public static void bubbleSort(int[] arr) {
        boolean sorting = false;
        int cpt = 0;
        do {
            boolean isSorted = true;

            for(int i = 0; i < arr.length - 1; i++) {
                if (arr[i] > arr[i+1]) {
                    isSorted = false;
                    int tmp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = tmp;
                }
            }
            cpt++;
            sorting = !isSorted;
        } while (sorting);
        System.out.printf("Sorted in %d loops\n", cpt);
    }

    public static void insertionSort(int[] arr) {
        for(int i = 1; i < arr.length; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr [j-1]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
    }

    public static void main(String[] args) {
        boolean test = false;

        if(!test) {
            final int ARR_LENGTH = 5000;
            int[] arr = new int[ARR_LENGTH];
            
            for(int i = 0; i < ARR_LENGTH; i++) {
                arr[i] = (int)(Math.random() * 100);
            }
            
            Utility.displayArray(arr);
            double start = System.nanoTime();
            
            selectionSort(arr);
            // bubbleSort(arr);
            // insertionSort(arr);
            
            double finish = System.nanoTime();
            
            Utility.displayArray(arr);
            Utility.testSort(arr);
            
            System.out.printf("Execution time: %.3f us\n", (finish - start)/1000);
            
        } else {
            double start = System.nanoTime();

            Utility.testSortAlgorithm(Utility.SELECTION);
            
            double finish = System.nanoTime();
            System.out.printf("Execution time: %.3f s\n", (finish - start) / 1000000000);
        }
    }
}