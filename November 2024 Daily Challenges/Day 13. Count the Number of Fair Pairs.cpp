class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0, n = nums.size();
        sort(begin(nums), end(nums));
        for(int i=0; i < n; i++){
            int l = lower_bound(begin(nums)+i+1, end(nums), lower-nums[i]) - begin(nums);
            int r = upper_bound(begin(nums)+i+1, end(nums), upper-nums[i]) - begin(nums);
            res += r-l;
        }
        return res;
    }
};