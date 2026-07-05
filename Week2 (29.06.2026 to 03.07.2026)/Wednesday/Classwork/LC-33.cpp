#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // Check if the target lies within the sorted left half
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1; // Narrow down to the left half
            } else {
                low = mid + 1;  // Search the right half
            }
        } 
        // Otherwise, the right half must be sorted
        else {
            // Check if the target lies within the sorted right half
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;  // Narrow down to the right half
            } else {
                high = mid - 1; // Search the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);

    // Expected Output: 4
    std::cout << "Target found at index: " << result << std::endl;
    return 0;
}