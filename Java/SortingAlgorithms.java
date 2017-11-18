import java.util.*;
import java.lang.Math;

public class SortingAlgorithms {
    private static int TEST_ARR_LENGTH = 5;
    private static int TEST_ARR_MAX_VALUE = 100;

    private static void displayArray(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.printf("%d\t", arr[i]);
        }
        System.out.println("");
    }

    private static int getIndexMin(int[] arr) {
        int min = arr[0];
        int index = 0;
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] < min) {
                min = arr[i];
                index = i;
            }
        }
        return index;
    }

    private static int getIndexMax(int[] arr) {
        int max = arr[0];
        int index = 0;
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }
        return index;
    }

    private static int[] selectionSort(int[] arr) {
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
        return arr;
    }

    public static int[] bubbleSort(int[] arr) {
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
        return arr;
    }

    public static int[] insertionSort(int[] arr) {
        for(int i = 1; i < arr.length; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr [j-1]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = new int[TEST_ARR_LENGTH];

        for(int i = 0; i < TEST_ARR_LENGTH; i++) {
            arr[i] = (int)(Math.random() * TEST_ARR_MAX_VALUE);
        }

        displayArray(arr);
        long start = System.nanoTime();
        
        // selectionSort(arr);
        // bubbleSort(arr);
        insertionSort(arr);

        long end = System.nanoTime();
        displayArray(arr);
        System.out.printf("Execution time: %d us\n", (end - start)/1000);
    }
}