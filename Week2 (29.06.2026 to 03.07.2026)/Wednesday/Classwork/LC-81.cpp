#include <iostream>
#include <vector>

bool search(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return true;
        }

        // Critical Duplicate Check: If boundaries match mid, we cannot identify the sorted half.
        // Shrink both ends and continue.
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // Check if the target lies within the boundaries of the sorted left half
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        // Otherwise, the right half must be sorted
        else {
            // Check if the target lies within the boundaries of the sorted right half
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false; // Target not found
}

int main() {
    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    // Expected Output: 1 (True)
    std::cout << "Target exists: " << search(nums, target) << std::endl;
    return 0;
}