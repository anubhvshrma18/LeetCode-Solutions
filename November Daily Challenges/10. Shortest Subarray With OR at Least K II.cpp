class Solution {
public:
    int minimumSubarrayLength(vector<int>& N, int k) {
        vector<int> bits(32,0);//stores number of one at each bit in a window
        int i=0, ans=1e9;
        for(int j=0;j<N.size();j++) {
            for(int k=0;k<32;k++) {
                if(N[j]&(1<<k))
                    bits[k]++;
            }
            long num=0;
            for(int k=0;k<32;k++)
                if(bits[k])
                    num+=(long)pow(2,k);
            
            while(num>=k&&i<=j) {
                ans=min(ans,j-i+1);
                for(int k=0;k<32;k++) {
                    if(N[i]&(1<<k))
                        bits[k]--; 
                }
                long long newNum=0;
                for(int k=0;k<32;k++)
                    if(bits[k])
                        newNum+=(long)pow(2,k);
                
                num=newNum;
                i++;
            }
        }
        return ans==1e9?-1:ans;
    }
};