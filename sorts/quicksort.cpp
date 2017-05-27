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