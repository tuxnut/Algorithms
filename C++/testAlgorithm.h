#include "./header.h"

void testSortAlgorithm(int algo_enum) {
    std::vector<double> execTime;
    std::srand(std::time(0));

    for(unsigned i = 0; i < TEST_NB_VECTOR; i++) {
        std::vector<int> vec;
    
        for(unsigned i = 0; i < TEST_ARRAY_LENGTH; i++) {
            vec.push_back(std::rand() % TEST_ARRAY_MAX_VALUE);
        }

        auto start = std::chrono::high_resolution_clock::now();

        switch (algo_enum) {
            case SELECTION:
                selectionSort(vec);
                break;
            case BUBBLE:
                bubbleSort(vec);
                break;
            case INSERTION:
                insertionSort(vec);
                break;
            case MERGE:
                mergeSort(vec.begin(), vec.end());
                break;
            case QUICK:
                quickSort(vec.begin(), vec.end());
        default:
            exit;
        }

        auto finish = std::chrono::high_resolution_clock::now();

        if(!testSort(vec)) {
            std::cout << "Algo ERROR" << std::endl;
            break;
        }
        std::chrono::duration<double> elapsed = finish - start;
        execTime.push_back(elapsed.count());
    }

    double avgExecutionTime = 0;
    double minExecutionTime = execTime[0];
    double maxExecutionTime = execTime[0];
    for(auto const& value: execTime) {
        avgExecutionTime += value;
        minExecutionTime = min(value, minExecutionTime);  
        maxExecutionTime = max(value, maxExecutionTime);
    }
    avgExecutionTime /= TEST_NB_VECTOR;
    std::cout << "Average Execution Time: " << avgExecutionTime * 1000 << "ms" << std::endl;
    std::cout << "Minimum Execution Time: " << minExecutionTime * 1000 << "ms" << std::endl;
    std::cout << "Maximum Execution Time: " << maxExecutionTime * 1000 << "ms" << std::endl;
}