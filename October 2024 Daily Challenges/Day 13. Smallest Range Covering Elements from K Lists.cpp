class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            mx = max(mx, nums[i][0]);
            mn = min(mn, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        
        vector<int> ans={mn, mx};
        while(true) {
            auto a = pq.top();
            pq.pop();
            mn = a[0];
            int crow = a[1];
            int cidx = a[2];
            
            
            if(mx-mn < ans[1]-ans[0]) {
                ans[0] = mn;
                ans[1] = mx;
            }
            if(cidx+1 == nums[crow].size()) 
                break;
            mx = max(mx, nums[crow][cidx+1]);
            cout << mn << " " << mx << endl;
            pq.push({nums[crow][cidx+1], crow, cidx+1});
        }
        return ans;
    }
};