#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    // Map to store the frequency of seen prefix sums: <prefix_sum, count>
    std::unordered_map<int, int> prefix_sums;
    
    int total_subarrays = 0;
    int current_sum = 0;
    
    // Base Case: A prefix sum of 0 has occurred exactly once.
    // This accounts for valid subarrays that sum to k starting from index 0.
    prefix_sums[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];

        // If (current_sum - k) exists in our history, add its frequency to the total
        int complement = current_sum - k;
        if (prefix_sums.find(complement) != prefix_sums.end()) {
            total_subarrays += prefix_sums[complement];
        }

        // Record the current prefix sum into the map history
        prefix_sums[current_sum]++;
    }

    return total_subarrays;
}

int main() {
    std::vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = subarraySum(nums, k);

    // Expected Output: 2 (Subarrays: [1, 1] at index 0-1 and index 1-2)
    std::cout << "Total subarrays that sum up to " << k << ": " << result << std::endl;
    return 0;
}