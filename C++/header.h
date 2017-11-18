#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>


#define TEST_ARRAY_LENGTH 5000
#define TEST_ARRAY_MAX_VALUE 10000
#define TEST_NB_VECTOR 50
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

enum ALGO {
    SELECTION,
    BUBBLE,
    INSERTION,
    MERGE,
    QUICK
};

const void displayVector(std::vector<int> &vec) {
    for(auto const& value: vec) {
        std::cout << value << "\t";
    }
    std::cout << std::endl;
}

const void displayArray(int arr[], const unsigned length) {
    for(unsigned i = 0; i < length; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

const int getIndexMax(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    const unsigned size = end - begin;
    const unsigned length = (size + 1) * 0.5;
    unsigned index_1 = 0;
    unsigned index_2 = size - 1;
    int max_1 = *begin;
    int max_2 = *(end-1);

    for(unsigned i = 1; i < length; i++) {
        if(*(begin+i) > max_1) {
            max_1 = *(begin+i);
            index_1 = i;
        }

        if(*(end-1-i) > max_2) {
            max_2 = *(end-1-i);
            index_2 = size-1-i;
        }
    }

    return (max_1 > max_2) ? index_1 : index_2;
}

const int getIndexMin(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    const unsigned size = end - begin;
    const unsigned length = (size + 1) * 0.5;
    unsigned index_1 = 0;
    unsigned index_2 = size - 1;
    int min_1 = *begin;
    int min_2 = *(end-1);

    for(unsigned i = 1; i < length; i++) {
        if(*(begin+i) < min_1) {
            min_1 = *(begin+i);
            index_1 = i;
        }

        if(*(end-1-i) < min_2) {
            min_2 = *(end-1-i);
            index_2 = size-1-i;
        }
    }

    return (min_1 < min_2) ? index_1 : index_2;
}

const bool testSort(std::vector<int> vec) {
    bool isWellSorted = true;
    for(unsigned i = 0; i < vec.size() - 1; i++) {
        if(vec[i+1] < vec[i]) {
            isWellSorted = false;
            std::cout << "At index: " << i << "\t" << vec[i+1] << " < " << vec[i] << std::endl;
        }
    }
    return isWellSorted;
}

void testSortAlgorithm(int algo_enum);
/// Tests with LENGTH = 5000 and MAX_VALUE = 10000 on 50 vector
inline void selectionSort(std::vector<int> &vec);      // 148.713 ms
inline void bubbleSort(std::vector<int> &vec);         // 251.325 ms
inline void insertionSort(std::vector<int> &vec);      // 87.7155 ms
inline void mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);   // 6.39154 ms
inline void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end);
inline void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);   // 1.90515 ms
std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end);
