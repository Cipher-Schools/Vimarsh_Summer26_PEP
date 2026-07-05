class Solution {
public:
    int mySqrt(int x) {
        int low= 1 ;
        int high = x ;
        long long mid ;
        int ans ;
        while(low<=high){
            mid = (high-low)/2 + low ;
            if(mid*mid <= x){
                ans = mid ;
                left = mid + 1;
            } else {
                right = mid -1 ;
            }
        }
        return ans ;
    }
};