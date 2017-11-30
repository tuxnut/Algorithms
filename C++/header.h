#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>

#define TEST_ARRAY_LENGTH 50000
#define TEST_ARRAY_MAX_VALUE 10000
#define TEST_NB_VECTOR 1
#define MAX_RAND 10
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

enum ALGO
{
    SELECTION,
    BUBBLE,
    INSERTION,
    MERGE,
    QUICK
};

int randomGenerator()
{
    return std::rand() % MAX_RAND;
}

const void displayVector(std::vector<int> &vec)
{
    for (auto const &value : vec)
    {
        std::cout << value << "\t";
    }
    std::cout << std::endl;
}

const void displayArray(int arr[], const unsigned length)
{
    for (unsigned i = 0; i < length; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

const int getIndexMax(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    const unsigned size = end - begin;
    const unsigned length = (size + 1) * 0.5;
    unsigned index_1 = 0;
    unsigned index_2 = size - 1;
    int max_1 = *begin;
    int max_2 = *(end - 1);

    for (unsigned i = 1; i < length; i++)
    {
        if (*(begin + i) > max_1)
        {
            max_1 = *(begin + i);
            index_1 = i;
        }

        if (*(end - 1 - i) > max_2)
        {
            max_2 = *(end - 1 - i);
            index_2 = size - 1 - i;
        }
    }

    return (max_1 > max_2) ? index_1 : index_2;
}

const int getIndexMin(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    const unsigned size = end - begin;
    const unsigned length = (size + 1) * 0.5;
    unsigned index_1 = 0;
    unsigned index_2 = size - 1;
    int min_1 = *begin;
    int min_2 = *(end - 1);

    for (unsigned i = 1; i < length; i++)
    {
        if (*(begin + i) < min_1)
        {
            min_1 = *(begin + i);
            index_1 = i;
        }

        if (*(end - 1 - i) < min_2)
        {
            min_2 = *(end - 1 - i);
            index_2 = size - 1 - i;
        }
    }

    return (min_1 < min_2) ? index_1 : index_2;
}

const bool testSort(std::vector<int> vec)
{
    bool isWellSorted = true;
    for (unsigned i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i + 1] < vec[i])
        {
            isWellSorted = false;
            std::cout << "At index: " << i << "\t" << vec[i + 1] << " < " << vec[i] << std::endl;
        }
    }
    return isWellSorted;
}

const bool testSort(int arr[], const unsigned length)
{
    bool isWellSorted = true;
    for (unsigned i = 1; i < length; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            isWellSorted = false;
            std::cout << "At index: " << i << "\t" << arr[i + 1] << " < " << arr[i] << std::endl;
        }
    }
    return isWellSorted;
}

void testSortAlgorithm(int algo_enum, bool isVector);

void selectionSort(int arr[], int length);
void bubbleSort(int arr[], int length);
void insertionSort(int arr[], int length);
void mergeSort(int arr[], const int first, const int last);
inline void merge(int arr[], const int first, const int middle, const int last);
void quickSort(int arr[], const int first, const int last);
inline const int partition(int arr[], int first, int last);

void selectionSort(std::vector<int> &vec);                                        // 148.713 ms
void bubbleSort(std::vector<int> &vec);                                           // 251.325 ms
void insertionSort(std::vector<int> &vec);                                        // 87.7155 ms
void mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end); // 6.39154 ms
inline void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end);
void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end); // 1.90515 ms
inline std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void countSort(std::vector<int> &vec);
