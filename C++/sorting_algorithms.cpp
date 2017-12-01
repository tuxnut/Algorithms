#include "./testAlgorithm.h"

/* In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.*/
void selectionSort(std::vector<int> &vec)
{
    for (unsigned i = 0; i < vec.size() - 1; i++)
    {
        int indexMin = i;
        for (unsigned j = i + 1; j < vec.size(); j++)
        {
            indexMin = (vec[j] < vec[indexMin]) ? j : indexMin;
        }
        if (indexMin == i)
        {
            continue;
        }
        int tmp = vec[i];
        vec[i] = vec[indexMin];
        vec[indexMin] = tmp;
    }
}

void selectionSort(int arr[], const long length)
{
    for (unsigned i = 0; i < length - 1; i++)
    {
        int indexMin = i;
        for (unsigned j = i; j < length; j++)
        {
            indexMin = (arr[j] < arr[indexMin]) ? j : indexMin;
        }
        if (indexMin == i)
        {
            continue;
        }
        int tmp = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = tmp;
    }
}

/* Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. */
void bubbleSort(std::vector<int> &vec)
{
    bool sorting = false;
    unsigned cpt = 0;
    do
    {
        bool isSorted = true;

        for (unsigned i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                isSorted = false;
                int tmp = vec[i + 1];
                vec[i + 1] = vec[i];
                vec[i] = tmp;
            }
        }
        cpt++;
        sorting = !isSorted;
    } while (sorting);
    std::cout << "Sorted in " << cpt << " loop." << std::endl;
}

void bubbleSort(int arr[], const long length)
{
    bool isSorted = false;
    unsigned cpt = 0;
    do
    {
        isSorted = true;

        for (unsigned i = 0; i < length - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                isSorted = false;
                int tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
            }
        }
        cpt++;
    } while (!isSorted);
    std::cout << "Sorted in " << cpt << " loop." << std::endl;
}

/* Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands. */
void insertionSort(std::vector<int> &vec)
{
    for (unsigned i = 1; i < vec.size(); i++)
    {
        int j = i;
        while (j > 0 && vec[j] < vec[j - 1])
        {
            int tmp = vec[j - 1];
            vec[j - 1] = vec[j];
            vec[j] = tmp;
            j--;
        }
    }
}

void insertionSort(int arr[], const long length)
{
    for (unsigned i = 1; i < length; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

/* Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. */
void mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    const auto length = std::distance(begin, end);

    if (length > 1)
    {
        const auto middle = std::next(begin, length / 2);

        mergeSort(begin, middle);
        mergeSort(middle, end);
        merge(begin, middle, end);
    }
}

void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end)
{
    const auto length = std::distance(begin, end);

    std::vector<int> left(begin, middle);
    std::vector<int> right(middle, end);
    auto iteLeft = left.begin();
    auto iteRight = right.begin();

    unsigned k = 0;

    while (iteLeft != left.end() && iteRight != right.end())
    {
        if (*iteLeft < *iteRight)
        {
            *(begin + k) = *iteLeft;
            iteLeft = std::next(iteLeft);
        }
        else
        {
            *(begin + k) = *iteRight;
            iteRight = std::next(iteRight);
        }
        k++;
    }

    while (iteLeft != left.end())
    {
        *(begin + k) = *iteLeft;
        iteLeft = std::next(iteLeft);
        k++;
    }

    while (iteRight != right.end())
    {
        *(begin + k) = *iteRight;
        iteRight = std::next(iteRight);
        k++;
    }
}

void mergeSort(int arr[], const long first, const long last)
{
    if (first < last)
    {
        long middle = first + (last - first) * 0.5;

        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);
        merge(arr, first, middle, last);
    }
}

void merge(int arr[], const long first, const long middle, const long last)
{
    long left_length = middle - first + 1;
    long right_length = last - middle;
    int *left = (int *)malloc(sizeof(int) * left_length);
    int *right = (int *)malloc(sizeof(int) * right_length);

    for (long i = 0; i < right_length; i++)
    {
        right[i] = arr[middle + 1 + i];
    }
    for (long i = 0; i < left_length; i++)
    {
        left[i] = arr[first + i];
    }

    long i = 0, j = 0, k = first;
    while (i < left_length && j < right_length)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_length)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    const auto length = std::distance(begin, end);

    if (length > 1)
    {
        std::vector<int>::iterator middle = partition(begin, end);

        quickSort(begin, middle);
        quickSort(middle, end);
    }
}

std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator middle = begin;
    std::vector<int>::iterator last = std::prev(end);
    int pivot = *last;

    for (auto ite = begin; ite != last; ite += 1)
    {
        if (*ite <= pivot)
        {
            int tmp = *middle;
            *middle = *ite;
            *ite = tmp;
            middle = std::next(middle);
        }
    }

    *last = *middle;
    *middle = pivot;

    return middle;
}

void quickSort(int arr[], const long first, const long last)
{
    if (first < last)
    {
        const long middle = partition(arr, first, last);

        quickSort(arr, first, middle - 1);
        quickSort(arr, middle, last);
    }
}

const long partition(int arr[], const long first, const long last)
{
    const int pivot = arr[last];
    long middle = first;

    for (long i = first; i <= last - 1; i++)
    {
        if (arr[i] <= pivot)
        {
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

void countSort(std::vector<int> &vec)
{
    std::vector<int> tmp(MAX_RAND);

    for (auto const &value : vec)
    {
        tmp[value]++;
    }

    int index = 0;
    for (long i = 0; i < tmp.size(); i++)
    {
        int occurences = tmp[i];
        while (occurences > 0)
        {
            vec[index] = i;
            index++;
            occurences--;
        }
    }
}

// #define TEST

int main(int argc, char **argv)
{
#ifndef TEST
    bool vector = true;

    std::srand(std::time(0));
    long ARR_LENGTH = std::pow(10, 5);

    if (vector)
    {
        std::vector<int> vec(ARR_LENGTH);
        std::generate(vec.begin(), vec.end(), randomGenerator);

        // displayVector(vec);

        const auto start = std::chrono::high_resolution_clock::now();

        // std::sort(vec.begin(), vec.end());

        // selectionSort(vec);
        // bubbleSort(vec);
        // insertionSort(vec);
        // mergeSort(vec.begin(), vec.end());
        // quickSort(vec.begin(), vec.end());
        countSort(vec);
        const auto finish = std::chrono::high_resolution_clock::now();
        // displayVector(vec);
        testSort(vec);
        const std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Execution time: " << elapsed.count() * 1000000 << "us" << std::endl;
        
    } else
    {
        int *arr = (int *)malloc(ARR_LENGTH * sizeof(int));
        for (long i = 0; i < ARR_LENGTH; i++)
        {
            arr[i] = randomGenerator();
        }

        // displayArray(arr, ARR_LENGTH);

        const auto start = std::chrono::high_resolution_clock::now();
        // selectionSort(arr, ARR_LENGTH);
        // bubbleSort(arr, ARR_LENGTH);
        // insertionSort(arr, ARR_LENGTH);
        mergeSort(arr, 0, ARR_LENGTH - 1);
        // quickSort(arr, 0, ARR_LENGTH - 1);

        const auto finish = std::chrono::high_resolution_clock::now();
        // displayArray(arr, ARR_LENGTH);
        // testSort(arr, ARR_LENGTH);


        const std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Execution time: " << elapsed.count() * 1000000 << "us" << std::endl;
    }


#else
    const auto start = std::chrono::high_resolution_clock::now();

    testSortAlgorithm(MERGE);

    const auto finish = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Global Execution time: " << elapsed.count() * 1000 << " ms" << std::endl;
#endif
    return 0;
}