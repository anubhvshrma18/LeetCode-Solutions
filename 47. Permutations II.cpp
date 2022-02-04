class Solution {
public:
    vector<vector<int>> ans;
    void permutation(vector<int> &nums,int r,int c,vector<int> &v,map<int,int>& mp){
        if(r>c){
            ans.push_back(v);
            return;
        }
        
        for(auto x:mp){
            if(x.second > 0){
                mp[x.first]--;
                v.push_back(x.first);
                permutation(nums,r+1,c,v,mp);
                v.pop_back();
                mp[x.first]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        permutation(nums,1,n,v,mp);
        return ans;
    }
};