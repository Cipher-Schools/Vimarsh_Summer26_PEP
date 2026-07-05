#include <iostream>
#include <vector>
#include <algorithm>

int longestOnes(std::vector<int>& nums, int k) {
    int left = 0;
    int max_length = 0;
    int zero_count = 0;

    for (int right = 0; right < nums.size(); right++) {
        // If we encounter a zero, log it into our budget tracker
        if (nums[right] == 0) {
            zero_count++;
        }

        // If we ran out of flips (zeros inside > k), shrink the window from the left
        while (zero_count > k) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++; // Move left pointer forward
        }

        // The window [left, right] contains at most k zeros at this point
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int result = longestOnes(nums, k);

    // Expected Output: 6
    // (We can flip the zeros at index 3 and 4, making the longest subarray of 1s from index 5 to 10)
    std::cout << "Maximum consecutive ones after at most " << k << " flips: " << result << std::endl;
    return 0;
}