#include <vector>

int findFloor(std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If current element is less than or equal to k, 
        // it's a potential floor. Record index and search right.
        if (arr[mid] <= k) {
            ans = mid;
            low = mid + 1; 
        } 
        // If current element is greater than k, it can't be the floor.
        else {
            high = mid - 1;
        }
    }

    return ans;
}