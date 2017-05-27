int* bubble(int* arr, int size) {
    int helper;

    for (int i(0); i < size; i++) {
        for (int j(0); j < size-1; j++) {
            helper = arr[j];

            if (helper > arr[j+1]) {
                arr[j] = arr[j+1];
                arr[j+1] = helper;
            }
        }
    }

    return arr;
}
