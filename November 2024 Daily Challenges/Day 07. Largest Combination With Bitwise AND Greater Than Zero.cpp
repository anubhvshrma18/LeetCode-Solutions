class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int mx = 0;
        for(int i=0;i<32;i++) {
            int cnt = 0;
            for(auto n:nums) {
                if(n&(1<<i)) {
                    cnt++;
                }
            }
            mx = max(mx,cnt);
        }
        return mx;
    }
};