#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <time.h>

using namespace std;

const int SIZE = 8;

int* bubble(int* arr);
int* cocktail(int* arr);
int* insertion(int* arr);
int* selection(int *arr);
int* gnome(int *arr);

int main() {

    int *arr = new int[SIZE];

    srand(time(nullptr));

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
    selection(arr);

    std::cout << "sorted:   ";

    for (int i(0); i < SIZE; i++) {
        std::cout << std::setw(2) << arr[i] << " ";
    }

//    std::cout << std::endl;
//    std::cout << "time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC;

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