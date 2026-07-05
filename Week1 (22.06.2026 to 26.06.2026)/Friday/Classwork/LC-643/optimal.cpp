#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

double findMaxAverage(std::vector<int>& nums, int k) {
    long long current_window_sum = 0;

    // Step 1: Compute the sum of the very first window of size k
    for (int i = 0; i < k; i++) {
        current_window_sum += nums[i];
    }

    long long max_sum = current_window_sum;

    // Step 2: Slide the window across the rest of the array
    for (int i = k; i < nums.size(); i++) {
        // Add the new element entering on the right (nums[i])
        // and subtract the old element leaving on the left (nums[i - k])
        current_window_sum += nums[i] - nums[i - k];
        
        max_sum = std::max(max_sum, current_window_sum);
    }

    // Step 3: Compute the maximum average by dividing the max sum by k exactly once
    return static_cast<double>(max_sum) / k;
}

int main() {
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);

    // Expected Output: 12.75000 (Subarray is [12, -5, -6, 50] -> sum is 51)
    std::cout << "Maximum average: " << result << std::endl;
    return 0;
}