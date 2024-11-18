class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(),sum=0, start=1, end=k;
        vector<int> ans(n,0);
        if(k==0) return ans;
        if(k<0) {
            k*=-1;
            start=n-k;
            end=n-1;
        }
        for(int i=start;i<=end;i++)
            sum+=code[i];
        for(int i=0;i<n;i++) {
            ans[i]=sum;
            sum-=code[(start++)%n];
            sum+=code[(++end)%n];
        }
        
        return ans;
    }
};