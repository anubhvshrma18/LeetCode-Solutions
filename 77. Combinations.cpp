class Solution {
public:
    vector<vector<int>> ans;
    void comb(vector<int> &x,vector<int> &v,int k,int idx){
        if(x.size()==k){
            // display(x);
            ans.push_back(x);
            return;
        }
        
        for(int i=idx;i<v.size();i++){
            x.push_back(v[i]);
            comb(x,v,k,i+1);
            x.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        vector<int> x;
        comb(x,v,k,0);
        return ans;
    }
};