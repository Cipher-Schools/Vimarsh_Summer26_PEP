class Solution {
private:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Base case: we've made a choice for every element
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Choice 1: Include nums[index]
        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, result);
        
        // Backtrack: Remove nums[index] to explore the other branch
        current.pop_back();
        
        // Choice 2: Exclude nums[index]
        generateSubsets(index + 1, nums, current, result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, nums, current, result);
        return result;
    }
};