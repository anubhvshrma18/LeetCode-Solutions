class Solution {
public:
    vector<vector<int>> ans;
    void makesum(vector<int>& v,int tar,int ssf,vector<int> &temp,int idx,int cnt){
        if(ssf>tar){
            return;
        }
        if(ssf==tar){
            if(cnt==0){
                ans.push_back(temp);
            }
            return;
        }
        
        for(int i=idx;i<v.size();i++){
            temp.push_back(v[i]);
            makesum(v,tar,ssf+v[i],temp,i+1,cnt-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<int> candidates;
        for(int i=0;i<9;i++){
            candidates.push_back(i+1);
        }
        makesum(candidates,n,0,temp,0,k);
        return ans;
    }
};