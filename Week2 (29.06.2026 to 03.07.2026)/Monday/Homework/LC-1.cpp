class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size() ;
        vector<int> ans ;
        ans.resize(2) ;
        sort(nums.begin(), nums.end()) ;
        int left= 0;
        int right= n-1 ;
        int sum = 0;
        while(right>left){
            sum= nums[left] + nums[right] ;
            if(sum>target){
                right-- ;
            } else if (sum<target){
                left++ ;
            } else {
                ans[0] = left ;
                ans[1] = right ;
                break;
            }
        }
        return ans ;
    }
};