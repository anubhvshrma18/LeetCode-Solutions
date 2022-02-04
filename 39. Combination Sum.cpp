class Solution {
public:
    vector<vector<int>> ans;
    void makesum(vector<int>& v,int tar,int ssf,vector<int> &temp,int idx){
        if(ssf>tar){
            return;
        }
        if(ssf==tar){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<v.size();i++){
            temp.push_back(v[i]);
            makesum(v,tar,ssf+v[i],temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // ans.clear();
        vector<int> temp;
        makesum(candidates,target,0,temp,0);
        
        return ans;
    }
};