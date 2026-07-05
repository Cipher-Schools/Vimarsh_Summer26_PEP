#include <iostream>
#include <vector>

int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    // Edge Case: Since nums contains positive integers (>= 1),
    // the smallest possible subarray product is 1. If k <= 1, 
    // no product can be strictly less than k.
    if (k <= 1) {
        return 0;
    }

    int total_subarrays = 0;
    long long current_product = 1;
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
        // Include the current element into the window's product
        current_product *= nums[right];

        // Shrink the window from the left if the product breaks the constraint
        while (current_product >= k && left <= right) {
            current_product /= nums[left];
            left++;
        }

        // Add the count of valid subarrays ending at the 'right' index
        total_subarrays += (right - left + 1);
    }

    return total_subarrays;
}

int main() {
    std::vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    int result = numSubarrayProductLessThanK(nums, k);

    // Expected Output: 8
    std::cout << "Total subarrays with product less than " << k << ": " << result << std::endl;
    return 0;
}