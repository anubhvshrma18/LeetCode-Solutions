class Solution {
public:
    void sub(vector<int>& n,vector<vector<int>>& res,vector<int>& v,int idx){
        for(int i=idx;i!=n.size();++i){
            if(i==idx || n[i]!=n[i-1]){
                v.push_back(n[i]);
                res.push_back(v);
                sub(n,res,v,i+1);
                v.pop_back();
            }
            
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        sub(nums,res,v,0);
        return res;
    }
};