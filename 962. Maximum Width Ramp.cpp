// Time Complexity - O(NLogN)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vec;
        for(int i = 0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int mni = n;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            mni = min(mni,vec[i].second);
            ans = max(ans,vec[i].second-mni);
        }
        return ans;
    }
};

// Time Complexity - O(N)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(st.empty() || nums[st.top()]>nums[i]) {
                // if the current value is smaller than in the storage
                st.push(i);
            }
        }
        int ans =0;
        for(int i=n-1;i>=0;i--) {
            while(st.size()>0 && nums[st.top()]<=nums[i]) {
                ans = max(ans, i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};
