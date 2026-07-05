#include <iostream>
#include <vector>

void sortColorsBetter(std::vector<int>& arr) {
    int n = arr.size();
    int count0 = 0, count1 = 0, count2 = 0;

    // Pass 1: Count frequencies
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else if (arr[i] == 2) count2++;
    }

    // Pass 2: Overwrite the array
    int i = 0;
    while (count0 > 0) { arr[i++] = 0; count0--; }
    while (count1 > 0) { arr[i++] = 1; count1--; }
    while (count2 > 0) { arr[i++] = 2; count2--; }
}