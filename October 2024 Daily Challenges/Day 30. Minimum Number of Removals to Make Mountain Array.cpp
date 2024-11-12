
// Leetcode - https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftLIS(n, 1);
        vector<int> rightLIS(n, 1);
        
        // populate left LIS
        for(int i=1;i<n-1;i++) {
            int mx = 0;
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    mx = max(mx, leftLIS[j]);
                }
            }
            leftLIS[i]=1+mx;
        }
        
        // populate right LIS
        for(int i=n-2;i>0;i--) {
            int mx = 0;
            for(int j=i+1;j<n;j++) {
                if(nums[i]>nums[j]) {
                    mx = max(mx, rightLIS[j]);
                }
            }
            rightLIS[i]=1+mx;
        }
        
        int totalMaxSizeOfMountain = 0;
        
        for(int i=0;i<n;i++) {
            if(leftLIS[i] > 1 && rightLIS[i] > 1) {
                int total = leftLIS[i]+rightLIS[i] - 1;
                totalMaxSizeOfMountain = max(totalMaxSizeOfMountain, total);
            }
        }
        
        return n-totalMaxSizeOfMountain;
    }
};