int* cocktail(int* arr, int size) {
    int helper = 0;
    int left = 0;
    int right = size - 1;

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
