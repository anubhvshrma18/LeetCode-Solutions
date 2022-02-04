class Solution {
public:
    vector<vector<int>> ans;
    void permutation(vector<int> &nums,int r,int c,vector<int> &v,vector<bool> &vis){
        if(c==0){
            if(v.size()==nums.size()){
                ans.push_back(v);
                // v.clear();
                return;
            }
        }
            
        for(int i=0;i<nums.size();i++){
            if(vis[i]==false){
                vis[i]=true;
                v.push_back(nums[i]);
                permutation(nums,r,c-1,v,vis);
                v.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        vector<bool> vis(n,false);
        permutation(nums,0,n,v,vis);
        return ans;
    }
};