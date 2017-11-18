#include "./testAlgorithm.h"

/* In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.*/
void selectionSort(std::vector<int> &vec) {
    for(unsigned i = 0; i < vec.size() - 1; i++) {
        // find minimum in unsorted array
        int indexMin = getIndexMin(vec.begin() + i, vec.end());
        // move the minimum found in the sorted array
        const int tmp = vec[indexMin+i];
        vec[indexMin+i] = vec[i];
        vec[i] = tmp;
    }
}

/* Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. */
void bubbleSort(std::vector<int> &vec) {
    bool sorting = false;
    unsigned cpt = 0;
    do {
        bool isSorted = true;

        for(unsigned i = 0; i < vec.size() - 1; i++) {
            if(vec[i] > vec[i+1]) {
                isSorted = false;
                int tmp = vec[i+1];
                vec[i+1] = vec[i];
                vec[i] = tmp;
            }
        }
        cpt++;
        sorting = !isSorted;
    } while(sorting);
    std::cout << "Sorted in " << cpt << " loop." << std::endl;
}

/* Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands. */
void insertionSort(std::vector<int> &vec) {
    for(unsigned i = 1; i < vec.size(); i++) {
        int j = i;
        while(j > 0 && vec[j] < vec[j-1]) {
            int tmp = vec[j-1];
            vec[j-1] = vec[j];
            vec[j] = tmp;
            j--;
        }
    }
}

/* Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. */
void mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    const auto length = std::distance(begin, end);

    if(length > 1) {
        const auto middle = std::next(begin, length / 2); 

        mergeSort(begin, middle);
        mergeSort(middle, end);
        merge(begin, middle, end);
        std::vector<int> vec(begin, end);
    }
}
 
void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end) {
    const auto length = std::distance(begin, end);

    std::vector<int> left (begin, middle);
    std::vector<int> right (middle, end);
    auto iteLeft = left.begin(); 
    auto iteRight = right.begin(); 

    unsigned k = 0;

    while(iteLeft != left.end() && iteRight != right.end()) {
        if(*iteLeft < *iteRight) {
            *(begin + k) = *iteLeft;
            iteLeft = std::next(iteLeft);
        } else {
            *(begin + k) = *iteRight;
            iteRight = std::next(iteRight);
        }
        k++;
    }

    while(iteLeft != left.end()) {
        *(begin + k) = *iteLeft;
        iteLeft = std::next(iteLeft);
        k++;
    }

    while(iteRight != right.end()) {
        *(begin + k) = *iteRight;
        iteRight = std::next(iteRight);
        k++;
    }
}

void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    const auto length = std::distance(begin, end);
    
    if(length > 1) {
        std::vector<int>::iterator middle = partition(begin, end);

        quickSort(begin, middle);
        quickSort(middle, end);
    }
}

std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>::iterator middle = begin;
    std::vector<int>::iterator last = std::prev(end);
    int pivot = *last;

    for(auto ite = begin; ite != last; ite += 1) {
        if(*ite <= pivot) {
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


int main(int argc, char **argv) {
    std::srand(std::time(0));
    
    std::vector<int> vec;
    
    for(unsigned i = 0; i < 5; i++) {
        vec.push_back(std::rand() % 100);
    }

    displayVector(vec);
    const auto start = std::chrono::high_resolution_clock::now();
    // selectionSort(vec);
    // bubbleSort(vec);
    // insertionSort(vec);
    // mergeSort(vec.begin(), vec.end());
    // quickSort(vec.begin(), vec.end());

    // testSortAlgorithm(QUICK);
    const auto finish = std::chrono::high_resolution_clock::now();

    displayVector(vec);
    testSort(vec);

    const std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Execution time: " << elapsed.count()*1000000 << "us" << std::endl;
    // std::cout << "Execution time: " << elapsed.count() << "s" << std::endl;
    return 0;
}