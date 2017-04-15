//
// Created by Павел Мовчан on 4/14/17.
//

#ifndef SORTS_MERGE_H
#define SORTS_MERGE_H

int* merge_arrays(int left[], int right[], int left_size, int right_size) {
    int *res = new int[left_size + right_size];
    int res_i = 0;
    int left_i = 0;
    int right_i = 0;


    while (left_i < left_size && right_i < right_size) {

        if (left[left_i] < right[right_i]) {
            res[res_i] = left[left_i];
            left_i++;
        } else {
            res[res_i] = right[right_i];
            right_i++;
        }

        res_i++;
    }

    for (int i(right_i); i < right_size; res_i++, i++) {
        res[res_i] = right[i];
    }

    for (int i(left_i); i < left_size; res_i++, i++) {
        res[res_i] = left[i];
    }

    return res;
}

#endif //SORTS_MERGE_H
