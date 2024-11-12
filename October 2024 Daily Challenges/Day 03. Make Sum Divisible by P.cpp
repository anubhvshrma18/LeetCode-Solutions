class Solution {
public:
    int minSubarray(vector<int>& N, int p) {
        int n = N.size(), totalSum = 0;
        for(int i=0;i<n;i++) {
            totalSum = (totalSum+N[i])%p;
        }
        if(totalSum%p == 0) return 0;
        int target = totalSum%p;
        unordered_map<int,int> mp;
        int currentSum = 0, ans = n;
        mp[currentSum]=-1;
        for(int i=0;i<n;i++) {
            currentSum = (currentSum+N[i])%p;
            int val = (currentSum - target + p)%p;
            if(mp.find(val) != mp.end()) {
                ans = min(ans, i-mp[val]);
            }
            mp[currentSum] = i;
        }
        return ans==n ? -1 : ans;
    }
    
};