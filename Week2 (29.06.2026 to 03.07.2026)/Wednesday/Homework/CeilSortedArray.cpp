#include <vector>

int findCeil(std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If current element is greater than or equal to k,
        // it's a potential ceil. Record index and search left for a smaller valid option.
        if (arr[mid] >= k) {
            ans = mid;
            high = mid - 1; 
        } 
        // If current element is less than k, it can't be the ceil.
        else {
            low = mid + 1;
        }
    }

    return ans;
}