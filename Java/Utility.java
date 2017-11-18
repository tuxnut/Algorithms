import java.util.*;
import java.lang.Math;

public class Utility {
    final public static int TEST_ARR_LENGTH = 5000;
    final public static int TEST_ARR_MAX_VALUE = 10000;
    final public static int TEST_NB_VECTOR = 50;

    final static public int SELECTION = 1;
    final static public int BUBBLE = 2;
    final static public int INSERTION = 3;

    public static void displayArray(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.printf("%d\t", arr[i]);
        }
        System.out.println("");
    }

    public static int getIndexMin(int[] arr) {
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

    public static int getIndexMax(int[] arr) {
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

    final public static boolean testSort(int[] arr) {
        boolean isWellSorted = true;
        for(int i = 0; i < arr.length - 1; i++) {
            if (arr[i+1] < arr[i]) {
                isWellSorted = false;
                System.out.printf("At index: %d\t%d < %d\n", i, arr[i+1], arr[i]);
            }
        }
        return isWellSorted;
    } 

    public static void testSortAlgorithm(int algo) {
        double[] execTime = new double[TEST_NB_VECTOR];

        for(int i = 0; i < TEST_NB_VECTOR; i++) {
            int[] arr = new int[TEST_ARR_LENGTH];

            for(int j = 0; j < TEST_ARR_LENGTH; j++) {
                arr[j] = (int)(Math.random() * TEST_ARR_MAX_VALUE);
            }

            double start = System.nanoTime();

            switch (algo) {
                case SELECTION:
                    SortingAlgorithms.selectionSort(arr);
                    break;
                case BUBBLE:
                    SortingAlgorithms.bubbleSort(arr);
                    break;
                case INSERTION:
                    SortingAlgorithms.insertionSort(arr);
                    break;
            
                default:
                    System.exit(0);
            }

            double finish = System.nanoTime();

            if (!testSort(arr)) {
                System.out.printf("Algo ERROR\n");
                break;
            }
            // System.out.printf("array %d\n", i);
            execTime[i] = finish - start;
        }

        double avgExecutionTime = 0;
        double minExecutionTime = execTime[0];
        double maxExecutionTime = execTime[0];
        for(int i = 0; i < execTime.length; i++) {
            avgExecutionTime += execTime[i];
            minExecutionTime = (execTime[i] < minExecutionTime) ? execTime[i] : minExecutionTime;
            maxExecutionTime = (execTime[i] > maxExecutionTime) ? execTime[i] : maxExecutionTime;
        }
        avgExecutionTime /= TEST_NB_VECTOR;
        System.out.printf("Average Execution Time: %.3f ms\n", avgExecutionTime / 1000000);
        System.out.printf("Minimum Execution Time: %.3f ms\n", minExecutionTime / 1000000);
        System.out.printf("Maximum Execution Time: %.3f ms\n", maxExecutionTime / 1000000);
    }
}