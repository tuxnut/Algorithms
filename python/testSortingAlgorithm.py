import numpy as np
import time
import sortingAlgorithms

TEST_NB_ARRAY = 50
TEST_ARR_MAX_VALUE = 10000
TEST_ARR_LENGTH = 5000

SELECTION = 1
BUBBLE = 2
INSERTION = 3
MERGE = 4
QUICK = 5

def testSortingAlgorithm(id_algo):
    execTime = [0] * TEST_NB_ARRAY

    for i in range(TEST_NB_ARRAY):
        
        arr = [0] * TEST_ARR_LENGTH
        for j in range(TEST_ARR_LENGTH):
            arr[j] = np.random.randint(0, TEST_ARR_MAX_VALUE)

        start = time.time();

        if id_algo == SELECTION:
            sortingAlgorithms.selectionSort(arr)
        elif id_algo == BUBBLE:
            sortingAlgorithms.bubbleSort(arr)
        elif id_algo == INSERTION:
            sortingAlgorithms.insertionSort(arr)
        # elif id_algo == MERGE:
            # sortingAlgorithms.mergeSort(arr)
        # elif id_algo == QUICK:
            # sortingAlgorithms.quickSort(arr)
        else:
            exit
        
        elapsed = time.time() - start

        if not testSort(arr):
            print('Algo ERROR')
            break

        execTime[i] = elapsed
    
    avgExecutionTime = 0
    minAvgExecutionTime = execTime[0]
    maxAvgExecutionTime = execTime[0]

    for i in range(TEST_NB_ARRAY):
        avgExecutionTime += execTime[i]
        minAvgExecutionTime = execTime[i] if execTime[i] < minAvgExecutionTime else minAvgExecutionTime
        maxAvgExecutionTime = execTime[i] if execTime[i] > maxAvgExecutionTime else maxAvgExecutionTime
    
    avgExecutionTime /= TEST_NB_ARRAY
    print("Average Execution Time: " + str(avgExecutionTime * 1000) + " ms")
    print("Minimum Execution Time: " + str(minAvgExecutionTime * 1000) + " ms")
    print("Maximum Execution Time: " + str(maxAvgExecutionTime * 1000) + " ms")

def testSort(arr):
    isWellSorted = True
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            isWellSorted = False
            print("At index: " + str(i) + "\t" + str(arr[i+1]) + " > " + str(arr[i]))
        
    return isWellSorted