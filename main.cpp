#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <time.h>
#include "merge.h"

using namespace std;

const int SIZE = 6;

int* bubble(int* arr);
int* cocktail(int* arr);
int* insertion(int* arr);
int* selection(int *arr);
int* gnome(int *arr);
int* merge(int *arr, int size);
int* quicksort(int * pArray, int size);

int main() {

    int *arr = new int[SIZE];

    srand((unsigned)time(nullptr));

    std::cout << "unsorted: ";

    for (int i(0); i < SIZE; i++) {
        arr[i] = (rand() % 100);
        std::cout << std::setw(2) << arr[i] << " ";
    }

    std::cout << std::endl;

//    clock_t tStart = clock();

//    bubble(arr);
//    cocktail(arr);
//    insertion(arr);
//    selection(arr);
//    gnome(arr);
//    arr = merge(arr, SIZE);
    arr = quicksort(arr, SIZE);

    std::cout << "sorted:   ";

    for (int i(0); i < SIZE; i++) {
        std::cout << std::setw(2) << arr[i] << " ";
    }

//    std::cout << std::endl;
//    std::cout << "time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC;


    delete arr;

    return 0;
}

// SIZE = 10000, Time = 0.60
int* bubble(int* arr) {
    int helper;

    for (int i(0); i < SIZE; i++) {
        for (int j(0); j < SIZE-1; j++) {
            helper = arr[j];

            if (helper > arr[j+1]) {
                arr[j] = arr[j+1];
                arr[j+1] = helper;
            }
        }
    }

    return arr;
}

// SIZE = 10000, Time = 0.38
int* cocktail(int* arr) {
    int helper = 0;
    int left = 0;
    int right = SIZE - 1;

    while (left <= right) {

        for (int i(left); i < right; i++) {
            helper = arr[i];

            if (helper > arr[i+1]) {
                arr[i] = arr[i+1];
                arr[i+1] = helper;
            }
        }

        right--;

        for (int i(right); i > left; i--) {
            helper = arr[i-1];

            if (arr[i] < arr[i-1]) {
                arr[i-1] = arr[i];
                arr[i] = helper;
            }
        }

        left++;
    }

    return arr;
}

// SIZE = 10000, Time = 0.20
int* insertion(int* arr) {
    int helper;
    int element;

    for (int i(1); i < SIZE; i++) {
        element = arr[i];

        for (int j(i); j > 0 && element <= arr[j-1]; j--) {

            helper = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = helper;
        }
    }

    return arr;
}

// SIZE = 10000, Time = 0.15
int* selection(int *arr) {
    int element, x = 0, min, sorted = 0;

    for (int i(0); i < SIZE; i++) {
        element = arr[i];
        min = arr[i];
        x = i;

        for (int j(sorted); j < SIZE; j++) {
            if (arr[j] < min) {
                min = arr[j];
                x = j;
            }
        }

        arr[x] = element;
        arr[i] = min;

        sorted++;
    }

    return arr;
}

// SIZE = 10000, Time = 0.28
int* gnome(int *arr) {
    int helper;

    for (int i(0); i < SIZE-1; i++) {
        helper = arr[i];

        if (arr[i] > arr[i+1]) {
            arr[i] = arr[i+1];
            arr[i+1] = helper;

            for (int j(i); j > 0; j--) {
                helper = arr[j];

                if (arr[j] < arr[j-1]) {
                    arr[j] = arr[j-1];
                    arr[j-1] = helper;
                }
            }
        }
    }

    return arr;
}

// SIZE = 10000, Time = 0.004
int* merge(int *arr, int size = SIZE) {
    if (size == 1) {
        return arr;
    }

    int left_from = 0;
    int left_to = size / 2 - 1;
    int left_size = left_to + 1;

    int right_from = size / 2;
    int right_to = size - 1;
    int right_size = right_to - right_from + 1;

    int *left_part = new int[left_size];
    int *right_part = new int[right_size];

    int i = left_from;
    int j = 0;

    for (; j < left_size; j++, i++) {
        left_part[j] = arr[i];
    }

    i = right_from;
    j = 0;

    for (; j < right_size; j++, i++) {
        right_part[j] = arr[i];
    }

    int *left = merge(left_part, left_size);
    int *right = merge(right_part, right_size);

    return merge_arrays(left, right, left_size, right_size);
}

// SIZE = 10000, Time = 0.010
int * quicksort(int * pArray, int size) {
    if (size < 2) {
        return pArray;
    }

    int elem;

    int pivot = pArray[0];

    int lessCount = 0, greaterCount = 0;

    int * lessDigits = new int[size];
    int * greaterDigits = new int[size];

    int i;

    for (i = 1; i < size; i++) {
        elem = pArray[i];

        if (elem > pivot) {
            greaterDigits[greaterCount] = elem;
            greaterCount++;

        } else {
            lessDigits[lessCount] = elem;
            lessCount++;
        }
    }

    int * pLessSorted = quicksort(lessDigits, lessCount);
    int * pGreaterSorted = quicksort(greaterDigits, greaterCount);

    int * result = new int[size];

    i = 0;

    for (int j = 0; j < lessCount; j++, i++) {
        result[i] = pLessSorted[j];
    }

    result[i++] = pivot;

    for (int j = 0; j < greaterCount; j++, i++) {
        result[i] = pGreaterSorted[j];
    }

    return result;
}