int* mergeArrays(int left[], int right[], int leftSize, int rightSize) {
    int *res = new int[leftSize + rightSize];
    int resI = 0;
    int leftI = 0;
    int rightI = 0;


    while (leftI < leftSize && rightI < rightSize) {

        if (left[leftI] < right[rightI]) {
            res[resI] = left[leftI];
            leftI++;
        } else {
            res[resI] = right[rightI];
            rightI++;
        }

        resI++;
    }

    for (int i(rightI); i < rightSize; resI++, i++) {
        res[resI] = right[i];
    }

    for (int i(leftI); i < leftSize; resI++, i++) {
        res[resI] = left[i];
    }

    return res;
}

int* merge(int *arr, int size) {
    if (size == 1) {
        return arr;
    }

    int leftFrom = 0;
    int leftTo = size / 2 - 1;
    int leftSize = leftTo + 1;

    int rightFrom = size / 2;
    int rightTo = size - 1;
    int rightSize = rightTo - rightFrom + 1;

    int *leftPart = new int[leftSize];
    int *rightPart = new int[rightSize];

    int i = leftFrom;
    int j = 0;

    for (; j < leftSize; j++, i++) {
        leftPart[j] = arr[i];
    }

    i = rightFrom;
    j = 0;

    for (; j < rightSize; j++, i++) {
        rightPart[j] = arr[i];
    }

    int *left = merge(leftPart, leftSize);
    int *right = merge(rightPart, rightSize);

    return mergeArrays(left, right, leftSize, rightSize);
}