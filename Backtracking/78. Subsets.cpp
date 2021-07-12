class Solution {
public:
    void sub(vector<int>& n,vector<vector<int>>& res,vector<int>& v,int idx){
        if(idx==n.size()){
            return;
        }
        v.push_back(n[idx]);
        res.push_back(v);
        sub(n,res,v,idx+1);
        v.pop_back();
        sub(n,res,v,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        sub(nums,res,v,0);
        return res;
    }
};