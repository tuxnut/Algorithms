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
        boolean isSorted = false;
        int cpt = 0;
        do {
            isSorted = true;

            for(int i = 0; i < arr.length - 1; i++) {
                if (arr[i] > arr[i+1]) {
                    isSorted = false;
                    int tmp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = tmp;
                }
            }
            cpt++;
        } while (!isSorted);
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

    public static void mergeSort(int[] arr, final int first, final int last) {
        if (first < last) {
            final int middle = first + (last - first) / 2;

            mergeSort(arr, first, middle);
            mergeSort(arr, middle + 1, last);
            merge(arr, first, middle, last);
        }
    }

    public static void merge(int[] arr, final int first, final int middle,  final int last) {
        final int left_length = middle - first + 1;
        final int right_length = last - middle;
        int[] left = new int[left_length];
        int[] right = new int[right_length];

        for(int i = 0; i < left_length; i++) {
            left[i] = arr[first+i];
        }
        for(int i = 0; i < right_length; i++) {
            right[i] = arr[middle+1+i];
        }

        int i = 0, j = 0, k = first;
        while (i < left_length && j < right_length) {
            if(left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left_length) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < right_length) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    public static void quickSort(int[] arr, final int first, final int last) {
        if(first < last) {
            final int middle = partition(arr, first, last);

            quickSort(arr, first, middle - 1);
            quickSort(arr, middle, last);
        }
    }

    public static final int partition(int[] arr, final int first, final int last) {
        final int pivot = arr[last];
        int middle = first;

        for(int i = first; i <= last - 1; i++) {
            if(arr[i] <= pivot) {
                int tmp = arr[middle];
                arr[middle] = arr[i];
                arr[i] = tmp;
                middle++;
            }
        }

        arr[last] = arr[middle];
        arr[middle] = pivot;

        return middle;
    }

    public static void main(String[] args) {
        boolean test = true;

        if(!test) {
            final int ARR_LENGTH = 5;
            int[] arr = new int[ARR_LENGTH];
            
            for(int i = 0; i < ARR_LENGTH; i++) {
                arr[i] = (int)(Math.random() * 100);
            }
            
            Utility.displayArray(arr);
            double start = System.nanoTime();
            
            // selectionSort(arr);
            // bubbleSort(arr);
            // insertionSort(arr);
            // mergeSort(arr, 0, ARR_LENGTH - 1);
            quickSort(arr, 0, ARR_LENGTH - 1);
            
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