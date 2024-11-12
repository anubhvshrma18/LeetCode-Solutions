class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        
        for(int a:arr) {
            mp[((a%k)+k)%k]++;
        }
        
        for(int i=0;i<k;i++) {
            if(i==0) {
                if(mp[i]%2!=0) return false;
            }
            else if(mp[i]!=mp[k-i])
                return false;
        }
        return true;
    }
};