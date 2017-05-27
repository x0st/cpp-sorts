#include <iostream>
#include <iomanip>

#include "sorts/quicksort.cpp"
#include "sorts/merge.cpp"
#include "sorts/gnome.cpp"
#include "sorts/selection.cpp"
#include "sorts/insertion.cpp"
#include "sorts/cocktail.cpp"
#include "sorts/bubble.cpp"

const int SIZE = 6;

void printArray(int * array, int size);
int * composeArray(int size);

int main() {

    int * unsortedArray = composeArray(SIZE);

    std::cout << "unsorted: ";
    printArray(unsortedArray, SIZE);

//    clock_t tStart = clock();

    int * sortedArray = insertion(unsortedArray, SIZE);

    std::cout << std::endl << "sorted:   ";
    printArray(sortedArray, SIZE);

//    std::cout << std::endl;
//    std::cout << "time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC;


    delete[] unsortedArray;

    return 0;
}

/**
 * Returns an array filled with random digits from 0 to 100.
 *
 * @param size
 * @return
 */
int * composeArray(int size) {
    int *arr = new int[size];

    srand((unsigned)time(nullptr));

    for (int i(0); i < SIZE; i++) {
        arr[i] = (rand() % 100);
    }

    return arr;
}

/**
 * Prints an array.
 *
 * @param array
 * @param size
 */
void printArray(int *array, int size) {
    for (int i(0); i < size; i++) {
        std::cout << std::setw(2) << array[i] << " ";
    }
}