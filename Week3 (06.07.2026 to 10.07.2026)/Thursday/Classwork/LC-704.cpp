class Solution {
private:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        if (low > high) return -1; // Base case: Element not found
        
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Search left or right half based on the comparison
        if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, high);
        } else {
            return binarySearch(nums, target, low, mid - 1);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};