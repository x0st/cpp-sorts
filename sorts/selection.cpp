int* selection(int *arr, int size) {
    int element, x = 0, min, sorted = 0;

    for (int i(0); i < size; i++) {
        element = arr[i];
        min = arr[i];
        x = i;

        for (int j(sorted); j < size; j++) {
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