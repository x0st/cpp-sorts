int* insertion(int* arr, int size) {
    int helper;
    int element;

    for (int i(1); i < size; i++) {
        element = arr[i];

        for (int j(i); j > 0 && element <= arr[j-1]; j--) {

            helper = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = helper;
        }
    }

    return arr;
}
