#include <iostream>
#include <vector>
#include <cmath> // For std::abs

std::vector<int> sortedSquaresOptimal(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n); // Create a result array of size n
    
    int left = 0;
    int right = n - 1;
    int index_to_fill = n - 1; // Start filling the result array from the BACK

    while (left <= right) {
        int left_square = nums[left] * nums[left];
        int right_square = nums[right] * nums[right];

        if (left_square > right_square) {
            result[index_to_fill] = left_square;
            left++; // Move the left pointer inward
        } else {
            result[index_to_fill] = right_square;
            right--; // Move the right pointer inward
        }
        index_to_fill--; // Move our result position one step to the left
    }

    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    
    std::vector<int> result = sortedSquaresOptimal(nums);
    
    // Output: 0 1 9 16 100
    for (int x : result) {
        std::cout << x << " ";
    }
    return 0;
}