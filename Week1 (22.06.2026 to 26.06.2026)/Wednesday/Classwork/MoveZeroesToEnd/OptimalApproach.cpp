#include <iostream>
#include <vector>
#include <algorithm> // Needed for std::swap

void moveZeroesOptimal(std::vector<int>& arr) {
    int n = arr.size();
    int write_index = 0;

    // Just ONE loop over the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap the non-zero element with the element at write_index
            std::swap(arr[write_index], arr[i]);
            write_index++;
        }
    }
}

int main() {
    std::vector<int> arr = {6, 0, 1, 0, 2};
    
    moveZeroesOptimal(arr);
    
    // Output the result
    for (int val : arr) {
        std::cout << val << " ";
    }
    return 0;
}