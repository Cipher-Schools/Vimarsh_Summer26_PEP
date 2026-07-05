#include <iostream>
#include <vector>

void moveZeroesBetter(std::vector<int>& arr) {
    int n = arr.size();
    int write_index = 0;

    // Loop 1: Shift all non-zero elements to the front
    for (int read_index = 0; read_index < n; read_index++) {
        if (arr[read_index] != 0) {
            arr[write_index] = arr[read_index];
            write_index++;
        }
    }

    // Loop 2: Fill the rest of the array with zeroes
    for (int i = write_index; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    std::vector<int> arr = {6, 0, 1, 0, 2};
    
    moveZeroesBetter(arr);
    
    // Output the result
    for (int val : arr) {
        std::cout << val << " ";
    }
    return 0;
}