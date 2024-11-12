class Solution {
public:
    int res = 0, target = 0;
    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums)
                target |= num;

        dfs(nums, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int idx, int mask) {
        if (mask == target) res++;

        for (int i = idx; i < nums.size(); i++)
            dfs(nums, i + 1, mask | nums[i]);
    }
};