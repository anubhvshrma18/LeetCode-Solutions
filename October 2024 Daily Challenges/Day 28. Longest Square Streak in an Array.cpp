class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(int ce:nums) {
            int ceSqrt = sqrt(ce);
            if(ceSqrt*ceSqrt == ce && mp[ceSqrt] > 0) {
                mp[ce] = 1+mp[ceSqrt];
                ans = max(ans, mp[ce]);
            } else {
                mp[ce] = 1;
            }
        }

        return ans == 1 ? -1 : ans;
    }
};