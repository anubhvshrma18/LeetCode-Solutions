class Solution {
public:
    long long dividePlayers(vector<int>& S) {
        if(S.size()==2) return S[0]*S[1];
        int ts = accumulate(S.begin(), S.end(),0);
        int tt = S.size()/2;
        if(ts%(tt) != 0) return -1;
        int tS = ts/tt;
        
        unordered_map<int,int> mp;
        for(int num:S) {
            mp[num%tS]++;
        }
        long long ans = 0;
        
        for(auto it:mp) {
            int val = it.first;
            int freq = it.second;
            int otherVal = tS-val;
            int otherFreq = mp[tS-val];
            if(val == otherVal) {
                if(freq != otherFreq) return -1;
                ans += (long long)freq/2 * (long long)val * (long long)otherVal * 1LL;
                mp[val] -= freq;
            } else {
                if(freq != otherFreq) return -1;
                ans += (long long)freq * (long long)val * (long long)otherVal * 1LL;
                mp[val] -= freq;
                mp[otherVal] -= freq;
            }
            cout << val << " " << otherVal << " "<< ans << endl;
        }
        
        return ans;
    }
};