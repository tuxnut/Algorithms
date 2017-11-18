import numpy as np
import time

def selectionSort(arr):
    for i in range(len(arr) - 1):
        indexMin = i
        
        for j in range(indexMin, len(arr)):
            indexMin = j if arr[j] < arr[indexMin] else indexMin
        
        if indexMin == i:
            continue

        tmp = arr[indexMin]
        arr[indexMin] = arr[i]
        arr[i] = tmp

    return arr

def bubbleSort(arr):
    isSorted = False
    cpt = 0
    while not isSorted:
        isSorted = True
        for i in range(len(arr) - 1):
            if arr[i] > arr[i+1]:
                isSorted = False
                tmp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = tmp
        
        cpt += 1;
    print("Sorted in " + str(cpt) + " loops")
    return arr

def insertionSort(arr):
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j] < arr[j-1]:
            tmp = arr[j-1]
            arr[j-1] = arr[j]
            arr[j] = tmp
            j -= 1
    return arr

def main():
    TEST_ARR_LENGTH = 5
    TEST_ARR_MAX_VALUE = 100
    arr = [0] * TEST_ARR_LENGTH

    for i in range(len(arr)):
        arr[i] = np.random.randint(0, TEST_ARR_MAX_VALUE)

    print(arr)
    start = time.time()

    # arr = selectionSort(arr)
    # arr = bubbleSort(arr)
    arr = insertionSort(arr)

    print("Execution time: " + str((time.time() - start) * 1000000) + "us")
    print(arr)

if __name__ == '__main__':
    main()
