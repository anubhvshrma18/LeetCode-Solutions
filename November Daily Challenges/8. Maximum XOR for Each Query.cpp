class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr=0,n=nums.size();
        for(int n:nums) {
            xr^=n;
        }
        xr^=((1<<maximumBit)-1);
        vector<int> ans(n);
        ans[0]=xr;
        for(int i=1;i<n;i++) {
            xr^=nums[n-i];
            ans[i]=xr;
        }
        return ans;
    }
};