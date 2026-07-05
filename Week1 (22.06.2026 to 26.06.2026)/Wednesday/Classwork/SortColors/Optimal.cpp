#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

void sortColorsOptimal(std::vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else if (arr[mid] == 2) {
            std::swap(arr[mid], arr[high]);
            high--;
            // Do NOT increment mid here! We must evaluate the new element at mid.
        }
    }
}

int main() {
    std::vector<int> arr = {2, 0, 1, 2, 0, 1};
    
    sortColorsOptimal(arr);
    
    for (int val : arr) {
        std::cout << val << " ";
    }
    return 0;
}