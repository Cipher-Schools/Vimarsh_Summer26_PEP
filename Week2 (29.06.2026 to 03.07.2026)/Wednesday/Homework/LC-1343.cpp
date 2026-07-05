#include <iostream>
#include <vector>
#include <numeric>

int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    int count = 0;
    int current_window_sum = 0;
    
    // Convert the average condition to a sum condition to avoid division:
    // sum / k >= threshold  ===>  sum >= threshold * k
    int target_sum = threshold * k;

    // 1. Compute the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        current_window_sum += arr[i];
    }

    // Check the first window
    if (current_window_sum >= target_sum) {
        count++;
    }

    // 2. Slide the window across the rest of the array
    for (int i = k; i < arr.size(); i++) {
        // Add the incoming element and subtract the outgoing element
        current_window_sum += arr[i] - arr[i - k];

        if (current_window_sum >= target_sum) {
            count++;
        }
    }

    return count;
}

int main() {
    std::vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;

    int result = numOfSubarrays(arr, k, threshold);

    // Expected Output: 3
    std::cout << "Number of matching subarrays: " << result << std::endl;
    return 0;
}