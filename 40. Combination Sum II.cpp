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
            if(i>idx && v[i]==v[i-1]) continue;
            temp.push_back(v[i]);
            makesum(v,tar,ssf+v[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        makesum(candidates,target,0,temp,0);
        return ans;
    }
};