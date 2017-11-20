
AlgorithmEnum = {
    SELECTION : 1,
    BUBBLE : 2,
    INSERTION : 3,
    MERGE : 4,
    QUICK : 5
}

class TestSortingAlgorithm {

    constructor() {
        this.TEST_ARR_LENGTH = 5000;
        this.TEST_ARR_MAX_VALUE = 10000;
        this.TEST_NB_ARR = 50;
    }

    testSort(arr) {
        isWellSorted = true;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] > arr[i+1]) {
                console.log("At index: " + i + "\t" + arr[i] + " > " + arr[i+1]);
                isWellSorted = false;
            }
        }
    }

    testSortingAlgorithm(id_algo) {
        execTime = [0] * thi;
        
        for (let i = 0; i < this.TEST_NB_ARR; i++) {
            const element = ];
            
        }
    }
}

