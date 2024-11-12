class Solution {
public:
    void solve(string& s, unordered_set<string>& st, int& ans, int idx) {
        if(idx == s.length()) {
            int size = st.size();
            ans = max(ans, size);
            return;
        }
        
        for(int i=idx+1;i<=s.length();i++) {
            string substring = s.substr(idx, i-idx);
            if(st.count(substring)==0) {
                st.insert(substring); // done our part
                solve(s, st, ans, i); // compute for other possibilities
                st.erase(substring); // undo the part we have done
            }
        }
    }
    int maxUniqueSplit(string s) {
        int ans=0;
        unordered_set<string> st; // hold the unique substrings
        solve(s,st,ans,0);
        return ans;
    }
    
    // T.C.- O(2^N)
    // S.C. - O(N)
};