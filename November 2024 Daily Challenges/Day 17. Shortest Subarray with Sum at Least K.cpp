class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0]==k ? nums[0] : -1;
        int n = nums.size(), mn = n + 1;
        vector<long long> prefixSum(n + 1);
        for(int i=0; i < n; i++)
            prefixSum[i+1] = prefixSum[i] + nums[i];
        deque<int> q;
        for(int i=0; i < n + 1; i++){
            while(!q.empty() && prefixSum[i] - prefixSum[q.front()] >= k) {
                mn = min(mn, i - q.front());
                q.pop_front();
            }
            
            
            while(!q.empty() && prefixSum[i] <= prefixSum[q.back()])
                q.pop_back();
            
            q.push_back(i);
        }
        
        return mn <= n ? mn : -1;
    }
};