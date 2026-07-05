#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If the middle element is greater than the rightmost element,
        // the minimum must be in the right un-sorted half.
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } 
        // Otherwise, the minimum is either at mid or to its left.
        else {
            high = mid;
        }
    }

    // When low == high, it will point directly to the minimum element.
    return nums[low];
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = findMin(nums);

    // Expected Output: 0
    std::cout << "The minimum element is: " << result << std::endl;
    return 0;
}