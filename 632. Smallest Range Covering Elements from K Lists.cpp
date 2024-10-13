class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // 3 things to store
        // 1. value 2. index of value 3. index of row/list
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int mx = INT_MIN, mn = INT_MAX;

        for(int i=0;i<k;i++) {
            pq.push({nums[i][0], 0, i});
            mx = max(mx, nums[i][0]);
            mn = min(mn, nums[i][0]);
        }

        vector<int> ans = {mn, mx};

        while(pq.size() == k) {
            auto tuple = pq.top();
            pq.pop();

            int currVal = tuple[0];
            int currValIdx = tuple[1];
            int currRow = tuple[2];

            mn = currVal;

            if(mx - mn < ans[1]-ans[0]) {
                ans[0]=mn;
                ans[1]=mx;
            }

            if(currValIdx+1 == nums[currRow].size()) {
                break;
            }

            mx = max(mx, nums[currRow][currValIdx+1]);
            pq.push({nums[currRow][currValIdx+1], currValIdx+1, currRow});

        }

        return ans;
    }
};
