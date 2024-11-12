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


class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        stack<int> st;
        int n=v.size();
        
        for(int i=0;i<n;i++){
            if(st.empty() || v[st.top()]>v[i]){
                st.push(i);
            }
        }
        int res=0;
        for(int j=n-1;j>res;j--){
            while(!st.empty() && v[st.top()]<=v[j]){
                res=max(res,j-st.top());
                st.pop();
            }
        }
        return res;
    }
};