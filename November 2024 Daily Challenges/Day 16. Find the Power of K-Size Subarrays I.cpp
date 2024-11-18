class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int maxpw = 0, n=nums.size(), id=0;
        vector<int> v(n-k+1, -1);
        if(k-1==0) {
            v[0]=nums[0];
        }
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]+1) {
                maxpw++;
            } else {
                maxpw=0;
            }
            if(maxpw+1 >= k) {
                v[i-k+1]=nums[i];
            }
        }
        return v;
    }
};