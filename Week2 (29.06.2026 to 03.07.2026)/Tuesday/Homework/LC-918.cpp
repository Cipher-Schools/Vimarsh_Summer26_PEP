#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int maxSubarraySumCircular(std::vector<int>& nums) {
    int total_sum = 0;
    
    int max_sum = nums[0];
    int current_max = 0;
    
    int min_sum = nums[0];
    int current_min = 0;

    for (int x : nums) {
        total_sum += x;

        // Standard Kadane's to find maximum linear subarray
        current_max = std::max(x, current_max + x);
        max_sum = std::max(max_sum, current_max);

        // Modified Kadane's to find minimum linear subarray
        current_min = std::min(x, current_min + x);
        min_sum = std::min(min_sum, current_min);
    }

    // Edge Case: If all numbers are negative, total_sum == min_sum.
    // In that case, the maximum circular subarray is just the largest single negative element (max_sum).
    if (max_sum < 0) {
        return max_sum;
    }

    // Return the maximum of the linear option and the wrapped option
    return std::max(max_sum, total_sum - min_sum);
}

int main() {
    std::vector<int> nums = {5, -3, 5};
    
    int result = maxSubarraySumCircular(nums);
    
    // Expected Output: 10 (Subarray [5, 5] wrapping around the edges)
    std::cout << "Maximum circular subarray sum: " << result << std::endl;
    return 0;
}