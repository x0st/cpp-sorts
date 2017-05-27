int* gnome(int *arr, int size) {
    int helper;

    for (int i(0); i < size - 1; i++) {
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