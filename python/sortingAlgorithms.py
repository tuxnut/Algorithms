import numpy as np
import time
import testSortingAlgorithm


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


def bubbleSort(arr):
    isSorted = False
    cpt = 0
    while not isSorted:
        isSorted = True
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                isSorted = False
                tmp = arr[i]
                arr[i] = arr[i + 1]
                arr[i + 1] = tmp

        cpt += 1
    print("Sorted in " + str(cpt) + " loops")


def insertionSort(arr):
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j] < arr[j - 1]:
            tmp = arr[j - 1]
            arr[j - 1] = arr[j]
            arr[j] = tmp
            j -= 1


def mergeSort(arr, first, last):
    if last > first:
        middle = (int)(first + (last - first) * 0.5)
        mergeSort(arr, first, middle)
        mergeSort(arr, middle + 1, last)
        merge(arr, first, middle, last)


def merge(arr, first, middle, last):
    left_length = middle - first + 1
    right_length = last - middle
    left = []
    right = []

    for i in range(0, left_length):
        left[i] = arr[first + i]
    for i in range(0, right_length):
        right[i] = arr[middle + 1 + i]

    i = 0
    j = 0
    k = first

    while i < left_length and j < right_length:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < left_length:
        arr[k] = left[i]
        k += 1
        i += 1

    while j < right_length:
        arr[k] = right[j]
        k += 1
        j += 1


def main():
    test = False

    if not test:
        ARR_LENGTH = 5
        ARR_MAX_VALUE = 100
        arr = [0] * ARR_LENGTH

        for i in range(len(arr)):
            arr[i] = np.random.randint(0, ARR_MAX_VALUE)

        print(arr)
        start = time.time()

        # selectionSort(arr)
        # bubbleSort(arr)
        # insertionSort(arr)
        mergeSort(arr, 0, ARR_LENGTH - 1)

        finish = time.time()
        print(arr)
        testSortingAlgorithm.testSort(arr)
        print("Execution time: " + str((finish - start) * 1000000) + " us")

    else:
        start = time.time()

        testSortingAlgorithm.testSortingAlgorithm(
            testSortingAlgorithm.SELECTION)

        print("Execution time: " + str((time.time() - start)) + " s")


if __name__ == '__main__':
    main()
