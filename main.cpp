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

    bubble(arr);

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